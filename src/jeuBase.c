/** @file jeuBase.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 15:02
 *
 *  @brief Fichier contenant le plateau et les fonction permettant le bon deroulement d'un partie
 *
 */

#include "jeuBase.h"

int testVictiore(partie *pPartie)
{
    int bool_Victoire = 1;                    // Variable de retour
    joueur *pJoueur = pPartie->joueurCourant; // Initialise le joueur a tester au joueur courant
    int int_i;                                // Itérateur
    for (int_i = 1; int_i < 9; int_i++)
    {
        if ((pPartie->plateau[int_i][pJoueur->zoneArr] == NULL) || (pPartie->plateau[int_i][pJoueur->zoneArr]->joueur != pJoueur))
        {
            bool_Victoire = 0;
        }
    }
    return (bool_Victoire);
}

int testNumTour(partie *pPartie)
{
    int bool_nonVide = 0; // Variable de retour
    if (pPartie->tour == 60 || pPartie->tour == 61)
    {
        joueur *joueur = pPartie->joueurCourant;
        int int_i; // Itérateur
        facePlateau zone = NORD;
        if (joueur->zoneArr == NORD)
        {
            zone = SUD;
        }
        for (int_i = 1; int_i < 9; int_i++)
        {
            if (!((pPartie->plateau[int_i][zone] == NULL) || (pPartie->plateau[int_i][zone]->joueur != joueur)))
            {
                bool_nonVide = 2;
            }
        }
    }
    return (bool_nonVide);
}

int testInactivite(partie *pPartie)
{
    int bool_estInactife = 0; // Variable de retour

    if (pPartie->joueurCourant->inactivite >= 3)
    {
        bool_estInactife = 3;
    }

    return (bool_estInactife);
}

void testFin(partie *pPartie, int *i_fin)
{
    *i_fin = testVictiore(pPartie);
    *i_fin = testNumTour(pPartie);
    *i_fin = testInactivite(pPartie);
}

void executeTour(partie *pPartie)
{
    selectionPion(pPartie);
}

void joueurSuivant(partie *pPartie)
{
    if (pPartie->joueurCourant->id == 0)
    {
        pPartie->joueurCourant = &(pPartie->joueurs[1]);
    }
    else
    {
        pPartie->joueurCourant = &(pPartie->joueurs[0]);
    }
}

void jouePartie(partie *pPartie)
{
    pPartie->joueurCourant = &(pPartie->joueurs[0]);
    int i_Fin = 0;
    do
    {
        executeTour(pPartie);
        testFin(pPartie, &i_Fin);
        printf("inactivité: %d\n", pPartie->joueurCourant->inactivite);
        if (!i_Fin)
        {
            joueurSuivant(pPartie);
            i_Fin = 0;
        }
        pPartie->tour++;

    } while (!i_Fin);
    afficheFin(pPartie, i_Fin);
}

void jouePartieOrdi(partie *pPartie)
{
    pPartie->joueurCourant = &(pPartie->joueurs[0]);
    int i_Fin = 0;
    do
    {
        if (pPartie->joueurCourant->id == 1)
        {
            joueMinMax(pPartie);
        }
        else
        {
            executeTour(pPartie);
        }
        testFin(pPartie, &i_Fin);
        printf("inactivité: %d\n", pPartie->joueurCourant->inactivite);
        if (!i_Fin)
        {
            joueurSuivant(pPartie);
            i_Fin = 0;
        }
        pPartie->tour++;

    } while (!i_Fin);
    afficheFin(pPartie, i_Fin);
}

void executeTest(int i_Mode)
{
    partie *p_PartieTest;
    int int_pion;
    switch (i_Mode)
    {
    case 1:
        p_PartieTest = initPartie();
        for (int_pion = 0; int_pion < 8; int_pion++)
        {
            coord coordPion;
            coordPion.y = 0;
            coordPion.x = int_pion + 1;
            deplacePionPlateau(p_PartieTest, &(p_PartieTest->joueurs[0].pions[int_pion]), coordPion);
            coordPion.y = 9;
            placePion(p_PartieTest, &(p_PartieTest->joueurs[1].pions[int_pion]), coordPion);
            coordPion.y = 1;
            coordPion.x = 1;
            deplacePionPlateau(p_PartieTest, &(p_PartieTest->joueurs[0].pions[0]), coordPion);
            coordPion.y = 8;
            coordPion.x = 1;
            deplacePionPlateau(p_PartieTest, &(p_PartieTest->joueurs[1].pions[0]), coordPion);
        }
        affichePlateau(p_PartieTest);
        jouePartie(p_PartieTest);
        freePartie(p_PartieTest);
        break;
    case 2:
        p_PartieTest = initPartie();
        p_PartieTest->tour = 58;
        jouePartie(p_PartieTest);
        freePartie(p_PartieTest);
        break;
    default:
        break;
    }
}
void executeMode(int i_Mode)
{
    partie *pPartie;
    switch (i_Mode)
    {
    case 1:
        pPartie = initPartie();
        jouePartie(pPartie);
        freePartie(pPartie);
        break;
    case 2:
        pPartie = initPartie();
        jouePartieOrdi(pPartie);
        freePartie(pPartie);
        break;
    case 3:
        menuTest();
        break;
    case 4:
        pPartie = chargeSav();
        jouePartie(pPartie);
        freePartie(pPartie);
        break;

    default:
        break;
    }
}