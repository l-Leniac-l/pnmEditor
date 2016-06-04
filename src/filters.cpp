/*
* INF 110 - Trabalho prático 03
* Author: Lenilson Nascimento, Raphael Carmo
*/

#include <iostream>
#include <algorithm>
#include <cmath>

#include <pnme/defs.h>

namespace filters
{
	int sobelY[3][3] =
	{
		{  1,  2,  1 },
		{  0,  0,  0 },
		{ -1, -2, -1 }
	};

	int sobelX[3][3] =
	{
		{ 1, 0, -1 },
		{ 2, 0, -2 },
		{ 1, 0, -1 }
	};

	int focus[3][3] =
	{
		{  0, -1,  0 },
		{ -1,  5, -1 },
		{  0, -1,  0 }
	};

	int gaussian[3][3] =
	{
		{ 1, 2, 1, },
		{ 2, 4, 2, },
		{ 1, 2, 1, }
	};

	int laplace[3][3] =
	{
		{  0, -1,  0 },
		{ -1,  4, -1 },
		{  0, -1,  0 }
	};

	int box[3][3] =
	{
		{ 1, 1, 1 },
		{ 1, 1, 1 },
		{ 1, 1, 1 }
	};
}

void lighten(
	unsigned char pixels[][MAXW],
	int width,
	int height,
	int mod
)
{
	for(int y = 0; y < height; y ++)
	{
		for(int x = 0; x < width; x ++)
		{
			pixels[y][x] = CLAMP(pixels[y][x] + mod, 0, 255);
		}
	}
}

void mirror(
	unsigned char pixels[][MAXW],
	int width,
	int height
)
{
	for(int y = 0; y < height; y ++)
	{
		for(int x = 0; x < width / 2; x ++)
		{
			std::swap(pixels[y][x], pixels[y][width - x - 1]);
		}
	}
}

void negative(
	unsigned char pixels[][MAXW],
	int width,
	int height
)
{
	for(int x = 0; x < width; x ++)
	{
		for(int y = 0; y < height; y ++)
		{
			pixels[y][x] = (255 - pixels[y][x]);
		}
	}
}

void sobel(
	unsigned char in[][MAXW],
	unsigned char out[][MAXW],
	int width,
	int height
)
{
	unsigned char temp[MAXH][MAXW];

	filter(in, temp, width, height, filters::sobelY);
	filter(temp, out, width, height, filters::sobelX);

	for(int y = 0; y < height; y ++)
	{
		for(int x = 0; x < width; x ++)
		{
			out[y][x] = (unsigned char) CLAMP(sqrt(
			    pow(out[y][x], 2) +
			    pow(temp[y][x], 2)
			  ), 0, 255);
		}
	}
}

int filterLine(
	unsigned char line[],
	int x,
	int width,
	int f[3]
)
{
	int j = line[x] * f[1];

	if(x >= 1)
	{
		j += line[x - 1] * f[0];
	}

	if(x < width - 1)
	{
		j += line[x + 1] * f[2];
	}

	return j;
}

void filter(
	unsigned char in[][MAXW],
	unsigned char out[][MAXW],
	int width,
	int height,
	int f[3][3],
	float norm
)
{
	for(int y = 0; y < height; y ++)
	{
		for(int x = 0; x < width; x ++)
		{
			int j = filterLine(in[y], x, width, f[1]);

			if(y >= 1)
			{
				j += filterLine(in[y - 1], x, width, f[0]);
			}

			if(y < height - 1)
			{
				j += filterLine(in[y + 1], x, width, f[2]);
			}

			out[y][x] = (unsigned char) CLAMP(j * norm, 0, 255);
		}
	}
}
