# Pathfinder

## Auteur
- Baptiste Sousa : 100% du boulot

## Descriptif

Pathfinder récupère la table des dons (feats) de la base de données sql pathfinderfr-data.db et les affiche dans une liste. 
Dans cette application nous avons donc deux listes différentes, une qui affiche l'ensemble des dons existants et l'autre qui affiche uniquement les dons que nous avons ajoutés en favoris.
Nous pouvons accéder aux détails du don en cliquant sur un élément de la liste (c'est valable pour les deux listes), cependant, nous ne pouvons pas modifier les champs du don mais il est possible de changer la valeur du don isFav qui permet donc d'ajouter ou de retirer le don de la liste des favoris en cliquant sur une petite étoile.

## Usage

Lancer l'application suffit, toutes les données sont chargées depuis la BDD importée depuis l'application. Les favoris sont égalements chargés.

# Techniques de programmation utilisées

## QObject avec QProperties

Chaque feats est un QObject avec plusieurs propriétés, j'ai ajouté de multiples propriétés pour prévoir dans le futur une amélioration de l'application, effectivement elle pourrait permettre d'ajouter de nouveaux feats et/ou en supprimer. Cependant, au jour d'aujourd'hui je ne souhaite pas que cela soit possible et c'est pour ça que j'intéragis uniquement avec l'attribut isFav.

## PathfinderApp (Database + Persistance)

Ma classe PathFinderApp permet de faire intéragir le model avec la base de données, c'est cette classe qui s'occupe de charger les données de la base au lancement de l'application mais aussi de mettre à jour les dons favoris en les stockant dans la BDD.

## ListView + Model + FeatsList

Le coeur de l'application réside au sein du model et de sa FeatsList, effectivement, grâce à ces derniers nous pouvons intéragir avec nos données. Le model dispose d'une FeatsList qui est en fait une encapsulation d'une QList afin de pouvoir profiter des propriétés QObject tout en ayant les bénéfices d'une QList. Le model utilise cette liste pour émettre des signaux et ces signaux seront utilisés par la SilicaListView dans laquelle nous assignons à sa propriété model notre Model customisé.

## QSortFilterProxyModel

La QSortFilterProxyModel va venir envelopper notre Model afin de filtrer nos données selon les filtres que nous allons lui attribuer. Ici nous filtrerons uniquement sur l'attribut boolean isFavoris. Ce model fraichement filtré sera attribué à la propriété model de notre SilicaListView présent dans la page des favoris.

## PullDownMenu

Un PullDownMenu est présent dans la page d'accueil et permet de naviguer entre la liste filtrée et la non filtrée.

## Clic

Un clic sur un élément d'une des deux listes ouvre la page de détails.

## SearchBar

La liste des feats peut être filtrée en tapant du texte dans la SearchBar. Si le nom d'un feats contient le texte tapé, il sera affiché.

## Détails : modif

La page de détails contient toutes les informations d'un Feats, vous noterez une petite étoile qui change de couleur quand vous cliquez dessus, cela signifie que vous avez ajouté en favoris le Feats si l'étoile est en surbrillance, sinon que vous l'avez retiré (par défaut, la liste des favoris est vide dans l'application).

## Bugs

Impossible d'UPDATE la base de données et donc de sauvegarder la liste des favoris, une erreur stipulant que la BDD est en lecture seul nous en empêche.

## Précisions

J'aurais aimé avoir une interface plus jolie et ajouter des filtres mais étant donné la charge de travail de cette période et étant seul sur le projet, je n'ai pas pu approfondir encore plus l'application.
