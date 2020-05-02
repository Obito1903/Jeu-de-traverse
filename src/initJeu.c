/** @file initJeu.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 19 Apr 2020 16:27
 *
 *  @brief Contient les fonction d'initialisation
 *
 */

#include "initJeu.h"

partie *allocPartie()
{
    partie *partieAlloc = (partie *)malloc(sizeof(partie));
    if (partieAlloc == NULL)
    {
        fprintf(stderr, "Erreur Alloc partie\n");
        exit(EXIT_FAILURE);
    }
    partieAlloc->plateau = (pion ***)malloc(sizeof(pion **) * TAILLEPLATEAU);
    if (partieAlloc->plateau == NULL)
    {
        fprintf(stderr, "Erreur Alloc plateau\n");
        exit(EXIT_FAILURE);
    }
    int int_x;
    int int_y;
    for (int_x = 0; int_x < TAILLEPLATEAU; int_x++)
    {
        partieAlloc->plateau[int_x] = (pion **)malloc(sizeof(pion *) * TAILLEPLATEAU);
        if (partieAlloc->plateau[int_x] == NULL)
        {
            fprintf(stderr, "Erreur D'alloc plateau\n");
            exit(EXIT_FAILURE);
        }

        for (int_y = 0; int_y < TAILLEPLATEAU; int_y++)
        {
            partieAlloc->plateau[int_x][int_y] = NULL;
        }
    }
    partieAlloc->joueurs = (joueur *)malloc(sizeof(joueur) * NBJOUEUR);
    int int_joueur;
    for (int_joueur = 0; int_joueur < NBJOUEUR; int_joueur++)
    {
        partieAlloc->joueurs[int_joueur].pions = (pion *)malloc(sizeof(pion) * NBPIONS);
        int int_pion;
        for (int_pion = 0; int_pion < NBPIONS; int_pion++)
        {
            partieAlloc->joueurs[int_joueur].pions[int_pion].coupsPossibles.Coups = NULL;
        }
    }
    return partieAlloc;
}

void freePartie(partie *partie)
{
    int int_joueur;
    int int_pion;
    for (int_joueur = 0; int_joueur < NBJOUEUR; int_joueur++)
    {
        for (int_pion = 0; int_pion < NBPIONS; int_pion++)
        {
            free(partie->joueurs[int_joueur].pions[int_pion].coupsPossibles.Coups);
        }
        free(partie->joueurs[int_joueur].pions);
    }
    free(partie->joueurs);
    int int_x;
    for (int_x = 0; int_x < TAILLEPLATEAU; int_x++)
    {
        free(partie->plateau[int_x]);
    }
    free(partie->plateau);
    free(partie);
}

typePion defTypePion(int int_i)
{
    typePion type; // Variable de retour
    if (int_i == 0 || int_i == 7)
    {
        type = CAREE;
    }
    else if (int_i == 1 || int_i == 6)
    {
        type = TRIANGLE;
    }
    else if (int_i == 2 || int_i == 5)
    {
        type = LOSANGE;
    }
    else if (int_i == 3 || int_i == 4)
    {
        type = CERCLE;
    }
    return (type);
}

void initDeplacementPion(pion *pion)
{
    int int_i;
    switch (pion->type)
    {
    case TRIANGLE:
        pion->coupsPossibles.nbCoup = 3;
        pion->coupsPossibles.Coups = (deplacement *)malloc(sizeof(deplacement) * 3);
        if (pion->joueur->id == 0)
        {
            pion->coupsPossibles.Coups[0] = D_NORD_EST;
            pion->coupsPossibles.Coups[1] = D_NORD_OUEST;
            pion->coupsPossibles.Coups[2] = D_SUD;
        }
        else
        {
            pion->coupsPossibles.Coups[0] = D_SUD_EST;
            pion->coupsPossibles.Coups[1] = D_SUD_OUEST;
            pion->coupsPossibles.Coups[2] = D_NORD;
        }
        break;
    case LOSANGE:
        pion->coupsPossibles.nbCoup = 4;
        pion->coupsPossibles.Coups = (deplacement *)malloc(sizeof(deplacement) * 4);
        pion->coupsPossibles.Coups[0] = D_SUD_EST;
        pion->coupsPossibles.Coups[1] = D_SUD_OUEST;
        pion->coupsPossibles.Coups[2] = D_NORD_EST;
        pion->coupsPossibles.Coups[3] = D_NORD_OUEST;
        break;
    case CAREE:
        pion->coupsPossibles.nbCoup = 4;
        pion->coupsPossibles.Coups = (deplacement *)malloc(sizeof(deplacement) * 4);
        pion->coupsPossibles.Coups[0] = D_SUD;
        pion->coupsPossibles.Coups[1] = D_OUEST;
        pion->coupsPossibles.Coups[2] = D_EST;
        pion->coupsPossibles.Coups[3] = D_NORD;
        break;
    case CERCLE:
        pion->coupsPossibles.nbCoup = 8;
        pion->coupsPossibles.Coups = (deplacement *)malloc(sizeof(deplacement) * 8);
        for (int_i = 0; int_i < 8; int_i++)
        {
            pion->coupsPossibles.Coups[int_i] = int_i;
        }
        break;
    default:
        break;
    }
}

void initPions(partie *partie, int idJoueur)
{
    int int_i;
    coord coord;
    pion pion;
    if (partie->joueurs[idJoueur].zoneArr == NORD)
    {
        coord.y = TAILLEPLATEAU - 1;
    }
    else
    {
        coord.y = 0;
    }

    for (int_i = 0; int_i < 8; int_i++)
    {
        pion.joueur = &(partie->joueurs[idJoueur]);
        coord.x = int_i + 1;
        pion.type = defTypePion(int_i);
        partie->joueurs[idJoueur].pions[int_i] = pion;
        initDeplacementPion(&partie->joueurs[idJoueur].pions[int_i]);
        placePion(partie, &partie->joueurs[idJoueur].pions[int_i], coord);
    }
}

void defZoneJoueur(partie *partie, int idJoueur)
{
    joueur *joueur = &(partie->joueurs[idJoueur]); // Variable de retour
    joueur->id = idJoueur;
    switch (idJoueur)
    {
    case 0:
        joueur->couleur = ROUGE;
        joueur->zoneArr = NORD;
        break;
    case 1:
        joueur->couleur = BLUE;
        joueur->zoneArr = SUD;
        break;
    default:
        fprintf(stderr, "[deCouleurJoueur]le joeur n'existe pas");
        exit(EXIT_FAILURE);
        break;
    }
}

void initJoueur(partie *partie, int idJoueur)
{
    defZoneJoueur(partie, idJoueur);
    initPions(partie, idJoueur);
    partie->joueurs[idJoueur].inactivite = 0;
}

partie *initPartie(void)
{
    partie *partie = allocPartie(); // Variable de retour
    initJoueur(partie, 0);
    initJoueur(partie, 1);
    printf("init terminer\n");
    partie->joueurCourant = &partie->joueurs[0];
    partie->tour = 0;
    return (partie);
}

partie *copiePartie(partie *partieOriginal)
{
    partie *partiCopie = allocPartie();

    int int_joueur;
    int int_pion;
    for (int_joueur = 0; int_joueur < NBJOUEUR; int_joueur++)
    {
        partiCopie->joueurs[int_joueur].couleur = partieOriginal->joueurs[int_joueur].couleur;
        partiCopie->joueurs[int_joueur].id = partieOriginal->joueurs[int_joueur].id;
        partiCopie->joueurs[int_joueur].inactivite = partieOriginal->joueurs[int_joueur].inactivite;
        partiCopie->joueurs[int_joueur].zoneArr = partieOriginal->joueurs[int_joueur].zoneArr;
        for (int_pion = 0; int_pion < NBPIONS; int_pion++)
        {
            partiCopie->joueurs[int_joueur].pions[int_pion].type = partieOriginal->joueurs[int_joueur].pions[int_pion].type;
            partiCopie->joueurs[int_joueur].pions[int_pion].coord = partieOriginal->joueurs[int_joueur].pions[int_pion].coord;
            partiCopie->joueurs[int_joueur].pions[int_pion].joueur = &partiCopie->joueurs[int_joueur];
            initDeplacementPion(&partiCopie->joueurs[int_joueur].pions[int_pion]);
            placePion(partiCopie, &partiCopie->joueurs[int_joueur].pions[int_pion], partiCopie->joueurs[int_joueur].pions[int_pion].coord);
        }
    }
    partiCopie->joueurCourant = &partiCopie->joueurs[partieOriginal->joueurCourant->id];
    partiCopie->tour = partieOriginal->tour;

    return (partiCopie);
}

void sauvegarde(partie *partie)
{
    mkdir("./Savs", 0700);
    FILE *fichierSauv = fopen("./Savs/sav.bin", "wb");
    int int_joueur;
    int int_pion;
    fwrite(&partie->joueurCourant->id, sizeof(int), 1, fichierSauv);
    fwrite(&partie->tour, sizeof(int), 1, fichierSauv);
    for (int_joueur = 0; int_joueur < NBJOUEUR; int_joueur++)
    {
        fwrite(&partie->joueurs[int_joueur], sizeof(joueur), 1, fichierSauv);
        for (int_pion = 0; int_pion < NBPIONS; int_pion++)
        {
            fwrite(&partie->joueurs[int_joueur].pions[int_pion], sizeof(pion), 1, fichierSauv);
        }
    }
    fclose(fichierSauv);
}

partie *chargeSav(void)
{
    partie *partie = allocPartie(); // Variable de retour
    FILE *fichierSauv;

    fichierSauv = fopen("./Savs/sav.bin", "rb");

    if (fichierSauv == NULL)
    {
        fprintf(stderr, "Le fichier de sauvegarde n'existe pas");
        exit(EXIT_FAILURE);
    }

    int idJoueurCourant;
    fread(&idJoueurCourant, sizeof(int), 1, fichierSauv);
    partie->joueurCourant = &partie->joueurs[idJoueurCourant];

    fread(&partie->tour, sizeof(int), 1, fichierSauv);

    int int_joueur;
    int int_pion;
    for (int_joueur = 0; int_joueur < NBJOUEUR; int_joueur++)
    {
        pion *tmp = partie->joueurs[int_joueur].pions;
        fread(&partie->joueurs[int_joueur], sizeof(joueur), 1, fichierSauv);
        partie->joueurs[int_joueur].pions = tmp;
        free(tmp);

        for (int_pion = 0; int_pion < NBPIONS; int_pion++)
        {
            fread(&partie->joueurs[int_joueur].pions[int_pion], sizeof(pion), 1, fichierSauv);
            partie->joueurs[int_joueur].pions[int_pion].joueur = &partie->joueurs[int_joueur];
            initDeplacementPion(&partie->joueurs[int_joueur].pions[int_pion]);
            placePion(partie, &partie->joueurs[int_joueur].pions[int_pion], partie->joueurs[int_joueur].pions[int_pion].coord);
        }
    }
    fclose(fichierSauv);
    return (partie);
}
