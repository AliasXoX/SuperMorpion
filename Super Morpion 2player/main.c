#include <stdio.h>
#include <string.h>

#include "morpion.h"
#include "superMorpion.h"

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

int main() {
    
    T_superMorpion morpi = newSuperMorpion();
    
    char position[5];
    
    showSuperGrille(&morpi);
    showSuperGrilleState(&morpi);
    fflush(stdout);
    fgets(position, sizeof(position), stdin);
    morpi = ajouteSuperPosition(morpi, position);
    showSuperGrille(&morpi);
    showSuperGrilleState(&morpi);
    fflush(stdout);
    
    while (!checkSuperGagnant(&morpi)) {
        clearInputBuffer();
        if (fgets(position, sizeof(position), stdin) == NULL) {
            break;
        }
        morpi = ajouteSuperPosition(morpi, position);
        showSuperGrille(&morpi);
        showSuperGrilleState(&morpi);
    }
    
    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    if (c == EOF) {
        clearerr(stdin); // Clear the end-of-file indicator if encountered
    }
}
