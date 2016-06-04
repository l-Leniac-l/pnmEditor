/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 */
 
#ifndef _WINDOWS_H_
#define _WINDOWS_H_

#define ENTER 10
#define ESCAPE 27
/*
 * Definindo a namespace do gerador de janelas
 */
namespace Windows{
  /*
   * Cria um menu @menubar
   */
  void criarMenu(WINDOW *menubar);

  /*
   * Cria o menu Imagem em @coluna
   */
  WINDOW **criarMenuImagem(int coluna);
  /*
   * Cria o menu Editar em @coluna
   */
  WINDOW **criarMenuEditar(int coluna);
  /*
   * Cria o menu Filtros em @coluna
   */
  WINDOW **criarMenuFiltros(int coluna);
  /*
   * Permite scroll no menu entre @itensmenu, indo de @colunainicial até @numeroitens
   */
  int scrollmenu(
    WINDOW **itensmenu,
    int numeroitens,
    int colunainicial
  );
}

#endif
