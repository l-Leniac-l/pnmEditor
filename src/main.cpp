/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 */

#include <iostream>
#include <string>
#include <pnme/defs.h>

int main(int argc, char** argv)
{
	int width, height;
	bool color, filtered = false;

	std::string filename;

	unsigned char *red, *green, *blue;
	unsigned char *fred, *fgreen, *fblue;

	std::cin >> filename;

	if(loadfile(filename, width, height, color, red, green, blue) == false)
	{
		std::cout << "Falha ao abrir imagem" << std::endl;

		delete[] red;
		delete[] green;
		delete[] blue;

		exit(-1);
	}

	return 0;
}
