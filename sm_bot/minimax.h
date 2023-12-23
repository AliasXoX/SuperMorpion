#include "superMorpion.h"

typedef struct
{
    char position[5];
    int poids;
}T_result;


T_result minimax(T_superM morpi, int depth, int traitOrdi, int visible); //visible permet d'afficher quelque chose ou non
T_result alphabeta(T_superM morpi, int depth, int traitOrdi,int alpha,int beta, int visible); //visible permet d'afficher quelque chose ou non
T_result negamax(T_superM morpi, int depth, int visible);
T_result negalphabeta(T_superM morpi, int depth,int alpha,int beta, int visible);
int max(int,int);
int min(int,int);
T_superMorpion rotation(T_superMorpion morpi,int k);//fait une rotation de la grille de supermorpion de sorte à ce que les cases soient décalées de k de manière indirecte par rapport à initialement
int grilleGagnee(T_superMorpion,int); //Renvoit le nombre de morpions gagnés pour celui au trait
int evalPositionMorpion(T_superMorpion,int,int);//Détermine les meilleurs positions des grilles gagnées pour le joueur au trait
int eval(T_superMorpion,int); //Fonction d'évaluation du minimax pour celui au trait