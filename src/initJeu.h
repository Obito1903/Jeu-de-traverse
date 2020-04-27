/** @file initJeu.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 19 Apr 2020 16:28
 *
 *  @brief 
 *
 */

#ifndef __INITJEU_H__
/**
*  @def __INITJEU_H__
*  Constante permettant de savoirs si le fichier à déjà été chargé.
*/
#define __INITJEU_H__

#include "jeuBase.h"
#include "deplacement.h"
#include <sys/types.h>
#include <sys/stat.h>

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 19 Apr 2020 17:30
 *
 *  @brief Alloue l'espace memoire pour une partie
 *
 *  @param[in,out] partie : adresse de la partie a alloué
 *
 */
partie *allocPartie();

/*
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 27 Apr 2020 17:48
 *
 *  @brief Libere l'espace memoire occupé par une partie
 *
 *  @param[in,out] partie : adresse de la partie a liberer
 *
 */
void freePartie(partie *partie);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 17:27
 *
 *  @brief permet de savoir quel sera le type du pion qui sera placer à l'initialisation
 *
 *  @param[in] int_i : iterateur qui doit etre testé
 *  @return retourne le type du pion qui
 *
 */
typePion defTypePion(int int_i);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 17:14
 *
 *  @brief Place les pions du joueur a leur emplacement initiale
 *
 *  @param[in,out] partie : adresse de la partie
 *  @param[in] idJoueur : numero du joueur a qui les pions appartiendrons
 *
 */
void initPions(partie *partie, int idJoueur);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 19 Apr 2020 16:42
 *
 *  @brief Definie la couleur du joueur
 *
 *  @param[in,out] partie : adresse de la partie
 *  @param[in] idJoueur : le numero du joueur
 *  @return Retourne le joueur avec ca couleur et zone defini;
 *
 */
void defZoneJoueur(partie *partie, int idJoueur);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 17:39
 *
 *  @brief initialise un joueur
 *
 *  @param[in,out] partie : l'adresse de la partie
 *  @param[in] idJoueur : numero du joueur
 *
 */
void initJoueur(partie *partie, int idJoueur);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 17 Apr 2020 16:27
 *
 *  @brief Initialise la partie
 *
 *  @return Le plateau de jeux
 *
 */
partie *initPartie(void);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 27 Apr 2020 18:03
 *
 *  @brief Crée un copie de la partie
 *
 *  @param[in] partieOriginal : la partie a copier
 *  @return la copie de la partie entré en parametre
 *
 */
partie *copiePartie(partie *partieOriginal);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 27 Apr 2020 18:35
 *
 *  @brief Sauvegarde la partie
 *
 *  @param[in] partie : la partie a sauvegarder
 *
 */
void sauvegarde(partie *partie);

/**
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 27 Apr 2020 18:59
 *
 *  @brief Charge une partie en memoire
 *
 *  @return La partie qui a était sauvegarder
 *
 */
partie *chargeSav(void);

#endif // __INITJEU_H__
