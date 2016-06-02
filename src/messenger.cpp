/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 */
 
#include <curses.h>
#include <stdlib.h>
#include <string>
#include "../include/def.h"
#include "../include/messenger.h"

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
    wprintw(janela,"Nao há imagem aberta, abra uma imagem antes de salvar.");
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
    wprintw(janela,"Nao há imagem aberta, abra uma imagem antes de salvar.");
    wrefresh(janela);
  }
}
void Messenger::imageLighten(
  WINDOW *janela,

  int &width,
  int &height,

  bool &imageSelected,
  bool &color,

  unsigned char red[MAXH][MAXW],
  unsigned char green[MAXH][MAXW],
  unsigned char blue[MAXH][MAXW]
)
{
  if(imageSelected){
    echo();
    int fator = 0; char fatorC[5], banda[1];
    werase(janela);
    wprintw(janela,"Digite um fator de clareamento (fator negativo escurece a imagem): ");
    wrefresh(janela);
    wgetstr(janela,fatorC);
    fator = std::stoi(fatorC);
    if(color)
    {
      werase(janela);
      wprintw(janela,"Clarear banda de cor (0: todas, 1: vermelho, 2: verde, 3: azul): ");
      wrefresh(janela);
      wgetstr(janela,banda);
      if(banda[0] == '0')
      {
        lighten(red,width,height,fator);
        lighten(green,width,height,fator);
        lighten(blue,width,height,fator);
      }
      else if(banda[0] == '1')
        lighten(red,width,height,fator);
      else if(banda[0] == '2')
        lighten(green,width,height,fator);
      else if(banda[0] == '3')
        lighten(blue,width,height,fator);

    }
    else
    {
      lighten(red,width,height,fator);
    }
    werase(janela);
    wprintw(janela,"Fator %d aplicado à imagem!",fator);
    wrefresh(janela);
    noecho();
  }
  else
  {
    werase(janela);
    wprintw(janela,"Nao há imagem aberta, abra uma imagem antes de editar.");
    wrefresh(janela);
  }
}

void Messenger::imageMirror(
  WINDOW *janela,

  int &width,
  int &height,

  bool &imageSelected,
  bool &color,

  unsigned char red[MAXH][MAXW],
  unsigned char green[MAXH][MAXW],
  unsigned char blue[MAXH][MAXW]
)
{
  char banda[1];
  if(imageSelected){
    echo();
    if(color)
    {
      werase(janela);
      wprintw(janela,"Espelhar banda de cor (0: todas, 1: vermelho, 2: verde, 3: azul): ");
      wrefresh(janela);
      wgetstr(janela,banda);
      if(banda[0] == '0')
      {
        mirror(red,width,height);
        mirror(green,width,height);
        mirror(blue,width,height);
      }
      else if(banda[0] == '1')
        mirror(red,width,height);
      else if(banda[0] == '2')
        mirror(green,width,height);
      else if(banda[0] == '3')
        mirror(blue,width,height);

    }
    else
    {
      mirror(red,width,height);
    }
    werase(janela);
    wprintw(janela,"A imagem foi espelhada verticalmente!");
    wrefresh(janela);
    noecho();
  }
  else
  {
    werase(janela);
    wprintw(janela,"Nao há imagem aberta, abra uma imagem antes de editar.");
    wrefresh(janela);
  }
}

void Messenger::imageNegative(
  WINDOW *janela,

  int &width,
  int &height,

  bool &imageSelected,
  bool &color,

  unsigned char red[MAXH][MAXW],
  unsigned char green[MAXH][MAXW],
  unsigned char blue[MAXH][MAXW]
)
{
  char banda[1];
  if(imageSelected){
    echo();
    if(color)
    {
      werase(janela);
      wprintw(janela,"Negativar banda de cor (0: todas, 1: vermelho, 2: verde, 3: azul): ");
      wrefresh(janela);
      wgetstr(janela,banda);
      if(banda[0] == '0')
      {
        negative(red,width,height);
        negative(green,width,height);
        negative(blue,width,height);
      }
      else if(banda[0] == '1')
        negative(red,width,height);
      else if(banda[0] == '2')
        negative(green,width,height);
      else if(banda[0] == '3')
        negative(blue,width,height);

    }
    else
    {
      negative(red,width,height);
    }
    werase(janela);
    wprintw(janela,"A imagem foi negativada!");
    wrefresh(janela);
    noecho();
  }
  else
  {
    werase(janela);
    wprintw(janela,"Nao há imagem aberta, abra uma imagem antes de editar.");
    wrefresh(janela);
  }
}

void Messenger::filterSobel(
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
)
{
  if(imageSelected){
    if(color)
    {
      sobel(red,filterRed,width,height);
      sobel(green,filterGreen,width,height);
      sobel(blue,filterBlue,width,height);
    }
    else
    {
      sobel(red,filterRed,width,height);
    }
    filtered = true;
    werase(janela);
    wprintw(janela,"Filtro de sobel aplicado!");
    wrefresh(janela);
  }
  else
  {
    werase(janela);
    wprintw(janela,"Nao há imagem aberta, abra uma imagem antes de editar.");
    wrefresh(janela);
  }
}

void Messenger::imageFilter(
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
)
{
  if(imageSelected){
    echo();
    if(color)
    {
      if(filterName == "gb")
      {
        filter(red, filterRed, width, height, Filters::Gaussian, 1.0f / 16);
				filter(green, filterGreen, width, height, Filters::Gaussian, 1.0f / 16);
				filter(blue, filterBlue, width, height, Filters::Gaussian, 1.0f / 16);
      }
      else if(filterName == "bo")
      {
        filter(red, filterRed, width, height, Filters::Box, 1.0f / 9);
				filter(green, filterGreen, width, height, Filters::Box, 1.0f / 9);
				filter(blue, filterBlue, width, height, Filters::Box, 1.0f / 9);
      }
      else if(filterName == "la")
      {
        filter(red, filterRed, width, height, Filters::Laplace);
				filter(green, filterGreen, width, height, Filters::Laplace);
				filter(blue, filterBlue, width, height, Filters::Laplace);
      }
      else if(filterName == "fo")
      {
        filter(red, filterRed, width, height, Filters::Focus);
				filter(green, filterGreen, width, height, Filters::Focus);
				filter(blue, filterBlue, width, height, Filters::Focus);
      }
    }
    else
    {
      if(filterName == "gb")
      {
        filter(red, filterRed, width, height, Filters::Gaussian, 1.0f / 16);
      }
      else if(filterName == "bo")
      {
        filter(red, filterRed, width, height, Filters::Box, 1.0f / 9);
      }
      else if(filterName == "la")
      {
        filter(red, filterRed, width, height, Filters::Laplace);
      }
      else if(filterName == "fo")
      {
        filter(red, filterRed, width, height, Filters::Focus);
      }
    }
    filtered = true;
    werase(janela);
    if(filterName == "gb")
    {
      wprintw(janela,"Filtro Gaussian Blur aplicado!");
    }
    else if(filterName == "bo")
    {
      wprintw(janela,"Filtro Box Blur aplicado!");
    }
    else if(filterName == "la")
    {
      wprintw(janela,"Filtro de Laplace aplicado!");
    }
    else if(filterName == "fo")
    {
      wprintw(janela,"Filtro Focus aplicado!");
    }
    wrefresh(janela);
    noecho();
  }
  else
  {
    werase(janela);
    wprintw(janela,"Nao há imagem aberta, abra uma imagem antes de editar.");
    wrefresh(janela);
  }
}
