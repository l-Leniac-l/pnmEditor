/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 * Date: Mon, May 31 2016
 */

#include <algorithm>
#include <cmath>
#include "../def.h"

int focus[3][3] =
{
	{0,-1,0},
	{-1,5,-1},
	{0,-1,0}
};

int gaussianBlur[3][3] =
{
	{1,2,1},
	{2,4,2},
	{1,2,1}
};

int sobelx[3][3] =
{
	{1,0,-1},
	{2,0,-2},
	{1,0,-1}
};

int sobely[3][3] =
{
	{1,2,1},
	{0,0,0},
	{-1,-2,-1}
};

int laplace[3][3] =
{
	{0,-1,0},
	{-1,4,-1},
	{0,-1,0}
};

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

void sobelFilter(
	unsigned char m[MAXH][MAXW], unsigned char n[MAXH][MAXW],
	int width, int height, int f[3][3], int g[3][3]
)
{
	int aux1, aux2, media=1;
	for(int x = 0; x < width; x ++)
	{
		for(int y = 0; y < height; y ++)
		{
			aux1 = aux2 = 0;
			aux1 = g[1][1] * m[y - 1][x - 1]
				+ g[1][2] * m[y - 1][x]
				+ g[1][3] * m[y - 1][x + 1]
				+ g[2][1] * m[y][x - 1]
				+ g[2][2] * m[y][x]
				+ g[2][3] * m[y][x + 1]
				+ g[3][1] * m[y + 1][x - 1]
				+ g[3][2] * m[y + 1][x]
				+ g[3][3] * m[y + 1][x + 1];
			aux2 = f[1][1] * m[y - 1][x - 1]
				+ f[1][2] * m[y - 1][x]
				+ f[1][3] * m[y - 1][x + 1]
				+ f[2][1] * m[y][x - 1]
				+ f[2][2] * m[y][x]
				+ f[2][3] * m[y][x + 1]
				+ f[3][1] * m[y + 1][x - 1]
				+ f[3][2] * m[y + 1][x]
				+ f[3][3] * m[y + 1][x + 1];
			media = sqrt(aux1*aux2);
			n[y][x] = CLAMP(media,0,255);
		}
	}
}

void filter(
	unsigned char m[MAXH][MAXW], unsigned char n[MAXH][MAXW],
	int width, int height, int f[3][3]
)
{
	for(int x = 0; x < width; x ++)
	{
		for(int y = 0; y < height; y ++)
		{
			n[y][x] = CLAMP(f[1][1] * m[y - 1][x - 1]
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
