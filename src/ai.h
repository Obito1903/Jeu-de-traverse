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
 * Stocke la liste des coup possible pour l'IA
 */
typedef struct
{
    /*! Indice du pion */
    int int_pion;
    /*! Indice du coup */
    int int_coup;
} Coup;

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 22:43
 *
 *  @brief Alloue et initialise la liste des coups possible
 *
 *  @return le pointeur vers la liste de coup
 *
 */
listeCoupPossible *allocListeCoupPossbile(void);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Thu 30 Apr 2020 22:08
 *
 *  @brief Libère la liste de coup
 *
 *  @param[in] listeCoup : pointeur vers la liste a libèrer
 *
 */
void freeListeCoupPossible(listeCoupPossible *listeCoup);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 22:43
 *
 *  @brief Alloue la liste d'evaluation
 *
 *  @return pointeur vers le tableau
 *
 */
tab *allocListeEval(void);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Thu 30 Apr 2020 01:25
 *
 *  @brief Alloue et remplis le tableau de coup
 *
 *  @param[in] listeCoups : pointeur vers la liste des coups à intégrer au tableau
 *  @param[in] listeEval : pointeur vers la liste des eval de chaque coup
 *  @return le tableau de coup
 *
 */
Coup *creeTabCoup(listeCoupPossible *listeCoups, tab *listeEval);

/**
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 21:24
 *
 *  @brief Ajoute un coup a la liste de coup possible d'un pion
 *
 *  @param[in,out] listeCoupsPion : Liste des coups possible par le pion
 *  @param[in] direction : direction du coup a ajouter
 *
 */
void ajouteListeCoup(listeCoupPossiblePion *listeCoupsPion, deplacement direction);

/**
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 15:50
 *
 *  @brief Liste les coups possible par un joueur et les intégre a la liste de coup possible
 *
 *  @param[in] partie : partie ou tester les coups
 *  @return la liste des coups possible par un joueur
 *
 */
listeCoupPossible *coupsDisponible(partie *partie);

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
void ajouteListeEval(tab *listeEval, int eval);

/**
 *  @author William Meunier <william.meunier@eisti.eu>
 *  @version 0.1
 *  @date Wed 29 Apr 2020 22:08
 *
 *  @brief trouve l'indice du max du tableau d'evaluation
 *
 *  @param[in] listeEval : pointeur vers la liste d'evaluation
 *  @return l'indice du maximum du tableau
 *
 */
int indiceMaxEval(tab *listeEval);

/**
 *  @author Théo Paesa <theo.paesa@eisti.eu>
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
 *  @author Théo Paesa <theo.paesa@eisti.eu>
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
 *  @brief Algorithme récursif MinMax
 *
 *  @param[in,out] noeudPartie : pointeur vers le noeud a traiter
 *  @param[in] profondeur : profondeur de traitement de l'algho
 *  @param[in] evalMax : si le joueur maximum est le joueur courant ou non
 *  @return evaluationd de la parti
 *
 */
int MinMax(partie *noeudPartie, int profondeur, int evalMax);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Thu 30 Apr 2020 01:13
 *
 *  @brief Execute l'algorithme MinMax
 *
 *  @param[in,out] noeudPartie : pointeur vers la partie ou executé l'algo
 *
 */
void joueMinMax(partie *noeudPartie);

#endif // __AI_H__