# Wiki

Bienvenu sur le wiki du "Jeu de traverse" réaliser par:

- Rodrigues Samuel
- Meunier William
- Paesa Théo

## Structure des données du jeu

Le jeu de traversse nécessite de connaitre en permanance l'état du plateau ainsi que à qui appartien chaque pion et quel est le type de chaque pion.

Ainsi nous avons decidé de stocker l'etat du jeu de cette maniere dans une structure comme celle ci

```C
typedef struct
{
    /*! tableau de joueur */
    joueur *joueurs;
    /*! Plateau de jeu (tableau 2D d'adresse de pion) */
    pion ***plateau;
    /*! adresse ver le joueur courant */
    joueur *joueurCourant;
    /*! numeros du tour */
    int tour;
} partie;
```

On à donc une structure contenant un tableau `joueurs` qui stock une liste de structure de joueur, un tableau a 2 dimension `plateau` qui en chaque case stock sois rien (aucun pion n'est a cette endroit sur le plateau) sois un pointeur vers le pion située en ces coordonées. Le pointeur `joueurCourant` renvoie a l'adresse du joueur courant situé dans le tableau `joueur`. Enfin `tour` qui permet de connaitre le numeros du tour actuel.

### Structure de Joueur

La structure `joueur` nous permet donc de stocker l'état d'un joueur suivant la structure suivante :

```C
struct joueur
{
    /*! Identifiant du joueur */
    int id;
    /*! Adresse vers le tableau contenant les pions du joueur */
    pion *pions;
    /*! Adresse vers le tableau contenant les pions du joueur */
    couleur couleur;
    /*! Permet de connaitre la zone d'arriver du joueur */
    facePlateau zoneArr;
    /*! Permet de connaitre le nombre de tours inactif*/
    int inactivite;
};
```

le premier element de la structure `joueur` est l'`id` qui nous permet donc d'identifier le joueur stocker dans cette structure. Ensuite nous avons l'element `pions` qui est un tableau contenant chaque pion sous la forme d'un structure `pion`. Ensuite on a la du joueur qui de type couleur, une énumeration des couleur disponible dans le jeu. De meme pour l'element `zoneArr` qui est une énumeration de chaque coin du plateau (sous forme de direction). Enfin `inactivite` nous permet de compter le nombre de tour consecutif ou le joueur n'a pas bougé de pion.

### Structure de Pion
