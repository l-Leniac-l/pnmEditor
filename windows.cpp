#include <curses.h>
#include <stdlib.h>
#include "windows.h"

void Windows::criarMenu(WINDOW *menubar)  //Função encarregada de criar um menu em nosso sistema
{
    wbkgd(menubar,COLOR_PAIR(2));    //Alterando a cor de fundo do menu
    waddstr(menubar,"Imagem");    //Esta função escreve os nomes dos menus
    wattron(menubar,COLOR_PAIR(3));  //Alterando o par de cores para 3
    waddstr(menubar," F1 ");
    wattroff(menubar,COLOR_PAIR(3)); //Retornando para o par de cor 2.
    wmove(menubar,0,20);            // Posiciona o cursor na linha 0, coluna 20
    waddstr(menubar,"Editar");
    wattron(menubar,COLOR_PAIR(3));
    waddstr(menubar," F2 ");
    wmove(menubar,0,40);            // Posiciona o cursor na linha 0, coluna 40
    waddstr(menubar,"Filtros");
    wattron(menubar,COLOR_PAIR(3));
    waddstr(menubar," F3 ");
    wattroff(menubar,COLOR_PAIR(3));
}

WINDOW **Windows::criarMenuImagem(int coluna)  //Desenha os ítens do menu quando as teclas F1 ou F2 for pressionada
{
/*
  +--------------------------------------------------------------------------------------------+
  |   - Cria uma janela itensmenu[0] para desenhar uma caixa à volta do menu.                  |
  |   - Cria 8 ítens como sub-janelas da janela itensmenu[0].                                  |
  |   - Os 8 ítens são criados para poder mostrar o ítem selecionado no menu.                  |
  |   - Para um ítem de menu parecer selecionado basta tornar a sua cor de fundo diferente.    |
  +--------------------------------------------------------------------------------------------+
*/
    int i;
    WINDOW **itensmenu;
    itensmenu=(WINDOW **)malloc(9*sizeof(WINDOW *));

    itensmenu[0]=newwin(5,22,1,coluna);
    wbkgd(itensmenu[0],COLOR_PAIR(2));
    box(itensmenu[0],ACS_VLINE,ACS_HLINE);
    itensmenu[1]=subwin(itensmenu[0],1,20,2,coluna+1);
    itensmenu[2]=subwin(itensmenu[0],1,20,3,coluna+1);
    itensmenu[3]=subwin(itensmenu[0],1,20,4,coluna+1);
    wprintw(itensmenu[1],"Abrir Imagem");
    wprintw(itensmenu[2],"Salvar Tons de Cinza");
    wprintw(itensmenu[3],"Salvar Colorida");
    wbkgd(itensmenu[1],COLOR_PAIR(1));
    wrefresh(itensmenu[0]);
    return itensmenu;
}

WINDOW **Windows::criarMenuEditar(int coluna)  //Desenha os ítens do menu quando as teclas F1 ou F2 for pressionada
{
/*
  +--------------------------------------------------------------------------------------------+
  |   - Cria uma janela itensmenu[0] para desenhar uma caixa à volta do menu.                  |
  |   - Cria 8 ítens como sub-janelas da janela itensmenu[0].                                  |
  |   - Os 8 ítens são criados para poder mostrar o ítem selecionado no menu.                  |
  |   - Para um ítem de menu parecer selecionado basta tornar a sua cor de fundo diferente.    |
  +--------------------------------------------------------------------------------------------+
*/
    int i;
    WINDOW **itensmenu;
    itensmenu=(WINDOW **)malloc(9*sizeof(WINDOW *));

    itensmenu[0]=newwin(6,19,1,coluna);
    wbkgd(itensmenu[0],COLOR_PAIR(2));
    box(itensmenu[0],ACS_VLINE,ACS_HLINE);
    itensmenu[1]=subwin(itensmenu[0],1,17,2,coluna+1);
    itensmenu[2]=subwin(itensmenu[0],1,17,3,coluna+1);
    itensmenu[3]=subwin(itensmenu[0],1,17,4,coluna+1);
    itensmenu[4]=subwin(itensmenu[0],1,17,5,coluna+1);
    wprintw(itensmenu[1],"Clarear/Escurecer");
    wprintw(itensmenu[2],"Espelhar");
    wprintw(itensmenu[3],"Negativo");
    wprintw(itensmenu[4],"Tons de Cinza");
    wbkgd(itensmenu[1],COLOR_PAIR(1));
    wrefresh(itensmenu[0]);
    return itensmenu;
}

WINDOW **Windows::criarMenuFiltros(int coluna)  //Desenha os ítens do menu quando as teclas F1 ou F2 for pressionada
{
/*
  +--------------------------------------------------------------------------------------------+
  |   - Cria uma janela itensmenu[0] para desenhar uma caixa à volta do menu.                  |
  |   - Cria 8 ítens como sub-janelas da janela itensmenu[0].                                  |
  |   - Os 8 ítens são criados para poder mostrar o ítem selecionado no menu.                  |
  |   - Para um ítem de menu parecer selecionado basta tornar a sua cor de fundo diferente.    |
  +--------------------------------------------------------------------------------------------+
*/
    int i;
    WINDOW **itensmenu;
    itensmenu=(WINDOW **)malloc(9*sizeof(WINDOW *));

    itensmenu[0]=newwin(7,19,1,coluna);
    wbkgd(itensmenu[0],COLOR_PAIR(2));
    box(itensmenu[0],ACS_VLINE,ACS_HLINE);
    itensmenu[1]=subwin(itensmenu[0],1,17,2,coluna+1);
    itensmenu[2]=subwin(itensmenu[0],1,17,3,coluna+1);
    itensmenu[3]=subwin(itensmenu[0],1,17,4,coluna+1);
    itensmenu[4]=subwin(itensmenu[0],1,17,5,coluna+1);
    itensmenu[5]=subwin(itensmenu[0],1,17,6,coluna+1);
    wprintw(itensmenu[1],"Sobel");
    wprintw(itensmenu[2],"Gaussian Blur");
    wprintw(itensmenu[3],"Box Blur");
    wprintw(itensmenu[4],"Laplace");
    wprintw(itensmenu[5],"Focus");
    wbkgd(itensmenu[1],COLOR_PAIR(1));
    wrefresh(itensmenu[0]);
    return itensmenu;
}

int Windows::scrollmenu(
  WINDOW **itensmenu,
  int numeroitens,
  int colunainicial
) //Permite fazer scroll entre e dentro dos menus
{
/*
  +--------------------------------------------------------------------------------------------+
  |- Lê as funções pressionadas com a função getch.                                            |
  |- Se as setas baixo ou cima são pressionadas então os ítens abaixo ou acima são seleciona- |
  |  dos tornando a cor do fundo do ítens diferente dos demais.                                |
  |- Se as setas direita ou esquerda são pressionadas então o menu aberto é fechado e o outro |
  |  é aberto.                                     |
  |- Se a tecla ENTER for pressionada, então o ítem selecionado é retornado.                   |
  |- Se a tecla ESC é pressionada, os menus são fechados.                                      |
  +--------------------------------------------------------------------------------------------+
*/
    int key;
    int selecionado=0;
    while (1)
    {
        key=getch();
        if (key==KEY_DOWN || key==KEY_UP)
        {
            wbkgd(itensmenu[selecionado+1],COLOR_PAIR(2));
            wnoutrefresh(itensmenu[selecionado+1]);
            if (key==KEY_DOWN)
            {
                selecionado=(selecionado+1) % numeroitens;
            } else
            {
                selecionado=(selecionado+numeroitens-1) % numeroitens;
            }
            wbkgd(itensmenu[selecionado+1],COLOR_PAIR(1));
            wnoutrefresh(itensmenu[selecionado+1]);
            doupdate();
        }
        else if (key==ESCAPE)
        {
            return -1;
        }
        else if (key==ENTER)
        {
            return selecionado;
        }
    }
}
