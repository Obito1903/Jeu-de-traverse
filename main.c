/** @file main.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 12:14
 *
 *  @brief Fichier contenant le fonction main
 *
 */

#include "main.h"

int main(int argc, char const *argv[])
{
    partie partie = initPartie();

    coord coordPion;
    coordPion.x = 1;
    coordPion.y = 8;
    deplacePionPlateau(&partie, &partie.joueurCourant->pions[1], coordPion);
    coordPion.x = 2;
    coordPion.y = 7;
    deplacePionPlateau(&partie, &partie.joueurCourant->pions[2], coordPion);

    //affichePlateau(partie.plateau);
    //demandeDeplacement(&partie, &partie.joueurCourant->pions[0], 0);

    selectionPion(&partie);

    affichePlateau(&partie);
    return (0);
}