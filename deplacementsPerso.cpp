#include "DeplacementsPerso.h"

void mouvbas(salle * s, SDL_Surface * ecran, int score, SDL_Surface * panneau[11], SDL_Rect tableauaffichage)
{
    int decalage = 28;

    SDL_Surface * p[4];

    // on charge les images
    /*On crée une animation de deplacement*/

    p[0] = SDL_LoadBMP("images/face-pied-gauche.bmp");
    p[1] = SDL_LoadBMP("images/face-pied-droit.bmp");
    p[2] = SDL_LoadBMP("images/face-pied-gauche.bmp");
    p[3] = SDL_LoadBMP("images/face.bmp");

    for(int i = 0; i < 4; i++)
    {
        SDL_Delay(50);

        s->perso = p[i];

        if(i == 0)//on decale de 1 pour arriver à 85 (N)
            s->positionperso.y = s->positionperso.y + decalage + 1;

        else if(i == 3) // la dernière image n'est pas décalée
            s->positionperso.y = s->positionperso.y;

        else s->positionperso.y = s->positionperso.y + decalage; // on bouge normalement le perso

        // on met la transparence blanche du perso
        SDL_SetColorKey(s->perso, SDL_SRCCOLORKEY, SDL_MapRGB(s->perso->format, 255, 255, 255));

        // on affiche l'image
        SDL_BlitSurface(s->chambre,NULL,ecran,&s->positionsalle);

        // On affiche le lit dans la première salle et le livre d'enigme dans les salles bonus
        if((s->niveau == 1) || (s->niveau == 0))
        {
            SDL_SetColorKey(s->objet, SDL_SRCCOLORKEY, SDL_MapRGB(s->objet->format, 255, 255, 255));

            SDL_BlitSurface(s->objet,NULL,ecran,&s->positionobjet);
        }


        // On affiche les enemis
        if((s->niveau%2 == 1) && (s->niveau != 1))
        {
            SDL_SetColorKey(s->ennemi[0], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[0]->format, 255, 255, 255));

            SDL_BlitSurface(s->ennemi[0],NULL,ecran,&s->positionennemi[0]);

            if(s->niveau > 4)
            {

                SDL_SetColorKey(s->ennemi[1], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[1]->format, 255, 255, 255));

                SDL_BlitSurface(s->ennemi[1],NULL,ecran,&s->positionennemi[1]);

            }

            if(s->niveau > 6)
            {

                SDL_SetColorKey(s->ennemi[2], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[2]->format, 255, 255, 255));

                SDL_BlitSurface(s->ennemi[2],NULL,ecran,&s->positionennemi[2]);

            }
        }

        SDL_BlitSurface(panneau[10],NULL,ecran,&tableauaffichage);

        compteur(ecran,score,panneau);



        // on affiche le perso
        SDL_BlitSurface(s->perso, NULL, ecran, &s->positionperso);

        SDL_Flip(ecran);
    }

}

void mouvhaut(salle * s, SDL_Surface * ecran,int score, SDL_Surface * panneau[11], SDL_Rect tableauaffichage)
{
    int decalage = 28;



    SDL_Surface * p[4];

    p[0] = SDL_LoadBMP("images/dos-pied-gauche.bmp");
    p[1] = SDL_LoadBMP("images/dos-pied-droit.bmp");
    p[2] = SDL_LoadBMP("images/dos-pied-gauche.bmp");
    p[3] = SDL_LoadBMP("images/dos.bmp");

    for(int i = 0; i < 4; i++)
    {
        SDL_Delay(50);

        s->perso = p[i];

        if(i == 0)
            s->positionperso.y = s->positionperso.y - decalage - 1;

        else if(i == 3) s->positionperso.y = s->positionperso.y;

        else s->positionperso.y = s->positionperso.y - decalage;

        SDL_SetColorKey(s->perso, SDL_SRCCOLORKEY, SDL_MapRGB(s->perso->format, 255, 255, 255));

        SDL_BlitSurface(s->chambre,NULL,ecran,&s->positionsalle);

        if((s->niveau == 1) || (s->niveau == 0))
        {
            SDL_SetColorKey(s->objet, SDL_SRCCOLORKEY, SDL_MapRGB(s->objet->format, 255, 255, 255));

            SDL_BlitSurface(s->objet,NULL,ecran,&s->positionobjet);
        }

        if((s->niveau%2 == 1) && (s->niveau != 1))
        {
            SDL_SetColorKey(s->ennemi[0], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[0]->format, 255, 255, 255));

            SDL_BlitSurface(s->ennemi[0],NULL,ecran,&s->positionennemi[0]);

            if(s->niveau > 4)
            {

                SDL_SetColorKey(s->ennemi[1], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[1]->format, 255, 255, 255));

                SDL_BlitSurface(s->ennemi[1],NULL,ecran,&s->positionennemi[1]);

            }

            if(s->niveau > 6)
            {

                SDL_SetColorKey(s->ennemi[2], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[2]->format, 255, 255, 255));

                SDL_BlitSurface(s->ennemi[2],NULL,ecran,&s->positionennemi[2]);

            }
        }

        SDL_BlitSurface(panneau[10],NULL,ecran,&tableauaffichage);

        compteur(ecran,score,panneau);

        SDL_BlitSurface(s->perso, NULL, ecran, &s->positionperso);

        SDL_Flip(ecran);
    }

}

void mouvgauche(salle * s, SDL_Surface * ecran,int score, SDL_Surface * panneau[11], SDL_Rect tableauaffichage)
{

    int decalage = 28;

    //

    SDL_Surface * p[4];

    p[0] = SDL_LoadBMP("images/gauche-pied-gauche.bmp");
    p[1] = SDL_LoadBMP("images/gauche-pied-droit.bmp");
    p[2] = SDL_LoadBMP("images/gauche-pied-gauche.bmp");
    p[3] = SDL_LoadBMP("images/gauche.bmp");

    for(int i = 0; i < 4; i++)
    {
        SDL_Delay(50);

        s->perso = p[i];

        if(i == 0)
            s->positionperso.x = s->positionperso.x - decalage - 1;

        else if(i == 3) s->positionperso.x = s->positionperso.x;

        else s->positionperso.x = s->positionperso.x - decalage;

        SDL_SetColorKey(s->perso, SDL_SRCCOLORKEY, SDL_MapRGB(s->perso->format, 255, 255, 255));

        SDL_BlitSurface(s->chambre,NULL,ecran,&s->positionsalle);


        if((s->niveau == 1) || (s->niveau == 0))
        {
            SDL_SetColorKey(s->objet, SDL_SRCCOLORKEY, SDL_MapRGB(s->objet->format, 255, 255, 255));

            SDL_BlitSurface(s->objet,NULL,ecran,&s->positionobjet);
        }

        if((s->niveau%2 == 1) && (s->niveau != 1))
        {
            SDL_SetColorKey(s->ennemi[0], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[0]->format, 255, 255, 255));

            SDL_BlitSurface(s->ennemi[0],NULL,ecran,&s->positionennemi[0]);

            if(s->niveau > 4)
            {

                SDL_SetColorKey(s->ennemi[1], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[1]->format, 255, 255, 255));

                SDL_BlitSurface(s->ennemi[1],NULL,ecran,&s->positionennemi[1]);

            }

            if(s->niveau > 6)
            {

                SDL_SetColorKey(s->ennemi[2], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[2]->format, 255, 255, 255));

                SDL_BlitSurface(s->ennemi[2],NULL,ecran,&s->positionennemi[2]);

            }
        }

        SDL_BlitSurface(panneau[10],NULL,ecran,&tableauaffichage);

        compteur(ecran,score,panneau);

        SDL_BlitSurface(s->perso, NULL, ecran, &s->positionperso);

        SDL_Flip(ecran);
    }


}

void mouvdroite(salle * s, SDL_Surface * ecran,int score, SDL_Surface * panneau[11], SDL_Rect tableauaffichage)
{

    int decalage = 28;


    SDL_Surface * p[4];

    p[0] = SDL_LoadBMP("images/droit-pied-gauche.bmp");
    p[1] = SDL_LoadBMP("images/droit-pied-droit.bmp");
    p[2] = SDL_LoadBMP("images/droit-pied-gauche.bmp");
    p[3] = SDL_LoadBMP("images/droit.bmp");

    for(int i = 0; i < 4; i++)
    {
        SDL_Delay(50);

        s->perso = p[i];

        if(i == 0)
            s->positionperso.x = s->positionperso.x + decalage + 1;

        else if(i == 3) s->positionperso.x = s->positionperso.x;

        else s->positionperso.x = s->positionperso.x + decalage;

        SDL_SetColorKey(s->perso, SDL_SRCCOLORKEY, SDL_MapRGB(s->perso->format, 255, 255, 255));


        SDL_BlitSurface(s->chambre,NULL,ecran,&s->positionsalle);


        if((s->niveau == 1) || (s->niveau == 0))
        {
            SDL_SetColorKey(s->objet, SDL_SRCCOLORKEY, SDL_MapRGB(s->objet->format, 255, 255, 255));
            SDL_BlitSurface(s->objet,NULL,ecran,&s->positionobjet);

        }

        if((s->niveau%2 == 1) && (s->niveau != 1))
        {
            SDL_SetColorKey(s->ennemi[0], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[0]->format, 255, 255, 255));

            SDL_BlitSurface(s->ennemi[0],NULL,ecran,&s->positionennemi[0]);

            if(s->niveau > 4)
            {

                SDL_SetColorKey(s->ennemi[1], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[1]->format, 255, 255, 255));

                SDL_BlitSurface(s->ennemi[1],NULL,ecran,&s->positionennemi[1]);

            }

            if(s->niveau > 6)
            {

                SDL_SetColorKey(s->ennemi[2], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[2]->format, 255, 255, 255));

                SDL_BlitSurface(s->ennemi[2],NULL,ecran,&s->positionennemi[2]);

            }
        }

        SDL_BlitSurface(panneau[10],NULL,ecran,&tableauaffichage);

        compteur(ecran,score,panneau);

        SDL_BlitSurface(s->perso, NULL, ecran, &s->positionperso);

        SDL_Flip(ecran);
    }

}
