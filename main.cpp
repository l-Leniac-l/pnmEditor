/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "def.h"

int main(int argc, char** argv)
{
	bool color, filtered = false;
	int width, height;
	std::string fname;

	unsigned char red[MAXH][MAXW], green[MAXH][MAXW], blue[MAXH][MAXW];
	unsigned char filterRed[MAXH][MAXW], filterGreen[MAXH][MAXW], filterBlue[MAXH][MAXW];

	if(argc != 2)
	{
		std::cout << "Nome do arquivo para abrir: ";
		std::cin >> fname;
	} else
	{
		fname = argv[1];
	}

	if(loadPNM(fname, width, height, color, red, green, blue) == false)
	{
		std::cout << "Erro ao carregar imagem." << std::endl;
		exit(-1);
	}

	/*
	 * Fim da parte chata.
	 * Início da parte divertida.
	 */

	std::cout << "Comandos disponíveis -" << std::endl;

/*	std::cout << "- (qi) Clarear ou escurecer imagem" << std::endl;
	std::cout << "- (qc) Clarear ou escurer banda de cor" << std::endl;
	std::cout << "- (ei) Espelhar imagem" << std::endl;
	std::cout << "- (ec) Espelhar banda" << std::endl;
	std::cout << "- (ni) Negativar imagem" << std::endl;
	std::cout << "- (nc) Begativar banda" << std::endl;*/

	std::cout << "- (fi) Filtros de imagem" << std::endl;
	std::cout << "- (s2) Exportar o buffer atual como P2 (greyscale)" << std::endl;
	std::cout << "- (s3) Exportar o buffer atual como P3 (colorida)" << std::endl;
	std::cout << "- (:q) Sair do programa" << std::endl;

	std::cout << std::endl;

	int intp;
	std::string action, strp;

	do
	{
		std::cout << "Comando) ";
		std::cin >> action;

		if(action == "s2" || action == "s3")
		{
			std::cout << "Nome do arquivo) ";
			std::cin >> strp;
			strp += ".pnm";

			if(action == "s2")
			{
				exportP2(filtered ? filterRed : red, width, height, strp);
			}
			else
			{
				if(filtered)
				{
					exportP3(filterRed, filterGreen, filterBlue, width, height, strp);
				} else
				{
					exportP3(red, green, blue, width, height, strp);
				}
			}
		}

		else if(action == "fi")
		{
			std::cout << "Filtros disponíveis - " << std::endl;
			std::cout << "- (so) Sobel" << std::endl;
			std::cout << "- (fo) Focus" << std::endl;
			std::cout << "- (gb) Gaussian blur" << std::endl;
			std::cout << "- (la) Laplace" << std::endl;
			std::cout << "- (bo) Box blur" << std::endl;
			std::cout << "- [outros valores] Cancelar" << std::endl;

			std::cout << std::endl << "Filtro) ";
			std::cin >> strp;

			filtered = true;

			if(strp == "fo")
			{
				filter(red, filterRed, width, height, Filters::Focus);
				filter(green, filterGreen, width, height, Filters::Focus);
				filter(blue, filterBlue, width, height, Filters::Focus);
			}

			else if(strp == "gb")
			{
				filter(red, filterRed, width, height, Filters::Gaussian, 1.0f / 16);
				filter(green, filterGreen, width, height, Filters::Gaussian, 1.0f / 16);
				filter(blue, filterBlue, width, height, Filters::Gaussian, 1.0f / 16);
			}

			else if(strp == "la")
			{
				filter(red, filterRed, width, height, Filters::Laplace);
				filter(green, filterGreen, width, height, Filters::Laplace);
				filter(blue, filterBlue, width, height, Filters::Laplace);
			}

			else if(strp == "so")
			{
				sobel(red, filterRed, width, height);
				sobel(green, filterGreen, width, height);
				sobel(blue, filterBlue, width, height);
			}

			else if(strp == "bo")
			{
				filter(red, filterRed, width, height, Filters::Box, 1.0f / 9);
				filter(green, filterGreen, width, height, Filters::Box, 1.0f / 9);
				filter(blue, filterBlue, width, height, Filters::Box, 1.0f / 9);
			}

			else
			{
				filtered = false;
				continue;
			}
		}

	} while(action != ":q");

	return 0;
}
