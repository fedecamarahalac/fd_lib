// combi
//
// Find all possible combinations 
// from incoming list taking "r" elements from array of size "n"
//
//
// Adapted from:
// https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
//
// by github.com/fdch


#include "stdlib.h"
#include "stdio.h"
#include "m_pd.h"

typedef struct _combi {
  t_object  x_obj;
  t_outlet *out;
  t_float *arr;
  int x_max, r;
} t_combi;

void combi_set(t_combi *x, t_symbol *selector, t_float f) {
  x->r = f;
}

void combinationUtil(t_combi *x, t_float data[], int start, int end, int index);

// Needed for qsort.  See http://w...content-available-to-author-only...s.com/reference/cstdlib/qsort/
int compare (const void * a, const void * b) { 
    return ( *(int*)a - *(int*)b );  
}

void combinationUtil(t_combi *x, t_float data[], int start, int end, int index) {
  if (index == x->r)
  {
    for (int i=0; i<x->r; i++)
      outlet_float(x->x_obj.ob_outlet, data[i]);
    return;
  }

  for (int i=start; i<=end && end-i+1 >= x->r-index; i++)
  {
    data[index] = x->arr[i];
    combinationUtil(x, data, i+1, end, index+1);
    while (x->arr[i] == x->arr[i+1]) i++;
  }
}

static void combi_alloc(t_combi *x, int n) {
  x->arr = (t_float *)t_getbytes(n*sizeof(t_float));
  x->x_max = n;
}

static void combi_list(t_combi *x, t_symbol *s, int argc, t_atom *argv) {
  int i, n;
  t_float data[x->r];

  if (!argc) return;
  if (argc != x->x_max) combi_alloc(x,argc);
  
  n=x->x_max;
  
  for(i=0; i<n; i++) x->arr[i] = argv[i].a_w.w_float;

  // Sort array to handle duplicates
  qsort (x->arr, n, sizeof(int), compare);

  // Print all combination using temprary array 'data[]'
  combinationUtil(x, data, 0, n-1, 0);

}

static t_class *combi_class;

void *combi_new(t_floatarg f) {
  t_combi *x = (t_combi *)pd_new(combi_class);
  x->r = f;
  outlet_new(&x->x_obj, &s_float);
  return (void *)x;
}

static void combi_free(t_combi *x) {
   t_freebytes(x->arr, (x->x_max)*sizeof(t_float));
}

void combi_setup(void) {
  combi_class = class_new(gensym("combi"),
    (t_newmethod)combi_new,
    (t_method)combi_free,
    sizeof(t_combi),
    CLASS_DEFAULT,A_DEFFLOAT,0);
  class_addlist(combi_class, combi_list);
  class_addmethod(combi_class,
    (t_method)combi_set,
    gensym("set"),
    A_GIMME, 0);

}