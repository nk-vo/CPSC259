/*
File:         discrete_fourier_transform.c
Purpose:      Calculates a fast discrete Fourier,
transformation based entirely on code available at:
http://paulbourke.net/miscellaneous/dft/
Author:			  Your names
Student #s:		12345678 and 12345678
CS Accounts:	a1a1 and b2b2
Date:				  Add the date here
*/

/******************************************************************
READ THIS FILE, ESPECIALLY THE COMMENTS FOR THE fft FUNCTION.  THE
COMMENTS CONTAIN HINTS ABOUT HOW TO INVOKE THE fft FUNCTION FROM
YOUR MAIN FUNCTION.

DO NOT EDIT THIS FILE
******************************************************************/

/*
Preprocessor directives
Use this special directive before including math.h because the
math.h header defines some useful constants like M_PI which are not
part of the C standard. */
#define _USE_MATH_DEFINES

#include <math.h>
#include "discrete_fourier_transform.h"

/*
Computes an in-place complex-to-complex FFT.
Since our data points are all real, we will use the forward
Fourier transform, and NOT the inverse.
PARAM:  dir
IF dir ==  1 THEN calculates forward transform
ELSE calculates reverse transform (so use 1!)
PARAM:  m where 2^m = the number of data points stored in x
PARAM:  x a reference to a real array containing 2^m data points
(note that this algorithm may require that x has
4 extra, empty "non-datum" cells at the end of the array --
see the definition of the FFT_ALGOR_BUFFER constant in the
tide_analyzer.c file for an explanation)
PARAM:  y a reference to a complex array of length 2^m.  If a
set of data points is real, pass an array of length 2^m
whose elements are all 0.0.
PRE:    x must be an array of length 2^m (possibly 2^m+ 4), containing
2^m data points, (and possibly terminating with 4 'empty, extra'
cells)
PRE:    y must be an array of length 2^m.  If the data points being
transformed are all real, then y must be an array of 0.0
of length 2^m.
POST:   x[i] for 0<i<((2^m)-1) contains the real component of
the fft of x[i] (inverse fft if dir != 1)
POST:   y[i] for 0<i<((2^m)-1) contains the complex component of
the fft of x[i] (inverse fft if dir != 1)
RETURN: N/A (void)
*/
void fft(short int dir, long m, double x[], double y[])
{
  long n, i, i1, j, k, i2, l, l1, l2;
  double c1, c2, tx, ty, t1, t2, u1, u2, z;

  /* Calculates the number of points */
  n = 1;
  for (i = 0; i < m; i++)
    n *= 2;

  /* Does the bit reversal */
  i2 = n >> 1;
  j = 0;
  for (i = 0; i < n - 1; i++) {
    if (i < j) {
      tx = x[i];
      ty = y[i];
      x[i] = x[j];
      y[i] = y[j];
      x[j] = tx;
      y[j] = ty;
    }
    k = i2;
    while (k <= j) {
      j -= k;
      k >>= 1;
    }
    j += k;
  }

  /* Computes the FFT */
  c1 = -1.0;
  c2 = 0.0;
  l2 = 1;
  for (l = 0; l < m; l++) {
    l1 = l2;
    l2 <<= 1;
    u1 = 1.0;
    u2 = 0.0;
    for (j = 0; j < l1; j++) {
      for (i = j; i < n; i += l2) {
        i1 = i + l1;
        t1 = u1 * x[i1] - u2 * y[i1];
        t2 = u1 * y[i1] + u2 * x[i1];
        x[i1] = x[i] - t1;
        y[i1] = y[i] - t2;
        x[i] += t1;
        y[i] += t2;
      }
      z = u1 * c1 - u2 * c2;
      u2 = u1 * c2 + u2 * c1;
      u1 = z;
    }
    c2 = sqrt((1.0 - c1) / 2.0);
    if (dir == 1)
      c2 = -c2;
    c1 = sqrt((1.0 + c1) / 2.0);
  }

  /* Scales for forward transform */
  if (dir == 1) {
    for (i = 0; i < n; i++) {
      x[i] /= n;
      y[i] /= n;
    }
  }

  return;
}