#include "Salles.h"

salle * initsalle()
{
    salle * s = (salle*)malloc(sizeof(salle));//allocation dynamique salle

    //initialisation des positions

    s->positionperso.x = N;

    s->positionperso.y = 7*N;

    s->positionobjet.x = N;

    s->positionobjet.y = 6*N;

    s->positionsalle.x = 0;

    s->positionsalle.y = 0;

    s->positionennemi[0].x = N;

    s->positionennemi[0].y = N;

    s->positionennemi[1].x = 10*N;

    s->positionennemi[1].y = 3*N;

    s->positionennemi[2].x = 10*N;

    s->positionennemi[2].y = 5*N;

    //on charge toutes les images

    s->chambre = SDL_LoadBMP("images/salle-1.bmp");

    s->perso = SDL_LoadBMP("images/face.bmp");

    s->objet = SDL_LoadBMP("images/LIT.bmp");

    s->ennemi[0] = SDL_LoadBMP("images/ennemi-droit.bmp");

    s->ennemi[1] = SDL_LoadBMP("images/ennemi-face.bmp");

    s->ennemi[2] = SDL_LoadBMP("images/ennemi-gauche.bmp");

    s->niveau = 1;//juste pour la première salle

    srand(time(NULL));

    s->nombreporte = rand()%2 + 2;//soit 2 ou soit 3 portes

    s->suivante = NULL;// jusqua ce que enigme soit different de 0

    s->precedente = NULL;//pour la premiere mais sinon on dit que c'est la precedente

    s->sallebonus = NULL;// pour l'instant! après on initialisera une salle bonus

    if ((s->niveau%2 == 0) || (s->nombreporte == 2))
        s->enigme = 10;//couloir pour aller a la prochaine salle

    else s->enigme = 0;

    return s;
}

// initialisation de bonus
salle * initsallebonus()
{
    salle * sb = (salle*)malloc(sizeof(salle));//allocation dynamique salle bonus

    //initalisation des positions

    sb->positionperso.x = 0;

    sb->positionperso.y = 4*N;

    sb->positionobjet.x = 5*N;

    sb->positionobjet.y = 4*N;

    sb->positionsalle.x = 0;

    sb->positionsalle.y = 0;

    sb->positionobjet.x = 5*N;

    sb->positionobjet.y = 4*N;

    //on upload les images

    sb->chambre = SDL_LoadBMP("images/salle-bonus.bmp");

    sb->perso = SDL_LoadBMP("images/droit.bmp");

    sb->objet = SDL_LoadBMP("images/livre.bmp");

    //pas de méchants dans la salle bonus (trop cruel)

    sb->ennemi[0] = NULL;

    sb->ennemi[1] = NULL;

    sb->ennemi[2] = NULL;

    //niveau nul pour les salles bonus

    sb->niveau = 0;

    sb->precedente = NULL;

    sb->suivante = NULL;

    sb->sallebonus = NULL;

    sb->enigme = 10;

    return sb;
}

// a chaque fois qu'on franchit une porte on creer une salle (pour le moment)
void creersallesuivante(salle * s)
{
    salle * sallenouvelle =  NULL;

    s->suivante = initsalle();

    sallenouvelle = s->suivante;

    //le niveau augmente de 1

    sallenouvelle->niveau = s->niveau+1;

    //on upload les images

    if (sallenouvelle->nombreporte == 3)
        sallenouvelle->chambre = SDL_LoadBMP("images/salle-3portes.bmp");

    if (sallenouvelle->nombreporte == 2)
        sallenouvelle->chambre = SDL_LoadBMP("images/salle-2portes.bmp");

    if (sallenouvelle->niveau%2 == 0)
        sallenouvelle->chambre = SDL_LoadBMP("images/couloir.bmp");

    sallenouvelle->precedente = s;//comme j ai dit dans initsalle

    sallenouvelle->suivante = NULL;//jusqua la franchection de la porte suivante
}

void creersallebonus(salle * s)
{
    salle * sb = NULL;

    s->sallebonus = initsallebonus();

    sb = s->sallebonus;

    sb->precedente = s;

    sb->suivante = NULL;// sans salle suivante

    sb->sallebonus = NULL;// sans salle bonus

}

void NettoyerLaMemoire (salle *s) {

    salle *a_suppr = NULL;

    while (s != NULL)

    {
        a_suppr = s;
        s = s->precedente;

        free(a_suppr);
    }
}


