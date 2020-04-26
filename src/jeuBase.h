/** @file jeuBase.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 15:02
 *
 *  @brief Header du fichier jeu.c
 *
 */

#ifndef __JEUBASE_H__
/**
*  @def __JEUBASE_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __JEUBASE_H__

#include <stdlib.h>
#include <stdio.h>

/**
 * @enum typePion
 * Definit le type de chaque pion
 */
typedef enum
{
    /*! Pion de type caree */
    CAREE = 254,
    /*! Pion de type triangle */
    TRIANGLE = 65,
    /*! Pion de type losange */
    LOSANGE = 76,
    /*! Pion de type cercle */
    CERCLE = 79
} typePion;

/**
 * @enum facePlateau
 * Definit le nom des faces du plateau
 */
typedef enum
{
    /*! Face nord plateau */
    NORD = 0,
    /*! Face sud du plateau */
    SUD = 9,
    /*! Face est du plateau */
    EST = 9,
    /*! Face ouest du plateau */
    OUEST = 0
} facePlateau;

/**
 * @enum couleur
 * Couleur disponible pour les pions
 */
typedef enum
{
    /*! Couleur Rouge */
    ROUGE = 91,
    /*! Couleur Vert */
    VERT = 93,
    /*! Couleur Blue */
    BLUE = 34,
    /*! Couleur Jaune */
    JAUNE = 93
} couleur;

/**
 * @enum deplacement
 * defini les type de deplacement possible
 */
typedef enum
{
    D_NORD,
    D_NORD_EST,
    D_EST,
    D_SUD_EST,
    D_SUD,
    D_SUD_OUEST,
    D_OUEST,
    D_NORD_OUEST
} deplacement;

/**
 * @struct coord
 * Permet de stocker un coordonées en 2 dimensions
 */
typedef struct
{
    /*! coordonnée en x */
    int x;
    /*! coordonnée en y */
    int y;
} coord;

/**
*  @def NBJOUEUR
*  Permet de connaitre le joueurs
*/
#define NBJOUEUR 2

typedef struct joueur joueur;
/**
 * @struct pion
 * Definit un pion
 */
typedef struct
{
    /*! Joueur au quel le point appartient */
    joueur *joueur;
    /*! Type du pion */
    typePion type;
    /*! Coordonées du pion sur le plateau */
    coord coord;
} pion;

/**
*  @def NBPIONS
*  Permet de connaitre le nombre de pions que doit posséder un joueur
*/
#define NBPIONS 8

/**
 * @struct joueur
 * Definit un joueur
 */
struct joueur
{
    /*! Identifiant du joueur */
    int id;
    /*! Adresse vers le tableau contenant les pions du joueur */
    pion *pions;
    /*! Adresse vers le tableau contenant les pions du joueur */
    couleur couleur;
    /*! Permet de connaitre la zone d'arriver du joueur */
    facePlateau zoneArr;
    /*!permet de connaitre le nombre de tours inactif*/
    int inactivite;
};

/**
*  @def TAILLEPLATEAU
*  Permet de connaitre la taille du plateau
*/
#define TAILLEPLATEAU 10

/**
 * @struct partie
 * Stock toute les infos necessaire pour gere la partie
 */
typedef struct
{
    /*! Plateau de jeu (tableau 2D d'adresse de pion) */
    pion ***plateau;
    /*! tableau de joueur */
    joueur *joueurs;
    joueur *joueurCourant;
    int tour;
} partie;

#include "affichage.h"
#include "deplacement.h"
#include "saut.h"
#include "initJeu.h"

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 25 Apr 2020 20:59
 *
 *  @brief execute un tour
 *
 *  @param[in,out] partie : Adresse de la partie
 *
 */
void executeTour(partie *partie);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 25 Apr 2020 20:58
 *
 *  @brief change le joueur courant
 *
 *  @param[in,out] partie : Adresse de la partie
 *
 */
void joueurSuivant(partie *partie);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 25 Apr 2020 20:55
 *
 *  @brief joue une partie
 *
 *  @param[in,out] partie : Adresse de la partie
 *
 */
void jouePartie(partie *partie);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 26 Apr 2020 16:09
 *
 *  @brief Execute le bon mode de test
 *
 *  @param[in] mode : Mode a executer
 *
 */
void executeTest(int mode, partie *partie);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 26 Apr 2020 16:09
 *
 *  @brief Execute le bon mode de jeu
 *
 *  @param[in] mode : Mode a executer
 *
 */
void executeMode(int mode);

#endif // __JEU_H__
