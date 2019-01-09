#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED

#include "Constante+include.h"
#include "Salles.h"
#include "menu.h"
#include "temps.h"


int Ennemi_1 (SDL_Surface * ecran, salle * s);
int Ennemi_2(SDL_Surface * ecran, salle *s, int ok);
int Ennemi_3(SDL_Surface * ecran, salle *s, int ok);
int TestVision( SDL_Surface * ecran, salle *salle1 );


#endif // IA_H_INCLUDED
