/** @file saut.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 25 Apr 2020 18:18
 *
 *  @brief 
 *
 */

#include "saut.h"

int sautPossible(partie *partie, coord coordTest, deplacement direction)
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

int testSautPossibleCare(partie *partie, pion *pion)
{
    int estPossible = 0; // Variable de retour
    int int_direction = 0;
    while ((int_direction < 8) && (estPossible != 1))
    {
        estPossible = sautPossible(partie, convertDirection(pion->coord, int_direction), int_direction);
        int_direction = int_direction + 2;
    }

    return (estPossible);
}

int testSautPossibleTriangle(partie *partie, pion *pion)
{
    int estPossible = 0; // Variable de retour

    if (pion->joueur->id == 0)
    {
        int int_direction = 1;
        while ((int_direction < 8) && (estPossible != 1))
        {
            estPossible = sautPossible(partie, convertDirection(pion->coord, int_direction), int_direction);
            int_direction = int_direction + 3;
        }
    }
    else
    {
        int int_direction = 0;
        while (((int_direction == 0) || (int_direction == 3) || (int_direction == 5)) && (estPossible != 1))
        {
            estPossible = sautPossible(partie, convertDirection(pion->coord, int_direction), int_direction);
            int_direction++;
        }
    }

    return (estPossible);
}

int testSautPossibleLosange(partie *partie, pion *pion)
{
    int estPossible = 0; // Variable de retour
    int int_direction = 1;
    while ((int_direction < 8) && (estPossible != 1))
    {
        estPossible = sautPossible(partie, convertDirection(pion->coord, int_direction), int_direction);
        int_direction = int_direction + 2;
    }

    return (estPossible);
}

int testSautPossibleCercle(partie *partie, pion *pion)
{
    int estPossible = 0; // Variable de retour
    int int_direction = 0;
    while ((int_direction < 8) && (estPossible != 1))
    {
        estPossible = sautPossible(partie, convertDirection(pion->coord, int_direction), int_direction);
        int_direction++;
    }

    return (estPossible);
}

int testSautPossiblePion(partie *partie, pion *pion)
{
    int estPossible = 0; // Variable de retour

    switch (pion->type)
    {
    case CAREE:
        estPossible = testSautPossibleCare(partie, pion);
        break;
    case TRIANGLE:
        estPossible = testSautPossibleTriangle(partie, pion);
        break;
    case LOSANGE:
        estPossible = testSautPossibleLosange(partie, pion);
        break;
    case CERCLE:
        estPossible = testSautPossibleCercle(partie, pion);
        break;

    default:
        printf("Type de pion inconu.\n");
        break;
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