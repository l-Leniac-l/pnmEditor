/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 */

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

#include <pnme/defs.h>

void exportP2(
	const std::string &filename,
	int width,
	int height,
	unsigned char *pixels
)
{
	std::ofstream fo;
	fo.open(filename, std::ios::out);

	fo << "P2" << std::endl << "# ~~" << std::endl;
	fo << width << ' ' << height << " 255" << std::endl;

	for(int y = 0; y < height; y ++)
	{
		for(int x = 0; x < width; x ++)
		{
			fo << (int) pixels[y * width + x] << std::endl;
		}
	}

	fo.close();
}

void exportP3(
	const std::string &filename,
	int width,
	int height,
	unsigned char *red,
	unsigned char *green,
	unsigned char *blue
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
			fo << (int) red[y * width + x] << std::endl;
			fo << (int) green[y * width + x] << std::endl;
			fo << (int) blue[y * width + x] << std::endl;
		}
	}

	fo.close();
}

bool loadfile(
	const std::string &filename,
	int &width,
	int &height,
	bool &colored,
	unsigned char *red,
	unsigned char *green,
	unsigned char *blue
)
{
	std::ifstream fin;
	std::string itype;

	int mc;

	fin.open(filename, std::ios::in);

	if(fin.is_open() == false)
	{
		return false;
	}

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

	red = new unsigned char[width * height];
	green =  new unsigned char[width * height];
	blue =  new unsigned char[width * height];

	int r, g, b;
	if(colored = (itype == "P3"))
	{
		for(int y = 0; y < height; y ++)
		{
			for(int x = 0; x < width; x ++)
			{
				fin >> r >> g >> b;

				red[y * width + x] = r;
				green[y * width + x] = g;
				blue[y * width + x] = b;
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
				red[y * width + x] = r;
			}
		}
	}

	fin.close();
	return true;
}
