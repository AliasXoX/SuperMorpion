#include "morpion.h"

#ifndef NB_CASES

    #define NB_CASES 9

#endif


#ifndef _SUPERMORPION_H_

    #define _SUPERMORPION_H_

    typedef struct {
        int trait;
        T_morpion grille[NB_CASES]; // attention à la numérotation
        int valide[NB_CASES + 1]; // la dernière case sert à donner la case dans laquelle le joueur joue, vaut -1 si le joueur doit choisir.
    } T_superMorpion, *T_superM;

#endif

/*
 Il ne faudra plus empêcher le joueur i de jouer dans un morpion s'il a été le dernier à jouer.
 Il ne faudra pas utiliser la fonction showGrille pour afficher le super morpion.
 Il faudra trouver un moyen d'indiquer au joueur dans quel morpion il joue (s'il n'a pas le choix) et alors ne pas rendre nécessaire de préciser le morpion lors de la commande de jeu.
 ajouteSuperPosition devra utiliser ajoutePosition.
 Il faudra modifier showGrilleState pour pouvoir l'utiliser dans showSuperGrilleState.
 Il faudra utiliser le pattern suivant pour les morpions :
 1 2 3
 4 5 6
 7 8 9
 */

void showSuperGrille(T_superM pSuperMorpion);
T_superMorpion newSuperMorpion();
T_superMorpion ajouteSuperPosition(T_superMorpion superMorpion, char position[5]);
int checkSuperGagnant(T_superM pSuperMorpion);
void showSuperGrilleState(T_superM pSuperMorpion);


