/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 */

#include <iostream>
#include <string>
#include "../include/console.h"

int main(int argc, char** argv)
{
  if(argc < 2)
  {
    console::start();
  }
  else
  {
    std::cout << "Aplicacao UI iniciada..." << std::endl;
  }

  return 0;
}
