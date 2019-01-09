#include "score.h"

void compteur(SDL_Surface * ecran, int score)
{
    int newscore = score/1000;

    int milliers = newscore/1000;

    int centaines = newscore/100;

    int dizaines = newscore/10;

    int unites = newscore - 1000*milliers - 100*centaines - 10*dizaines;

    SDL_Surface * SCORE[4];

    SDL_Rect positionscore[4];

    //position du score sur l'écran

    positionscore[0].x = 0;

    positionscore[0].y = 0;

    positionscore[1].x = 50;

    positionscore[1].y = 0;

    positionscore[2].x = 100;

    positionscore[2].y = 0;

    positionscore[3].x = 150;

    positionscore[3].y = 0;

    switch (unites)
        {
        case 0:
            SCORE[3] = SDL_LoadBMP("images/score/0.bmp");
            break;

        case 1:
            SCORE[3] = SDL_LoadBMP("images/score/1.bmp");
            break;

        case 2:
            SCORE[3] = SDL_LoadBMP("images/score/2.bmp");
            break;

        case 3:
            SCORE[3] = SDL_LoadBMP("images/score/3.bmp");
            break;

        case 4:
            SCORE[3] = SDL_LoadBMP("images/score/4.bmp");
            break;

        case 5:
            SCORE[3] = SDL_LoadBMP("images/score/5.bmp");
            break;

        case 6:
            SCORE[3] = SDL_LoadBMP("images/score/6.bmp");
            break;

        case 7:
            SCORE[3] = SDL_LoadBMP("images/score/7.bmp");
            break;

        case 8:
            SCORE[3] = SDL_LoadBMP("images/score/8.bmp");
            break;

        case 9:
            SCORE[3] = SDL_LoadBMP("images/score/9.bmp");
            break;

        default:
            break;

        }

    switch (dizaines)
        {
        case 0:
            SCORE[2] = SDL_LoadBMP("images/score/0.bmp");
            break;

        case 1:
            SCORE[2] = SDL_LoadBMP("images/score/1.bmp");
            break;

        case 2:
            SCORE[2] = SDL_LoadBMP("images/score/2.bmp");
            break;

        case 3:
            SCORE[2] = SDL_LoadBMP("images/score/3.bmp");
            break;

        case 4:
            SCORE[2] = SDL_LoadBMP("images/score/4.bmp");
            break;

        case 5:
            SCORE[2] = SDL_LoadBMP("images/score/5.bmp");
            break;

        case 6:
            SCORE[2] = SDL_LoadBMP("images/score/6.bmp");
            break;

        case 7:
            SCORE[2] = SDL_LoadBMP("images/score/7.bmp");
            break;

        case 8:
            SCORE[2] = SDL_LoadBMP("images/score/8.bmp");
            break;

        case 9:
            SCORE[2] = SDL_LoadBMP("images/score/9.bmp");
            break;

        default:
            break;

        }

    switch (centaines)
        {
        case 0:
            SCORE[1] = SDL_LoadBMP("images/score/0.bmp");
            break;

        case 1:
            SCORE[1] = SDL_LoadBMP("images/score/1.bmp");
            break;

        case 2:
            SCORE[1] = SDL_LoadBMP("images/score/2.bmp");
            break;

        case 3:
            SCORE[1] = SDL_LoadBMP("images/score/3.bmp");
            break;

        case 4:
            SCORE[1] = SDL_LoadBMP("images/score/4.bmp");
            break;

        case 5:
            SCORE[1] = SDL_LoadBMP("images/score/5.bmp");
            break;

        case 6:
            SCORE[1] = SDL_LoadBMP("images/score/6.bmp");
            break;

        case 7:
            SCORE[1] = SDL_LoadBMP("images/score/7.bmp");
            break;

        case 8:
            SCORE[1] = SDL_LoadBMP("images/score/8.bmp");
            break;

        case 9:
            SCORE[1] = SDL_LoadBMP("images/score/9.bmp");
            break;

        default:
            break;

        }

    switch (milliers)
        {
        case 0:
            SCORE[0] = SDL_LoadBMP("images/score/0.bmp");
            break;

        case 1:
            SCORE[0] = SDL_LoadBMP("images/score/1.bmp");
            break;

        case 2:
            SCORE[0] = SDL_LoadBMP("images/score/2.bmp");
            break;

        case 3:
            SCORE[0] = SDL_LoadBMP("images/score/3.bmp");
            break;

        case 4:
            SCORE[0] = SDL_LoadBMP("images/score/4.bmp");
            break;

        case 5:
            SCORE[0] = SDL_LoadBMP("images/score/5.bmp");
            break;

        case 6:
            SCORE[0] = SDL_LoadBMP("images/score/6.bmp");
            break;

        case 7:
            SCORE[0] = SDL_LoadBMP("images/score/7.bmp");
            break;

        case 8:
            SCORE[0] = SDL_LoadBMP("images/score/8.bmp");
            break;

        case 9:
            SCORE[0] = SDL_LoadBMP("images/score/9.bmp");
            break;

        default:
            break;

        }



    //on blit tous les panneaux

    for (int ca = 0; ca < 4; ca++)
    {
         SDL_BlitSurface(SCORE[ca],NULL,ecran,&positionscore[ca]);
    }



    SDL_Flip(ecran);//on affiche l'écran

}
