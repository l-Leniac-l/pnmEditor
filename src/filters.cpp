/*
* INF 110 - Trabalho prático 03
* Author: Lenilson Nascimento, Raphael Carmo
*/

#include <iostream>
#include <algorithm>
#include <cmath>

#include <pnme/defs.h>

namespace pnm
{

int SobelY[3][3] = {
	{  1,  2,  1 },
	{  0,  0,  0 },
	{ -1, -2, -1 }
};

int SobelX[3][3] = {
	{ 1, 0, -1 },
	{ 2, 0, -2 },
	{ 1, 0, -1 }
};

int Focus[3][3] =
{
	{  0, -1,  0 },
	{ -1,  5, -1 },
	{  0, -1,  0 }
};

int Gaussian[3][3] =
{
	{ 1, 2, 1, },
	{ 2, 4, 2, },
	{ 1, 2, 1, }
};

int Laplace[3][3] =
{
	{  0, -1,  0 },
	{ -1,  4, -1 },
	{  0, -1,  0 }
};

int Box[3][3] =
{
	{ 1, 1, 1 },
	{ 1, 1, 1 },
	{ 1, 1, 1 }
};

void lighten(
	unsigned char **pixels,
	int width,
	int height,
	int mod
)
{
	for(int x = 0; x < width; x ++)
	{
		for(int y = 0; y < height; y ++)
		{
			pixels[x][y] = CLAMP(pixels[x][y] + mod, 0, 255);
		}
	}
}

void mirror(
	unsigned char **pixels,
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
	unsigned char **pixels,
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
	unsigned char **in,
	unsigned char **out,
	int width,
	int height
)
{
	unsigned char **temp = new unsigned char[height][width];

	filter(in, temp, width, height, filters::SobelY);
	filter(tempb, out, width, height, filters::SobelX);

	for(int x = 0; x < width; x ++)
	{
		for(int y = 0; y < height; y ++)
		{
			out[y][x] = (unsigned char) CLAMP(sqrt(
			    pow(out[y][x], 2) +
			    pow(temp[y][x], 2)
			  ), 0, 255);
		}
	}

	delete[][] temp;
}

void flip90(
	unsigned char **in,
	unsigned char **out,
	int width,
	int height,
	bool horary)
{
	for(int y = 0; y < height; y ++)
	{
		for(int x = 0; x < width; x ++)
		{
			out[x][y] = in[y][x];
		}
	}
}

int filterLine(
	unsigned char *line,
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
	unsigned char **in,
	unsigned char **out,
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
			int j = filters::filterLine(in[y], x, width, f[1]);

			if(y >= 1)
			{
				j += filters::filterLine(in[y - 1], x, width, f[0]);
			}

			if(y < height - 1)
			{
				j += filters::filterLine(in[y + 1], x, width, f[2]);
			}

			out[y][x] = (unsigned char) CLAMP(j * norm, 0, 255);
		}
	}
}

}
