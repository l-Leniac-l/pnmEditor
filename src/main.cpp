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
	std::cout << " [-pixelate <0...>] [-mirror] [-negativate]";
	std::cout << " [-sobel] [-gaussian] [-box] [-laplace]";
	std::cout << " [-focus]";
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

		delete[] r;
		delete[] g;
		delete[] b;

		return -1;
	}

	for(int n = 2; n < argc; n ++)
	{
		bool valid = true;

		std::string ar(argv[n]);
		if(n + 1 < argc)
		{
			if(ar == "-lighten")
			{
				std::cout << "Clareando imagem..." << std::endl;

				n ++;
				lighten(r, width, height, CLAMP(atoi(argv[n]), 0, 255));
				lighten(g, width, height, CLAMP(atoi(argv[n]), 0, 255));
				lighten(b, width, height, CLAMP(atoi(argv[n]), 0, 255));
			}
			else if(ar == "-darken")
			{
				std::cout << "Escurecendo imagem..." << std::endl;

				n ++;
				lighten(r, width, height, -1 * CLAMP(atoi(argv[n]), 0, 255));
				lighten(g, width, height, -1 * CLAMP(atoi(argv[n]), 0, 255));
				lighten(b, width, height, -1 * CLAMP(atoi(argv[n]), 0, 255));
			}
			else if(ar == "-pixelate")
			{
				std::cout << "Pixelizando imagem..." << std::endl;

				n ++;
				pixelate(r, width, height, atoi(argv[n]));
				pixelate(g, width, height, atoi(argv[n]));
				pixelate(b, width, height, atoi(argv[n]));
			}
			else if(ar == "-p3")
			{
				std::cout << "Exportando imagem..." << std::endl;

				n ++;
				exportP3(r, g, b, width, height, std::string(argv[n]));
			}
			else if(ar == "-p2")
			{
				std::cout << "Exportando imagem..." << std::endl;

				n++;
				exportP2(r, width, height, std::string(argv[n]));
			}
			else
			{
				valid = false;
			}
		}

		if(ar == "-sobel")
		{
			std::cout << "Aplicando sobel..." << std::endl;

			sobel(r, width, height);
			sobel(g, width, height);
			sobel(b, width, height);
		}
		else if(ar == "-mirror")
		{
			std::cout << "Espelhando imagem..." << std::endl;

			mirror(r, width, height);
			mirror(g, width, height);
			mirror(b, width, height);
		}
		else if(ar == "-laplace")
		{
			std::cout << "Aplicando laplace..." << std::endl;

			filter(r, width, height, filters::laplace, 1.0f / 1);
			filter(g, width, height, filters::laplace, 1.0f / 1);
			filter(b, width, height, filters::laplace, 1.0f / 1);
		}
		else if(ar == "-box")
		{
			std::cout << "Aplicando box blur..." << std::endl;

			filter(r, width, height, filters::box, 1.0f / 9);
			filter(g, width, height, filters::box, 1.0f / 9);
			filter(b, width, height, filters::box, 1.0f / 9);
		}
		else if(ar == "-gaussian")
		{
			std::cout << "Aplicando gaussian blur..." << std::endl;

			filter(r, width, height, filters::gaussian, 1.0f / 16);
			filter(g, width, height, filters::gaussian, 1.0f / 16);
			filter(b, width, height, filters::gaussian, 1.0f / 16);
		}
		else if(ar == "-focus")
		{
			std::cout << "Aplicando focus..." << std::endl;

			filter(r, width, height, filters::focus, 1.0f / 1);
			filter(g, width, height, filters::focus, 1.0f / 1);
			filter(b, width, height, filters::focus, 1.0f / 1);
		}
		else if(ar == "-greyscale")
		{
			std::cout << "Transformando em preto-e-branco..." << std::endl;

			greyscale(r, g, b, width, height);
		}
		else if(valid == false)
		{
			std::cout << ar << ": opção inválida" << std::endl;
		}
	}

	delete[] r;
	delete[] g;
	delete[] b;

	return 0;
}
