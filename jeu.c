/** @file jeu.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 15:02
 *
 *  @brief Fichier contenant le plateau et les fonction permettant le bon deroulement d'un partie
 *
 */

#include "jeu.h"

void affichePlateau(pion plateau[TAILLEPLATEAU][TAILLEPLATEAU])
{
    int i_coordy;
    int i_coordx;
    printf("╔");
    for (i_coordx = 1; i_coordx < TAILLEPLATEAU - 1; i_coordx++)
    {
        printf("═╦");
    }
    printf("╗");
    for (i_coordy = TAILLEPLATEAU - 1; i_coordy <= 0; i_coordy++)
    {
        printf("║");
        for (i_coordy = 0; i_coordx < TAILLEPLATEAU; i_coordx++)
        {
            if (&plateau[i_coordx][i_coordy] != NULL)
            {
                printf("\033[%d%c\033[0m║", plateau[i_coordx][i_coordy].joueur->couleur, plateau[i_coordx][i_coordy].type);
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
    printf("╝");
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 16:38
 *
 *  @brief place les pion du joueur a leurs emplacement d'origine sur le plateau
 *
 *  @param[in,out] partie : Adresse de la partie a modifier
 *  @param[in] idJoueur : id du Joueur auquel le pion appartient
 *  @param[in] idPion : id du pion a placer
 *  @param[in] coord : coordonées ou placer le pion
 *
 */
void placePion(partie *partie, int idJoueur, int idPion, coord coord)
{
    partie->joueurs[idJoueur].pions[idPion].coord = coord;
    partie->plateau[coord.x][coord.y] = &partie->joueurs[idJoueur].pions[idPion];
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 16:27
 *
 *  @brief Initialise la partie
 *
 *  @return Le plateau de jeux
 *
 */
partie initPartie(void)
{
    partie partie; // Variable de retour

    return (partie);
}