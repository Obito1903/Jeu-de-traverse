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