#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "morpion.h"

/*
typedef struct {
    int trait;
    int state;
    int grille[NB_CASES];
    int valide[NB_CASES];
} * T_morpion;
*/

/*
3 | 2 5 8
2 | 1 4 7
1 | 0 3 6
    a b c
*/




void showGrille(T_morpion morpion) {
    printf("-----\n");
    printf("%c %c %c \n", morpion.grille[2], morpion.grille[5], morpion.grille[8]);
    printf("%c %c %c \n", morpion.grille[1], morpion.grille[4], morpion.grille[7]);
    printf("%c %c %c \n", morpion.grille[0], morpion.grille[3], morpion.grille[6]);
    printf("-----\n");
}

char getChar(T_morpion morpion, int indice) {
    if (morpion.grille[indice] == -1) {
        return '.';
    } else if (morpion.grille[indice]) {
        return 'X';
    }
    return 'O';
}

T_morpion newMorpion() {
    T_morpion morpion = {1, -1, {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, {1, 1, 1, 1, 1, 1, 1, 1, 1}};
    
    return morpion;
}

T_morp ajoutePosition(T_morp pMorpion, char position[3]) {
    int column = (position[0] - 'a')*3 - 1;
    int line = atoi(&position[1]);
    
    if (!pMorpion->valide[column+line]) {
        printf("Coup invalide, rejouez !\n");
        return pMorpion;    
    }
    
    pMorpion->valide[column+line] = 0;
    
    char symbol = 'O';
    if (pMorpion->trait) {
        symbol = 'X';
    }
    pMorpion->grille[column+line] = symbol;
    
    return pMorpion;
}

int checkGagnant(T_morp pMorpion){
    
    int s = 0;
    for (int i = 0 ; i < NB_CASES ; i++) {
        if (!pMorpion->valide[i]) {
            s++;
        }
    }
    if (s < 3) {
        return 0;
    } else if (s == 9) {
        printf("Ce morpion est un match nul !");
        pMorpion->state = -2;
        return 1;
    }
    
    int gagnant = 0;
    int column = 0;
    while ((column < 3) && (!gagnant)) {
        if ((pMorpion->grille[column*4] != '.') && (pMorpion->grille[column*4 + 1] != '.') && (pMorpion->grille[column*4 + 2] != '.') && (pMorpion->grille[column*4] == pMorpion->grille[column*4 + 1]) && (pMorpion->grille[column*4] == pMorpion->grille[column*4 + 2])) {
            gagnant = 1;
            if (pMorpion->trait) {
                printf("Le joueur 1 a gagné un morpion !\n");
                pMorpion->state = 1;
            } else {
                printf("Le joueur 2 a gagné un morpion !\n");
                pMorpion->state = 0;
            }
        } else if ((pMorpion->grille[column] != '.') && (pMorpion->grille[column + 3] != '.') && (pMorpion->grille[column + 6] != '.') && (pMorpion->grille[column] == pMorpion->grille[column + 3]) && (pMorpion->grille[column] == pMorpion->grille[column + 6])) {
            gagnant = 1;
            if (pMorpion->grille[column]) {
                printf("Le joueur 1 a gagné un morpion !\n");
                pMorpion->state = 1;
            } else {
                printf("Le joueur 2 a gagné un morpion !\n");
                pMorpion->state = 0;
            }
        }
        column++;
    }
    
    if (((pMorpion->grille[2] == pMorpion->grille[4]) && (pMorpion->grille[2] == pMorpion->grille[6])) || ((pMorpion->grille[0] == pMorpion->grille[4]) && (pMorpion->grille[0] == pMorpion->grille[8]))) {
        if (((pMorpion->grille[2] != '.') && (pMorpion->grille[4] != '.') && (pMorpion->grille[6] != '.')) || ((pMorpion->grille[0] != '.') && (pMorpion->grille[4] != '.') && (pMorpion->grille[8] != '.'))) {
            gagnant = 1;
            if (pMorpion->grille[column]) {
                printf("Le joueur 1 a gagné un morpion !\n");
                pMorpion->state = 1;
            } else {
                printf("Le joueur 2 a gagné un morpion !\n");
                pMorpion->state = 0;
            }
        }
    }
    
    return gagnant;
}

void showGrilleState(T_morp pMorpion) {
    int ordre[] = {2, 5, 8, 1, 4, 7, 0, 3, 6};
    int i = 0;
    while (i < NB_CASES) {
        if (pMorpion->grille[ordre[i]] == 'X') {
            printf("x");
            i++;
        } else if (pMorpion->grille[ordre[i]] == 'O') {
            printf("o");
            i++;
        } else {
            int s = 0;
            while ((i < NB_CASES) && (pMorpion->grille[ordre[i]] == '.')) {
                s++;
                i++;
            }
            printf("%d", s);
        }
    }
}
