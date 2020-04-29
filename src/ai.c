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
    if (listeCoupsPion->nbCoup == 0)
    {
        listeCoupsPion->nbCoup = 1;
        listeCoupsPion->Coups[0] = direction;
    }
    else
    {
        printf("realloc Liste Coup\n");
        listeCoupsPion->Coups = realloc(listeCoupsPion->Coups, sizeof(deplacement) * listeCoupsPion->nbCoup);
        printf("realloc Ok\n");
        listeCoupsPion->Coups[listeCoupsPion->nbCoup] = direction;
        listeCoupsPion->nbCoup++;
    }
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
listeCoupPossible allocListeCoupPossbile(void)
{
    listeCoupPossible listeCoup; // Variable de retour

    int int_pion;
    for (int_pion = 0; int_pion < NBPIONS; int_pion++)
    {
        listeCoup.pions[int_pion].nbCoup = 0;
        listeCoup.pions[int_pion].Coups = malloc(sizeof(deplacement));
    }
    listeCoup.nbCoups = 0;
    return (listeCoup);
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
tab allocListeEval(void)
{
    tab listeEval;
    listeEval.taille = 0;
    listeEval.tab = malloc(sizeof(int));
    return (listeEval);
}

listeCoupPossible coupsDisponible(partie *partie)
{
    int int_pion;
    int int_coup;
    listeCoupPossible listeCoups = allocListeCoupPossbile();
    for (int_pion = 0; int_pion < NBPIONS; int_pion++)
    {
        pion *pion = &partie->joueurCourant->pions[int_pion];
        for (int_coup = 0; int_coup < pion->coupsPossibles.nbCoup; int_coup++)
        {
            if (coordValide(partie, convertDirection(pion->coord, pion->coupsPossibles.Coups[int_coup])))
            {
                printf("ajout coup au pion %d\n", int_pion);
                ajouteCoup(&listeCoups.pions[int_pion], pion->coupsPossibles.Coups[int_coup]);
                listeCoups.nbCoups++;
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
    if (listeEval->taille == 0)
    {
        listeEval->taille = 1;
        listeEval->tab[0] = eval;
    }
    else
    {
        printf("realloc Liste\n");
        listeEval->tab = realloc(listeEval->tab, sizeof(listeEval->tab) + sizeof(int));
        printf("realloc Ok\n");
        listeEval->tab[listeEval->taille] = eval;
        listeEval->taille++;
    }
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
    affichePlateau(noeudPartie);
    printf("profondeur %d\n", profondeur);
    listeCoupPossible listeCoups = coupsDisponible(noeudPartie);
    tab listeEval = allocListeEval();
    testFin(noeudPartie, &fin);
    if (profondeur == 0 || fin)
    {
        retour = evalPartie(noeudPartie);
    }
    else
    {
        for (int_pion = 0; int_pion < NBPIONS; int_pion++)
        {
            for (int_coup = 0; int_coup < listeCoups.pions[int_pion].nbCoup; int_coup++)
            {
                partie *noeudPartieSuivant = copiePartie(noeudPartie);
                joueurSuivant(noeudPartieSuivant);
                ajouteListe(&listeEval, MinMax(appliqueCoup(int_pion, int_coup, listeCoups, noeudPartieSuivant), profondeur - 1, !evalMax));
                printf("Free partie\n");
                //freePartie(noeudPartieSuivant);
                printf("Free Ok\n");
            }
        }
        if (evalMax)
        {
            retour = maxEval(&listeEval);
        }
        else
        {
            retour = minEval(&listeEval);
        }
    }
    printf("Free Liste eval\n");
    free(listeEval.tab);
    printf("Free Ok\n");
    for (int_pion = 0; int_pion < NBPIONS; int_pion++)
    {
        printf("Free Coup pion %d\n", int_pion);
        free(listeCoups.pions[int_pion].Coups);
        printf("Free Ok\n");
    }

    return (retour);
}