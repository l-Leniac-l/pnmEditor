#include <iostream>
#include <string>
#include "../include/console.h"
#include "../include/pnmeditor.h"
#include "../include/filters.h"

namespace console
{
  void start()
  {
    std::cout << "Digite o nome ou caminho da imagem: ";
    fileOpen();
  }

  void fileOpen()
  {
    std::cin >> fileName;
    if(pnmEditor::loadPNM(fileName,width,height,color,red,green,blue)){
      writeMenu();
    }else
      std::cout << "Erro ao abrir o arquivo:" << fileName << std::endl;
  }

  void writeMenu()
  {
    std::cout << "*********************************" << std::endl;
    std::cout << "*       Opções disponiveis: \n*" << std::endl;
    std::cout << "* :c - Clarear/Escurecer imagem" << std::endl;
    std::cout << "* :e - Espelhar imagem" << std::endl;
    std::cout << "* :n - Negativar imagem" << std::endl;
    std::cout << "* :f - Aplicar filtro na imagem" << std::endl;
    std::cout << "* :s - Salvar imagem" << std::endl;
    std::cout << "* :q - Sair do programa" << std::endl;
    std::cout << "*********************************" << std::endl;
    readOption();
  }

  void readOption()
  {
    std::string option;
    std::cin >> option;
    if(option == ":c")
    {
      std::cout << "Digite um fator de clareamento (fator negativo escurece a imagem): ";
      int mod;
      std::cin >> mod;
      if(color)
      {
        std::cout << "Clarear banda de cor (0: todas, 1: vermelho, 2: verde, 3: azul): ";
        int band;
        std::cin >> band;
        if(band == 0)
        {
          filters::lighten(red,width,height,mod);
          filters::lighten(green,width,height,mod);
          filters::lighten(blue,width,height,mod);
        }
        else if(band == 1)
        {
          filters::lighten(red,width,height,mod);
        }
        else if(band == 2)
        {
          filters::lighten(green,width,height,mod);
        }
        else if(band == 3)
        {
          filters::lighten(blue,width,height,mod);
        }
      }
      else
        filters::lighten(red,width,height,mod);
    }
    if(option == ":s")
    {
      std::cout << "Digite o formato para salvar(1 - Tons de cinza, 2 - Colorido): ";
      int format;
      std::cin >> format;
      if(format == 1)
        saveFile(true);
      else
        saveFile(false);
    }
    else if(option == ":q")
    {
      return;
    }
  }

  void saveFile(bool grayscale)
  {
    std::cout << "Digite um nome para salvar o arquivo: ";
    std::string fo;
    std::cin >> fo;
    if(grayscale)
    {
      std::cout << "Digite um nome para salvar o arquivo: ";
      pnmEditor::exportP2(fo,width,height,red);
    }
    else
      pnmEditor::exportP3(fo,width,height,red,green,blue);
  }
}
