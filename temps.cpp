#include "temps.h"

void compteur(SDL_Surface * ecran, int score, SDL_Surface * panneau[11])
{
    int newscore = (int)score/1000;

    int milliers = (int)(newscore/1000)%10; // premier panneau

    int centaines = (int)(newscore/100)%10;// deuxieme panneau

    int dizaines = (int)(newscore/10)%10;// troisieme panneau

    int unites =(int)((newscore - 1000*milliers - 100*centaines - 10*dizaines))%10; // quatrième panneau

    SDL_Surface * SCORE[5];

    SDL_Rect positionscore[5];

    //position du score sur l'écran

    positionscore[0].x = 16;

    positionscore[0].y = 16;

    positionscore[1].x = 36;

    positionscore[1].y = 16;

    positionscore[2].x = 62;

    positionscore[2].y = 16;

    positionscore[3].x = 82;

    positionscore[3].y = 16;



    switch (unites)
        {
        case 0:
            SCORE[3] = panneau[0];
            break;

        case 1:
            SCORE[3] = panneau[1];
            break;

        case 2:
            SCORE[3] = panneau[2];
            break;

        case 3:
            SCORE[3] = panneau[3];
            break;

        case 4:
            SCORE[3] = panneau[4];
            break;

        case 5:
            SCORE[3] = panneau[5];
            break;

        case 6:
            SCORE[3] = panneau[6];
            break;

        case 7:
            SCORE[3] = panneau[7];
            break;

        case 8:
            SCORE[3] = panneau[8];
            break;

        case 9:
            SCORE[3] = panneau[9];
            break;

        default:
            break;

        }

    switch (dizaines)
        {
        case 0:
            SCORE[2] = panneau[0];
            break;

        case 1:
            SCORE[2] = panneau[1];
            break;

        case 2:
            SCORE[2] = panneau[2];
            break;

        case 3:
            SCORE[2] = panneau[3];
            break;

        case 4:
            SCORE[2] = panneau[4];
            break;

        case 5:
            SCORE[2] = panneau[5];
            break;

        case 6:
            SCORE[2] = panneau[6];
            break;

        case 7:
            SCORE[2] = panneau[7];
            break;

        case 8:
            SCORE[2] = panneau[8];
            break;

        case 9:
            SCORE[2] = panneau[9];
            break;

        default:
            break;

        }

    switch (centaines)
        {
        case 0:
            SCORE[1] = panneau[0];
            break;

        case 1:
            SCORE[1] = panneau[1];
            break;

        case 2:
            SCORE[1] = panneau[2];
            break;

        case 3:
            SCORE[1] = panneau[3];
            break;

        case 4:
            SCORE[1] = panneau[4];
            break;

        case 5:
            SCORE[1] = panneau[5];
            break;

        case 6:
            SCORE[1] = panneau[6];
            break;

        case 7:
            SCORE[1] = panneau[7];
            break;

        case 8:
            SCORE[1] = panneau[8];
            break;

        case 9:
            SCORE[1] = panneau[9];
            break;

        default:
            break;

        }

    switch (milliers)
        {
        case 0:
            SCORE[0] = panneau[0];
            break;

        case 1:
            SCORE[0] = panneau[1];
            break;

        case 2:
            SCORE[0] = panneau[2];
            break;

        case 3:
            SCORE[0] = panneau[3];
            break;

        case 4:
            SCORE[0] = panneau[4];
            break;

        case 5:
            SCORE[0] = panneau[5];
            break;

        case 6:
            SCORE[0] = panneau[6];
            break;

        case 7:
            SCORE[0] = panneau[7];
            break;

        case 8:
            SCORE[0] = panneau[8];
            break;

        case 9:
            SCORE[0] = panneau[9];
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
