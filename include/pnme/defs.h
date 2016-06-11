/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 */

#ifndef _PNM_DEFS_H_
#define _PNM_DEFS_H_

#include <string>
#include <tuple>

/*
 * Limita um valor A entre B e C, ou seja, força B <= A <= C.
 */
#define CLAMP(A,B,C) (A <= B ? B : A >= C ? C : A)

#define MAXW 1024
#define MAXH 1024

namespace filters
{
	/*
	 * Filtros definidos globalmente pela conveniência de mudanças e acesso. 
	 * Utilizados em suas respectivas funções.
	 */

	extern int focus[3][3];

	extern int box[3][3];
	extern int gaussian[3][3];

	extern int laplace[3][3];

	extern int sobelY[3][3];
	extern int sobelX[3][3];
}

/*
 * Abre o arquivo @filename para leitura e carrega seus pixels nos vetores
 * @red, @green e @blue. A largura e altura serão guardadas, respectivamente,
 * nas variáveis @width e @height, e @color será true se a imagem for
 * colorida.
 *
 * Retorna true em caso de sucesso.
 */
std::tuple<unsigned char*, unsigned char*, unsigned char*> loadfile(
	const std::string &filename,
	int &width,
	int &height,
	bool &color
);

/*
 * Escurece (@mod < 0) ou clareia (@mod > 0) um arranjo de cores.
 */
void lighten(
	unsigned char *pixels,
	int width,
	int height,
	int mod
);

/*
 * Espelha um arranjo de cores.
 */
void mirror(
	unsigned char *pixels,
	int width,
	int height
);

void pixelate(
	unsigned char *pixels,
	int width,
	int height,
	int radius
);

/*
 * Inverte as cores de cada pixel em uma banda de cor.
 */
void negative(
	unsigned char *pixels,
	int width,
	int height
);

/*
 * Aplica o filtro de sobel em @pixels.
 * @in e @out devem ser diferentes.
 */
void sobel(
	unsigned char *pixels,
	int width,
	int height
);

/*
 * Aplica um filtro @f 3*3 na matriz @in e guarda o resultado da operação
 * na matriz @out.
 */
void filter(
	unsigned char *pixels,
	int width,
	int height,
	int f[3][3],
	float normalization = 1.0f
);

/*
 * Exporta uma banda de cores como uma imagem preto-e-branco.
 */
void exportP2(
	const std::string &filename,
	int width,
	int height,
	unsigned char pixels[][MAXW]
);

/*
 * Exporta as bandas @red @green e @blue como uma imagem colorida.
 */
void exportP3(
	unsigned char *r,
	unsigned char *g,
	unsigned char *b,
	int width,
	int height,
	const std::string &filename
);

#endif
