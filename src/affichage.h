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

#include "lib/samIO.h"
#include "jeuBase.h"

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
void affichePlateau(partie *partie);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 20 Apr 2020 14:32
 *
 *  @brief Demande a l'utilisateur d'entre le deplacement a réaliser
 *
 *  @param[in,out] partie : Adresse de la partie
 *  @param[in,out] pion : Adresse du pion a deplacer
 *
 */
void demandeDeplacement(partie *partie, pion *pion, int estSaut);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 25 Apr 2020 19:10
 *
 *  @brief Demande au joueur de selectioner le pion a deplacer
 *
 *  @param[in,out] partie : Adresse de la partie
 *
 */
void selectionPion(partie *partie);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 26 Apr 2020 16:12
 *
 *  @brief Affiche un menu pour choisir le mode de test
 *
 */
void menuTest(partie *partie);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 26 Apr 2020 16:06
 *
 *  @brief Affiche le menu qui permet de selectioner le mode de jeu
 *
 */
void menuPrincipale(void);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 26 Apr 2020 16:59
 *
 *  @brief Affiche le message de fin
 *
 *  @param[in,out] partie : Adresse de la partie
 *  @param[in] etatFin : id de la fin a afficher
 *
 */
void afficheFin(partie *partie, int etatFin);

#endif // __AFFICHAGE_H__