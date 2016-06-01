/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 * Date: Mon, May 30 2016
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#include "def.h"

int main(int argc, char** argv)
{
	bool color;
	int width, height;
	std::string fname;

	unsigned char red[MAXH][MAXW], green[MAXH][MAXW], blue[MAXH][MAXW];

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
	std::cout << "- (qi) Clarear ou escurecer imagem. " << std::endl;
	std::cout << "- (qc) Clarear ou escurer banda de cor. " << std::endl;
	std::cout << "- (ei) Espelhar imagem. " << std::endl;
	std::cout << "- (ec) Espelhar banda. " << std::endl;
	std::cout << "- (ni) Aplicar filtro negativo na imagem. " << std::endl;
	std::cout << "- (nc) Aplicar filtro negativo numa banda. " << std::endl;
	std::cout << "- (fa) Um filtro aí. " << std::endl;
	std::cout << "- (s2) Exportar o buffer atual como P2 (greyscale). " << std::endl;
	std::cout << "- (s3) Exportar o buffer atual como P3 (colorida). " << std::endl;
	std::cout << "- (Qq) Sair do programa. " << std::endl;
	std::cout << std::endl;

	std::string act;
	std::string filterName;
	do
	{
		std::cout << "Comando) ";
		std::cin >> act;

		int b[3][3] = {{1, 0, -1}, {2, 0, -2}, {1, 0, -1}};

		if(act == "qi" || act == "qc")
		{
			int aux;
			std::cin >> aux;

			lighten(red, width, height, aux);

			if(act == "qi")
			{
				lighten(green, width, height, aux);
				lighten(blue, width, height, aux);
			}
		}

		else if(act == "ei" || act == "ec")
		{
			mirror(red, width, height);

			if(act == "qi")
			{
				mirror(green, width, height);
				mirror(blue, width, height);
			}
		}

		else if(act == "ni" || act == "nb")
		{
			negative(red, width, height);

			if(act == "ni")
			{
				negative(green, width, height);
				negative(blue, width, height);
			}
		}

		else if(act == "s2" || act == "s3")
		{
			std::string fout;

			std::cout << "Nome do arquivo: ";
			std::cin >> fout;
			fout += ".pnm";

			if(act == "s2")
			{
				exportP2(red, width, height, fout);
			}
			else
			{
				exportP3(red, green, blue, width, height, fout);
			}

			std::cout << "✓" << std::endl;
		}

		else if(act == "fa")
		{
			std::cout << "Filtros disponíveis - " << std::endl;
			std::cout << "- (so) Sobel. (Padrao) " << std::endl;
			std::cout << "- (fo) Focus. " << std::endl;
			std::cout << "- (gb) Gaussian Blur. " << std::endl;
			std::cout << "- (la) Laplace. " << std::endl;
			std::cout << "Filtro) ";
			std::cin >> filterName;
			if(filterName == "fo")
			{
				filter(red,width,height,focus);
				filter(green,width,height,focus);
				filter(blue,width,height,focus);
			}
			else if(filterName == "gb")
			{
				filter(red,width,height,gaussianBlur);
				filter(green,width,height,gaussianBlur);
				filter(blue,width,height,gaussianBlur);
			}
			else if(filterName == "so")
			{
				filter(red,width,height,sobel);
				filter(green,width,height,sobel);
				filter(blue,width,height,sobel);
			}
			else if(filterName == "la")
			{
				filter(red,width,height,laplace);
				filter(green,width,height,laplace);
				filter(blue,width,height,laplace);
			}
			else
			{
				filter(red,width,height,sobel);
				filter(green,width,height,sobel);
				filter(blue,width,height,sobel);
			}
		}

	} while(act != "Qq");

	return 0;
}
