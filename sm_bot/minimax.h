#include "superMorpion.h"

typedef struct
{
    char position[5];
    double poids;
}T_result;


T_result minimax(T_superM morpi, int depth, int traitOrdi, int visible); //minimax qui favorise l'ordi;visible permet d'afficher quelque chose ou non
T_result alphabeta(T_superM morpi, int depth, int traitOrdi,double alpha,double beta, int visible); //élagage alpha-beta qui favorise l'ordi; visible permet d'afficher quelque chose ou non
double max(double,double); //retourne le maximum de deux nombres
double min(double,double); //retourne le minimum de deux nombres
int convert(char c,int traitOrdi); //converti un symbole x et o en 1 ou -1 selon le trait de l'ordi
double evalPositionMorpion(T_morpion,int traitOrdi); //Fonction d'évaluation pour un morpion classique
double evaluation(T_superMorpion,int); //Fonction d'évaluation du minimax pour celui au trait