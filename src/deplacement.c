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

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 20 Apr 2020 15:02
 *
 *  @brief 
 *
 *  @param[in] Origine : emplacement a partir du quel le deplacement est realiser
 *  @param[in] direction : direction a convertir
 *  @return les coordonées correspondent
 *
 */
coord convertDirection(coord Origine, deplacement direction)
{
    coord coord = Origine; // Variable de retour

    switch (direction)
    {
    case D_NORD:
        coord.y = Origine.y - 1;
        break;
    case D_SUD:
        coord.y = Origine.y + 1;
        break;
    case D_EST:
        coord.x = Origine.x + 1;
        break;
    case D_OUEST:
        coord.x = Origine.x - 1;
        break;
    default:
        printf("direction inconue.\n");
        break;
    }

    return (coord);
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 20 Apr 2020 15:31
 *
 *  @brief 
 *
 *  @param[in]
 *  @return
 *
 */
int sautPossible(partie *partie, coord coordTest, deplacement direction)
{
    coord coordSaut = convertDirection(coordTest, direction);
    int sautPossible = 0;
    if (partie->plateau[coordSaut.x][coordSaut.y] == NULL)
    {
        sautPossible = 1;
    }

    return (sautPossible);
}

int deplaceCare(partie *partie, pion *pion, deplacement direction)
{
    int estDeplace = 0;
    if ((direction == D_NORD) || (direction == D_SUD) || (direction == D_EST) || (direction == D_OUEST))
    {
        coord coordArrive = convertDirection(pion->coord, direction);
        if (partie->plateau[coordArrive.x][coordArrive.y] == NULL)
        {
            deplacePionPlateau(partie, pion, coordArrive);
            estDeplace = 1;
        }
        else if (sautPossible(partie, coordArrive, direction))
        {
            printf("Les saut c'est pas encore fait !!\n");
        }
    }
    else
    {
        printf("Ce pion ne peut pas ce deplacer de cette maniere.\n");
        demandeDeplacement(partie, pion);
    }

    return estDeplace;
}