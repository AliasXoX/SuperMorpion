#include <stdio.h>
#include <string.h>

#include "morpion.h"
#include "superMorpion.h"
#include "minimax.h"

/*
typedef struct {
    int trait;
    char grille[NB_CASES];
    char valide[NB_CASES];
} * T_morpion;
*/

/*
3 | 2 5 8
2 | 1 4 7
1 | 0 3 6
    a b c
*/





void clearInputBuffer();
int toPos(char * s);

int main(int argc, char *argv[])
{
    
    if (argc>5)
    {
        printf("ERREUR ARGUMENTS ERRONÉS\n");
        return(1);
    }

    int depth = 5;
    char fen[100];
    int temps = atoi(argv[2]);
    sprintf(fen,"%s",argv[1]);
    

    int evalt = evalTemps(fen);
    if (evalt<20) {depth = 7;}
    else if (evalt>=20&&evalt<50) {depth = 8;}
    else {depth = 9;}
    if (temps<6) {depth = 3;}
    int traitOrdi = -1;
    T_superMorpion m = decryptSuper(fen);
    traitOrdi = m.trait;
    T_result r = alphabeta(&m,depth,traitOrdi,-99999,99999,0);
    printf("%d",toPos(r.position));
    return(0);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    if (c == EOF) {
        clearerr(stdin); // Clear the end-of-file indicator if encountered
    }
}

int toPos(char * s) //Traduit des coordonnées de la forme 1 b2 en 15
{
    int i = atoi(&s[0])-1;
    int j = 0;
    if (s[2]=='a')
    {
        j = 6 - (atoi(&s[3])-1)*3;
    }
    if (s[2]=='b')
    {
        j = 7 - (atoi(&s[3])-1)*3;
    } 
    if (s[2]=='c')
    {
        j = 8 - (atoi(&s[3])-1)*3;
    }
    i++;
    j++;
    return(i*10+j);
}