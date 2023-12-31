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
            //printf("Coup invalide, rejouez !\n");
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

    int checkGagnant(T_morp pMorpion, int visible){
        
        int s = 0;
        for (int i = 0 ; i < NB_CASES ; i++) {
            if (!pMorpion->valide[i]) {
                s++;
            }
        }
        if (s < 3) {
            return 0;
        } else if (s == 9) {
            if (visible) {printf("Ce morpion est un match nul !");}
            pMorpion->state = -2;
            return 1;
        }
        
        int corres[9] = {6,3,0,7,4,1,8,5,2};

        int a = 'X';
        if (pMorpion->grille[corres[0]] + pMorpion->grille[corres[1]] + pMorpion->grille[corres[2]] == a * 3 || pMorpion->grille[corres[3]] + pMorpion->grille[corres[4]] + pMorpion->grille[corres[5]] == a * 3 || pMorpion->grille[corres[6]] + pMorpion->grille[corres[7]] + pMorpion->grille[corres[8]] == a * 3 || pMorpion->grille[corres[0]] + pMorpion->grille[corres[3]] + pMorpion->grille[corres[6]] == a * 3 || pMorpion->grille[corres[1]] + pMorpion->grille[corres[4]] + pMorpion->grille[corres[7]] == a * 3 ||
        pMorpion->grille[corres[2]] + pMorpion->grille[corres[5]] + pMorpion->grille[corres[8]] == a * 3 || pMorpion->grille[corres[0]] + pMorpion->grille[corres[4]] + pMorpion->grille[corres[8]] == a * 3 || pMorpion->grille[corres[2]] + pMorpion->grille[corres[4]] + pMorpion->grille[corres[6]] == a * 3) 
        {
            if (visible) {printf("Le joueur 1 a gagné un morpion !\n");}
            pMorpion->state = 1;
            return 1;
        }

        a = 'O';
        if (pMorpion->grille[corres[0]] + pMorpion->grille[corres[1]] + pMorpion->grille[corres[2]] == a * 3 || pMorpion->grille[corres[3]] + pMorpion->grille[corres[4]] + pMorpion->grille[corres[5]] == a * 3 || pMorpion->grille[corres[6]] + pMorpion->grille[corres[7]] + pMorpion->grille[corres[8]] == a * 3 || pMorpion->grille[corres[0]] + pMorpion->grille[corres[3]] + pMorpion->grille[corres[6]] == a * 3 || pMorpion->grille[corres[1]] + pMorpion->grille[corres[4]] + pMorpion->grille[corres[7]] == a * 3 ||
        pMorpion->grille[corres[2]] + pMorpion->grille[corres[5]] + pMorpion->grille[corres[8]] == a * 3 || pMorpion->grille[corres[0]] + pMorpion->grille[corres[4]] + pMorpion->grille[corres[8]] == a * 3 || pMorpion->grille[corres[2]] + pMorpion->grille[corres[4]] + pMorpion->grille[corres[6]] == a * 3) 
        {
            if (visible) {printf("Le joueur 2 a gagné un morpion !\n");}
            pMorpion->state = 0;
            return 1;
        }

        return 0;
    }
