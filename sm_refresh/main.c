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

int main() {
    
    T_superMorpion superMorpion = newSuperMorpion();
    
    T_superM pSuperMorpion = &superMorpion;

    T_superMorpion S = newSuperMorpion();

    char position[5];

    printf("Voulez vous commencer en premier (0) ou en deuxième (1) ?\n");
    int traitOrdi;
    scanf("%d", &traitOrdi);
    clearInputBuffer();

    if (traitOrdi)
    {
        showSuperGrille(pSuperMorpion);
        showSuperGrilleState(pSuperMorpion);
        showPosition(pSuperMorpion);
        fflush(stdout);
        T_result r = minimax(pSuperMorpion,5,0,0);
        S = ajouteSuperPosition(*pSuperMorpion, r.position,1);
        pSuperMorpion = &S;
        showSuperGrille(pSuperMorpion);
        showSuperGrilleState(pSuperMorpion);
        showPosition(pSuperMorpion);
        fflush(stdout);
    }
    else
    {
        showSuperGrille(pSuperMorpion);
        showSuperGrilleState(pSuperMorpion);
        showPosition(pSuperMorpion);
        fflush(stdout);
        fgets(position, sizeof(position), stdin);
        S = ajouteSuperPosition(*pSuperMorpion, position,1);
        pSuperMorpion = &S;
        showSuperGrille(pSuperMorpion);
        showSuperGrilleState(pSuperMorpion);
        showPosition(pSuperMorpion);
        fflush(stdout);
    }
    
    while (!checkSuperGagnant(pSuperMorpion)) {
        if (pSuperMorpion->trait==1)
        {
            clearInputBuffer();
            if (fgets(position, sizeof(position), stdin) == NULL) {
                break;
            }
            S = ajouteSuperPosition(*pSuperMorpion, position,1);
            pSuperMorpion = &S;
            showSuperGrille(pSuperMorpion);
            showSuperGrilleState(pSuperMorpion);
            showPosition(pSuperMorpion);
        }
        else
        {
            T_result r = minimax(pSuperMorpion,5,0,0);
            S = ajouteSuperPosition(*pSuperMorpion,r.position,1);
            pSuperMorpion = &S;
            showSuperGrille(pSuperMorpion);
            showSuperGrilleState(pSuperMorpion);
            showPosition(pSuperMorpion);
        }
        
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

