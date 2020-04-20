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
#include "affichage.h"

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 16:38
 *
 *  @brief place les pion du joueur a leurs emplacement d'origine sur le plateau
 *
 *  @param[in,out] partie : Adresse de la partie a modifier
 *  @param[in,out] pion : Adresse du pion a placer
 *  @param[in] coord : coordonées ou placer le pion
 *
 */
void placePion(partie *partie, pion *pion, coord coord);

/** @fn void enlevePion (partie *partie, int idJoueur, int idPion)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 19 Apr 2020 19:00
 *
 *  @brief enleve un pion du plateau
 *
 *  @param[in,out] partie : Adresse de la partie a modifier
 *  @param[in,out] pion : Adresse du pion a enlever
 *
 */
void enlevePion(partie *partie, pion *pion);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 20 Apr 2020 14:04
 *
 *  @brief réalise le deplacement d'un pion sur le plateau
 *
 *  @param[in,out] partie : Adresse de la partie a modifier
 *  @param[in,out] pion : Adresse du pion a deplacer
 *  @param[in] coord : coordonées ou deplacer le pion
 *
 */
void deplacePionPlateau(partie *partie, pion *pion, coord coordArrive);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 20 Apr 2020 15:02
 *
 *  @brief 
 *
 *  @param[in] Origine : emplacement a partir du quel le deplacement est realiser
 *  @param[in] direction : direction a convertir
 *  @return les coordonées correspondent
 *
 */
coord convertDirection(coord Origine, deplacement direction);

/** @fn
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 20 Apr 2020 14:17
 *
 *  @brief gere le deplacement d'un pion caré
 *
 *  @param[in,out] partie : Adresse de la partie a modifier
 *  @param[in,out] pion : Adresse du pion a deplacer
 *  @param[in] direction : direction vers ou deplacer le pion
 *  @return 1 si la pion a pu ce deplacer, 0 sinon
 *
 */
int deplaceCare(partie *partie, pion *pion, deplacement direction);

#endif // __DEPLACEMENT_H__
