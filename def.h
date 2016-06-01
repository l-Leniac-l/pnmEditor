/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 */

#ifndef _DEF_H_
#define _DEF_H_

#include <string>

#define CLAMP(A,B,C) (A < B ? B : A > C ? C : A)

#define MAXW 1024
#define MAXH 1024
/*
* Define as matrizes dos filtros: focus(Realçar), gaussianBlur(Desfoque Gaussiano)
* sobel, e laplace.
*/
extern int focus[3][3];

extern int gaussianBlur[3][3];

extern int sobelx[3][3];

extern int sobely[3][3];

extern int laplace[3][3];

/*
 * Abre o arquivo @filename para leitura e carrega seus pixels nos vetores
 * @red, @green e @blue. A largura e altura serão guardadas, respectivamente,
 * nas variáveis @width e @height, e @color será true se a imagem for
 * colorida.
 *
 * Retorna true em caso de sucesso.
 */
bool loadPNM(
	const std::string &filename,

	int &width,
	int &height,

	bool &color,

	unsigned char red[MAXH][MAXW],
	unsigned char green[MAXH][MAXW],
	unsigned char blue[MAXH][MAXW]
);

/*
 * Escurece (@mod < 0) ou clareia (@mod > 0) um arranjo de cores.
 */
void lighten(
	unsigned char pixels[MAXH][MAXW],
	int width, int height, int mod
);

/*
 * Espelha um arranjo de cores.
 */
void mirror(
	unsigned char pixels[MAXH][MAXW],
	int width, int height
);

/*
 * Inverte as cores de cada pixel em uma banda de cor.
 */
void negative(
	unsigned char pixels[MAXH][MAXW],
	int width, int height
);

/*
* Aplica um filtro de sobel na imagem
*/

void sobelFilter(
	unsigned char m[MAXH][MAXW], unsigned char n[MAXH][MAXW],
	int width, int height, int f[3][3], int g[3][3]
);
/*
* Aplica um filtro na imagem
*/

void filter(
	unsigned char m[MAXH][MAXW], unsigned char n[MAXH][MAXW],
	int width, int height, int f[3][3]
);

/*
 * Exporta um arranjo de cores como uma imagem preto-e-branco.
 */
void exportP2(
	unsigned char pixels[MAXH][MAXW],
	int width, int height, const std::string &fo
);

/*
 * Exporta os arranjos correspondentes ao formato RGB como uma imagem colorida.
 */
void exportP3(
	unsigned char red[MAXH][MAXW],
	unsigned char green[MAXH][MAXW],
	unsigned char blue[MAXH][MAXW],
	int width, int height, const std::string &fo
);

#endif
