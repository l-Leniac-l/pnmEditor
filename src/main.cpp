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

	unsigned char red[1024][1024], green[1024][1024], blue[1024][1024];
	unsigned char fred[1024][1024], fgreen[1024][1024], fblue[1024][1024];

	std::cin >> filename;

	if(loadfile(filename, width, height, color, red, green, blue) == false)
	{
		std::cout << "Falha ao abrir imagem" << std::endl;
		exit(-1);
	}

	filter(red, fred, width, height, filters::box, 1.0f / 9);
	filter(green, fgreen, width, height, filters::box, 1.0f / 9);
	filter(blue, fblue, width, height, filters::box, 1.0f / 9);

//	sobel(red, fred, width, height);
//	sobel(green, fgreen, width, height);
//	sobel(blue, fblue, width, height);

	std::cin >> filename;

	exportP3(filename, width, height, fred, fgreen, fblue);

	return 0;
}
