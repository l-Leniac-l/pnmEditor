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
		{ -1, -2, -1 },
		{  0,  0,  0 },
		{  1,  2,  1 }
	};

	int sobelX[3][3] =
	{
		{ -1, 0, 1 },
		{ -2, 0, 2 },
		{ -1, 0, 1 }
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

int convolve(
	unsigned char in[][MAXW],
	int x,
	int y,
	int width,
	int height,
	int f[3][3]
)
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

	return j;
}

void sobel(
	unsigned char in[][MAXW],
	unsigned char out[][MAXW],
	int width,
	int height
)
{
	for(int y = 0; y < height; y ++)
	{
		for(int x = 0; x < width; x ++)
		{
			int convX = 1.f / 8 * convolve(in, x, y, width, height, filters::sobelX);
			int convY = 1.f / 8 * convolve(in, x, y, width, height, filters::sobelY);

//			out[y][x] = CLAMP(std::abs(convX) + std::abs(convY), 0, 255);
//			out[y][x] = (int) CLAMP((convX + convY) / 2.f, 0, 255);
			out[y][x] = (int) CLAMP(sqrt(convX * convX + convY * convY), 0, 255);
		}
	}
}

void pixelate(
	unsigned char in[][MAXW],
	unsigned char out[][MAXW],
	int width,
	int height,
	int radius
)
{
	radius = std::max(1, radius);

	for(int y = 0; y < height - 1; )
	{
		for(int x = 0; x < width - 1; )
		{
			for(int z = y; z < std::min(height, y + radius); z ++)
			{
				for(int w = x; w < std::min(width, x + radius); w ++)
				{
					out[z][w] = CLAMP(
							convolve(
								in, x + 1, y + 1, width, height, filters::box
							) / 8.f,
						0, 255);
				}
			}

			x += radius;
		}

		y += radius;
	}
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
			int conv = convolve(in, x, y, width, height, f);
			out[y][x] = (unsigned char) CLAMP(conv * norm, 0, 255);
		}
	}
}
