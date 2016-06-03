#include <iostream>
#include <string>
#include "../include/console.h"
#include "../include/pnmeditor.h"

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
    std::cout << "********************************" << std::endl;
    std::cout << "*       Opções disponiveis: \n*" << std::endl;
    std::cout << "* s2 - salvar em tons de cinza" << std::endl;
    std::cout << "* s3 - salvar colorido" << std::endl;
    std::cout << "********************************" << std::endl;
    readOption();
  }

  void readOption()
  {
    std::string option;
    std::cin >> option;
    if(option == "s2" || option == "s3")
    {
      if(option == "s2")
        saveFile(true);
      else
        saveFile(false);
    }
  }

  void saveFile(bool grayscale)
  {
    std::cout << "Digite um nome para salvar o arquivo: ";
    std::string fo;
    std::cin >> fo;
    if(grayscale)
      pnmEditor::exportP2(fo,width,height,red);
    else
      pnmEditor::exportP3(fo,width,height,red,green,blue);
  }
}
