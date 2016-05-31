/*
 * INF 110 - Trabalho prático 03
 * Date: Mon, May 31 2016
 */

#include <algorithm>
#include "def.h"

void lighten(unsigned char pixels[MAXH][MAXW], int width, int height, int mod)
{
	for(int x = 0; x < width; x ++)
	{
		for(int y = 0; y < height; y ++)
		{
			pixels[y][x] = CLAMP(pixels[y][x] + mod, 0, 255);
		}
	}
}

void mirror(unsigned char pixels[MAXH][MAXW], int width, int height)
{
	for(int y = 0; y < height; y ++)
	{
		for(int x = 0; x < width / 2; x ++)
		{
			std::swap(pixels[y][x], pixels[y][width - x - 1]);
		}
	}
}

void negative(unsigned char pixels[MAXH][MAXW], int width, int height)
{
	for(int x = 0; x < width; x ++)
	{
		for(int y = 0; y < height; y ++)
		{
			pixels[y][x] = (255 - pixels[y][x]);
		}
	}
}

void filter(
	unsigned char m[MAXH][MAXW],
	int width, int height, int f[3][3]
)
{
	for(int x = 0; x < width; x ++)
	{
		for(int y = 0; y < height; y ++)
		{
			m[y][x] = CLAMP(f[1][1] * m[y - 1][x - 1] 
				+ f[1][2] * m[y - 1][x] 
				+ f[1][3] * m[y - 1][x + 1] 
				+ f[2][1] * m[y][x - 1]
				+ f[2][2] * m[y][x] 
				+ f[2][3] * m[y][x + 1] 
				+ f[3][1] * m[y + 1][x - 1] 
				+ f[3][2] * m[y + 1][x] 
				+ f[3][3] * m[y + 1][x + 1], 0, 255);
		}
	}
}
