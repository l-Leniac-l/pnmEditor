/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 */

#ifndef _CONSOLE_H_
#define _CONSOLE_H_

  #include <string>

  namespace console
  {
    static std::string fileName;

    static int width, height;

    static bool color;

    static unsigned char **red;
    static unsigned char **green;
    static unsigned char **blue;

    void start();

    void fileOpen();

    void writeMenu();

    void readOption();

    void saveFile(bool grayscale);
  }
#endif
