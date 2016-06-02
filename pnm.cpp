/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 */

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

#include "def.h"

void exportP2(unsigned char c[MAXH][MAXW], int width, int height, const std::string &filename)
{
	std::ofstream fo;
	fo.open(filename, std::ios::out);

	fo << "P2" << std::endl << "# ~~" << std::endl;
	fo << width << ' ' << height << " 255" << std::endl;

	for(int y = 0; y < height; y ++)
	{
		for(int x = 0; x < width; x ++)
		{
			fo << (int) c[y][x] << std::endl;
		}
	}

	fo.close();
}

void exportP3(
	unsigned char red[MAXH][MAXW],
	unsigned char green[MAXH][MAXW],
	unsigned char blue[MAXH][MAXW],
	int width, int height, const std::string &filename
)
{
	std::ofstream fo;
	fo.open(filename, std::ios::out);

	fo << "P3" << std::endl << "# ~~" << std::endl;
	fo << width << ' ' << height << " 255" << std::endl;

	for(int y = 0; y < height; y ++)
	{
		for(int x = 0; x < width; x ++)
		{
			fo << (int) red[y][x] << std::endl;
			fo << (int) green[y][x] << std::endl;
			fo << (int) blue[y][x] << std::endl;
		}
	}

	fo.close();
}

bool loadPNM(
	const std::string &filename,

	int &width,
	int &height,

	bool &colored,

	unsigned char red[MAXH][MAXW],
	unsigned char green[MAXH][MAXW],
	unsigned char blue[MAXH][MAXW]
)
{
	std::ifstream fin;
	std::string itype;

	int mc;

	/* TODO: file validation */
	fin.open(filename, std::ios::in);

	fin >> itype;
	fin.get();

	/* Descarta os comentários */
	char c, comm[200];

	while((c = fin.get()) == '#')
	{
		fin.getline(comm, 200);
	}

	fin.putback(c);
	fin >> width >> height >> mc;

	int r, g, b;
	if(colored = (itype == "P3"))
	{
		for(int y = 0; y < height; y ++)
		{
			for(int x = 0; x < width; x ++)
			{
				fin >> r >> g >> b;

				red[y][x] = r;
				green[y][x] = g;
				blue[y][x] = b;
			}
		}
	}

	else
	{
		for(int y = 0; y < height; y ++)
		{
			for(int x = 0; x < width; x ++)
			{
				fin >> r;
				red[y][x] = r;
			}
		}
	}

	fin.close();

	return true;
}
