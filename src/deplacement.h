/** @file deplacement.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 19 Apr 2020 16:34
 *
 *  @brief 
 *
 */

#ifndef __DEPLACEMENT_H__
/**
*  @def __DEPLACEMENT_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __DEPLACEMENT_H__

#include "jeuBase.h"

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 16:38
 *
 *  @brief place les pion du joueur a leurs emplacement d'origine sur le plateau
 *
 *  @param[in,out] partie : Adresse de la partie a modifier
 *  @param[in] idJoueur : id du Joueur auquel le pion appartient
 *  @param[in] idPion : id du pion a placer
 *  @param[in] coord : coordonées ou placer le pion
 *
 */
void placePion(partie *partie, int idJoueur, int idPion, coord coord);

#endif // __DEPLACEMENT_H__
