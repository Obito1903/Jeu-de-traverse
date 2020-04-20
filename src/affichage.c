/** @file affichage.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 19 Apr 2020 16:32
 *
 *  @brief Gére l'affichage du jeu
 *
 */

#include "affichage.h"

void affichePlateau(pion ***plateau)
{
    int i_coordy;
    int i_coordx;
    printf("\n╔");
    for (i_coordx = 1; i_coordx < TAILLEPLATEAU; i_coordx++)
    {
        printf("═══╦");
    }
    printf("═══╗\n");
    for (i_coordy = 0; i_coordy < TAILLEPLATEAU; i_coordy++)
    {
        printf("║");
        for (i_coordx = 0; i_coordx < TAILLEPLATEAU; i_coordx++)
        {
            if (plateau[i_coordx][i_coordy] != NULL)
            {
                printf(" \033[%dm%c\033[0m ║", plateau[i_coordx][i_coordy]->joueur->couleur, plateau[i_coordx][i_coordy]->type);
            }
            else
            {
                printf("   ║");
            }
        }
        printf("\n");
        if (i_coordy < TAILLEPLATEAU - 1)
        {
            printf("╠");
            for (i_coordx = 0; i_coordx < TAILLEPLATEAU - 1; i_coordx++)
            {
                printf("═══╬");
            }
            printf("═══╣\n");
        }
    }
    printf("╚");
    for (i_coordx = 1; i_coordx < TAILLEPLATEAU; i_coordx++)
    {
        printf("═══╩");
    }
    printf("═══╝\n");
}

void demandeDeplacement(partie *partie, pion *pion)
{
    printf("Quel direction ?\n 1-NORD\n 2-NORD EST\n 3-EST\n 4-SUD EST\n 5-SUD\n 6-SUD OUEST\n 7-OUEST\n 8-NORD OUEST\n");
    deplacement direction = saisieInt() - 1;
    switch (pion->type)
    {
    case CAREE:
        deplaceCare(partie, pion, direction);
        break;
    default:
        break;
    }
}