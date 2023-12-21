#include "superMorpion.h"

typedef struct
{
    char position[5];
    int poids;
}T_result;


T_result minimax(T_superM morpi, int depth, int traitOrdi, int visible); //visible permet d'afficher quelque chose ou non
T_result alphabeta(T_superM morpi, int depth, int traitOrdi,int alpha,int beta, int visible);
int max(int,int);
int min(int,int);
int grilleGagnee(T_superMorpion,int);