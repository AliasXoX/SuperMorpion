#include "superMorpion.h"

#ifndef MAXLEN

    #define MAXLEN 1001

#endif

#ifndef NB_CASES

    #define NB_CASES 9

#endif

void showMenuDebug(void);
T_superMorpion newConfigSuperGrille(char newSuperConfig[MAXLEN]);
//T_superM ajouteSuperRootPosition(T_superM pSuperMorpion, char position[5]);
int isFormatValide(char position[MAXLEN]);
