#ifndef _MESSENGER_H_
#define _MESSENGER_H_
namespace Messenger{
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

  void fileSaveGray(
    WINDOW *janela,

    int &width,
    int &height,

    bool &imageSelected,
    bool &filtered,

    unsigned char red[MAXH][MAXW],
    unsigned char filterRed[MAXH][MAXW]
  );

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

}

#endif