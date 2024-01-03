#include "superMorpion.h"

typedef struct
{
    char position[5];
    double poids;
}T_result;


T_result minimax(T_superM morpi, int depth, int traitOrdi, int visible); //visible permet d'afficher quelque chose ou non
T_result alphabeta(T_superM morpi, int depth, int traitOrdi,double alpha,double beta, int visible); //visible permet d'afficher quelque chose ou non
T_result negamax(T_superM morpi, int depth, int visible);
T_result negalphabeta(T_superM morpi, int depth,int alpha,int beta, int visible);
double max(double,double);
double min(double,double);
T_superMorpion rotation(T_superMorpion morpi,int k);//fait une rotation de la grille de supermorpion de sorte à ce que les cases soient décalées de k de manière indirecte par rapport à initialement
int grilleGagnee(T_superMorpion,int); //Renvoit le nombre de morpions gagnés pour celui au trait
int convert(char c,int traitOrdi);
int evalPositionMorpion(T_morpion,int traitOrdi); //Fonction d'évaluation pour un morpion classique
int evaluation(T_superMorpion,int); //Fonction d'évaluation du minimax pour celui au trait

T_result show_alphabeta(T_superM morpi, int depth, int traitOrdi,double alpha,double beta, int visible,int parent,FILE* fichier);