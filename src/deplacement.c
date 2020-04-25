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

int executeDeplacement(partie *partie, pion *pion, deplacement direction, int estSaut)
{
    int estDeplace = 0;
    coord coordArrive = convertDirection(pion->coord, direction);
    if ((partie->plateau[coordArrive.x][coordArrive.y] == NULL) && (estSaut == 0))
    {
        deplacePionPlateau(partie, pion, coordArrive);
        estDeplace = 1;
    }
    else if (sautPossible(partie, coordArrive, direction))
    {
        coordArrive = convertDirection(coordArrive, direction);
        deplacePionPlateau(partie, pion, coordArrive);
        estDeplace = 1;
    }
    return estDeplace;
}

int deplaceCare(partie *partie, pion *pion, deplacement direction, int estSaut)
{
    int estDeplace = 0;
    if ((direction == D_NORD) || (direction == D_SUD) || (direction == D_EST) || (direction == D_OUEST))
    {
        estDeplace = executeDeplacement(partie, pion, direction, estSaut);
    }

    return estDeplace;
}

int deplaceTriangle(partie *partie, pion *pion, deplacement direction, int estSaut)
{
    int estDeplace = 0;
    switch (pion->joueur->id)
    {
    case 0:
        if ((direction == D_NORD_EST) || (direction == D_SUD) || (direction == D_NORD_OUEST))
        {
            estDeplace = executeDeplacement(partie, pion, direction, estSaut);
        }
        break;
    case 1:
        if ((direction == D_SUD_EST) || (direction == D_NORD) || (direction == D_NORD_OUEST))
        {
            estDeplace = executeDeplacement(partie, pion, direction, estSaut);
        }
        break;
    default:
        break;
    }

    return estDeplace;
}

int deplaceLosange(partie *partie, pion *pion, deplacement direction, int estSaut)
{
    int estDeplace = 0;
    if ((direction == D_NORD_EST) || (direction == D_SUD_EST) || (direction == D_SUD_OUEST) || (direction == D_NORD_OUEST))
    {
        estDeplace = executeDeplacement(partie, pion, direction, estSaut);
    }

    return estDeplace;
}

int deplaceCercle(partie *partie, pion *pion, deplacement direction, int estSaut)
{
    int estDeplace = 0;
    estDeplace = executeDeplacement(partie, pion, direction, estSaut);

    return estDeplace;
}

int deplacementPion(partie *partie, pion *pion, deplacement direction, int estSaut)
{
    int estDeplacer = 0; // Variable de retour

    switch (pion->type)
    {
    case CAREE:
        estDeplacer = deplaceCare(partie, pion, direction, estSaut);
        break;
    case TRIANGLE:
        estDeplacer = deplaceTriangle(partie, pion, direction, estSaut);
        break;
    case LOSANGE:
        estDeplacer = deplaceLosange(partie, pion, direction, estSaut);
        break;
    case CERCLE:
        estDeplacer = deplaceCercle(partie, pion, direction, estSaut);
        break;
    default:
        printf("\033[91m /!\\Type de pion inconu./!\\ \033[0m\n");
        getchar();
        break;
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