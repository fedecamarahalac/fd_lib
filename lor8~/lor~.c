#include "m_pd.h"
#ifdef NT
#pragma warning( disable : 4244 )
#pragma warning( disable : 4305 )
#endif

/* ------------------------ lor~ ----------------------------- */

/* tilde object to take absolute value. */

static t_class *lor_class;

typedef struct _lor
{
    t_object x_obj; 	/* obligatory header */
    t_float x_f;
    t_float val;    	/* place to hold inlet's value if it's set by message */

	t_float outcome;
	t_float x, y, z;
	t_float inith, inita, initb, initc, dist;
} t_lor;

    /* this is the actual performance routine which acts on the samples.
    It's called with a single pointer "w" which is our location in the
    DSP call list.  We return a new "w" which will point to the next item
    after us.  Meanwhile, w[0] is just a pointer to dsp-perform itself
    (no use to us), w[1] and w[2] are the input and output vector locations,
    and w[3] is the number of points to calculate. */
static t_int *lor_perform(t_int *w)
{
    t_lor *x = (t_lor *)(w[1]);  
    t_float *in = (t_float *)(w[2]);
    t_float *out = (t_float *)(w[3]);
    int n = (int)(w[4]);
    float f = 0;
    
    float x0, y0, z0, x1, y1, z1;
   	float h = x->inith; //step-size
   	float a = x->inita;
   	float b = x->initb;
   	float c = x->initc;
    float t_dist;
    float outcome;
    
    while (n--)
    {
    	f = *(in++);
		//*out++  = x->prev = (f + x->prev * x->val) / 2;
		x0 = x->x;
   		y0 = x->y;
   		z0 = x->z;
   		
   		x1 = x0 + h * a * (y0 - x0);
   		y1 = y0 + h * (x0 * (b - z0) - y0);
   		z1 = z0 + h * (x0 * y0 - c * z0);   	
   	
   		t_dist = sqrt((x1 * x1) + (y1 * y1)  + (z1 * z1));
   		   	
   		x->outcome = cos((sqrt((t_dist*t_dist)+(f*f))* 0.0345975)-1);
   	
		
		
		*out++ = x->outcome = cos(((sqrt((f*f)+(x->outcome*x->outcome))) * 0.0345975)-1);
		
		x->dist = t_dist;
		
		x->x = x1;
   		x->y = y1;
   		x->z = z1;
    }
    return (w+5);
}

void lor_ft1(t_lor *x, t_floatarg g)
{
    x->val = g;
}

    /* called to start DSP.  Here we call Pd back to add our perform
    routine to a linear callback list which Pd in turn calls to grind
    out the samples. */
static void lor_dsp(t_lor *x, t_signal **sp)
{
    dsp_add(lor_perform, 4, x, sp[0]->s_vec, sp[1]->s_vec, sp[0]->s_n);
}



/*
********************** VARIABLES *********************
*/

/*
********************** inita *********************
*/
void lor_inita(t_lor *x, t_symbol *selector, int argcount, t_atom *argvec)
{
	int i;
	for (i = 0; i < argcount; i++)
    {
    	if (argvec[i].a_type == A_FLOAT)
    	{
    	x->inita = argvec[i].a_w.w_float;
	    //post("Prandlt = %f", argvec[i].a_w.w_float);
	    }
    }
}
/*
********************** initb *********************
*/
void lor_initb(t_lor *x, t_symbol *selector, int argcount, t_atom *argvec)
{
	int i;
	for (i = 0; i < argcount; i++)
    {
    	if (argvec[i].a_type == A_FLOAT)
    	{
    	x->initb = argvec[i].a_w.w_float;
	    //post("Rayleigh = %f", argvec[i].a_w.w_float);
	    }
    }
}
/*
********************** initc *********************
*/
void lor_initc(t_lor *x, t_symbol *selector, int argcount, t_atom *argvec)
{
	int i;
	for (i = 0; i < argcount; i++)
    {
    	if (argvec[i].a_type == A_FLOAT)
    	{
    	x->initc = argvec[i].a_w.w_float;
	    //post("c = %f", argvec[i].a_w.w_float);
	    }
    }
}
/*
********************** inith *********************
*/
void lor_inith(t_lor *x, t_symbol *selector, int argcount, t_atom *argvec)
{
	int i;
	for (i = 0; i < argcount; i++)
    {
    	if (argvec[i].a_type == A_FLOAT)
    	{
    	x->inith = argvec[i].a_w.w_float;
	    //post("h = %f", argvec[i].a_w.w_float);
	    }
    }
}
/*
********************** initx *********************
*/
void lor_initx(t_lor *x, t_symbol *selector, int argcount, t_atom *argvec)
{
	int i;
	for (i = 0; i < argcount; i++)
    {
    	if (argvec[i].a_type == A_FLOAT)
    	{
    	x->x = argvec[i].a_w.w_float;
	    //post("x = %f", argvec[i].a_w.w_float);
	    }
    }
}
/*
********************** inity *********************
*/
void lor_inity(t_lor *x, t_symbol *selector, int argcount, t_atom *argvec)
{
	int i;
	for (i = 0; i < argcount; i++)
    {
    	if (argvec[i].a_type == A_FLOAT)
    	{
    	x->y = argvec[i].a_w.w_float;
	    //post("y = %f", argvec[i].a_w.w_float);
	    }
    }
}
/*
********************** initz *********************
*/
void lor_initz(t_lor *x, t_symbol *selector, int argcount, t_atom *argvec)
{
	int i;
	for (i = 0; i < argcount; i++)
    {
    	if (argvec[i].a_type == A_FLOAT)
    	{
    	x->z = argvec[i].a_w.w_float;
	    //post("z = %f", argvec[i].a_w.w_float);
	    }
    }
}

static void *lor_new(void)
{
    t_lor *x = (t_lor *)pd_new(lor_class);
    outlet_new(&x->x_obj, gensym("signal"));
    x->x_f = 0.0;
    x->outcome = 0.0;
	x->inith = 0.001;
	x->inita = 10.0;
	x->initb = 28.0;
	x->initc = 8/3;
	x->x = 0.1;
	x->y = 0;
	x->z = 0;
	x->dist = 0.0;
    return (x);
}

    /* this routine, which must have exactly this name (with the "~" replaced
    by "_tilde) is called when the code is first loaded, and tells Pd how
    to build the "class". */
void lor_tilde_setup(void)
{
    lor_class = class_new(gensym("lor~"), (t_newmethod)lor_new, 0,
    	sizeof(t_lor), 0, A_DEFFLOAT, 0);
	    /* this is magic to declare that the leftmost, "main" inlet
	    takes signals; other signal inlets are done differently... */
    CLASS_MAINSIGNALIN(lor_class, t_lor, x_f);
    	/* here we tell Pd about the "dsp" method, which is called back
	when DSP is turned on. */
    class_addmethod(lor_class, (t_method)lor_dsp, gensym("dsp"), 0);
	class_addmethod(lor_class, (t_method)lor_ft1, gensym("ft1"), A_FLOAT, 0);
	//variables
    class_addmethod(lor_class, (t_method)lor_inita, gensym("inita"), A_GIMME, 0);
    class_addmethod(lor_class, (t_method)lor_initb, gensym("initb"), A_GIMME, 0);
    class_addmethod(lor_class, (t_method)lor_initc, gensym("initc"), A_GIMME, 0);
    class_addmethod(lor_class, (t_method)lor_inith, gensym("inith"), A_GIMME, 0);
   // class_addmethod(lor_class, (t_method)lor_reset, gensym("reset"), A_GIMME, 0);
    class_addmethod(lor_class, (t_method)lor_initx, gensym("initx"), A_GIMME, 0);
    class_addmethod(lor_class, (t_method)lor_inity, gensym("inity"), A_GIMME, 0);
    class_addmethod(lor_class, (t_method)lor_initz, gensym("initz"), A_GIMME, 0);
}




