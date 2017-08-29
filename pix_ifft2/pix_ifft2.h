#ifndef _INCLUDE__GEM_PIXES_pix_ifft2_H_
#define _INCLUDE__GEM_PIXES_pix_ifft2_H_

#include "Base/GemPixObj.h"
#include "fftw3.h"


class GEM_EXTERN pix_ifft2 : public GemPixObj
{
  CPPEXTERN_HEADER(pix_ifft2, GemPixObj);

  public:

  //////////
  // Constructor
  pix_ifft2(t_floatarg n);

  protected:

  //////////
  // Destructor
  virtual ~pix_ifft2(void);

  virtual void  processGrayImage(imageStruct &image);

  float  *fftwOut;
  unsigned char  *q1,*q2,*q3,*q4;
  
  fftwf_complex  *fftwIn;
  fftwf_plan  fftwPlan;
  int m_size, m_xsize, m_ysize, m_insize;
  bool m_enable;
  
  void  BANGMess(void);
  void  reallocAll(int n, int m);
  void  deallocAll(void);
  void  copyRect(unsigned char*s,unsigned char*t, bool dir, bool Yoff, bool Xoff);
  void  shiftFFT(unsigned char*data);

};
#endif
