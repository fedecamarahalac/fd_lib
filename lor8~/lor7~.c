#include "m_pd.h"
#include <math.h>
#ifdef NT
#pragma warning( disable : 4244 )
#pragma warning( disable : 4305 )
#endif

/* ------------------------ lor7~ ----------------------------- */


static t_class *lor7_class;

typedef struct _lor7
{
    t_object x_obj; 	/* obligatory header */
    t_float x_f;
    t_inlet *in2;
    t_inlet *in3;
    t_inlet *in4;
	t_outlet *out1;
    t_outlet *out2;
    t_outlet *out3;
    t_outlet *out4;
	t_float x, y, z;
} t_lor7;



static t_int *lor7_perform(t_int *w)
{
    t_lor7 *x = (t_lor7 *)(w[1]);  
    t_sample *in1 = (t_sample *)(w[2]);
    t_sample *in2 = (t_sample *)(w[3]);
    t_sample *in3 = (t_sample *)(w[4]);
    t_sample *in4 = (t_sample *)(w[5]);
    t_sample *out1 = (t_sample *)(w[6]);
    t_sample *out2 = (t_sample *)(w[7]);
    t_sample *out3 = (t_sample *)(w[8]);
    t_sample *out4 = (t_sample *)(w[9]);
    int n = (int)(w[10]);
    
    float x0, y0, z0, x1, y1, z1;
    float h, a, b, c;
    float distance;

    while (n--)
    {
    	h= *in1++;
		a= *in2++;
		b=*in3++;
		c=*in4++;
		
		x0 = x->x;
   		y0 = x->y;
   		z0 = x->z;
   		
   		x1 = x0 + h * a * (y0 - x0);
   		y1 = y0 + h * (x0 * (b - z0) - y0);
   		z1 = z0 + h * (x0 * y0 - c * z0);   	
   	
		
		distance = sqrt((x1 * x1) + (y1 * y1)  + (z1 * z1));
	 	
	 	
	    *out1++ = x->x = x1;
		*out2++ = x->y = y1;
	    *out3++ = x->z = z1;
	    *out4++ = distance;

    }
    return (w+11);
}


void lor7_tilde_free(t_lor7 *x)
{
inlet_free(x->in2);
inlet_free(x->in3);
inlet_free(x->in4);
 outlet_free(x->out1);
 outlet_free(x->out2);
 outlet_free(x->out3);
 outlet_free(x->out4);
}


static void lor7_dsp(t_lor7 *x, t_signal **sp)
{
    dsp_add(lor7_perform, 10,  x, 
    sp[0]->s_vec, 
    sp[1]->s_vec,
    sp[2]->s_vec,
    sp[3]->s_vec,
    sp[4]->s_vec,
    sp[5]->s_vec,
    sp[6]->s_vec,
    sp[7]->s_vec,
    sp[0]->s_n);
}


void lor7_initx(t_lor7 *x,  int argcount, t_atom *argvec)
{
	int i;
	for (i = 0; i < argcount; i++)
    {
    	if (argvec[i].a_type == A_FLOAT)
    	{
    	x->x = argvec[i].a_w.w_float;
	    }
    }
}
void lor7_inity(t_lor7 *x,  int argcount, t_atom *argvec)
{
	int i;
	for (i = 0; i < argcount; i++)
    {
    	if (argvec[i].a_type == A_FLOAT)
    	{
    	x->y = argvec[i].a_w.w_float;
	    }
    }
}
void lor7_initz(t_lor7 *x,  int argcount, t_atom *argvec)
{
	int i;
	for (i = 0; i < argcount; i++)
    {
    	if (argvec[i].a_type == A_FLOAT)
    	{
    	x->z = argvec[i].a_w.w_float;
	    }
    }
}

static void *lor7_new(void)
{
    t_lor7 *x = (t_lor7 *)pd_new(lor7_class);
    x->in2 = inlet_new(&x->x_obj,&x->x_obj.ob_pd, &s_signal,&s_signal);
    x->in3 = inlet_new(&x->x_obj,&x->x_obj.ob_pd, &s_signal,&s_signal);
    x->in4 = inlet_new(&x->x_obj,&x->x_obj.ob_pd, &s_signal,&s_signal);
    x->out1 = outlet_new(&x->x_obj, &s_signal);
    x->out2 = outlet_new(&x->x_obj, &s_signal);
    x->out3 = outlet_new(&x->x_obj, &s_signal);
    x->out4 = outlet_new(&x->x_obj, &s_signal);
    x->x_f = 0.0;
	x->x = 0.1;
	x->y = 0;
	x->z = 0;
	/*
	x->x1max = 10000000000.0;
	x->x1min = 0.0;
	*/
    return (x);
}

void lor7_tilde_setup(void)
{
    lor7_class = class_new(gensym("lor7~"),
    (t_newmethod)lor7_new, 0,
    	sizeof(t_lor7), 0, A_DEFFLOAT, 0);

    CLASS_MAINSIGNALIN(lor7_class, t_lor7, x_f);

    class_addmethod(lor7_class, (t_method)lor7_dsp, gensym("dsp"), 0);
    class_addmethod(lor7_class, (t_method)lor7_initx, gensym("initx"), A_GIMME, 0);
    class_addmethod(lor7_class, (t_method)lor7_inity, gensym("inity"), A_GIMME, 0);
    class_addmethod(lor7_class, (t_method)lor7_initz, gensym("initz"), A_GIMME, 0);
}