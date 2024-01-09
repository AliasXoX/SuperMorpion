#include "morpion.h"

#ifndef MAXLEN

    #define MAXLEN 1001

#endif

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

void showSuperGrille(T_superM pSuperMorpion);
T_superMorpion newSuperMorpion();
T_superM ajouteSuperPosition(T_superM pSuperMorpion, char position[5], int showNextCase);
int checkSuperGagnant(T_superM pSuperMorpion);
void showSuperGrilleState(T_superM pSuperMorpion);
void showPosition(T_superM pSuperMorpion, char chemin[MAXLEN]);
T_superM removeLastSuperPosition(T_superM pSuperMorpion, char position[5], int isCaseAuChoix);
T_superM initSuperGrille(T_superM pSuperMorpion, char superPosition[MAXLEN]);
