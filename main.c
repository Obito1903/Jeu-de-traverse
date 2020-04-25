/** @file main.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 12:14
 *
 *  @brief Fichier contenant le fonction main
 *
 */

#include "main.h"

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
    while (1)
    {
        executeTour(partie);
        joueurSuivant(partie);
    }
}

int main(int argc, char const *argv[])
{
    partie partie = initPartie();

    /*
    coord coordPion;
    coordPion.x = 1;
    coordPion.y = 8;
    deplacePionPlateau(&partie, &partie.joueurCourant->pions[1], coordPion);
    coordPion.x = 2;
    coordPion.y = 7;
    deplacePionPlateau(&partie, &partie.joueurCourant->pions[2], coordPion);
    */

    jouePartie(&partie);
    return (0);
}