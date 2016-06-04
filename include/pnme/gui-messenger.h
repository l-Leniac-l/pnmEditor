/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 */
 
#ifndef _MESSENGER_H_
#define _MESSENGER_H_
/*
 * Definindo a namespace do gerador de mensagens
 */
namespace Messenger{
  /*
   * Gera as mensagens da abertura de arquivo em @janela
   * Faz as operações de atribuição em @width, @height, @color,
   * @imageSelected, @red, @green, @blue
   */
  void fileOpen(
    WINDOW *janela,

    int &width,
    int &height,

    bool &color,

    bool &imageSelected,

    unsigned char red[MAXH][MAXW],
  	unsigned char green[MAXH][MAXW],
  	unsigned char blue[MAXH][MAXW]
  );
  /*
   * Gera as mensagens para salvar em tons de cinza em @janela
   * Faz as operações utilizando @width, @height, @imageSelected,
   * @filtered, @red, @filterRed
   */
  void fileSaveGray(
    WINDOW *janela,

    int &width,
    int &height,

    bool &imageSelected,
    bool &filtered,

    unsigned char red[MAXH][MAXW],
    unsigned char filterRed[MAXH][MAXW]
  );
  /*
   * Gera as mensagens para salvar colorido em @janela
   * Faz as operações utilizando @width, @height, @imageSelected,
   * @filtered, @red, @green, @blue, @filterRed, @filterGreen, @filterBlue
   */
  void fileSaveColor(
    WINDOW *janela,

    int &width,
    int &height,

    bool &imageSelected,
    bool &filtered,

    unsigned char red[MAXH][MAXW],
    unsigned char green[MAXH][MAXW],
    unsigned char blue[MAXH][MAXW],
    unsigned char filterRed[MAXH][MAXW],
    unsigned char filterGreen[MAXH][MAXW],
    unsigned char filterBlue[MAXH][MAXW]
  );
  /*
   * Gera as mensagens para clarear a imagem em @janela
   * Faz as operações utilizando @width, @height, @imageSelected,
   * @color, @red, @green, @blue
   */
  void imageLighten(
    WINDOW *janela,

    int &width,
    int &height,

    bool &imageSelected,
    bool &color,

    unsigned char red[MAXH][MAXW],
    unsigned char green[MAXH][MAXW],
    unsigned char blue[MAXH][MAXW]
  );
  /*
   * Gera as mensagens para espelhar a imagem em @janela
   * Faz as operações utilizando @width, @height, @imageSelected,
   * @color, @red, @green, @blue
   */
  void imageMirror(
    WINDOW *janela,

    int &width,
    int &height,

    bool &imageSelected,
    bool &color,

    unsigned char red[MAXH][MAXW],
    unsigned char green[MAXH][MAXW],
    unsigned char blue[MAXH][MAXW]
  );
  /*
   * Gera as mensagens para negativar a imagem em @janela
   * Faz as operações utilizando @width, @height, @imageSelected,
   * @color, @red, @green, @blue
   */
  void imageNegative(
    WINDOW *janela,

    int &width,
    int &height,

    bool &imageSelected,
    bool &color,

    unsigned char red[MAXH][MAXW],
    unsigned char green[MAXH][MAXW],
    unsigned char blue[MAXH][MAXW]
  );
  /*
   * Gera as mensagens para aplicar filtro de sobel em @janela
   * Faz as operações utilizando @width, @height, @imageSelected, @color,
   * @filtered, @red, @green, @blue, @filterRed, @filterGreen, @filterBlue
   */
  void filterSobel(
    WINDOW *janela,

    int &width,
    int &height,

    bool &imageSelected,
    bool &color,
    bool &filtered,

    unsigned char red[MAXH][MAXW],
    unsigned char green[MAXH][MAXW],
    unsigned char blue[MAXH][MAXW],
    unsigned char filterRed[MAXH][MAXW],
    unsigned char filterGreen[MAXH][MAXW],
    unsigned char filterBlue[MAXH][MAXW]
  );
  /*
   * Gera as mensagens para aplicar o filtro @filterName em @janela
   * Faz as operações utilizando @width, @height, @imageSelected, @color,
   * @filtered, @red, @green, @blue, @filterRed, @filterGreen, @filterBlue
   */
  void imageFilter(
    WINDOW *janela,

    char filterName[2],

    int &width,
    int &height,

    bool &imageSelected,
    bool &color,
    bool &filtered,

    unsigned char red[MAXH][MAXW],
    unsigned char green[MAXH][MAXW],
    unsigned char blue[MAXH][MAXW],
    unsigned char filterRed[MAXH][MAXW],
    unsigned char filterGreen[MAXH][MAXW],
    unsigned char filterBlue[MAXH][MAXW]
  );
}

#endif
