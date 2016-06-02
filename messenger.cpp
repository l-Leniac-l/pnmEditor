#include <curses.h>
#include <stdlib.h>
#include <string>
#include "def.h"
#include "messenger.h"

void Messenger::fileOpen(
  WINDOW *janela,

  int &width,
  int &height,

  bool &color,

  bool &imageSelected,

  unsigned char red[MAXH][MAXW],
	unsigned char green[MAXH][MAXW],
	unsigned char blue[MAXH][MAXW]
)
{
  std::string fileNameOpen;
  char fileNameOpenC[200];
  wprintw(janela,"Digite o nome ou caminho da imagem:");
  echo();
  wgetstr(janela,fileNameOpenC);
  fileNameOpen = std::string(fileNameOpenC);
  if(loadPNM(fileNameOpen, width, height, color, red, green, blue) == false)
  {
    werase(janela);
    wprintw(janela,"Erro ao carregar imagem: %s. Verifique se a imagem existe.",fileNameOpenC);
    wrefresh(janela);
  }
  else
  {
    werase(janela);
    wprintw(janela,"Imagem selecionada: %s",fileNameOpenC);
    wrefresh(janela);
    imageSelected = true;
  }
  noecho();
}

void Messenger::fileSaveGray(
  WINDOW *janela,

  int &width,
  int &height,

  bool &imageSelected,
  bool &filtered,

  unsigned char red[MAXH][MAXW],
  unsigned char filterRed[MAXH][MAXW]
)
{
  std::string fileNameSave;
  char fileNameSaveC[200];
  if(imageSelected)
  {
    wprintw(janela,"Digite o nome ou caminho para salvar imagem:");
    echo();
    wgetstr(janela,fileNameSaveC);
    fileNameSave = std::string(fileNameSaveC);
    werase(janela);
    wprintw(janela,"Salvando arquivo...");
    wrefresh(janela);
    exportP2(filtered ? filterRed : red, width, height, fileNameSave);
    werase(janela);
    wprintw(janela,"Imagem salva como: %s",fileNameSaveC);
    wrefresh(janela);
    noecho();
  }
  else
  {
    werase(janela);
    wprintw(janela,"Nao ha imagem aberta, abra uma imagem antes de salvar.");
    wrefresh(janela);
  }
}

void Messenger::fileSaveColor(
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
)
{
  std::string fileNameSave;
  char fileNameSaveC[200];
  if(imageSelected)
  {
    wprintw(janela,"Digite o nome ou caminho para salvar imagem:");
    echo();
    wgetstr(janela,fileNameSaveC);
    fileNameSave = std::string(fileNameSaveC);
    werase(janela);
    wprintw(janela,"Salvando arquivo...");
    wrefresh(janela);
    if(filtered)
      exportP3(filterRed, filterGreen, filterBlue, width, height, fileNameSave);
    else
         exportP3(red, green, blue, width, height, fileNameSave);
    werase(janela);
    wprintw(janela,"Imagem salva como: %s",fileNameSaveC);
    wrefresh(janela);
    noecho();
  }
  else
  {
    werase(janela);
    wprintw(janela,"Nao ha imagem aberta, abra uma imagem antes de salvar.");
    wrefresh(janela);
  }
}
