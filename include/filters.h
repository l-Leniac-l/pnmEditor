/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 */

#ifndef _FILTERS_H
#define _FILTERS_H

namespace filters{
  #define CLAMP(A,B,C) (A <= B ? B : A >= C ? C : A);

  extern int Focus[3][3];

	extern int Box[3][3];
	extern int Gaussian[3][3];

	extern int Laplace[3][3];

	extern int SobelY[3][3];
	extern int SobelX[3][3];

  void lighten(
  	unsigned char **pixels,
  	int width, int height, int mod
  );

  void mirror(
  	unsigned char **pixels,
  	int width, int height
  );

  void negative(
  	unsigned char **pixels,
  	int width, int height
  );

  void sobel(
  	unsigned char **in,
  	unsigned char **out,
  	int width, int height
  );

  void filter(
  	unsigned char **in, unsigned char **out,
  	int width, int height, int f[3][3], float normalization = 1.0f
  );
}

#endif
