#include "superMorpion.h"

typedef struct
{
    char position[5];
    int poids;
} T_superResult;


T_superResult superMinimax(T_superMorpion SuperMorpion, int depth, int traitOrdi);
