# GIT help

## Install Git

Premierement il faut installer Git

### linux

```bash
sudo apt install git
```

### Windows

Il suffit de telecharger la derniere version ici : <https://git-scm.com/download/win>

## Initialisation de Git

Dans le terminal entrer ceci:

```bash
Git global setup

git config --global user.name "Premon Nom"

git config --global user.email "prenom.nom@eisti.fr"
```

## Le principe

Git est un outil créé pour nous aider à partager et suivre les changements apportés à un code source. Pour ce projet il n'est pas nécessaire de tout connaitre mais seulement quelques fonctionnalités essentielles.

Cette partie ne fait qu'expliquer comment Git fonctionne dans les grandes lignes toutes les manipulations spécifiques à chaque fonctionnalités sont expliquées [plus bas](#command-line).

A la création du nouveau projet il faut commencer par créer un "repository", un dépôt ou seront stocker les fichiers. Mais cela est déjà fait dans notre cas il n'est donc pas nécessaire de détailler plus

Lorsque vous avez été invité à rejoindre un projet il vous faut copier les fichiers sur votre ordinateur ([CLI](#cloner-un-repo)/VSCoce).

Une fois que le repo a été cloner vous pouvez commencer à éditer votre code, y ajouter de nouveaux fichiers...

Quand vous avez fini d'éditer le code ou que vous voulez faire une sauvegarde de votre travail pour l'envoyer sur le repo il vous faudra d'abord soumettre les fichiers à Git grâce à la fonction "commit" ([CLI](#commit-son-code)/VSCoce). Mais cela n'est pas suffisant, car le "commit" s'occupe uniquement d'appliquer les changer sur les fichiers locaux pour ensuite envoyer les modifications et repo et donc les rendre accessible à tout le monde il faut utiliser "Push" ([CLI](#push-son-code)/VSCoce).

Si le code a été modifié par un autre utilisateur il vous faut récupérer les modifications pour ça on utilise "Pull" ([CLI](#pull-son-code)/VSCoce).

## Command line

Si vous souhaitez utiliser Git en ligne de commande.

### Cloner un repo

Aller dans le dossier où vous souhaitez stocker le projet et executé ces commandes:

```bash
git clone https://gitlab.etude.eisti.fr/rodriguess/jeu-de-traverse.git

cd jeu-de-traverse
```

### Commit son code

Si vous avez créé de nouveaux fichiers il faut d'abord les ajouter à la liste des fichiers:

```bash
git add myNewFile
```

Vous pouvez ensuite effectuer le commit:

```bash
git commit -m "Your message"
```

### Push son code

```bash
git push origin master
```

### Pull son code

```bash
git pull origin master
```

## VScode

Je recommande d'utiliser VSCode, car il est simple d'utilisation et possède des outils permettant de gérer Git bien plus facilement (les éditeurs comme Sublime ou Atom possèdes aussi ce genre de fonctionnalité, mais sont moins complet que VSCode).

### Clone

Appuyer sur <kbd>Ctrl</kbd> + <kbd>shift</kbd> + <kbd>P</kbd> pour ouvrir la palette de commande et entrer `Git Clone` on vous demandera donc d'entrer l'adresse du Git a cloner puis le dossier ou le stocker.

Vous pouvez aussi utiliser l'interface graphique directment.

### Commit

En général avant de commit il faut "stage" les changements c'est-à-dire les valider, mais ce n'est pas nécessaire dans un projet comme le notre. On va donc directement commit.

Comme pour cloner un repo vous pouvez commit en utilisant directement les boutons dédié de l'interface de VSCode ou ouvrir la palette (<kbd>Ctrl</kbd> + <kbd>shift</kbd> + <kbd>P</kbd>) et entrer `Git Commit`.

### Push to repo

Pour Push il suffit d'entrer `Git Push` dans la palette de commande.

Pour Pull c'est la meme chose avec `Pull` a la place de `Push`.
