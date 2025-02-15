# DIS Mods Utils

*This readme exits in English*

Ce mod permet de partagé les fonction DIS.

A ce jours 2 fonctions sont implémenter :
1. Script de lumière
2. Garage DIS


## Les Fonctions :

### Script de lumière :
Ce script a été pensé en partant du postulat que on ne pouvais pas coupé les lampadaire dans les villes, ce qui peux etre génant lorsque l'ont souhaite faire des missions de nuits.

#### Utilisation :
Au lancement de la mission, pour vérifier l'activation de la fonctionallité le message suivant apparaît : "Script de lumière par \[DIS\]Wolv initialisé" (ou équivalent traduit). Si ce n'est pas votre cas, redémarrez votre mission, recommencez l'installation, puis demandez moi de l'aide si les problemes persistent. Si les fonctions se sont correctement exécuté, lorsque vous vous approchez d'un transformateur électrique, vous aurez les options suivantes dans le menue molette : 
- "Turn ON" : active le transformateur, les lumières à proximité, ainsi que toutes les lumières à proximité des poteaux électriques à proximité jusqu'au transformateur suivant, 
- "Turn OFF" : désactive le transformateur, les lumières à proximité, ainsi que toutes les lumières à proximité des poteaux électrique à proximité jusqu'au transformateur suivant.

Si vous le souhaitez, vous pouvez faire afficher sur la carte les informations suivantes, au choix, grâce à une interaction sur un objet prédéfini (voir installation). Les différente action sont les suivantes : 
- soit les transformateurs (conseillé) 
- soit le transformateur et leur rayon d'action sur les lampes 
- soit les transformateurs ainsi que tous les poteaux connectés (déconseillé car cause des chutes de FPS)
- soit les lignes éléctrique au complet (WIP)

#### Mise en place :
Lancer votre missions en eden editeur, dans le menue module, vous devrier trouvé le module "init Light" dans le dossier "Modules DIS".
La position ou direction du module n'ont pas d'impact.
si vous souhaité afficher des informations grace a une action mollette, choisier un objet, copier sont nom de variable dans le module, et choissier le niveaux de précission souhaité.




