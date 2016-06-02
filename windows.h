#ifndef _WINDOWS_H_
#define _WINDOWS_H_

#define ENTER 10
#define ESCAPE 27

namespace Windows{
  void criarMenu(WINDOW *menubar);

  WINDOW **criarMenuImagem(int coluna);

  WINDOW **criarMenuEditar(int coluna);

  WINDOW **criarMenuFiltros(int coluna);

  int scrollmenu(
    WINDOW **itensmenu,
    int numeroitens,
    int colunainicial
  );
}

#endif
