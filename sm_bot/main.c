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

int main() 
{
    T_superMorpion morpi = newSuperMorpion();
    T_superM pmorpi = &morpi;

    T_result r = alphabeta(pmorpi,7,1,-99999,99999,0);

    printf("ALPHABETA : %d  %s\n",r.poids,r.position);

    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    if (c == EOF) {
        clearerr(stdin); // Clear the end-of-file indicator if encountered
    }
}

