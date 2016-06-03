/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 */

#include <iostream>
#include <fstream>
#include <string>

#include "../include/pnmeditor.h"

namespace pnmEditor
{
  bool loadPNM(
  	std::string &filename,

  	int &width,
  	int &height,

  	bool &colored,

  	unsigned char ** &red,
  	unsigned char ** &green,
  	unsigned char ** &blue
  )
  {
  	std::ifstream fin;
  	std::string itype;

  	int mc;

  	fin.open(filename, std::ios::in);

  	if(fin.is_open())
  	{
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

      red = new unsigned char*[width];
      for(int i = 0; i < width; i++)
  		  red[i] = new unsigned char[height];

      green = new unsigned char*[width];
      for(int i = 0; i < width; i++)
  		  green[i] = new unsigned char[height];

      blue = new unsigned char*[width];
      for(int i = 0; i < width; i++)
  		  blue[i] = new unsigned char[height];

  		int r, g, b;
  		if(itype == "P3")
  		{
        colored = true;
  			for(int x = 0; x < width; x ++)
  			{
  				for(int y = 0; y < height; y ++)
  				{
  					fin >> r >> g >> b;

  					red[x][y] = r;
  					green[x][y] = g;
  					blue[x][y] = b;
  				}
  			}
  		}

  		else
  		{
  			for(int x = 0; x < width; x ++)
  			{
  				for(int y = 0; y < height; y ++)
  				{
  					fin >> r;
  					red[x][y]= r;
  				}
  			}
  		}

  		fin.close();

  		return true;
  	}
  	else
  		return false;
  }

  void exportP2(
    std::string &fname,

    int width,
    int height,

    unsigned char **pixels
  )
  {
  	std::ofstream fo;
  	fo.open(fname, std::ios::out);

  	fo << "P2" << std::endl << "# ~~" << std::endl;
  	fo << width << ' ' << height << " 255" << std::endl;

  	for(int x = 0; x < width; x ++)
  	{
  		for(int y = 0; y < height; y ++)
  		{
  			fo << (int) pixels[x][y] << std::endl;
  		}
  	}

  	fo.close();
  }

  void exportP3(
    std::string &fname,

    int width,
    int height,

    unsigned char **red,
    unsigned char **green,
    unsigned char **blue
  )
  {
  	std::ofstream fo;
  	fo.open(fname, std::ios::out);

  	fo << "P3" << std::endl << "# ~~" << std::endl;
  	fo << width << ' ' << height << " 255" << std::endl;

  	for(int x = 0; x < width; x ++)
  	{
  		for(int y = 0; y < height; y ++)
  		{
  			fo << (int) red[x][y] << std::endl;
  			fo << (int) green[x][y] << std::endl;
  			fo << (int) blue[x][y] << std::endl;
  		}
  	}

  	fo.close();
  }

  void freeMemory(unsigned char **pixels, int width, int height)
  {
    for(int i = 0 ; i < width ; ++i)
     delete[] pixels[i];
   delete[] pixels;
  }
}
