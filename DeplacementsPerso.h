#ifndef DEPLACEMENTSPERSO_H_INCLUDED
#define DEPLACEMENTSPERSO_H_INCLUDED

#include "Constante+include.h"
#include "Salles.h"
#include "temps.h"

void mouvbas(salle * s, SDL_Surface * ecran,int score, SDL_Surface * panneau[11], SDL_Rect tableauaffichage);
void mouvhaut(salle * s, SDL_Surface * ecran,int score, SDL_Surface * panneau[11], SDL_Rect tableauaffichage);
void mouvgauche(salle * s, SDL_Surface * ecran,int score, SDL_Surface * panneau[11], SDL_Rect tableauaffichage);
void mouvdroite(salle * s, SDL_Surface * ecran,int score, SDL_Surface * panneau[11], SDL_Rect tableauaffichage);

#endif // DEPLACEMENTSPERSO_H_INCLUDED
