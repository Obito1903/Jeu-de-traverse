/** @file affichage.h
 *  @author Théo Paesa <theo.paesa@eisti.eu>
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
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 15:37
 *
 *  @brief Permet d'afficher le plateau
 *
 *  @param[in] pPartie : adresse de la partie à afficher
 * 
 */
void affichePlateau(partie *pPartie);

/**
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Mon 20 Apr 2020 14:32
 *
 *  @brief Demande a l'utilisateur d'entre le deplacement a réaliser
 *
 *  @param[in,out] pPartie : Adresse de la partie
 *  @param[in,out] pPion : Adresse du pion a deplacer
 *  @param[in,out] bool_EstSaut : permet de savoir si les deplacement fait suite a un saut
 *
 */
void demandeDeplacement(partie *pPartie, pion *pPion, int bool_EstSaut);

/**
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Sat 25 Apr 2020 19:10
 *
 *  @brief Demande au joueur de selectioner le pion a deplacer
 *
 *  @param[in,out] pPartie : Adresse de la partie
 *
 */
void selectionPion(partie *pPartie);

/**
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Sun 26 Apr 2020 16:12
 *
 *  @brief Affiche un menu pour choisir le mode de test
 * 
 */
void menuTest();

/**
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Sun 26 Apr 2020 16:06
 *
 *  @brief Affiche le menu qui permet de selectioner le mode de jeu
 *
 */
void menuPrincipale(void);

/**
 *  @author Théo Paesa <theo.paesa@eisti.eu>
 *  @version 0.1
 *  @date Sun 26 Apr 2020 16:59
 *
 *  @brief Affiche le message de fin
 *
 *  @param[in,out] pPartie : Adresse de la partie
 *  @param[in] i_EtatFin : id de la fin a afficher
 *
 */
void afficheFin(partie *pPartie, int i_EtatFin);

#endif // __AFFICHAGE_H__