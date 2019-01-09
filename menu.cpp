#include "menu.h"

void menu()
{
    int continuer = 1;//boucle du menu (sommaire)

    int temps = 0;//temps passé sur le menu ou le sommaire

    SDL_Surface * ecran = NULL;//fenetre

    SDL_Surface * sommaire = NULL;//la surface du menu

    SDL_Rect positionsommaire;//sa position

    positionsommaire.x = 0;//coordonnée horizontale

    positionsommaire.y = 0;//coordonnée verticale

    SDL_Event evenement;//evenement

    sommaire = SDL_LoadBMP("images/menu.bmp");//logo + onglets

    SDL_Init(SDL_INIT_VIDEO);//affiche la fenetre

    ecran = SDL_SetVideoMode(1024, 768, 32, SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DOUBLEBUF);//taille fenetre

    SDL_WM_SetCaption("escape", NULL);//titre fenetre

    SDL_WM_SetIcon(SDL_LoadBMP("images/logo.bmp"), NULL);//icone fenetre

    SDL_EnableKeyRepeat(250,250);//touche enfoncée

    while (continuer == 1)
    {
        SDL_WaitEvent(&evenement);//on attend ce que le joueur veut faire

        switch(evenement.type)
        {

        case SDL_QUIT://drapeaux suisse (meme si en full screen y'en a pas
            continuer = 0;

            break;

        case SDL_MOUSEBUTTONUP:

            if ((evenement.button.x > 85) && (evenement.button.x < 233) && (evenement.button.y > 238) && (evenement.button.y < 298))
            {
                temps = SDL_GetTicks();
                jouer(ecran,temps);//let's go!!!
            }

            if ((evenement.button.x > 744) && (evenement.button.x < 939) && (evenement.button.y > 327) && (evenement.button.y < 387))
            {
                continuer = 0;
            }


            if ((evenement.button.x > 85) && (evenement.button.x < 277) && (evenement.button.y > 327) && (evenement.button.y < 387))
                regles (ecran);
            continue;

            if ((evenement.button.x > 85) && (evenement.button.x < 233) && (evenement.button.y > 411) && (evenement.button.y < 471))
                continue;

            if ((evenement.button.x > 744) && (evenement.button.x < 939) && (evenement.button.y > 238) && (evenement.button.y < 298))
                break;

        default:
            break;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));//ecran françois

        SDL_BlitSurface(sommaire,NULL,ecran, &positionsommaire);//collage du menu sur ecran

        SDL_Flip(ecran);//affichage de l'écran
    }

    SDL_FreeSurface(sommaire);//suppression du sommaire snif!

    SDL_Quit();//bye bye
}



// Fonction Game Over

void gameOver (SDL_Surface * ecran, salle * salle1)
{
    int continuer = 1;

    int temps = 0;

    SDL_Surface * sommaire_gameOver = NULL;

    SDL_Rect positionsommaire_gameOver;

    positionsommaire_gameOver.x = 0;

    positionsommaire_gameOver.y = 0;

    SDL_Event evenement;//evenement

    // on charge l'image de game over
    sommaire_gameOver = SDL_LoadBMP("images/gameover.bmp");

    while (continuer)
    {

        SDL_WaitEvent(&evenement);


        switch(evenement.type)
        {


        case SDL_MOUSEBUTTONDOWN:

            if ((evenement.button.x > 380) && (evenement.button.x < 680) && (evenement.button.y > 600) && (evenement.button.y < 650))
            {

                    temps = SDL_GetTicks();

                    jouer(ecran,temps);

                    // recommencer


            }

            if ((evenement.button.x > 60) && (evenement.button.x < 180) && (evenement.button.y > 600) && (evenement.button.y < 650))
            {

                menu();
                //menu du jeu
            }
            if ((evenement.button.x > 820) && (evenement.button.x < 960) && (evenement.button.y > 600) && (evenement.button.y < 650))
            {

                continuer = 0;
            }

            break;

        default:
            break;
        }

        SDL_BlitSurface(sommaire_gameOver,NULL,ecran, &positionsommaire_gameOver);

        SDL_Flip(ecran);
    }


    SDL_FreeSurface(sommaire_gameOver);
    //NettoyerLaMemoire(salle1);

    SDL_Quit();

}


void regles (SDL_Surface * ecran)
{
    int continuer = 1;
    int image = 1;

    SDL_Surface * page_regle = NULL;

    SDL_Rect position_page_regle;

    position_page_regle.x = 0;

    position_page_regle.y = 0;

    SDL_Event evenement;//evenement

    // on charge l'image des règles
    page_regle = SDL_LoadBMP("images/regles-1.bmp");


    while (continuer)
    {
        SDL_WaitEvent(&evenement);

        switch(evenement.type)
        {

        case SDL_MOUSEBUTTONUP:

            if ((evenement.button.x > 680) && (evenement.button.x < 850) && (evenement.button.y > 680) && (evenement.button.y < 720) )//&& (page_regle == SDL_LoadBMP("images/regles-1.bmp")))
            {
                if (image == 1)
                {
                    page_regle = SDL_LoadBMP("images/regles-2.bmp");
                    image = 2;
                }
                else if (image == 2)
                {
                    page_regle = SDL_LoadBMP("images/regles-1.bmp");
                    image = 1;
                }
                SDL_BlitSurface(page_regle,NULL,ecran, &position_page_regle);
                SDL_Flip(ecran);

            }
            if ((evenement.button.x > 70) && (evenement.button.x < 450) && (evenement.button.y > 680) && (evenement.button.y < 720))
                return;
            //menu();

            break;

        default:
            break;
        }

        SDL_BlitSurface(page_regle,NULL,ecran, &position_page_regle);

        SDL_Flip(ecran);
    }

    SDL_FreeSurface(page_regle);

    SDL_Quit();

}

void you_Win(SDL_Surface * ecran, int scorefinal) {

int continuer = 1;

    SDL_Surface * page_FIN = NULL;

    SDL_Rect position_page_FIN;

    position_page_FIN.x = 0;

    position_page_FIN.y = 0;

    SDL_Event evenement;  //evenement

    // on charge l'image de Fin
    page_FIN = SDL_LoadBMP("images/fin.bmp");

    int millier =(int)(scorefinal/1000)%10;

    int centaine = (int)(scorefinal/100)%10;

    int dizaine = (int)(scorefinal/10)%10;

    int unite =(int)(scorefinal - 1000*millier - 100*centaine - 10*dizaine)%10;

    SDL_Surface * SF[4];

    SDL_Rect PSF[4];

    PSF[0].x = 460;

    PSF[0].y = 710;

    PSF[1].x = 495;

    PSF[1].y = 710;

    PSF[2].x = 530;

    PSF[2].y = 710;

    PSF[3].x = 565;

    PSF[3].y = 710;


    switch (unite)
        {
        case 0:
            SF[3] = SDL_LoadBMP("images/score/0sang.bmp");
            break;

        case 1:
            SF[3] = SDL_LoadBMP("images/score/1sang.bmp");
            break;

        case 2:
            SF[3] = SDL_LoadBMP("images/score/2sang.bmp");
            break;

        case 3:
            SF[3] = SDL_LoadBMP("images/score/3sang.bmp");
            break;

        case 4:
            SF[3] = SDL_LoadBMP("images/score/4sang.bmp");
            break;

        case 5:
            SF[3] = SDL_LoadBMP("images/score/5sang.bmp");
            break;

        case 6:
            SF[3] = SDL_LoadBMP("images/score/6sang.bmp");
            break;

        case 7:
            SF[3] = SDL_LoadBMP("images/score/7sang.bmp");
            break;

        case 8:
            SF[3] = SDL_LoadBMP("images/score/8sang.bmp");
            break;

        case 9:
            SF[3] = SDL_LoadBMP("images/score/9sang.bmp");
            break;

        default:
            break;

        }

    switch (dizaine)
        {
        case 0:
            SF[2] = SDL_LoadBMP("images/score/0sang.bmp");
            break;

        case 1:
            SF[2] = SDL_LoadBMP("images/score/1sang.bmp");
            break;

        case 2:
            SF[2] = SDL_LoadBMP("images/score/2sang.bmp");
            break;

        case 3:
            SF[2] = SDL_LoadBMP("images/score/3sang.bmp");
            break;

        case 4:
            SF[2] = SDL_LoadBMP("images/score/4sang.bmp");
            break;

        case 5:
            SF[2] = SDL_LoadBMP("images/score/5sang.bmp");
            break;

        case 6:
            SF[2] = SDL_LoadBMP("images/score/6sang.bmp");
            break;

        case 7:
            SF[2] = SDL_LoadBMP("images/score/7sang.bmp");
            break;

        case 8:
            SF[2] = SDL_LoadBMP("images/score/8sang.bmp");
            break;

        case 9:
            SF[2] = SDL_LoadBMP("images/score/9sang.bmp");
            break;

        default:
            break;

        }

    switch (centaine)
        {
        case 0:
            SF[1] = SDL_LoadBMP("images/score/0sang.bmp");
            break;

        case 1:
            SF[1] = SDL_LoadBMP("images/score/1sang.bmp");
            break;

        case 2:
            SF[1] = SDL_LoadBMP("images/score/2sang.bmp");
            break;

        case 3:
            SF[1] = SDL_LoadBMP("images/score/3sang.bmp");
            break;

        case 4:
            SF[1] = SDL_LoadBMP("images/score/4sang.bmp");
            break;

        case 5:
            SF[1] = SDL_LoadBMP("images/score/5sang.bmp");
            break;

        case 6:
            SF[1] = SDL_LoadBMP("images/score/6sang.bmp");
            break;

        case 7:
            SF[1] = SDL_LoadBMP("images/score/7sang.bmp");
            break;

        case 8:
            SF[1] = SDL_LoadBMP("images/score/8sang.bmp");
            break;

        case 9:
            SF[1] = SDL_LoadBMP("images/score/9sang.bmp");
            break;

        default:
            break;

        }

        switch (millier)
        {
        case 0:
            SF[0] = SDL_LoadBMP("images/score/0sang.bmp");
            break;

        case 1:
            SF[0] = SDL_LoadBMP("images/score/1sang.bmp");
            break;

        case 2:
            SF[0] = SDL_LoadBMP("images/score/2sang.bmp");
            break;

        case 3:
            SF[0] = SDL_LoadBMP("images/score/3sang.bmp");
            break;

        case 4:
            SF[0] = SDL_LoadBMP("images/score/4sang.bmp");
            break;

        case 5:
            SF[0] = SDL_LoadBMP("images/score/5sang.bmp");
            break;

        case 6:
            SF[0] = SDL_LoadBMP("images/score/6sang.bmp");
            break;

        case 7:
            SF[0] = SDL_LoadBMP("images/score/7sang.bmp");
            break;

        case 8:
            SF[0] = SDL_LoadBMP("images/score/8sang.bmp");
            break;

        case 9:
            SF[0] = SDL_LoadBMP("images/score/9sang.bmp");
            break;

        default:
            break;

        }

     while (continuer)
    {
        SDL_WaitEvent(&evenement);

        switch(evenement.type)
        {

        case SDL_MOUSEBUTTONUP:

                if ((evenement.button.x > 15) && (evenement.button.x < 170) && (evenement.button.y > 15) && (evenement.button.y < 62))
            {

                continuer = 0;
            }

             break;

        default:
            break;
        }



        SDL_BlitSurface(page_FIN,NULL,ecran, &position_page_FIN);

        for(int i = 0; i<4; i++)
        {
            SDL_SetColorKey(SF[i], SDL_SRCCOLORKEY, SDL_MapRGB(SF[i]->format, 255, 255, 255));

            SDL_BlitSurface(SF[i],NULL,ecran,&PSF[i]);
        }

        SDL_Flip(ecran);
    }


    SDL_FreeSurface(page_FIN);

    SDL_Quit();

}



