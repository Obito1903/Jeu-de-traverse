/** @file saut.c
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Sat 25 Apr 2020 18:18
 *
 *  @brief 
 *
 */

#include "saut.h"

int testSautPossible(partie *partie, coord coordTest, deplacement direction)
{
    coord coordSaut = convertDirection(coordTest, direction);
    int sautPossible = 0;
    if ((coordSaut.x < 10) && (coordSaut.x >= 0) && (coordSaut.y < 10) && (coordSaut.y >= 0))
    {
        if ((partie->plateau[coordTest.x][coordTest.y] != NULL) && (partie->plateau[coordSaut.x][coordSaut.y] == NULL))
        {
            sautPossible = 1;
        }
    }

    return (sautPossible);
}

int testSautPossiblePion(partie *partie, pion *pion)
{
    int estPossible = 0; // Variable de retour
    int int_i;
    unsigned int int_direction = 0;
    while ((int_direction < 8) && (estPossible != 1))
    {
        for (int_i = 0; int_i < pion->coupsPossibles.nbCoup; int_i++)
        {
            if (int_direction == pion->coupsPossibles.Coups[int_i])
            {
                estPossible = testSautPossible(partie, convertDirection(pion->coord, int_direction), int_direction);
            }
        }
        int_direction++;
    }
    return (estPossible);
}

void saut(partie *partie, pion *pion)
{
    if (testSautPossiblePion(partie, pion))
    {
        demandeDeplacement(partie, pion, 1);
    }
}