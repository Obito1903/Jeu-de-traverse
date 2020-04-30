/** @file deplacement.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 19 Apr 2020 16:33
 *
 *  @brief Gére les deplacements
 *
 */

#include "deplacement.h"

void placePion(partie *partie, pion *pion, coord coord)
{
    pion->coord = coord;
    partie->plateau[coord.x][coord.y] = pion;
}

void enlevePion(partie *partie, pion *pion)
{
    coord coordPion = pion->coord;
    partie->plateau[coordPion.x][coordPion.y] = NULL;
}

void deplacePionPlateau(partie *partie, pion *pion, coord coordArrive)
{
    enlevePion(partie, pion);
    placePion(partie, pion, coordArrive);
}

coord convertDirection(coord Origine, deplacement direction)
{
    coord coord = Origine; // Variable de retour

    switch (direction)
    {
    case D_NORD:
        coord.y = Origine.y - 1;
        break;
    case D_NORD_EST:
        coord.y = Origine.y - 1;
        coord.x = Origine.x + 1;
        break;
    case D_EST:
        coord.x = Origine.x + 1;
        break;
    case D_SUD_EST:
        coord.y = Origine.y + 1;
        coord.x = Origine.x + 1;
        break;
    case D_SUD:
        coord.y = Origine.y + 1;
        break;
    case D_SUD_OUEST:
        coord.y = Origine.y + 1;
        coord.x = Origine.x - 1;
        break;
    case D_OUEST:
        coord.x = Origine.x - 1;
        break;
    case D_NORD_OUEST:
        coord.y = Origine.y - 1;
        coord.x = Origine.x - 1;
        break;
    default:
        printf("direction inconue.\n");
        break;
    }

    return (coord);
}

int coordValide(partie *partie, coord coordTest)
{
    int estValide = 0; // Variable de retour

    if ((coordTest.x < 10 && coordTest.x >= 0) && (coordTest.y < 10 && coordTest.y >= 0) && (partie->plateau[coordTest.x][coordTest.y] == NULL))
    {
        estValide = 1;
    }

    return (estValide);
}

int executeDeplacement(partie *partie, pion *pion, deplacement direction, int estSaut)
{
    int estDeplace = 0;
    coord coordArrive = convertDirection(pion->coord, direction);
    if (coordValide(partie, coordArrive) && (estSaut == 0))
    {
        deplacePionPlateau(partie, pion, coordArrive);
        estDeplace = 1;
    }
    else if (testSautPossible(partie, coordArrive, direction))
    {
        coordArrive = convertDirection(coordArrive, direction);
        deplacePionPlateau(partie, pion, coordArrive);
        estDeplace = 1;
    }
    return estDeplace;
}

int deplacementPion(partie *partie, pion *pion, deplacement direction, int estSaut)
{
    int estDeplacer = 0; // Variable de retour

    int int_i;
    for (int_i = 0; int_i < pion->coupsPossibles.nbCoup; int_i++)
    {
        if (direction == pion->coupsPossibles.Coups[int_i])
        {
            estDeplacer = executeDeplacement(partie, pion, direction, estSaut);
        }
    }

    if (estDeplacer)
    {
        saut(partie, pion);
    }
    else
    {
        printf("\033[91m /!\\Ce pion ne peut pas ce deplacer de cette maniere./!\\ \033[0m\n");
        getchar();
        demandeDeplacement(partie, pion, estSaut);
    }

    return (estDeplacer);
}