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
	unsigned char *pixels,
	int width,
	int height,
	const std::string &filename
)
{
	std::ofstream fo;
	fo.open(filename, std::ios::out);

	fo << "P2" << std::endl << "# ~~" << std::endl;
	fo << width << ' ' << height << " 255" << std::endl;

	for(int y = 0; y < height * width; y ++)
	{
		fo << (int) pixels[y] << std::endl;
	}

	fo.close();
}

void exportP3(
	unsigned char *red,
	unsigned char *green,
	unsigned char *blue,
	int width,
	int height,
	const std::string &filename
)
{
	std::ofstream fo;
	fo.open(filename, std::ios::out);

	fo << "P3" << std::endl;
	fo << width << ' ' << height << " 255" << std::endl;

	for(int y = 0; y < height; y ++)
	{
		fo << (int) red[y] << std::endl;
		fo << (int) green[y] << std::endl;
		fo << (int) blue[y] << std::endl;
	}

	fo.close();
}

std::tuple<unsigned char*, unsigned char*, unsigned char*> loadfile(
	const std::string &filename,
	int &width,
	int &height,
	bool &colored
)
{
	std::ifstream fin;
	std::string itype;

	int mc;

	fin.open(filename, std::ios::in);

	if(fin.is_open() == false)
	{
		return std::make_tuple(nullptr, nullptr, nullptr);
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

	unsigned char *r = new unsigned char[width * height];
	unsigned char *g = new unsigned char[width * height];
	unsigned char *b = new unsigned char[width * height];

	if(colored = (itype == "P3"))
	{
		for(int y = 0; y < height; y ++)
		{
			for(int x = 0; x < width; x ++)
			{
				fin >> r[y * width + x] >> g[y * width + x] >> b[y * width + x];
			}
		}
	}
	else
	{
		for(int y = 0; y < height; y ++)
		{
			for(int x = 0; x < width; x ++)
			{
				fin >> r[y * width + x];
			}
		}
	}

	fin.close();

	return std::make_tuple(r, g, b);
}
