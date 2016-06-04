/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 */

#include <iostream>
#include <string>
#include <pnme/ui.h>

int main(int argc, char** argv)
{
	int width, height;
	bool colored, filtered = false;

	std::string filename;

	unsigned char *red, *green, *blue;
	unsigned char *fred, *fgreen, *fblue;

	uiSetup();
	filename = getFilename("Nome do arquivo");

	if(pnmLoad(filename, width, height, colored, red, green, blue) == false)
	{
		showMessage("Falha ao abrir imagem");

		goto cleanup;
		exit(-1);
	}

	goto cleanup;
	return 0;

cleanup:
	delete[] red;
	delete[] green;
	delete[] blue;
	delete[] fred;
	delete[] fgreen;
	delete[] fblue;
}
