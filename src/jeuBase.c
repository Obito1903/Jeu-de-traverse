/** @file jeuBase.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 15:02
 *
 *  @brief Fichier contenant le plateau et les fonction permettant le bon deroulement d'un partie
 *
 */

#include "jeuBase.h"

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 26 Apr 2020 15:56
 *
 *  @brief test si un des joueur a gagné
 *
 *  @param[in]
 *  @return
 *
 */
int testVictiore(partie *partie)
{
    int victoire = 1; // Variable de retour
    joueur *joueur = partie->joueurCourant;
    int int_i;
    for (int_i = 1; int_i < 9; int_i++)
    {
        if ((partie->plateau[int_i][joueur->zoneArr] == NULL) || (partie->plateau[int_i][joueur->zoneArr]->joueur != joueur))
        {
            victoire = 0;
        }
    }
    int_i++;
    return (victoire);
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 26 Apr 2020 17:09
 *
 *  @brief 
 *
 *  @param[in]
 *  @return
 *
 */
int testNumTour(partie *partie)
{
    int nonVide = 0; // Variable de retour
    if (partie->tour == 60 || partie->tour == 61)
    {
        joueur *joueur = partie->joueurCourant;
        int int_i;
        facePlateau zone = NORD;
        if (joueur->zoneArr == NORD)
        {
            zone = SUD;
        }
        for (int_i = 1; int_i < 9; int_i++)
        {
            if (!((partie->plateau[int_i][zone] == NULL) || (partie->plateau[int_i][zone]->joueur != joueur)))
            {
                nonVide = 2;
            }
        }
    }
    return (nonVide);
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 26 Apr 2020 18:01
 *
 *  @brief Test si un joueur est inactif
 *
 *  @param[in]
 *  @return
 *
 */
int testInactivite(partie *partie)
{
    int estInactife = 0; // Variable de retour

    if (partie->joueurCourant->inactivite >= 3)
    {
        estInactife = 3;
    }

    return (estInactife);
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 26 Apr 2020 17:04
 *
 *  @brief 
 *
 *  @param[in,out] partie : Adresse de la partie
 *  @param[in,out] fin : Pointeur ver la valeur de fin
 *
 */
void testFin(partie *partie, int *fin)
{
    *fin = testVictiore(partie);
    *fin = testNumTour(partie);
    *fin = testInactivite(partie);
}

void executeTour(partie *partie)
{
    selectionPion(partie);
}

void joueurSuivant(partie *partie)
{
    if (partie->joueurCourant->id == 0)
    {
        partie->joueurCourant = &(partie->joueurs[1]);
    }
    else
    {
        partie->joueurCourant = &(partie->joueurs[0]);
    }
}

void jouePartie(partie *partie)
{
    partie->joueurCourant = &(partie->joueurs[0]);
    int fin = 0;
    do
    {
        executeTour(partie);
        testFin(partie, &fin);
        printf("inactivité: %d\n", partie->joueurCourant->inactivite);
        if (!fin)
        {
            joueurSuivant(partie);
            fin = 0;
        }
        partie->tour++;

    } while (!fin);
    afficheFin(partie, fin);
}

void executeTest(int mode, partie *partie)
{
    switch (mode)
    {
    case 1:
        *partie = initPartie();
        int int_pion;
        for (int_pion = 0; int_pion < 8; int_pion++)
        {
            coord coordPion;
            coordPion.y = 0;
            coordPion.x = int_pion + 1;
            deplacePionPlateau(partie, &(partie->joueurs[0].pions[int_pion]), coordPion);
            coordPion.y = 9;
            placePion(partie, &(partie->joueurs[1].pions[int_pion]), coordPion);
            coordPion.y = 1;
            coordPion.x = 1;
            deplacePionPlateau(partie, &(partie->joueurs[0].pions[0]), coordPion);
            coordPion.y = 8;
            coordPion.x = 1;
            deplacePionPlateau(partie, &(partie->joueurs[1].pions[0]), coordPion);
        }
        affichePlateau(partie);
        jouePartie(partie);
        break;
    case 2:
        *partie = initPartie();
        partie->tour = 58;
        jouePartie(partie);
        break;
    default:
        break;
    }
}

void executeMode(int mode)
{
    partie partie;
    switch (mode)
    {
    case 1:
        partie = initPartie();
        jouePartie(&partie);
        break;
    case 2:
        menuTest(&partie);
        break;
    default:
        break;
    }
}