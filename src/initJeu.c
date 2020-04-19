/** @file initJeu.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 19 Apr 2020 16:27
 *
 *  @brief Contient les fonction d'initialisation
 *
 */

#include "initJeu.h"

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 19 Apr 2020 17:08
 *
 *  @brief Alloue l'espace memoire de la partie
 *
 *  @param[in]
 *  @return
 *
 */
partie *allocPartie(void)
{
    partie *partie = malloc(sizeof(partie)); // Variable de retour
    partie->joueurs = malloc(sizeof(joueur) * NBJOUEUR);
    int int_joueur;
    int int_pion;
    for (int_joueur = 0; int_joueur < NBJOUEUR; int_joueur++)
    {
        partie->joueurs[int_joueur].pions = malloc(sizeof(pion) * NBPIONS);

        for (int_pion = 0; int_pion < NBPIONS; int_pion++)
        {
            partie->joueurs[int_joueur].pions[int_pion].joueur = &partie->joueurs[int_joueur];
        }
    }

    //partie->plateau = malloc(sizeof())

    return (partie);
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
        pion.joueur = &partie->joueurs[idJoueur];
        pion.coord.x = int_i + 1;
        pion.type = defTypePion(int_i);
        placePion(partie, idJoueur, int_i, coord);
        partie->joueurs[idJoueur].pions[int_i] = pion;
    }
}

joueur defZoneJoueur(int idJoueur)
{
    joueur joueur; // Variable de retour

    switch (idJoueur)
    {
    case 0:
        joueur.couleur = ROUGE;
        joueur.zoneArr = NORD;
        break;
    case 1:
        joueur.couleur = BLUE;
        joueur.zoneArr = SUD;
        break;
    default:
        fprintf(stderr, "[deCouleurJoueur]le joeur n'existe pas");
        exit(EXIT_FAILURE);
        break;
    }

    return (joueur);
}

void initJoueur(partie *partie, int idJoueur)
{

    partie->joueurs[idJoueur].id = idJoueur;
    partie->joueurs[idJoueur] = defZoneJoueur(idJoueur);
    initPions(partie, idJoueur);
}

partie initPartie(void)
{
    partie partie; // Variable de retour
    initJoueur(&partie, 0);
    initJoueur(&partie, 1);
    return (partie);
}