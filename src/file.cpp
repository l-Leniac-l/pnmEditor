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
	unsigned char pixels[][MAXW]
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
			fo << (int) pixels[y][x] << std::endl;
		}
	}

	fo.close();
}

void exportP3(
	const std::string &filename,
	int width,
	int height,
	unsigned char red[][MAXW],
	unsigned char green[][MAXW],
	unsigned char blue[][MAXW]
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

bool loadfile(
	const std::string &filename,
	int &width,
	int &height,
	bool &colored,
	unsigned char red[][MAXW],
	unsigned char green[][MAXW],
	unsigned char blue[][MAXW]
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
