
#include "IA.h"

int Ennemi_1 (SDL_Surface * ecran, salle * s)
{



    int action = rand()%3;
    int tempsActuel = SDL_GetTicks();
    int tempsPrecedent = 0;

    if (action == 1 && s->positionennemi[0].y < ecran->h - 3*N)
    {
        if (tempsActuel - tempsPrecedent > 500)
        {
            SDL_FreeSurface(s->ennemi[0]);
            s->ennemi[0] = SDL_LoadBMP("images/ennemi-face.bmp");
            s->posEnnemi[0] = BAS;
            s->positionennemi[0].y = s->positionennemi[0].y + N;
            tempsPrecedent = tempsActuel;

        }
        if ((s->positionennemi[0].x == s->positionperso.x) && ( s->positionennemi[0].y < s->positionperso.y ))
        {

            SDL_SetColorKey(s->ennemi[0], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[0]->format,255,255,255));
            SDL_BlitSurface(s->ennemi[0],NULL,ecran, &s->positionennemi[0]);
            SDL_Flip(ecran);
            return 1;

        }
    }

    else if (action == 2 && s->positionennemi[0].y != N)
    {
        if (tempsActuel - tempsPrecedent > 500)
        {
            SDL_FreeSurface(s->ennemi[0]);
            s->ennemi[0] = SDL_LoadBMP("images/ennemi-dos.bmp");
            s->posEnnemi[0] = HAUT;
            s->positionennemi[0].y = s->positionennemi[0].y - N;
            tempsPrecedent = tempsActuel;
        }

        if ((s->positionennemi[0].x == s->positionperso.x) && ( s->positionennemi[0].y > s->positionperso.y ))
        {

            SDL_SetColorKey(s->ennemi[0], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[0]->format,255,255,255));
            SDL_BlitSurface(s->ennemi[0],NULL,ecran, &s->positionennemi[0]);
            SDL_Flip(ecran);
            return 1;

        }

    }

    else
    {
        if (tempsActuel - tempsPrecedent > 1000 + rand()%5000)
        {
            SDL_FreeSurface(s->ennemi[0]);
            s->ennemi[0] = SDL_LoadBMP("images/ennemi-droit.bmp");
            s->posEnnemi[0] = DROITE;
            SDL_SetColorKey(s->ennemi[0], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[0]->format,255,255,255));
            SDL_BlitSurface (s->ennemi[0], NULL, ecran,&s->positionennemi[0]);
            tempsPrecedent = tempsActuel;

        }


        if (s->positionennemi[0].y == s->positionperso.y)
        {

            SDL_SetColorKey(s->ennemi[0], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[0]->format,255,255,255));
            SDL_BlitSurface(s->ennemi[0],NULL,ecran, &s->positionennemi[0]);
            SDL_Flip(ecran);
            return 1;

        }
    }

    return 0;
}

/***Ennemi 2 ***/


int Ennemi_2 (SDL_Surface * ecran, salle *s, int ok)
{
    //ok%2 = 0 face
    //ok%2 = 1 gauche

    if (ok%2 == 0)
    {


        s->ennemi[1] = SDL_LoadBMP("images/ennemi-gauche.bmp");
        s->posEnnemi[1] = GAUCHE;
        SDL_SetColorKey(s->ennemi[1], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[1]->format,255,255,255));
        SDL_BlitSurface(s->ennemi[1],NULL,ecran, &s->positionennemi[1]);
        SDL_Flip(ecran);

/*verifier si l'ennemi voit l' perso au moment ou il change de position*/
        /** Evite les probleme de latence du a TestVision (de l'ordre de quelques ms)*/
        if (s->positionennemi[1].y == s->positionperso.y)
        {
            return 1;
        }


    }

    else
    {

        s->ennemi[1] = SDL_LoadBMP("images/ennemi-face.bmp");
        s->posEnnemi[1] = BAS;
        SDL_SetColorKey(s->ennemi[1], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[1]->format,255,255,255));
        SDL_BlitSurface(s->ennemi[1],NULL,ecran, &s->positionennemi[1]);
        SDL_Flip(ecran);

/*verifier si l'ennemi voit l' perso au moment ou il change de position*/
        /** Evite les probleme de latence du a TestVision (de l'ordre de quelques ms)*/
        if ((s->positionennemi[1].x == s->positionperso.x) && ( s->positionennemi[1].y < s->positionperso.y))
        {

            return 1;
        }
    }


    return 0;
}




/** Ennemi 3 **/

int Ennemi_3 (SDL_Surface * ecran, salle *s, int ok)
{
    //ok%2 = 0 face
    //ok%2 = 1 gauche

    if (ok%2 == 0)
    {


        s->ennemi[2] = SDL_LoadBMP("images/ennemi-gauche.bmp");
        s->posEnnemi[2] = GAUCHE;
        SDL_SetColorKey(s->ennemi[2], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[2]->format,255,255,255));
        SDL_BlitSurface(s->ennemi[2],NULL,ecran, &s->positionennemi[2]);
        SDL_Flip(ecran);

/*verifier si l'ennemi voit l' perso au moment ou il change de position*/
        /** Evite les probleme de latence du a TestVision (de l'ordre de quelques ms)*/
        if (s->positionennemi[2].y == s->positionperso.y)
        {
            return 1;
        }


    }

    else
    {

        s->ennemi[2] = SDL_LoadBMP("images/ennemi-dos.bmp");
        s->posEnnemi[2] = HAUT;
        SDL_SetColorKey(s->ennemi[2], SDL_SRCCOLORKEY, SDL_MapRGB(s->ennemi[2]->format,255,255,255));
        SDL_BlitSurface(s->ennemi[2],NULL,ecran, &s->positionennemi[2]);
        SDL_Flip(ecran);

        /*verifier si l'ennemi voit l' perso au moment ou il change de position*/
        /** Evite les probleme de latence du a TestVision (de l'ordre de quelques ms)*/
        if ((s->positionennemi[2].x == s->positionperso.x) && ( s->positionennemi[2].y > s->positionperso.y))
        {

            return 1;
        }
    }


    return 0;
}




/**  Verifier si l'ennemi nous voit **/

int TestVision( SDL_Surface * ecran, salle *salle1 )
{



    if (
        (  (salle1->positionennemi[0].y == salle1->positionperso.y) &&  (salle1->posEnnemi[0] == DROITE) )
        ||
        ( (salle1->positionennemi[0].x == salle1->positionperso.x) && ( salle1->positionennemi[0].y < salle1->positionperso.y ) && (salle1->posEnnemi[0] == BAS) )
        ||
        (  (salle1->positionennemi[0].x == salle1->positionperso.x) && ( salle1->positionennemi[0].y > salle1->positionperso.y ) && (salle1->posEnnemi[0] == HAUT)  )
    )
        return 1;

    if (salle1->niveau > 4)
    {


        if ( ( (salle1->positionennemi[1].y == salle1->positionperso.y) &&  (salle1->posEnnemi[1] == GAUCHE) )
                ||
                ( (salle1->positionennemi[1].x == salle1->positionperso.x) && ( salle1->positionennemi[1].y < salle1->positionperso.y) && ( salle1->posEnnemi[1] == BAS )  )

           )
            return 1;

    }

    if (salle1->niveau > 6)
    {


        if ( ( (salle1->positionennemi[2].y == salle1->positionperso.y) &&  (salle1->posEnnemi[2] == GAUCHE) )
                ||
                ( (salle1->positionennemi[2].x == salle1->positionperso.x) && ( salle1->positionennemi[2].y > salle1->positionperso.y) && ( salle1->posEnnemi[2] == HAUT )  )

           )
            return 1;

    }



    return 0;

}
