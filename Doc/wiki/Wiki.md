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

le premier element de la structure `joueur` est l'`id` qui nous permet donc d'identifier le joueur stocker dans cette structure. Ensuite nous avons l'element `pions` qui est un tableau contenant chaque pion sous la forme d'un structure `pion`. Ensuite on a la du joueur qui de type couleur, une énumeration des couleur disponible dans le jeu. De meme pour l'element [`zoneArr`](https://obito.fr/docs/jeuTraversse/structjoueur.html#a4f51748e7b49508e5dd9454d97c0d455) qui est une énumeration de chaque coin du plateau (sous forme de direction). Enfin `inactivite` nous permet de compter le nombre de tour consecutif ou le joueur n'a pas bougé de pion.

### Structure de Pion

La structure `pion` nous sert a stocker toutes les données relative a un pion

```C
typedef struct
{
    /*! Joueur au quel le point appartient */
    joueur *joueur;
    /*! Type du pion */
    typePion type;
    /*! Type du pion */
    listeCoupPossiblePion coupsPossibles;
    /*! Coordonées du pion sur le plateau */
    coord coord;
} pion;
```

Cette structure contient donc tous ce qui nous est necessaire de savoirs a propos d'un pion. Le joueur auquel il appartient grace au pionteur `joueur` qui renvoie donc vers le joueur lié au pion. le type de pion qui est de type [`typePion`](https://obito.fr/docs/jeuTraversse/jeuBase_8h.html#a14b3bb39a048fc794d50959e2d2d497b), La liste des coup possible par ce pion (ie: les direction qui lui sont possible de réaliser). Et enfin une structure contenant les coordonées du pion sur le plateau.

## Gestion des mouvements

La gestion des mouvement est quelque chose d'assez simple il suffit pour un pion donnée recuperer ces coordonées, calculé ces coordonées d'arrivé, l'enlever du plateau et le replacer au nouvel coordonées.

Nous avons donc découper le deplacement en 3 phases:

- Calcule des coordonées d'arrivé
- Supression du pion sur le plateau
- Placement du pion au nouvelles coordonées

Pour la premiere phase on demande donc au joueur de selectionner le pion à deplacer à l'aide de ses coordonées sur le plateau ainsi que d'indiqué la direction dans laquel il veut le deplacer.

Une fois les informations nécéssaire connue on commence par calculé les coordonées d'arrivé. Pour cela nous avons implementer la fonction [`convertDirection()`](https://obito.fr/docs/jeuTraversse/deplacement_8c.html#aa2842b15e47848f014d2b1eb45adddc9) qui prend en parametre les coordonées actuel du pion ainsi que la direction dans laquel la direction qand laquel le deplacer (cf: [`deplacement`](https://obito.fr/docs/jeuTraversse/jeuBase_8h.html#a6d4ffc154a40ec48a05a6ed74f2bb619)) et renvoie les coordonées ou le pion sera deplacer.

Ensuite il nous faut verifier que les coordonées renvoyé sont valides pour ça on test si les coordonées renvoyé de pointe pas en dehors du plateau ou vers un case deja ocupé auquel que on redemandera d'entré les coordonées au joueur ou on initiera un saut si cela est possible.

Une faut que les coordonées on etait validé on s'ocupe de s'implement retiré l'adresse vers le pion a deplacer du plateau.

Finalement il nous sufit de mettre a jour les coordonées du pion ainsi que de le replacer en ses nouvelles coordonées sur le plateau.

## IA

L'inteligence artificiel à était implementé grâce à l'algorithme MinMax qui nous a était proposé. Bien qu'assez lent il nous suffit car notre but n'est pas de faire de notre IA la plus performante mais plutot de l'implementer correctement.

## Sauvegarde d'une partie

Pour sauvegarder une partie il nous suffit d'ecrire les donées d'une partie dans un fichier puis de pouvoir le recharger plus tard. Cependant nous n'avons pas besoin de stocké toutes les données contenu dans la structure `partie`, Ainsi nous n'ecrivons que le numéros du tour, l'id du joueur courant et la liste joueur et des pion ainsi que leurs position sur le plateau.

Pour charger une partie il nous suffi donc d'initialiser une nouvelle partie et d'ecrire par dessu les information de la partie sauvegarder.

## Paufinage

Nous avons sur les dernier jours qui nous rester passez beacoup de temps a nous assurer qu'il n'y pas de fuite memoire autrement dit que tout ce qui a était alloue de maniere dynamique a bien était libéré quand il faut. Cela a était très fastidieux en particulier avec l'IA qui génère beacoup de plateau de jeu constitué d'enormement d'element alloué dynamiquement
