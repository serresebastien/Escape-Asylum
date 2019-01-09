
#include "jeu.h"

void jouer(SDL_Surface * ecran, int temps)
{
    int score = 0, tempstotal = 0;//score : score affiché | tempstotal: temps depuis run and compilation

    int loose;

    int scorefinal;

    int ok = 0; // gère la rotation des Ennemis 2 et 3

    int tempsa = 0, tempsp = 0, tempsP_rotation = 0;//compteurs pour bouger l'IA

    salle * salle1 = initsalle();//premiere salle

    salle1->enigme = 10;//pour aller dans le premier couloir

    SDL_Surface *enigme = NULL;

    SDL_Rect positionenigme;//position de l'énigme

    SDL_Event event;//evenement

    int continuer = 1;// boucle du jeu

    int continuerEnigme =1;//boucle de l'énigme

    int engm[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};

    int nbenigme;

    int reponse[15] = {0,0,0,1,1,1,1,1,0,1,1,0,0,0,0};

    int NiveauMax = NM;//niveau maximale jusqu'à dernière salle

    // on charge juste une fois les images
    SDL_Surface * joueurdos = NULL;

    joueurdos = SDL_LoadBMP("images/dos.bmp");

    SDL_Surface * joueurface = NULL;

    joueurface = SDL_LoadBMP("images/face.bmp");

    SDL_Surface * joueurgauche = NULL;

    joueurgauche = SDL_LoadBMP("images/gauche.bmp");

    SDL_Surface * joueurdroite = NULL;

    joueurdroite = SDL_LoadBMP("images/droit.bmp");

    SDL_Surface * pause = NULL;

    pause = SDL_LoadBMP("images/pause.bmp");

    SDL_Surface * deuxportes = NULL;

    deuxportes = SDL_LoadBMP("images/salle-2portes.bmp");

    SDL_Surface * finale = NULL;

    finale =SDL_LoadBMP("images/salle-fin.bmp");

    SDL_Surface * bonus = NULL;

    bonus = SDL_LoadBMP("images/salle-bonus.bmp");

    // panneau d'affichage

    SDL_Surface * panneau[11];

    panneau[0] = SDL_LoadBMP("images/score/0.bmp");
    panneau[1] = SDL_LoadBMP("images/score/1.bmp");
    panneau[2] = SDL_LoadBMP("images/score/2.bmp");
    panneau[3] = SDL_LoadBMP("images/score/3.bmp");
    panneau[4] = SDL_LoadBMP("images/score/4.bmp");
    panneau[5] = SDL_LoadBMP("images/score/5.bmp");
    panneau[6] = SDL_LoadBMP("images/score/6.bmp");
    panneau[7] = SDL_LoadBMP("images/score/7.bmp");
    panneau[8] = SDL_LoadBMP("images/score/8.bmp");
    panneau[9] = SDL_LoadBMP("images/score/9.bmp");
    panneau[10] = SDL_LoadBMP("images/score/score.bmp");

    SDL_Rect tableauaffichage;

    tableauaffichage.x = 11;

    tableauaffichage.y = 11;


    SDL_Init(SDL_INIT_VIDEO);//affiche la fenetre

    while (continuer)
    {

        ofstream Fichier("score.txt",std::ofstream::out|std::ofstream::trunc);//fichier où l'on notera le score actuel et le meilleur score

        tempstotal = SDL_GetTicks();

        score = tempstotal - temps;//temps : temps du menu

        Fichier << score << endl;//on met le score dans le fichier

        if ((salle1->niveau%2 == 0) || (salle1->nombreporte == 2))
            salle1->enigme = 10;

        if (salle1->chambre == bonus)
            salle1->nombreporte = 1;

        SDL_PollEvent(&event);//attente d un evenement

        if ((salle1->niveau%2 == 1)&&(salle1->niveau != 1))
        {
            tempsa = SDL_GetTicks();

            if(tempsa - tempsp > 1000)
            {
                loose = Ennemi_1 (ecran,salle1);//deplacement de l'ennemi EN TEMPS REEL

                if (loose)
                    gameOver(ecran, salle1);

                tempsp = tempsa;
            }

            if (tempsa - tempsP_rotation > 2000 + rand()%2000)
            {
                if (salle1->niveau >4)
                {
                    loose = Ennemi_2(ecran,salle1,ok);//deplacement deuxieme ia


                    if (loose)
                        gameOver(ecran, salle1);

                    if (salle1->niveau >6)
                        loose = Ennemi_3(ecran,salle1,ok);//deplacement troisieme ia


                    if (loose)
                        gameOver(ecran, salle1);


                    tempsP_rotation = tempsa;
                    ok ++;
                }

            }

            loose = TestVision (ecran,salle1);

            if (loose)
                gameOver(ecran, salle1);

        }


        int tempsc = 0, tempsd = 0;
        tempsc = SDL_GetTicks();

        if (tempsc - tempsd > 1000)
        {
            compteur(ecran,score,panneau);//affichage du score EN TEMPS REEL

            tempsd = tempsc;
        }

        switch(event.type)
        {

        case SDL_QUIT://croix rouge pour quitter

            Fichier << score << endl;//on met le score dans le fichier

            continuer = 0;

            break;

        case SDL_KEYDOWN:

            switch (event.key.keysym.sym)
            {

            case SDLK_ESCAPE://bouton echap
            {

                Fichier << score << endl;//on met le score dans le fichier

                int tmpscore = score;

                int continuerpause = 1;

                SDL_Surface *stop = NULL;

                SDL_Rect positionstop;

                stop = pause;

                positionstop.x = 0;

                positionstop.y = 0;

                SDL_Event EVENT;

                while (continuerpause)
                {
                    SDL_WaitEvent(&EVENT);

                    switch(EVENT.type)
                    {

                    case SDL_MOUSEBUTTONUP:
                    {

                        if ((EVENT.button.x > 30) && (EVENT.button.x < 775) && (EVENT.button.y > 60) && (EVENT.button.y < 140))
                        {
                            score = tmpscore;

                            continuerpause = 0;

                            //reprendre
                        }

                        if ((EVENT.button.x > 30) && (EVENT.button.x < 400 ) && (EVENT.button.y > 315) && (EVENT.button.y < 415))
                        {
                            menu();

                            //menu du jeu

                        }

                        if ((EVENT.button.x > 30) && (EVENT.button.x < 985 ) && (EVENT.button.y > 590) && (EVENT.button.y < 675))
                        {
                            jouer(ecran,tempstotal);

                            //recommencer
                        }

                        break;
                    }

                    default :
                        break;

                    }

                    SDL_BlitSurface(stop,NULL,ecran,&positionstop);

                    SDL_Flip(ecran);

                }
                SDL_FreeSurface(stop);

                break;
            }

            case SDLK_UP://fleche du haut

                salle1->perso = joueurdos;//upload image

                if((salle1->positionperso.x == salle1->positionennemi[0].x) && (salle1->positionperso.y == salle1->positionennemi[0].y + N))
                    continue;

                if( (salle1->niveau > 4) && (salle1->positionperso.x == salle1->positionennemi[1].x) && (salle1->positionperso.y == salle1->positionennemi[1].y + N))
                    continue;

                if( (salle1->niveau > 6) && (salle1->positionperso.x == salle1->positionennemi[2].x) && (salle1->positionperso.y == salle1->positionennemi[2].y + N))
                    continue;

                if ((salle1->positionperso.x == 9*N ) && (salle1->positionperso.y == N) && (salle1->niveau == NiveauMax))
                {
                    scorefinal = score/1000;
                    you_Win(ecran,scorefinal);
                }


                if ( (salle1->niveau < 2) && (salle1->positionperso.x >= salle1->positionobjet.x) && (salle1->positionperso.x <= salle1->positionobjet.x + salle1->objet->w - N) && (salle1->positionperso.y == salle1->positionobjet.y + salle1->objet->h))
                    continue;//objet

                if ((salle1->positionperso.x == 5*N) && (salle1->positionperso.y == N) && (salle1->niveau == NiveauMax))
                    continue;//derniere salle donc pas de porte suivante

                if ((salle1->positionperso.x == 6*N) && (salle1->positionperso.y == N) && (salle1->niveau == NiveauMax))
                    continue;//pareil que la ligne du dessus

                if ((salle1->positionperso.x == 5*N) && (salle1->positionperso.y == N) && (salle1->niveau != 0) && (salle1->niveau != NiveauMax))
                {
                    if (salle1->enigme == 10)//si on est allé dans la salle bonus ou si y'en avait pas
                    {
                        if(salle1->suivante == NULL)
                            creersallesuivante(salle1);

                        salle1 = salle1->suivante;//on va à la salle suivante

                        if(salle1->niveau == NiveauMax - 2)
                            salle1->nombreporte = 2;//avant dernière salle

                        if (salle1->niveau == NiveauMax - 2)
                            salle1->chambre = deuxportes;// salle sans bonus

                        if (salle1->niveau == NiveauMax)
                            salle1->chambre = finale;//on charge l'image de la salle finale

                        salle1->perso = joueurdos;//on met le personnage de dos

                        //on initialise ses nouvelles positions

                        salle1->positionperso.x = 5*N;

                        salle1->positionperso.y = 8*N;
                    }
                }

                if ((salle1->positionperso.x == 6*N) && (salle1->positionperso.y == N) && (salle1->niveau != 0) && (salle1->niveau != NiveauMax))
                {
                    if (salle1->enigme == 10)//si on est allé dans la salle bonus ou si y'en avait pas
                    {
                        if(salle1->suivante == NULL)
                            creersallesuivante(salle1);


                        salle1 = salle1->suivante;//on va à la salle suivante

                        if(salle1->niveau == NiveauMax - 2)
                            salle1->nombreporte = 2;//avant dernière salle

                        if (salle1->niveau == NiveauMax - 2)
                            salle1->chambre = deuxportes;//salle sans bonus

                        if (salle1->niveau == NiveauMax)
                            salle1->chambre = finale;//on charge l'image de la salle finale

                        salle1->perso = joueurdos;//on met le personnage de dos

                        //on initialise ses nouvelles positions

                        salle1->positionperso.x = 6*N;

                        salle1->positionperso.y = 8*N;
                    }
                }

                if (salle1->positionperso.y < 2*N)
                    continue;//mur

                else
                    mouvhaut(salle1,ecran,score,panneau,tableauaffichage);//on bouge vers le haut

                break;

            case SDLK_DOWN://fleche du bas

                salle1->perso = joueurface;//upload de l'image

                if((salle1->positionperso.x == salle1->positionennemi[0].x) && (salle1->positionperso.y == salle1->positionennemi[0].y - N))
                    continue;

                if( (salle1->niveau > 4) &&  (salle1->positionperso.x == salle1->positionennemi[1].x) && (salle1->positionperso.y == salle1->positionennemi[1].y - N))
                    continue;

                if( (salle1->niveau > 6) &&  (salle1->positionperso.x == salle1->positionennemi[2].x) && (salle1->positionperso.y == salle1->positionennemi[2].y - N))
                    continue;

                if ( (salle1->niveau < 2) && (salle1->positionperso.y == salle1->positionobjet.y - N) && (salle1->positionperso.x >= salle1->positionobjet.x) && (salle1->positionperso.x <= salle1->positionobjet.x + salle1->objet->w - N))
                    continue;//objet

                if ((salle1->positionperso.x == 5*N) && (salle1->positionperso.y == 7*N) && (salle1->niveau != 0))
                {
                    if (salle1->niveau == 1)
                        continue;

                    else
                    {
                        salle1 = salle1->precedente;//on retourne à la salle precédente

                        salle1->positionperso.x = 5*N;

                        salle1->positionperso.y = 0;

                        salle1->perso = joueurface;//upload de l'image
                    }
                }

                if ((salle1->positionperso.x == 6*N) && (salle1->positionperso.y == 7*N) && (salle1->niveau != 0))
                {
                    if (salle1->niveau == 1)
                        continue;

                    else
                    {
                        salle1 = salle1->precedente;//on retourne à la salle précédente

                        salle1->positionperso.x = 6*N;

                        salle1->positionperso.y = 0;

                        salle1->perso = joueurface;//:upload de l'image
                    }
                }

                if (salle1->positionperso.y > ecran->h - N - 2*salle1->perso->h )
                    continue;//mur

                else
                    mouvbas(salle1,ecran,score,panneau,tableauaffichage);//on bouge vers le bas

                break;

            case SDLK_LEFT://fleche de gauche

                salle1->perso = joueurgauche;//upload de l'image

                if((salle1->positionperso.x == salle1->positionennemi[0].x + N) && (salle1->positionperso.y == salle1->positionennemi[0].y))
                    continue;

                if ((salle1->niveau == 1) && (salle1->positionperso.x == N) && (salle1->positionperso.y == 4*N))
                    continue;

                if ((salle1->niveau%2 == 0) && (salle1->positionperso.x == 5*N) && (salle1->niveau != 0))
                    continue;//mur

                if ( (salle1->niveau < 2) && (salle1->positionperso.x == salle1->positionobjet.x + salle1->objet->w) && (salle1->positionperso.y >= salle1->positionobjet.y) && (salle1->positionperso.y <= salle1->positionobjet.y + salle1->objet->h - N))
                    continue;//objet

                if ((salle1->niveau == 0) && (salle1->positionperso.x == N) && (salle1->positionperso.y == 4*N))
                {
                    salle1 = salle1->precedente;//on retourne à la salle précédente

                    salle1->enigme = 10;//du coup la porte est ouverte

                    salle1->positionperso.x = 11*N;

                    salle1->positionperso.y = 4*N;

                    salle1->perso = joueurgauche;//upload de l'image

                    ok++;

                }

                if (salle1->positionperso.x < N + salle1->perso->w)
                    continue;//mur

                else
                    mouvgauche(salle1,ecran,score,panneau,tableauaffichage);//on bouge vers la gauche

                break;


            case SDLK_RIGHT://fleche de droite

                salle1->perso = joueurdroite;//upload de l'image

                if( (salle1->niveau > 4) && (salle1->positionperso.x == salle1->positionennemi[1].x - N) && (salle1->positionperso.y == salle1->positionennemi[1].y))
                    continue;

                if(  (salle1->niveau > 6) &&  (salle1->positionperso.x == salle1->positionennemi[2].x - N) && (salle1->positionperso.y == salle1->positionennemi[2].y))
                    continue;

                if ((salle1->niveau%2 == 0) && (salle1->positionperso.x == 6*N) && (salle1->niveau != 0))
                    continue;//mur

                if ((salle1->nombreporte == 3) && (salle1->positionperso.x == 10*N) && (salle1->positionperso.y == 4*N) && (salle1->niveau != 1) && (salle1->niveau != 0))
                {
                    creersallebonus(salle1);

                    salle1 = salle1->sallebonus;//on bouge à la salle bonus

                    salle1->chambre = bonus;//upload de l'image

                    salle1->enigme = 10;// en conséquence, on pourra revenir vers la salle d'avant
                }

                if ( (salle1->niveau < 2) && (salle1->enigme) && (salle1->positionperso.x == salle1->positionobjet.x - N) && (salle1->positionperso.y >= salle1->positionobjet.y) && (salle1->positionperso.y <= salle1->positionobjet.y + salle1->objet->h - N))
                    continue;//objet

                if (salle1->positionperso.x > ecran->w - N - 2*salle1->perso->w)
                    continue;//mur

                if ((salle1->positionperso.x == 10*N) && (salle1->positionperso.y == 4*N) && (salle1->niveau == 1))
                    continue;//mur

                else
                    mouvdroite(salle1,ecran,score,panneau,tableauaffichage);//on bouge vers la droite

                break;

            case SDLK_e ://enigme

                if ((((salle1->positionperso.x == 5*N) && (salle1->positionperso.y ==5*N)) || ((salle1->positionperso.x == 5*N) && (salle1->positionperso.y == 3*N)) || ((salle1->positionperso.x == 4*N) && (salle1->positionperso.y == 4*N)) || ((salle1->positionperso.x == 6*N) && (salle1->positionperso.y == 4*N))) && (salle1->niveau == 0))
                {
                    nbenigme = engm[rand()%15];

                    while (nbenigme == 16)
                    {
                        nbenigme = engm[rand()%15];
                    }

                    switch (nbenigme)
                    {

                    case 0 :
                        enigme = SDL_LoadBMP("images/enigmes/1.bmp");

                        break;

                    case 1:
                        enigme = SDL_LoadBMP("images/enigmes/2.bmp");

                        break;

                    case 2:
                        enigme = SDL_LoadBMP("images/enigmes/3.bmp");

                        break;

                    case 3:
                        enigme = SDL_LoadBMP("images/enigmes/4.bmp");

                        break;

                    case 4 :
                        enigme = SDL_LoadBMP("images/enigmes/5.bmp");

                        break;

                    case 5:
                        enigme = SDL_LoadBMP("images/enigmes/6.bmp");

                        break;

                    case 6:
                        enigme = SDL_LoadBMP("images/enigmes/7.bmp");

                        break;

                    case 7:
                        enigme = SDL_LoadBMP("images/enigmes/8.bmp");

                        break;
                    case 8 :
                        enigme = SDL_LoadBMP("images/enigmes/9.bmp");

                        break;

                    case 9 :
                        enigme = SDL_LoadBMP("images/enigmes/10.bmp");

                        break;
                    case 10 :
                        enigme = SDL_LoadBMP("images/enigmes/11.bmp");

                        break;
                    case 11 :
                        enigme = SDL_LoadBMP("images/enigmes/12.bmp");

                        break;
                    case 12 :
                        enigme = SDL_LoadBMP("images/enigmes/13.bmp");

                        break;
                    case 13 :
                        enigme = SDL_LoadBMP("images/enigmes/14.bmp");

                        break;
                    case 14 :
                        enigme = SDL_LoadBMP("images/enigmes/15.bmp");

                        break;

                    default:

                        break;
                    }

                    engm[nbenigme] = 16;

                    positionenigme.x = ecran->w /2 - enigme->w /2;

                    positionenigme.y = ecran->h /2 - enigme->h /2;

                    SDL_BlitSurface (enigme,NULL,ecran,&positionenigme);//:on colle l'énigme sur l'écran

                    SDL_Flip(ecran);//on affiche l'écran

                    while (continuerEnigme)
                    {
                        SDL_WaitEvent(&event);

                        switch(event.type)
                        {

                        case SDL_KEYDOWN:

                            switch(event.key.keysym.sym)
                            {

                            case SDLK_q://réponse a

                                /*(bonne réponse)*/
                                if (reponse[nbenigme] == 0)
                                    NiveauMax = NiveauMax - 2;//moins de salles au total donc temps plus bas donc score plus haut

                                /* muvaise reponse */
                                else if (reponse[nbenigme] == 1)
                                    NiveauMax = NiveauMax + 2;

                                salle1->enigme = 10;

                                salle1->precedente->enigme = 10;

                                continuerEnigme = 0;

                                SDL_FreeSurface(enigme);//on supprime l'énigme

                                break;

                            case SDLK_b://reponse b

                               /* mauvaise réponse*/
                                if (reponse[nbenigme] == 0)
                                    NiveauMax = NiveauMax + 2;//plus de salles donc temps plus haut donc score plus faible

                                /* bonne rponse*/
                                else if (reponse[nbenigme] == 1)
                                    NiveauMax = NiveauMax - 2;

                                salle1->enigme = 10;

                                salle1->precedente->enigme = 10;

                                continuerEnigme = 0;

                                SDL_FreeSurface(enigme);//on supprime l'énigme

                                break;

                            default:
                                break;
                            }

                            break;
                        }
                    }

                    if ((salle1->positionperso.x == 6*N) && (salle1->positionperso.y == N) && (salle1->niveau == NiveauMax))
                        continue;//mur

                    continuerEnigme = 1;
                }

                break;
            }

            break;

        default :
            break;
        }

        //on enleve tout le blanc des images .bmp

        SDL_SetColorKey(salle1->perso, SDL_SRCCOLORKEY, SDL_MapRGB(salle1->perso->format, 255, 255, 255));//decoloration du personnage

        if ((salle1->niveau == 1) || (salle1->ennemi == NULL))
            SDL_SetColorKey(salle1->objet, SDL_SRCCOLORKEY, SDL_MapRGB(salle1->objet->format, 255, 255, 255));//decoloration de l'objet

        if ((salle1->niveau != 1) && (salle1->chambre != bonus) && (salle1->niveau %2 == 1))//décoloration des ennemis
        {
            SDL_SetColorKey(salle1->ennemi[0], SDL_SRCCOLORKEY, SDL_MapRGB(salle1->ennemi[0]->format, 255, 255, 255));

            if(salle1->niveau > 4)
                SDL_SetColorKey(salle1->ennemi[1], SDL_SRCCOLORKEY, SDL_MapRGB(salle1->ennemi[1]->format, 255, 255, 255));

            if(salle1->niveau > 6)
                SDL_SetColorKey(salle1->ennemi[2], SDL_SRCCOLORKEY, SDL_MapRGB(salle1->ennemi[2]->format, 255, 255, 255));
        }

        //on colle les images sur la fenetre

        //ps: d abord perso puis objet sinon le matelas cache le personage lorsque le personnage est en dessous de l'objet

        SDL_BlitSurface(salle1->chambre, NULL, ecran, &salle1->positionsalle);//blitage de la chambre

        if ((salle1->niveau == 1) || (salle1->niveau == 0))

            SDL_BlitSurface(salle1->objet, NULL, ecran, &salle1->positionobjet);//blitage de l'objet

        if ((salle1->niveau != 1) && (salle1->chambre != bonus) && (salle1->niveau %2 == 1))
        {
            SDL_BlitSurface(salle1->ennemi[0], NULL, ecran, &salle1->positionennemi[0]);//blitage de l'ennemi

            if(salle1->niveau > 4)
                SDL_BlitSurface(salle1->ennemi[1], NULL, ecran, &salle1->positionennemi[1]);

            if(salle1->niveau > 6)
                SDL_BlitSurface(salle1->ennemi[2], NULL, ecran, &salle1->positionennemi[2]);

        }

        SDL_BlitSurface(panneau[10],NULL,ecran,&tableauaffichage);

        SDL_BlitSurface(salle1->perso, NULL, ecran, &salle1->positionperso);//blitage du perso

        //actualisation de l'ecran.

        SDL_Flip(ecran);

        Fichier.close();//on ferme le dossier des scores


    }

   // le nettoyage de la memoire !

    SDL_FreeSurface(joueurdos);
    SDL_FreeSurface(joueurface);
    SDL_FreeSurface(joueurdroite);
    SDL_FreeSurface(joueurgauche);

    NettoyerLaMemoire(salle1);

    //on quitte =(
    SDL_Quit();
}
