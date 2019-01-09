#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Constante+include.h"
#include "jeu.h"

void menu();
void gameOver (SDL_Surface * ecran, salle * s);
void regles (SDL_Surface * ecran);
void you_Win(SDL_Surface * ecran, int scorefinal);

#endif // MENU_H_INCLUDED
