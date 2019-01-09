#ifndef SALLES_H_INCLUDED
#define SALLES_H_INCLUDED

#include "Constante+include.h"

typedef struct salle salle;
salle * initsalle();
void creersallesuivante(salle * s);
void creersallebonus(salle * s);
void NettoyerLaMemoire(salle *s);

enum {HAUT, BAS, GAUCHE, DROITE};

struct salle
{
    SDL_Surface * chambre; // la salle

    SDL_Surface * perso; // le petit bonhomme

    SDL_Surface * objet;

    SDL_Surface * ennemi[3]; // l'homme-bec

    SDL_Rect positionperso;

    SDL_Rect positionobjet;

    SDL_Rect positionsalle;

    SDL_Rect positionennemi[3];

    int posEnnemi [3];

    int nombreobjet;//pour les mises a jour ultérieures

    int nombreporte;

    int niveau;

    int enigme; // clé pour aller dans la salle suivante

    salle * suivante;

    salle * precedente;

    salle * sallebonus;
};

#endif // SALLES_H_INCLUDED
