/** @file ai.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 14:35
 *
 *  @brief 
 *
 */

#include "ai.h"

void ajouteCoup(listeCoupPossiblePion *listeCoupsPion, deplacement direction)
{
    listeCoupsPion->Coups[listeCoupsPion->nbCoup] = direction;
    listeCoupsPion->nbCoup++;
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 22:43
 *
 *  @brief 
 *
 *  @param[in]
 *  @return
 *
 */
listeCoupPossible *allocListeCoupPossbile(void)
{
    listeCoupPossible *listeCoup = (listeCoupPossible *)malloc(sizeof(listeCoupPossible)); // Variable de retour
    listeCoup->pions = (listeCoupPossiblePion *)malloc(sizeof(listeCoupPossiblePion) * NBPIONS);

    int int_pion;
    for (int_pion = 0; int_pion < NBPIONS; int_pion++)
    {
        listeCoup->pions[int_pion].nbCoup = 0;
        listeCoup->pions[int_pion].Coups = (deplacement *)malloc(sizeof(deplacement) * 8);
    }

    return listeCoup;
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Thu 30 Apr 2020 22:08
 *
 *  @brief 
 *
 *  @param[in]
 *
 */
void freeListeCoupPossible(listeCoupPossible *listeCoup)
{
    int int_pion;
    for (int_pion = 0; int_pion < NBPIONS; int_pion++)
    {
        free(listeCoup->pions[int_pion].Coups);
    }
    free(listeCoup->pions);
    free(listeCoup);
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 22:43
 *
 *  @brief 
 *
 *  @param[in]
 *  @return
 *
 */
tab *allocListeEval(void)
{
    tab *listeEval = (tab *)malloc(sizeof(tab));
    listeEval->taille = 0;
    listeEval->tab = NULL;
    return (listeEval);
}

listeCoupPossible *coupsDisponible(partie *partie)
{
    int int_pion;
    int int_coup;
    listeCoupPossible *listeCoups = allocListeCoupPossbile();
    for (int_pion = 0; int_pion < NBPIONS; int_pion++)
    {
        pion *pion = &partie->joueurCourant->pions[int_pion];
        for (int_coup = 0; int_coup < pion->coupsPossibles.nbCoup; int_coup++)
        {
            if (coordValide(partie, convertDirection(pion->coord, pion->coupsPossibles.Coups[int_coup])))
            {
                ajouteCoup(&listeCoups->pions[int_pion], pion->coupsPossibles.Coups[int_coup]);
                listeCoups->nbCoups++;
            }
        }
    }

    return (listeCoups);
}

partie *appliqueCoup(int int_pion, int int_coup, listeCoupPossible listeCoups, partie *partie)
{
    executeDeplacement(partie, &partie->joueurCourant->pions[int_pion], listeCoups.pions[int_pion].Coups[int_coup], 0);
    return (partie);
}

void ajouteListe(tab *listeEval, int eval)
{
    if (listeEval->tab == NULL)
    {
        listeEval->taille = 1;
        listeEval->tab = (int *)malloc(sizeof(int));
        listeEval->tab[0] = eval;
    }
    else
    {
        listeEval->tab = (int *)realloc(listeEval->tab, sizeof(int) * listeEval->taille + 1);
        listeEval->tab[listeEval->taille - 1] = eval;
        listeEval->taille++;
    }
}

int indiceMaxEval(tab *listeEval)
{
    int max = 0; // Variable de retour

    int int_i;
    for (int_i = 1; int_i < listeEval->taille; int_i++)
    {
        if (listeEval->tab[int_i] > listeEval->tab[max])
        {
            max = int_i;
        }
    }

    return (max);
}

int maxEval(tab *listeEval)
{
    int max = listeEval->tab[0]; // Variable de retour

    int int_i;
    for (int_i = 1; int_i < listeEval->taille; int_i++)
    {
        if (listeEval->tab[int_i] > max)
        {
            max = listeEval->tab[int_i];
        }
    }

    return (max);
}

int minEval(tab *listeEval)
{
    int min = listeEval->tab[0]; // Variable de retour

    int int_i;
    for (int_i = 1; int_i < listeEval->taille; int_i++)
    {
        if (listeEval->tab[int_i] < min)
        {
            min = listeEval->tab[int_i];
        }
    }

    return (min);
}

int evalPartie(partie *partie)
{
    int eval = 0; // Variable de retour

    int int_pion;
    for (int_pion = 0; int_pion < NBPIONS; int_pion++)
    {
        if (partie->joueurCourant->id == 0)
        {
            eval = eval + (9 - partie->joueurCourant->pions[int_pion].coord.y);
        }
        else
        {
            eval = eval + partie->joueurCourant->pions[int_pion].coord.y;
        }
    }

    return (eval);
}

int MinMax(partie *noeudPartie, int profondeur, int evalMax)
{
    int retour; // Variable de retour
    int fin = 0;
    int int_pion;
    int int_coup;
    noeudPartie->joueurCourant = &noeudPartie->joueurs[0];
    if (evalMax)
    {
        noeudPartie->joueurCourant = &noeudPartie->joueurs[1];
    }
    listeCoupPossible *listeCoups = coupsDisponible(noeudPartie);
    tab *listeEval = allocListeEval();
    testFin(noeudPartie, &fin);
    if (profondeur == 0 || fin)
    {
        retour = evalPartie(noeudPartie);
    }
    else
    {
        for (int_pion = 0; int_pion < NBPIONS; int_pion++)
        {
            for (int_coup = 0; int_coup < listeCoups->pions[int_pion].nbCoup; int_coup++)
            {
                partie *noeudPartieSuivant = copiePartie(noeudPartie);
                ajouteListe(listeEval, MinMax(appliqueCoup(int_pion, int_coup, *listeCoups, noeudPartieSuivant), profondeur - 1, !evalMax));
                freePartie(noeudPartieSuivant);
            }
        }
        if (evalMax)
        {
            retour = maxEval(listeEval);
        }
        else
        {
            retour = minEval(listeEval);
        }
    }
    free(listeEval->tab);
    free(listeEval);
    freeListeCoupPossible(listeCoups);

    return (retour);
}

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Thu 30 Apr 2020 01:25
 *
 *  @brief 
 *
 *  @param[in]
 *  @return
 *
 */
Coup *creeTabCoup(listeCoupPossible *listeCoups, tab *listeEval)
{
    Coup *retour = malloc(sizeof(Coup) * listeEval->taille); // Variable de retour

    int int_pion;
    for (int_pion = 0; int_pion < NBPIONS; int_pion++)
    {
        int int_coup;
        for (int_coup = 0; int_coup < listeCoups->pions[int_pion].nbCoup; int_coup++)
        {
            retour[int_pion + int_coup].int_pion = int_pion;
            retour[int_pion + int_coup].int_pion = int_coup;
        }
    }

    return (retour);
}

void joueMinMax(partie *noeudPartie)
{
    listeCoupPossible *listeCoups = coupsDisponible(noeudPartie);
    tab *listeEval = allocListeEval();
    int int_pion;
    int int_coup;

    for (int_pion = 0; int_pion < NBPIONS; int_pion++)
    {
        for (int_coup = 0; int_coup < listeCoups->pions[int_pion].nbCoup; int_coup++)
        {
            partie *noeudPartieSuivant = copiePartie(noeudPartie);
            ajouteListe(listeEval, MinMax(appliqueCoup(int_pion, int_coup, *listeCoups, noeudPartieSuivant), 3, 0));
            freePartie(noeudPartieSuivant);
        }
    }
    Coup *ListeCoupEval = creeTabCoup(listeCoups, listeEval);
    int max = indiceMaxEval(listeEval);
    appliqueCoup(ListeCoupEval[max].int_pion, ListeCoupEval[max].int_coup, *listeCoups, noeudPartie);
    free(ListeCoupEval);
    free(listeEval->tab);
    free(listeEval);
    freeListeCoupPossible(listeCoups);
}