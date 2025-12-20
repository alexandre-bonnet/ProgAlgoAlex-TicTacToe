Bienvenue dans le projet TicTacToe de Alexandre Bonnet
Vous pouvez choisir le mode Multijoueurs ou Solo contre l'ordinateur.
pour jouer saisissez le numéro de la case corresponsante :
 ===========
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
 ===========

J'ai divisé mon jeu un 3 fichiers cpp principaux (main.cpp sert juste à lancer le programme). 
-  player.cpp gère la structure Player et les fonctions qui lui sont associées comme l'initialisation et un seter.
-  board.cpp gère la structure gameBoard et ses fonctions.
Pour mon système de board. J'ai choisi de faire une Array d'int, chaque joueur a un symbole et un int qui lui correspond.
Cela m'a permi de faire un systeme d'IA plus efficace.
-  game.cpp va gérer tout le reste, les fonctions liées à la partie en cours.

J'ai choisi le systeme d'Array d'int car ça rendait le code moins lourd au niveau de la fonction checkWin.
On a simplement besoin de faire le produit des trois cases et voir si osn résultat est égal au cube du signe du joueur.
Pour l'ia, la détéctions de deux signes alignés est aussi plus facile. Cette fois l'addition est nécéssaire. La multiplication rendrait 0 si au moins une case est vide sur la rangée.
On peut donc détecter si le résultat est 2 (le joueur a deux pions sur la ligne) ou bien 6 (L'ia a deux pions sur la ligne).
L'ia joue d'abord pour gagner, puis pour bloquer et enfin, en random si aucune occasion se présente.
Pour l'affichage de la board, les ints sont convertis en symboles du joueur correspondant.

Bon jeu !
Alexandre BONNET
E3 IMAC