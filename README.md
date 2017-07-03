# Ft_ls
Projet 42 - Langage C - Ft_ls
-----------------------------------------------------------------------------------------------------------------------------------------------

Ft_ls est un projet ayant pour but de nous faire recoder la fonction ls.

ls: ls est une commande POSIX (abréviation de list segments en anglais), qui permet d'afficher le contenu d'un répertoire.

Son comportement doit être identique à celui de la commande ls originale du système, avec les indications suivantes:
- Parmi les nombreuses options disponibles sur la ligne de commande, il nous est demandé de réaliser les suivantes : -l, -R, -a, -r et -t
- Nous n'avons pas à gérer le formatage en plusieurs colonnes de la sortie quand l’option -l n’est pas passée.
- Nous ne sommes pas obligés de gérer les ACL et les attributs étendus.
- L’affichage général, selon chaque option, doit rester sensiblement identique à celui de la commande système. Une certaine tolérance est appliquée sur le padding et la mise en page, mais il ne doit manquer aucune information.

Toutes les fonctions présentes ont été prototypées dans le fichier "ft_ls.h" et nous utilisons egalement notre Libft mise à jour avec les fonctions précédemment utilisées au cours des derniers projets.

Pour finir, l'ensemble du projet est compilable dans un environnement UNIX, via le Makefile. Les règles a dispositions sont les suivantes: clean, fclean, re

-----------------------------------------------------------------------------------------------------------------------------------------------
mtacnet@student.42.fr
