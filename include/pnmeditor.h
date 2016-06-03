/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 */

#ifndef _PNMEDITOR_H_
#define _PNMEDITOR_H_
  namespace pnmEditor{
    bool loadPNM(
    	std::string &filename,

    	int &width,
    	int &height,

    	bool &color,

    	unsigned char ** &red,
    	unsigned char ** &green,
    	unsigned char ** &blue
    );

    void exportP2(
      std::string &fname,

      int width,
      int height,

      unsigned char **pixels
    );

    void exportP3(
      std::string &fname,

      int width,
      int height,

    	unsigned char **red,
    	unsigned char **green,
    	unsigned char **blue
    );
  }
#endif
