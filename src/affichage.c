/** @file affichage.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 19 Apr 2020 16:32
 *
 *  @brief Gére l'affichage du jeu
 *
 */

#include "affichage.h"

void affichePlateau(partie *partie)
{
    system("clear");
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
            if (partie->plateau[i_coordx][i_coordy] != NULL)
            {
                printf(" \033[%dm%c\033[0m ║", partie->plateau[i_coordx][i_coordy]->joueur->couleur, partie->plateau[i_coordx][i_coordy]->type);
            }
            else
            {
                printf("\033[90m%d,%d\033[0m║", i_coordx, i_coordy);
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
    printf("Tour n°%d\n", partie->tour / 2);
    printf("\033[%dmJoueur %d :\033[0m\n", partie->joueurCourant->couleur, partie->joueurCourant->id);
}

void demandeDeplacement(partie *partie, pion *pion, int estSaut)
{
    affichePlateau(partie);
    if (estSaut)
    {
        printf("Un saut est disponible, Entré -1 si vous ne voulez pas sautez.\n");
    }
    printf("Quel direction ?\n 1-NORD\n 2-NORD EST\n 3-EST\n 4-SUD EST\n 5-SUD\n 6-SUD OUEST\n 7-OUEST\n 8-NORD OUEST\n");
    deplacement direction = saisieIntTest(1, 8) - 1;
    deplacementPion(partie, pion, direction, estSaut);
}

void selectionPion(partie *partie)
{
    affichePlateau(partie);
    printf("Veuillez entrer les coordonées du pion a deplacer (Entrer -1 pour passer le tour) :\n");
    partie->joueurCourant->inactivite++;
    int x = saisieIntTest(-1, 9, "x:");
    if (x != -1)
    {
        partie->joueurCourant->inactivite = 0;
        int y = saisieIntTest(0, 9, "y:");
        pion *pion = partie->plateau[x][y];
        if (pion != NULL)
        {
            demandeDeplacement(partie, pion, 0);
        }
        else
        {
            selectionPion(partie);
        }
    }
}
void menuTest(partie *partie)
{
    printf("Mode Test. Quel mode lancer ?\n");
    printf("1 - Test victoire\n2 - Test tour 30\n");
    executeTest(saisieIntTest(1, 2), partie);
}

void menuPrincipale(void)
{
    printf("Bienvenue sur le jeu de traverse. Quel mode lancer ?\n");
    printf("1 - Mode normal (2 Joueur)\n2 - Mode Test\n");
    executeMode(saisieIntTest(1, 2));
}

void afficheFin(partie *partie, int etatFin)
{
    switch (etatFin)
    {
    case 1:
        printf("\033[%dmVictoire du Joueur %d !\033[0m\n", partie->joueurCourant->couleur, partie->joueurCourant->id);
        break;
    case 2:
        printf("\033[%dmVotre zone de depart contient toujour un de vos pion !!\033[0m\n\n", partie->joueurCourant->couleur);
        joueurSuivant(partie);
        printf("\033[%dmVictoire du Joueur %d !\033[0m\n", partie->joueurCourant->couleur, partie->joueurCourant->id);
        break;
    case 3:
        printf("\033[%dmVous êtes inactif depuis 3 tours !!\033[0m\n\n", partie->joueurCourant->couleur);
        joueurSuivant(partie);
        printf("\033[%dmVictoire du Joueur %d !\033[0m\n", partie->joueurCourant->couleur, partie->joueurCourant->id);
        break;
    default:
        break;
    }
}