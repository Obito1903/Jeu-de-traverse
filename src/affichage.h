/** @file affichage.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 19 Apr 2020 16:30
 *
 *  @brief Gere l'affichage du jeu
 *
 */

#ifndef __AFFICHAGE_H__
/**
*  @def __AFFICHAGE_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __AFFICHAGE_H__

#include "jeuBase.h"
#include "lib/samIO.h"
#include "deplacement.h"

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 15:37
 *
 *  @brief Permet d'afficher le plateau
 *
 *  @param[in] plateau : adresse du plateau à afficher
 * 
 */
void affichePlateau(pion ***plateau);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 20 Apr 2020 14:32
 *
 *  @brief 
 *
 *  @param[in]
 *
 */
void demandeDeplacement(partie *partie, pion *pion);

#endif // __AFFICHAGE_H__