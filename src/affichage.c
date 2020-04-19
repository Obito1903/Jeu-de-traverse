/** @file affichage.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 19 Apr 2020 16:32
 *
 *  @brief Gére l'affichage du jeu
 *
 */

#include "affichage.h"

void affichePlateau(pion *plateau[TAILLEPLATEAU][TAILLEPLATEAU])
{
    int i_coordy;
    int i_coordx;
    printf("╔");
    for (i_coordx = 1; i_coordx < TAILLEPLATEAU - 1; i_coordx++)
    {
        printf("═╦");
    }
    printf("═╗");
    for (i_coordy = TAILLEPLATEAU - 1; i_coordy >= 0; i_coordy++)
    {
        printf("║");
        for (i_coordy = 0; i_coordx < TAILLEPLATEAU; i_coordx++)
        {
            if (&plateau[i_coordx][i_coordy] != NULL)
            {
                printf("\033[%d%c\033[0m║", plateau[i_coordx][i_coordy]->joueur->couleur, plateau[i_coordx][i_coordy]->type);
            }
            else
            {
                printf(" ║");
            }
        }
    }
    printf("╚");
    for (i_coordx = 1; i_coordx < TAILLEPLATEAU - 1; i_coordx++)
    {
        printf("═╩");
    }
    printf("═╝");
}