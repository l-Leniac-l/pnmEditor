/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 */

#include <iostream>
#include <string>
#include <pnme/defs.h>
#include <cstdlib>
#include <cstring>

void usage(char *basename)
{
	std::cout << "Uso:" << std::endl;
	std::cout << "	" << basename << " <imagem>";
	std::cout << " [-lighten <-255..255>] [-darken <-255..255>]";
	std::cout << " [-pixelate <1..>] [-mirror] [-negativate]";
	std::cout << " [-sobel] [-gaussian] [-box] [-laplace]";
	std::cout << " [-greyscale] [-p2 <saída>] [-p3 <saída>]";
	std::cout << std::endl;
}

int main(int argc, char** argv)
{
	bool color = true;
	int width, height;
	unsigned char *r, *g, *b;

	if(argc <= 2)
	{
		usage(argv[0]);
		return -1;
	}

	std::tie(r, g, b) = loadfile(std::string(argv[1]), width, height, color);
	if(r == nullptr)
	{
		std::cout << "falha ao abrir imagem - arquivo não existe." << std::endl;
	}

	for(int n = 2; n < argc; n ++)
	{
		std::string ar(argv[n]);
		std::cout << argv[n] << std::endl;
		if(n + 1 < argc)
		{
			if(ar == "-lighten")
			{
				n ++;
				lighten(r, width, height, CLAMP(atoi(argv[n]), 0, 255));
				lighten(g, width, height, CLAMP(atoi(argv[n]), 0, 255));
				lighten(b, width, height, CLAMP(atoi(argv[n]), 0, 255));
			} else if(ar == "-darken")
			{
				n ++;
				lighten(r, width, height, -1 * CLAMP(atoi(argv[n]), 0, 255));
				lighten(g, width, height, -1 * CLAMP(atoi(argv[n]), 0, 255));
				lighten(b, width, height, -1 * CLAMP(atoi(argv[n]), 0, 255));
			} else if(ar == "-pixelate")
			{
				n ++;
				pixelate(r, width, height, atoi(argv[n]));
				pixelate(g, width, height, atoi(argv[n]));
				pixelate(b, width, height, atoi(argv[n]));
			} else if(ar == "-p3")
			{
				n ++;
				exportP3(r, g, b, width, height, std::string(argv[n]));
			}
		}

		if(ar == "-sobel")
		{
			sobel(r, width, height);
			sobel(g, width, height);
			sobel(b, width, height);
		}
	}

	return 0;
}
