#include <stdio.h>
#include <string.h>

#include "morpion.h"
#include "minimax.h"


#ifndef MAXLEN

    #define MAXLEN 1001

#endif

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

int main(int argc, char *argv[]) {
    
    //char temp[MAXLEN] = {'o', 'x', 'o', 'x', 'o', 'o', 'x', '.', '.', 'o'};
    //printf("isProchainCoupGagnant(temp) = %d\n\n", isProchainCoupGagnant(temp));
    //char aux[MAXLEN] = {'o', 'x', 'o', 'x', 'o', 'o', 'x', '.', 'x', 'o'};
    //printf("isGagnant(temp) = %d\n\n", isGagnant(aux));
    
    if (argc > 1) {
        printf("digraph  {\n");
        
        T_minimax minimax = newMinimax(argv[1]);
        T_result result = &minimax;
        
        createGraph(result, 0, -1, "green", 'o', 0);
        
        if (result->grille[NB_CASES] == 'x') {
            result->grille[NB_CASES] = 'o';
        } else {
            result->grille[NB_CASES] = 'x';
        }
        
        tourSuivant(result, 0, "green");
        printf("}\n");
        
    } else {
        printf("pas d'argument\n");
    }
    
    return 0;
}
