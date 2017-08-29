////////////////////////////////////////////////////////
//
// pix_fft
//
// Calculates the Forward Fourier Transform using FFTW
// and outputs real and imaginary values as images
//
// fdch.github.io/tv
// camarafede@gmail.com
// Fede Camara Halac 2017
//
// GEM - Graphics Environment for Multimedia
//
// zmoelnig@iem.kug.ac.at
//
// Implementation file
//
//    Copyright (c) 1997-1998 Mark Danks.
//    Copyright (c) Günther Geiger.
//    Copyright (c) 2001-2011 IOhannes m zmölnig. forum::für::umläute. IEM. zmoelnig@iem.at
//    For information on usage and redistribution, and for a DISCLAIMER OF ALL
//    WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.
//
/////////////////////////////////////////////////////////
#include "pix_fft.h"
#include "Utils/Functions.h"
#include <cmath>
#define FFTWPLANNERFLAG FFTW_ESTIMATE
#define DEF 64

CPPEXTERN_NEW_WITH_TWO_ARGS(pix_fft, t_floatarg, A_DEFFLOAT, t_floatarg, A_DEFFLOAT);
/////////////////////////////////////////////////////////
//
// pix_fft
//
/////////////////////////////////////////////////////////
// Constructor
//
/////////////////////////////////////////////////////////
pix_fft :: pix_fft(t_floatarg n, t_floatarg t):
 m_enable(false),
 m_type(t>0?1:0),
 m_insize(0),
 m_size(0)
{
  if(0>=n)n=DEF;
  m_insize=n*n;
  m_size=n*(n/2+1);
  reallocAll(n,n);
}
/////////////////////////////////////////////////////////
// Destructor
//
/////////////////////////////////////////////////////////
pix_fft :: ~pix_fft()
{
  if(!m_size)return;
  else {
    delete [] fftwIn;
    fftwf_free(fftwOut);
    fftwf_destroy_plan(fftwPlan);
  }
}
void pix_fft :: reallocAll(int n, int m)
{
  if(m_enable)m_enable=false;

  m_insize = n*m; //actual size of image
  m_size = n*(m/2+1); //FFTW output size

  fftwIn = new float [m_insize];
  fftwOut = (fftwf_complex *)fftwf_alloc_complex(m_size);
  fftwPlan = fftwf_plan_dft_r2c_2d(n, m, fftwIn, fftwOut, FFTWPLANNERFLAG);

  //post("m_insize=%d, m_size=%d", m_insize,m_size);
  m_enable=true;
}

void pix_fft :: processGrayImage(imageStruct &image) {
  unsigned char *pixels = image.data;
  
  int rows = image.ysize;
  int cols = image.xsize;
  
  long i;
  
  if(!m_enable)return;
// Check if sizes match and reallocate.
  if(m_insize!=rows*cols)
    reallocAll(cols, rows);
  else {
    //perform FFT
    for (i=0; i<m_insize; i++)
      fftwIn[i] = (float)pixels[i]/255.;
    
    fftwf_execute(fftwPlan);

    for (i=0; i<m_size; i++)
      if(!m_type)
        pixels[i] = fftwOut[i][0];
      else
        pixels[i] = fftwOut[i][1];
  }
}
/////////////////////////////////////////////////////////
// static member function
//
/////////////////////////////////////////////////////////
void pix_fft :: obj_setupCallback(t_class *classPtr) {}