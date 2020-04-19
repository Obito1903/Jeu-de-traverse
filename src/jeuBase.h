/** @file jeu.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 15:02
 *
 *  @brief Header du fichier jeu.c
 *
 */

#ifndef __JEU_H__
/**
*  @def __JEU_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __JEU_H__

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
    NORD,
    /*! Face sud du plateau */
    SUD,
    /*! Face est du plateau */
    EST,
    /*! Face ouest du plateau */
    OUEST
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
    /*!  */
    pion *plateau[TAILLEPLATEAU][TAILLEPLATEAU];
    joueur *joueurs;
} partie;

#endif // __JEU_H__
