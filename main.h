/** @file main.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 12:14
 *
 *  @brief Header du fichier main.c
 *
 */

#ifndef __MAIN_H__
/**
*  @def __MAIN_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __MAIN_H__

#include "src/jeuBase.h"
#include "src/affichage.h"
#include "src/initJeu.h"
#include "src/deplacement.h"

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
 *  @date Fri 17 Apr 2020 13:37
 *
 *  @brief Fonction Principale 
 *
 *  @param[in] argc
 *  @param[in] *argv[]
 *  @return EXIT_SUCCESS : le programme doit se terminer normalement
 *
 */
int main(int argc, char const *argv[]);

#endif // __MAIN_H__