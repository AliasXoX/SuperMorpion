#ifndef MAXLEN

    #define MAXLEN 1001

#endif

#ifndef NB_CASES

    #define NB_CASES 9

#endif


#ifndef _MORPION_H_

    #define _MORPION_H_

    typedef struct {
        int trait;
        int state;  // -2, s'il n'a pas été gagné et ne peut pas être joué, -1 s'il n'a pas été gagné, 0 si O a gagné, 1 si X a gagné
        char grille[NB_CASES];
        int valide[NB_CASES];
    } T_morpion, * T_morp;

#endif

void showGrille(T_morp pMorpion);
T_morpion newMorpion();
T_morp ajoutePosition(T_morp pMorpion, char position[3]);
int checkGagnant(T_morp pMorpion, int showGagnant);
void showGrilleState(T_morp pMorpion);
T_morp initGrille(T_morp pMorpion, char position[MAXLEN]);
