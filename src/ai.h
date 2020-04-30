/** @file ai.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 14:36
 *
 *  @brief 
 *
 */

#ifndef __AI_H__
/**
*  @def __AI_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __AI_H__

#include "jeuBase.h"

/**
 * @struct listeCoupPossible
 * liste les coup possible
 */
typedef struct
{
    /*! taille du tableau */
    int nbCoups;
    /*! tableau contenant les coups possibles de chaque pion  */
    listeCoupPossiblePion *pions;
} listeCoupPossible;

/**
 * @struct tab
 * Tableau a une dimension
 */
typedef struct
{
    /*! taille du tableau */
    int taille;
    /*! tableau */
    int *tab;
} tab;

/**
 * @struct Coup
 * 
 */
typedef struct
{
    /*!  */
    int int_pion;
    int int_coup;
} Coup;

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 21:24
 *
 *  @brief Ajoute un coup a la liste de coup possible d'un pion
 *
 *  @param[in,out] listeCoupsPion : Liste des coups possible par le pion
 *  @param[in] direction : direction du coup a ajouter
 *
 */
void ajouteCoup(listeCoupPossiblePion *listeCoupsPion, deplacement direction);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 15:50
 *
 *  @brief Liste les coups possible par un joueur
 *
 *  @param[in] partie : partie ou tester les coups
 *  @return la liste des coups possible par un joueur
 *
 */
listeCoupPossible *coupsDisponible(partie *partie);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 21:49
 *
 *  @brief Applique le coup demander par MinMax au noeud courant
 *
 *  @param[in] int_pion : Indice du pion a deplacer
 *  @param[in] int_coup : Indice du coup a effectué
 *  @param[in] listeCoups : liste des coups possible
 *  @param[in] partie : noeud ou appliquer le coup
 *  @return l'adresse du noeud ou le coup a etait appliqué
 *
 */
partie *appliqueCoup(int int_pion, int int_coup, listeCoupPossible listeCoups, partie *partie);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 21:59
 *
 *  @brief Ajoute la valeur de l'evaluation courante a la liste d'evaluation
 *
 *  @param[in,out] listeEval : pointeur vers la liste d'evaluation
 *  @param[in] eval : evaluation a ajouter
 *
 */
void ajouteListe(tab *listeEval, int eval);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 22:08
 *
 *  @brief trouve le max du tableau d'evaluation
 *
 *  @param[in] listeEval : pointeur vers la liste d'evaluation
 *  @return le maximum du tableau
 *
 */
int maxEval(tab *listeEval);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 22:08
 *
 *  @brief trouve le min du tableau d'evaluation
 *
 *  @param[in] listeEval : pointeur vers la liste d'evaluation
 *  @return le minimum du tableau
 *
 */
int minEval(tab *listeEval);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 22:12
 *
 *  @brief Evalue une partie
 *
 *  @param[in] partie : pointeur ver la partie a évaluer
 *  @return la valeur d'evaluation de la partie
 *
 */
int evalPartie(partie *partie);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 15:35
 *
 *  @brief Execute l'algho Minmax
 *
 *  @param[in,out] noeudPartie : pointeur vers le noeud a traiter
 *  @param[in] profondeur : profondeur de traitement de l'algho
 *  @param[in] evalMax : si le joueur maximum est le joueur courant ou non
 *  @return evaluationd e la parti
 *
 */
int MinMax(partie *noeudPartie, int profondeur, int evalMax);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Thu 30 Apr 2020 01:13
 *
 *  @brief 
 *
 *  @param[in]
 *
 */
void joueMinMax(partie *noeudPartie);

#endif // __AI_H__