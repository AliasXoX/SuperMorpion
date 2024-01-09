#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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




void showGrille(T_morp pMorpion) {
    printf("-----\n");
    printf("%c %c %c \n", pMorpion->grille[2], pMorpion->grille[5], pMorpion->grille[8]);
    printf("%c %c %c \n", pMorpion->grille[1], pMorpion->grille[4], pMorpion->grille[7]);
    printf("%c %c %c \n", pMorpion->grille[0], pMorpion->grille[3], pMorpion->grille[6]);
    printf("-----\n");
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
    pMorpion->trait = (pMorpion->trait + 1) % 2;
    
    return pMorpion;
}

int checkGagnant(T_morp pMorpion, int showGagnant) {
    
    int s = 0;
    for (int i = 0 ; i < NB_CASES ; i++) {
        if (!pMorpion->valide[i]) {
            s++;
        }
    }
    if (s < 3) {
        return 0;
    } else if (s == 9) {
        if (showGagnant) {
            printf("Match nul !");
        }
        pMorpion->state = -2;
        return 1;
    }
    
    int gagnant = 0;
    int column = 0;
    while ((column < 3) && (!gagnant)) {
        if ((pMorpion->grille[column*3] != '.') && (pMorpion->grille[column*3] == pMorpion->grille[column*3 + 1]) && (pMorpion->grille[column*3] == pMorpion->grille[column*3 + 2])) {
            gagnant = 1;
            if (pMorpion->grille[column*3] == 'X') {
                if (showGagnant) {
                    printf("Le joueur 1 a gagné un morpion ! (1)\n");
                }
                pMorpion->state = 1;
            } else if (pMorpion->grille[column*3] == 'O') {
                if (showGagnant) {
                    printf("Le joueur 2 a gagné un morpion ! (1)\n");
                }
                pMorpion->state = 0;
            }
        } else if ((pMorpion->grille[column] != '.') && (pMorpion->grille[column] == pMorpion->grille[column + 3]) && (pMorpion->grille[column] == pMorpion->grille[column + 6])) {
            gagnant = 1;
            if (pMorpion->grille[column] == 'X') {
                if (showGagnant) {
                    printf("Le joueur 1 a gagné un morpion ! (2)\n");
                }
                pMorpion->state = 1;
            } else if (pMorpion->grille[column] == 'O') {
                if (showGagnant) {
                    printf("Le joueur 2 a gagné un morpion ! (2)\n");
                }
                pMorpion->state = 0;
            }
        }
        column++;
    }
    
    if (((pMorpion->grille[2] == pMorpion->grille[4]) && (pMorpion->grille[2] == pMorpion->grille[6])) || ((pMorpion->grille[0] == pMorpion->grille[4]) && (pMorpion->grille[0] == pMorpion->grille[8]))) {
        if (pMorpion->grille[4] != '.') {
            gagnant = 1;
            if (pMorpion->grille[4] == 'X') {
                if (showGagnant) {
                    printf("Le joueur 1 a gagné un morpion ! (3)\n");
                }
                pMorpion->state = 1;
            } else if (pMorpion->grille[4] == 'O') {
                if (showGagnant) {
                    printf("Le joueur 2 a gagné un morpion ! (3)\n");
                }
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
        if ((pMorpion->grille[ordre[i]] == 'X') || (pMorpion->grille[ordre[i]] == 'x')) {
            printf("x");
            i++;
        } else if ((pMorpion->grille[ordre[i]] == 'O') || (pMorpion->grille[ordre[i]] == 'o')) {
            printf("o");
            i++;
        } else {
            int s = 0;
            while ((i < NB_CASES) && (pMorpion->grille[ordre[i]] == '.')) {
                s++;
                i++;
            }
            
            if (s == 0) {
                i++;
            } else {
                printf("%d", s);
            }
        }
    }
}

T_morp initGrille(T_morp pMorpion, char position[MAXLEN]) {
    int ordre[] = {2, 5, 8, 1, 4, 7, 0, 3, 6};
    int n = 0;
    
    for (int i = 0 ; i < NB_CASES ; i++) {
        pMorpion->grille[i] = '.';
    }
    
    for (int i = 0 ; i < strlen(position) - 2 ; i++) {
        char c = position[i];
        if (isdigit(c)) {
            n += c - '0';
        } else {
            pMorpion->grille[ordre[n]] = toupper(c);
            pMorpion->valide[ordre[n]] = 0;
            n++;
        }
    }
    pMorpion->trait = position[strlen(position) - 2] - '0';
    
    return pMorpion;
}
