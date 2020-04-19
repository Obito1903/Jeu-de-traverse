/** @file deplacement.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 19 Apr 2020 16:33
 *
 *  @brief Gére les deplacements
 *
 */

#include "deplacement.h"

void placePion(partie *partie, int idJoueur, int idPion, coord coord)
{
    partie->joueurs[idJoueur].pions[idPion].coord = coord;
    partie->plateau[coord.x][coord.y] = &(partie->joueurs[idJoueur].pions[idPion]);
}