/** @file saut.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 25 Apr 2020 18:18
 *
 *  @brief 
 *
 */

#ifndef __SAUT_H__
/**
*  @def __SAUT_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __SAUT_H__

#include "jeuBase.h"

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 20 Apr 2020 15:31
 *
 *  @brief Test si un saut est possible
 *
 *  @param[in,out] partie : Adresse de la partie
 *  @param[in] coordTest : coordonée a tester
 *  @param[in] direction : direction ou faire le test
 *  @return 1 si le deplacement est possible dans cette direction, 0 sinon
 *
 */
int sautPossible(partie *partie, coord coordTest, deplacement direction);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 25 Apr 2020 18:24
 *
 *  @brief 
 *
 *  @param[in,out] partie : Adresse de la partie
 *  @param[in,out] pion : Adresse du pion
 *  @return 1 si un saut est possible, 0 sinon
 *
 */
int testSautPossiblePion(partie *partie, pion *pion);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 25 Apr 2020 17:50
 *
 *  @brief Test et execute un saut
 *
 *  @param[in,out] partie : Adresse de la partie
 *  @param[in,out] pion : Adresse du pion
 * 
 */
void saut(partie *partie, pion *pion);

#endif // __SAUT_H__
