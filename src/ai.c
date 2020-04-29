/** @file ai.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 14:35
 *
 *  @brief 
 *
 */

#include "ai.h"

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 16:04
 *
 *  @brief 
 *
 *  @param[in]
 *  @return
 *
 */
int deplacementPossible(deplacement direction, partie *partie, pion *pion)
{
    int possible = 0; // Variable de retour
    coord coordArrive = convertDirection(pion->coord, direction);

    if ((coordArrive.x < 10 && coordArrive.x >= 0) && (coordArrive.y < 10 && coordArrive.y >= 0) && (partie->plateau[coordArrive.x][coordArrive.y] == NULL))
    {
        possible = 1;
    }

    return (possible);
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 15:50
 *
 *  @brief Calcule le nombre de coups disponible pour le joueur
 *
 *  @param[in]
 *  @return
 *
 */
int coupsDisponible(partie *partie)
{
    int nbCoup = 0; // Variable de retour

    int int_pion;
    for (int_pion = 0; int_pion < NBPIONS; int_pion++)
    {
        switch (partie->joueurCourant->pions[int_pion].type)
        {
        case TRIANGLE:
            nbCoup = nbCoup + nbCoupPossibleTriangle(partie, &partie->joueurCourant->pions[int_pion]);
            break;

        default:
            break;
        }
    }

    return (nbCoup);
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 15:35
 *
 *  @brief 
 *
 *  @param[in]
 *  @return
 *
 */
int MinMax(partie *noeudPartie, int profondeur, int evalMax)
{
    int retour; // Variable de retour
    int fin;
    int *listeEval = malloc(sizeof(int) * coupsDisponible(noeudPartie));
    testFin(noeudPartie, &fin);
    if (profondeur == 0 || fin)
    {
        retour = evalPartie(noeudPartie);
    }
    else
    {
        int int_coup;
        for (int_coup = 0; int_coup < nbCoupPossible(noeudPartie); int_coup++)
        {
            ajouterListe(listeEval, MinMax(appliqueCoup(int_coup, noeudPartie), profondeur - 1, !evalMax));
        }
        if (evalMax)
        {
            retour = max(listeEval);
        }
        else
        {
            retour = min(listeEval);
        }
    }

    return (retour);
}