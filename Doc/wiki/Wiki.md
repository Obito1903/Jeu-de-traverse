# Wiki

Bienvenu sur le wiki du "Jeu de traverse" réaliser par:

- Rodrigues Samuel
- Meunier William
- Paesa Théo

## Structure des données du jeu

Le jeu de traversse necessite de connaitre en permanance l'etat du plateau ainsi que a qui appartien chaque pion et quel est le type de chaque pion.

Ainsi nous avons decidé de stocker l'etat du jeu de cette maniere:

- Partie
  - Joueurs : tableau de joueurs
  - Plateau : tableau a deux dimension qui contient les pions

Un a donc un structure contenant un tableau qui stock les donnée la structure de chaque joueur est un tableau à 2 dimension representant le plateau

### Joueur

Commencons par expliqué le tableau de joueur.

Le tableau de joueur contient dans chaque case un structure represantant l'etat d'un joueur comme ceci

- Joueurs
  - joueur 1
    - id : numeros du joueur
    - pions : tableau contenant les pion du joueur et leur etat
    - couleur : couleur du joueur a afficher sur le plateau
    - zoneArr : l'emplacement de la zone d'arrivé
  - joueur 2...

A l'interieur de la structure de chaque joueur on retrouve donc plein d'information utiles. L'id du joueur (sont utilité sera expliqué plus tard quand on parlera du plateau),
la liste des pions du joueur qui contient dans chaque case l'etat de chaque pion, Et enfin la couleur du joueur ainsi que ca zone d'arrivé.

#### Pion

Maintenant qu'on sait comment l'etat de chaque joueur est stocker on peut s'interessé a comment l'etat de chaque pion est stocké.

Comme on a pu le voir la liste des pions est stocker a l'interieur de l'etat du joueur cela permet d'acceder facilement au information des pion possedé par le joueur.

la structure d'un pion est donc la suivante: 

- Pion
  - Proprietere : adresse vers la structure du joueur possedant le pion
  - Type : type du pion (losange, caré, cercle, triangle)
  - coordonées : les coordonées du pion sur le plateau

Le fait de stocké l'adresse vers la structure du joueur possedant le pion permet ainsi de pouvoir facilement determiner a qui appartient le pion ainsi que la couleur qu'il doit avoir.

### Plateau

Le plateau de jeu est representé par un tableau a 2 dimension contenant l'addresse des piont placée sur le plateau a la case corespondante. Ainsi si on regarde une case du plateau on a quelque chose de la sorte :

