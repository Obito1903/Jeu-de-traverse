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

void placePion(partie *partie, int idJoueur, int idPion, coord coord)
{
    partie->joueurs[idJoueur].pions[idPion].coord = coord;
    partie->plateau[coord.x][coord.y] = &partie->joueurs[idJoueur].pions[idPion];
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 17:27
 *
 *  @brief permet de savoir quel sera le type du pion qui sera placer à l'initialisation
 *
 *  @param[in] int_i : iterateur qui doit etre testé
 *  @return retourne le type du pion qui
 *
 */
typePion defTypePion(int int_i)
{
    typePion type; // Variable de retour
    if (int_i == 0 || int_i == 7)
    {
        type = CAREE;
    }
    else if (int_i == 1 || int_i == 6)
    {
        type = TRIANGLE;
    }
    else if (int_i == 2 || int_i == 5)
    {
        type = LOSANGE;
    }
    else if (int_i == 3 || int_i == 4)
    {
        type = CERCLE;
    }
    return (type);
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 17:14
 *
 *  @brief Place les pions du joueur a leur emplacement initiale
 *
 *  @param[in]
 *
 */
void initPions(partie *partie, int idJoueur)
{
    int int_i;
    coord coord;
    pion pion;

    if (partie->joueurs[idJoueur].zoneArr == NORD)
    {
        coord.y = TAILLEPLATEAU - 1;
    }
    else
    {
        coord.y = 0;
    }

    for (int_i = 0; int_i < 8; int_i++)
    {
        pion.joueur = &partie->joueurs[idJoueur];
        pion.coord.x = int_i + 1;
        pion.type = defTypePion(int_i);
        placePion(partie, idJoueur, int_i, coord);
        partie->joueurs[idJoueur].pions[int_i] = pion;
    }
}

/** @fn void initJoueur (partie *partie, int idJoueur)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 17:39
 *
 *  @brief initialise un joueur
 *
 *  @param[in]
 *
 */
void initJoueur(partie *partie, int idJoueur)
{
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