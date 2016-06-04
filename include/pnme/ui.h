/*
 * INF 110 - Trabalho prático 03
 * Author: Lenilson Nascimento, Raphael Carmo
 */

#ifndef _PNM_UI_H_
#define _PNM_UI_H_

#include <string>

/*
 * Prepara e inicia uma interface. 
 */
void uiSetup();

/*
 * Faz a limpeza dos dados utilizados pela UI.
 */
void uiUnset();

/*
 * Sequência de atualização/render da UI.
 */
void uiUpdate();

/*
 * Requisita o nome do arquivo
 */
std::string getFilename(const std::string &prompt);

/*
 * Requisita a próxima ação.
 */
std::string getCommand(const std::string &prompt);

/*
 * Mostra uma mensagem na tela
 */
void showMessage(const std::string &message);

#endif _PNM_UI_H
