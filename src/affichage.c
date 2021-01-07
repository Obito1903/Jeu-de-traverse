/** @file affichage.c
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Sun 19 Apr 2020 16:32
 *
 *  @brief Gére l'affichage du jeu
 *
 */

#include "affichage.h"

void affichePlateau(partie *pPartie)
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
            if (pPartie->plateau[i_coordx][i_coordy] != NULL)
            {
                printf(" \033[%dm%c\033[0m ║", pPartie->plateau[i_coordx][i_coordy]->joueur->couleur, pPartie->plateau[i_coordx][i_coordy]->type);
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
    printf("Tour n°%d\n", pPartie->tour / 2);
    printf("\033[%dmJoueur %d :\033[0m\n", pPartie->joueurCourant->couleur, pPartie->joueurCourant->id);
    printf("%c\n║", 186);
}

void afficheCoup(deplacement *coup)
{
    switch (*coup)
    {
    case D_NORD:
        printf("1-NORD\n");
        break;
    case D_NORD_EST:
        printf("2-NORD EST\n");
        break;
    case D_EST:
        printf("3-EST\n");
        break;
    case D_SUD_EST:
        printf("4-SUD EST\n");
        break;
    case D_SUD:
        printf("5-SUD\n");
        break;
    case D_SUD_OUEST:
        printf("6-SUD OUEST\n");
        break;
    case D_OUEST:
        printf("7-OUEST\n");
        break;
    case D_NORD_OUEST:
        printf("8-NORD OUEST\n");
        break;
    default:
        break;
    }
}

void demandeDeplacement(partie *pPartie, pion *pPion, int bool_EstSaut)
{
    affichePlateau(pPartie);
    printf("\033[%dmPion %c(%d,%d)\033[0m\n", pPartie->joueurCourant->couleur, pPion->type, pPion->coord.x, pPion->coord.y);
    if (bool_EstSaut)
    {
        printf("Un saut est disponible, Entré 0 si vous ne voulez pas sautez.\n");
    }
    int int_i;
    printf("Quel direction ?\n");
    for (int_i = 0; int_i < pPion->coupsPossibles.nbCoup; int_i++)
    {
        afficheCoup(&pPion->coupsPossibles.Coups[int_i]);
    }
    int direction = saisieIntTest(0, 8);
    if (direction > 0)
    {
        deplacementPion(pPartie, pPion, direction - 1, bool_EstSaut);
    }
}

void selectionPion(partie *partie)
{
    affichePlateau(partie);
    printf("Veuillez entrer les coordonées du pion a deplacer (Entrer -1 pour passer le tour, -2 pour sauvegarder et quitter) :\n");
    partie->joueurCourant->inactivite++;
    int x = saisieIntTest(-2, 9, "x:");
    if (x >= 0)
    {
        partie->joueurCourant->inactivite = 0;
        int y = saisieIntTest(0, 9, "y:");
        pion *pion = partie->plateau[x][y];
        if ((pion != NULL) && (&pion->joueur->id == &partie->joueurCourant->id))
        {
            demandeDeplacement(partie, pion, 0);
        }
        else
        {
            selectionPion(partie);
        }
    }
    if (x == -2)
    {
        sauvegarde(partie);
        fprintf(stdout, "Partie Sauvegarder...\n");
        exit(EXIT_SUCCESS);
    }
}
void menuTest()
{
    printf("Mode Test. Quel mode lancer ?\n");
    printf("1 - Test victoire\n2 - Test tour 30\n");
    executeTest(saisieIntTest(1, 2));
}

void menuPrincipale(void)
{
    printf("Bienvenue sur le jeu de traverse. Quel mode lancer ?\n");
    printf("1 - Mode normal (2 Joueur)\n2 - Jeu contre ordi\n3 - Mode Test\n4 - Charge sav\n");
    executeMode(saisieIntTest(1, 4));
}

void afficheFin(partie *pPartie, int i_EtatFin)
{
    switch (i_EtatFin)
    {
    case 1:
        printf("\033[%dmVictoire du Joueur %d !\033[0m\n", pPartie->joueurCourant->couleur, pPartie->joueurCourant->id);
        break;
    case 2:
        printf("\033[%dmVotre zone de depart contient toujour un de vos pion !!\033[0m\n\n", pPartie->joueurCourant->couleur);
        joueurSuivant(pPartie);
        printf("\033[%dmVictoire du Joueur %d !\033[0m\n", pPartie->joueurCourant->couleur, pPartie->joueurCourant->id);
        break;
    case 3:
        printf("\033[%dmVous êtes inactif depuis 3 tours !!\033[0m\n\n", pPartie->joueurCourant->couleur);
        joueurSuivant(pPartie);
        printf("\033[%dmVictoire du Joueur %d !\033[0m\n", pPartie->joueurCourant->couleur, pPartie->joueurCourant->id);
        break;
    default:
        break;
    }
}
