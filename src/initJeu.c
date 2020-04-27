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
    partie *partie = malloc(sizeof(partie));
    partie->plateau = malloc(sizeof(pion **) * TAILLEPLATEAU);
    int int_x;
    for (int_x = 0; int_x < TAILLEPLATEAU; int_x++)
    {
        partie->plateau[int_x] = malloc(sizeof(pion *) * TAILLEPLATEAU);
    }

    partie->joueurs = malloc(sizeof(joueur) * NBJOUEUR);
    int int_joueur;
    for (int_joueur = 0; int_joueur < NBJOUEUR; int_joueur++)
    {
        partie->joueurs[int_joueur].pions = malloc(sizeof(pion) * NBPIONS);
    }
    return partie;
}

void freePartie(partie *partie)
{
    int int_pion;
    int int_joueur;
    for (int_joueur = 0; int_joueur < NBJOUEUR; int_joueur++)
    {
        for (int_pion = 0; int_pion < NBPIONS; int_pion++)
        {
            free(partie->joueurs[int_joueur].pions);
        }
    }
    free(partie->joueurs);
    int int_x;
    for (int_x = 0; int_x < TAILLEPLATEAU; int_x++)
    {
        free(partie->plateau[int_x]);
    }
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
        partiCopie->joueurs[int_joueur] = partieOriginal->joueurs[int_joueur];
        for (int_pion = 0; int_pion < NBPIONS; int_pion++)
        {
            partiCopie->joueurs[int_joueur].pions[int_pion] = partieOriginal->joueurs[int_joueur].pions[int_pion];
            partiCopie->joueurs[int_joueur].pions[int_pion].joueur = &partiCopie->joueurs[int_joueur];
            placePion(partiCopie, &partiCopie->joueurs[int_joueur].pions[int_pion], partiCopie->joueurs[int_joueur].pions[int_pion].coord);
        }
    }
    partiCopie->joueurCourant = &partiCopie->joueurs[partieOriginal->joueurCourant->id];
    partiCopie->tour = partieOriginal->tour;

    return (partiCopie);
}

void sauvegarde(partie *partie)
{
    FILE *fichierSauv;
    mkdir("./Savs", 0700);
    fichierSauv = fopen("./Savs/sav.bin", "wb");
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
            placePion(partie, &partie->joueurs[int_joueur].pions[int_pion], partie->joueurs[int_joueur].pions[int_pion].coord);
        }
    }

    return (partie);
}
