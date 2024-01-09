#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "superMorpion.h"
#include "morpion.h"

/*
typedef struct {
 int trait;
 T_morpion grille[NB_CASES]; // attention à la numérotation
 int valide[NB_CASES + 1]; // la dernière case sert à donner la case dans laquelle le joueur joue, vaut -1 si le joueur doit choisir.
} T_superMorpion, *T_superM;

*/

/*
1 2 3
4 5 6
7 8 9
*/


void showSuperGrille(T_superM pSuperMorpion) {
    printf(" ----- ----- ----- \n");
    
    for (int i = 0 ; i < NB_CASES ; i+=3) {
        int a = pSuperMorpion->grille[i].state;
        int b = pSuperMorpion->grille[i+1].state;
        int c = pSuperMorpion->grille[i+2].state;
        if ((a <= -1) && (b <= -1) && (c <= -1)) {
            printf("|%c %c %c|%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i].grille[2], pSuperMorpion->grille[i].grille[5], pSuperMorpion->grille[i].grille[8], pSuperMorpion->grille[i+1].grille[2], pSuperMorpion->grille[i+1].grille[5], pSuperMorpion->grille[i+1].grille[8], pSuperMorpion->grille[i+2].grille[2], pSuperMorpion->grille[i+2].grille[5], pSuperMorpion->grille[i+2].grille[8]);
            printf("|%c %c %c|%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i].grille[1], pSuperMorpion->grille[i].grille[4], pSuperMorpion->grille[i].grille[7], pSuperMorpion->grille[i+1].grille[1], pSuperMorpion->grille[i+1].grille[4], pSuperMorpion->grille[i+1].grille[7], pSuperMorpion->grille[i+2].grille[1], pSuperMorpion->grille[i+2].grille[4], pSuperMorpion->grille[i+2].grille[7]);
            printf("|%c %c %c|%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i].grille[0], pSuperMorpion->grille[i].grille[3], pSuperMorpion->grille[i].grille[6], pSuperMorpion->grille[i+1].grille[0], pSuperMorpion->grille[i+1].grille[3], pSuperMorpion->grille[i+1].grille[6], pSuperMorpion->grille[i+2].grille[0], pSuperMorpion->grille[i+2].grille[3], pSuperMorpion->grille[i+2].grille[6]);
        } else if ((a > -1) && (b <= -1) && (c <= -1)) {
            if (a) {
                printf("|/   /|%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i+1].grille[2], pSuperMorpion->grille[i+1].grille[5], pSuperMorpion->grille[i+1].grille[8], pSuperMorpion->grille[i+2].grille[2], pSuperMorpion->grille[i+2].grille[5], pSuperMorpion->grille[i+2].grille[8]);
                printf("|  X  |%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i+1].grille[1], pSuperMorpion->grille[i+1].grille[4], pSuperMorpion->grille[i+1].grille[7], pSuperMorpion->grille[i+2].grille[1], pSuperMorpion->grille[i+2].grille[4], pSuperMorpion->grille[i+2].grille[7]);
                printf("|/   /|%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i+1].grille[0], pSuperMorpion->grille[i+1].grille[3], pSuperMorpion->grille[i+1].grille[6], pSuperMorpion->grille[i+2].grille[0], pSuperMorpion->grille[i+2].grille[3], pSuperMorpion->grille[i+2].grille[6]);
            } else {
                printf("|/---/|%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i+1].grille[2], pSuperMorpion->grille[i+1].grille[5], pSuperMorpion->grille[i+1].grille[8], pSuperMorpion->grille[i+2].grille[2], pSuperMorpion->grille[i+2].grille[5], pSuperMorpion->grille[i+2].grille[8]);
                printf("||   ||%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i+1].grille[1], pSuperMorpion->grille[i+1].grille[4], pSuperMorpion->grille[i+1].grille[7], pSuperMorpion->grille[i+2].grille[1], pSuperMorpion->grille[i+2].grille[4], pSuperMorpion->grille[i+2].grille[7]);
                printf("|/___/|%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i+1].grille[0], pSuperMorpion->grille[i+1].grille[3], pSuperMorpion->grille[i+1].grille[6], pSuperMorpion->grille[i+2].grille[0], pSuperMorpion->grille[i+2].grille[3], pSuperMorpion->grille[i+2].grille[6]);
            }
        } else if ((a <= -1) && (b > -1) && (c <= -1)) {
            if (b) {
                printf("|%c %c %c|/   /|%c %c %c|\n", pSuperMorpion->grille[i].grille[2], pSuperMorpion->grille[i].grille[5], pSuperMorpion->grille[i].grille[8], pSuperMorpion->grille[i+2].grille[2], pSuperMorpion->grille[i+2].grille[5], pSuperMorpion->grille[i+2].grille[8]);
                printf("|%c %c %c|  X  |%c %c %c|\n", pSuperMorpion->grille[i].grille[1], pSuperMorpion->grille[i].grille[4], pSuperMorpion->grille[i].grille[7], pSuperMorpion->grille[i+2].grille[1], pSuperMorpion->grille[i+2].grille[4], pSuperMorpion->grille[i+2].grille[7]);
                printf("|%c %c %c|/   /|%c %c %c|\n", pSuperMorpion->grille[i].grille[0], pSuperMorpion->grille[i].grille[3], pSuperMorpion->grille[i].grille[6], pSuperMorpion->grille[i+2].grille[0], pSuperMorpion->grille[i+2].grille[3], pSuperMorpion->grille[i+2].grille[6]);
            } else {
                printf("|%c %c %c|/---/|%c %c %c|\n", pSuperMorpion->grille[i].grille[2], pSuperMorpion->grille[i].grille[5], pSuperMorpion->grille[i].grille[8], pSuperMorpion->grille[i+2].grille[2], pSuperMorpion->grille[i+2].grille[5], pSuperMorpion->grille[i+2].grille[8]);
                printf("|%c %c %c||   ||%c %c %c|\n", pSuperMorpion->grille[i].grille[1], pSuperMorpion->grille[i].grille[4], pSuperMorpion->grille[i].grille[7], pSuperMorpion->grille[i+2].grille[1], pSuperMorpion->grille[i+2].grille[4], pSuperMorpion->grille[i+2].grille[7]);
                printf("|%c %c %c|/___/|%c %c %c|\n", pSuperMorpion->grille[i].grille[0], pSuperMorpion->grille[i].grille[3], pSuperMorpion->grille[i].grille[6], pSuperMorpion->grille[i+2].grille[0], pSuperMorpion->grille[i+2].grille[3], pSuperMorpion->grille[i+2].grille[6]);
            }
        } else if ((a <= -1) && (b <= -1) && (c > -1)) {
            if (c) {
                printf("|%c %c %c|%c %c %c|/   /|\n", pSuperMorpion->grille[i].grille[2], pSuperMorpion->grille[i].grille[5], pSuperMorpion->grille[i].grille[8], pSuperMorpion->grille[i+1].grille[2], pSuperMorpion->grille[i+1].grille[5], pSuperMorpion->grille[i+1].grille[8]);
                printf("|%c %c %c|%c %c %c|  X  |\n", pSuperMorpion->grille[i].grille[1], pSuperMorpion->grille[i].grille[4], pSuperMorpion->grille[i].grille[7], pSuperMorpion->grille[i+1].grille[1], pSuperMorpion->grille[i+1].grille[4], pSuperMorpion->grille[i+1].grille[7]);
                printf("|%c %c %c|%c %c %c|/   /|\n", pSuperMorpion->grille[i].grille[0], pSuperMorpion->grille[i].grille[3], pSuperMorpion->grille[i].grille[6], pSuperMorpion->grille[i+1].grille[0], pSuperMorpion->grille[i+1].grille[3], pSuperMorpion->grille[i+1].grille[6]);
            } else {
                printf("|%c %c %c|%c %c %c|/---/|\n", pSuperMorpion->grille[i].grille[2], pSuperMorpion->grille[i].grille[5], pSuperMorpion->grille[i].grille[8], pSuperMorpion->grille[i+1].grille[2], pSuperMorpion->grille[i+1].grille[5], pSuperMorpion->grille[i+1].grille[8]);
                printf("|%c %c %c|%c %c %c||   ||\n", pSuperMorpion->grille[i].grille[1], pSuperMorpion->grille[i].grille[4], pSuperMorpion->grille[i].grille[7], pSuperMorpion->grille[i+1].grille[1], pSuperMorpion->grille[i+1].grille[4], pSuperMorpion->grille[i+1].grille[7]);
                printf("|%c %c %c|%c %c %c|/___/|\n", pSuperMorpion->grille[i].grille[0], pSuperMorpion->grille[i].grille[3], pSuperMorpion->grille[i].grille[6], pSuperMorpion->grille[i+1].grille[0], pSuperMorpion->grille[i+1].grille[3], pSuperMorpion->grille[i+1].grille[6]);
            }
        } else if ((a > -1) && (b > -1) && (c <= -1)) {
            if (a == b) {
                if (a) {
                    printf("|/   /|/   /|%c %c %c|\n", pSuperMorpion->grille[i+2].grille[2], pSuperMorpion->grille[i+2].grille[5], pSuperMorpion->grille[i+2].grille[8]);
                    printf("|  X  |  X  |%c %c %c|\n", pSuperMorpion->grille[i+2].grille[1], pSuperMorpion->grille[i+2].grille[4], pSuperMorpion->grille[i+2].grille[7]);
                    printf("|/   /|/   /|%c %c %c|\n", pSuperMorpion->grille[i+2].grille[0], pSuperMorpion->grille[i+2].grille[3], pSuperMorpion->grille[i+2].grille[6]);
                } else {
                    printf("|/---/|/---/|%c %c %c|\n", pSuperMorpion->grille[i+2].grille[2], pSuperMorpion->grille[i+2].grille[5], pSuperMorpion->grille[i+2].grille[8]);
                    printf("||   |||   ||%c %c %c|\n", pSuperMorpion->grille[i+2].grille[1], pSuperMorpion->grille[i+2].grille[4], pSuperMorpion->grille[i+2].grille[7]);
                    printf("|/___/|/___/|%c %c %c|\n", pSuperMorpion->grille[i+2].grille[0], pSuperMorpion->grille[i+2].grille[3], pSuperMorpion->grille[i+2].grille[6]);
                }
            } else {
                if (a) {
                    printf("|/   /|/---/|%c %c %c|\n", pSuperMorpion->grille[i+2].grille[2], pSuperMorpion->grille[i+2].grille[5], pSuperMorpion->grille[i+2].grille[8]);
                    printf("|  X  ||   ||%c %c %c|\n", pSuperMorpion->grille[i+2].grille[1], pSuperMorpion->grille[i+2].grille[4], pSuperMorpion->grille[i+2].grille[7]);
                    printf("|/   /|/___/|%c %c %c|\n", pSuperMorpion->grille[i+2].grille[0], pSuperMorpion->grille[i+2].grille[3], pSuperMorpion->grille[i+2].grille[6]);

                } else {
                    printf("|/---/|/   /|%c %c %c|\n", pSuperMorpion->grille[i+2].grille[2], pSuperMorpion->grille[i+2].grille[5], pSuperMorpion->grille[i+2].grille[8]);
                    printf("||   ||  X  |%c %c %c|\n", pSuperMorpion->grille[i+2].grille[1], pSuperMorpion->grille[i+2].grille[4], pSuperMorpion->grille[i+2].grille[7]);
                    printf("|/___/|/   /|%c %c %c|\n", pSuperMorpion->grille[i+2].grille[0], pSuperMorpion->grille[i+2].grille[3], pSuperMorpion->grille[i+2].grille[6]);
                }
            }
        } else if ((a > -1) && (b <= -1) && (c > -1)) {
            if (a == c) {
                if (a) {
                    printf("|/   /|%c %c %c|/   /|\n", pSuperMorpion->grille[i+1].grille[2], pSuperMorpion->grille[i+1].grille[5], pSuperMorpion->grille[i+1].grille[8]);                    printf("|  X  |%c %c %c|  X  |\n", pSuperMorpion->grille[i+1].grille[1], pSuperMorpion->grille[i+1].grille[4], pSuperMorpion->grille[i+1].grille[7]);
                    printf("|  X  |%c %c %c|  X  |\n", pSuperMorpion->grille[i+1].grille[1], pSuperMorpion->grille[i+1].grille[4], pSuperMorpion->grille[i+1].grille[7]);
                    printf("|/   /|%c %c %c|/   /|\n", pSuperMorpion->grille[i+1].grille[0], pSuperMorpion->grille[i+1].grille[3], pSuperMorpion->grille[i+1].grille[6]);
                } else {
                    printf("|/---/|%c %c %c|/---/|\n", pSuperMorpion->grille[i+1].grille[2], pSuperMorpion->grille[i+1].grille[5], pSuperMorpion->grille[i+1].grille[8]);
                    printf("||   ||%c %c %c||   ||\n", pSuperMorpion->grille[i+1].grille[1], pSuperMorpion->grille[i+1].grille[4], pSuperMorpion->grille[i+1].grille[7]);
                    printf("|/___/|%c %c %c|/___/|\n", pSuperMorpion->grille[i+1].grille[0], pSuperMorpion->grille[i+1].grille[3], pSuperMorpion->grille[i+1].grille[6]);
                }
            } else {
                if (a) {
                    printf("|/   /|%c %c %c|/---/|\n", pSuperMorpion->grille[i+1].grille[2], pSuperMorpion->grille[i+1].grille[5], pSuperMorpion->grille[i+1].grille[8]);
                    printf("|  X  |%c %c %c||   ||\n", pSuperMorpion->grille[i+1].grille[1], pSuperMorpion->grille[i+1].grille[4], pSuperMorpion->grille[i+1].grille[7]);
                    printf("|/   /|%c %c %c|/___/|\n", pSuperMorpion->grille[i+1].grille[0], pSuperMorpion->grille[i+1].grille[3], pSuperMorpion->grille[i+1].grille[6]);
                } else {
                    printf("|/---/|%c %c %c|/   /|\n", pSuperMorpion->grille[i+1].grille[2], pSuperMorpion->grille[i+1].grille[5], pSuperMorpion->grille[i+1].grille[8]);
                    printf("||   ||%c %c %c|  X  |\n", pSuperMorpion->grille[i+1].grille[1], pSuperMorpion->grille[i+1].grille[4], pSuperMorpion->grille[i+1].grille[7]);
                    printf("|/___/|%c %c %c|/   /|\n", pSuperMorpion->grille[i+1].grille[0], pSuperMorpion->grille[i+1].grille[3], pSuperMorpion->grille[i+1].grille[6]);
                }
            }
        } else if ((a <= -1) && (b > -1) && (c > -1)) {
            if (b == c) {
                if (b) {
                    printf("|%c %c %c|/   /|/   /|\n", pSuperMorpion->grille[i].grille[2], pSuperMorpion->grille[i].grille[5], pSuperMorpion->grille[i].grille[8]);
                    printf("|%c %c %c|  X  |  X  |\n", pSuperMorpion->grille[i].grille[1], pSuperMorpion->grille[i].grille[4], pSuperMorpion->grille[i].grille[7]);
                    printf("|%c %c %c|/   /|/   /|\n", pSuperMorpion->grille[i].grille[0], pSuperMorpion->grille[i].grille[3], pSuperMorpion->grille[i].grille[6]);
                } else {
                    printf("|%c %c %c|/---/|/---/|\n", pSuperMorpion->grille[i].grille[2], pSuperMorpion->grille[i].grille[5], pSuperMorpion->grille[i].grille[8]);
                    printf("|%c %c %c||   |||   ||\n", pSuperMorpion->grille[i].grille[1], pSuperMorpion->grille[i].grille[4], pSuperMorpion->grille[i].grille[7]);
                    printf("|%c %c %c|/___/|/___/|\n", pSuperMorpion->grille[i].grille[0], pSuperMorpion->grille[i].grille[3], pSuperMorpion->grille[i].grille[6]);
                }
            } else {
                if (b) {
                    printf("|%c %c %c|/   /|/---/|\n", pSuperMorpion->grille[i].grille[2], pSuperMorpion->grille[i].grille[5], pSuperMorpion->grille[i].grille[8]);
                    printf("|%c %c %c|  X  ||   ||\n", pSuperMorpion->grille[i].grille[1], pSuperMorpion->grille[i].grille[4], pSuperMorpion->grille[i].grille[7]);
                    printf("|%c %c %c|/   /|/___/|\n", pSuperMorpion->grille[i].grille[0], pSuperMorpion->grille[i].grille[3], pSuperMorpion->grille[i].grille[6]);
                } else {
                    printf("|%c %c %c|/---/|/   /|\n", pSuperMorpion->grille[i].grille[2], pSuperMorpion->grille[i].grille[5], pSuperMorpion->grille[i].grille[8]);
                    printf("|%c %c %c||   ||  X  |\n", pSuperMorpion->grille[i].grille[1], pSuperMorpion->grille[i].grille[4], pSuperMorpion->grille[i].grille[7]);
                    printf("|%c %c %c|/___/|/   /|\n", pSuperMorpion->grille[i].grille[0], pSuperMorpion->grille[i].grille[3], pSuperMorpion->grille[i].grille[6]);
                }
            }
        } else if ((a > -1) && (b > -1) && (c > -1)) {
            if ((a == b) && (a == c)) {
                if (a) {
                    printf("|/   /|/   /|/   /|\n");
                    printf("|  X  |  X  |  X  |\n");
                    printf("|/   /|/   /|/   /|\n");
                } else {
                    printf("|/---/|/---/|/---/|\n");
                    printf("||   |||   |||   ||\n");
                    printf("|/___/|/___/|/___/|\n");
                }
            } else if ((a == b) && (a != c)){
                if (a) {
                    printf("|/   /|/   /|/---/|\n");
                    printf("|  X  |  X  ||   ||\n");
                    printf("|/   /|/   /|/___/|\n");
                } else {
                    printf("|/---/|/---/|/   /|\n");
                    printf("||   |||   ||  X  |\n");
                    printf("|/___/|/___/|/   /|\n");
                }
            } else if ((a == c) && (a != b)){
                if (a) {
                    printf("|/   /|/---/|/   /|\n");
                    printf("|  X  ||   ||  X  |\n");
                    printf("|/   /|/___/|/   /|\n");
                } else {
                    printf("|/---/|/   /|/---/|\n");
                    printf("||   ||  X  ||   ||\n");
                    printf("|/___/|/   /|/___/|\n");
                }
            } else if ((b == c) && (b != a)){
                if (b) {
                    printf("|/---/|/   /|/   /|\n");
                    printf("||   ||  X  |  X  |\n");
                    printf("|/___/|/   /|/   /|\n");
                } else {
                    printf("|/   /|/---/|/---/|\n");
                    printf("|  X  ||   |||   ||\n");
                    printf("|/   /|/___/|/___/|\n");
                }
            }
        } else {
            printf("CAS NON PRIS EN COMPTE\n");
        }
        printf(" ----- ----- ----- \n");
    }
}

T_superMorpion newSuperMorpion() {
    T_superMorpion superMorpion = {1, {newMorpion(), newMorpion(), newMorpion(), newMorpion(), newMorpion(), newMorpion(), newMorpion(), newMorpion(), newMorpion()}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    
    return superMorpion;
}

T_superM ajouteSuperPosition(T_superM pSuperMorpion, char position[5], int showNextCase) {
    int nbMorpion = atoi(&position[0]) - 1;
    int column = (position[2] - 'a')*3 - 1;
    int line = atoi(&position[3]);
    
    if ((pSuperMorpion->valide[NB_CASES] > -1) && (nbMorpion + 1 != pSuperMorpion->valide[NB_CASES])) {
        printf("Coup invalide, rejouez en case %d ! (1)\n", pSuperMorpion->valide[NB_CASES]);
        return pSuperMorpion;
    } else if (!pSuperMorpion->grille[nbMorpion].valide[column+line]) {
        printf("Coup invalide, rejouez en case %d ! (2)\n", nbMorpion + 1);
        return pSuperMorpion;
    } else if ((nbMorpion < 0) || (nbMorpion > 8) || (column < -1) || (column > 5) || (line < 1) || (line > 3)) {
        printf("Coup invalide, rejouez en case %d ! (3)\n", nbMorpion + 1);
        return pSuperMorpion;
    } else if (pSuperMorpion->grille[nbMorpion].state >= 0) {
        printf("Ce morpion est déjà gagné, jouez dans une autre case !\n");
        return pSuperMorpion;
    }
    
    char nPosition[3];
    nPosition[0] = position[2];
    nPosition[1] = position[3];
    nPosition[2] = '\n';
    pSuperMorpion->grille[nbMorpion].trait = pSuperMorpion->trait;
    pSuperMorpion->grille[nbMorpion] = *ajoutePosition(&pSuperMorpion->grille[nbMorpion], nPosition);
    
    pSuperMorpion->trait = (pSuperMorpion->trait + 1)%2;
    
    int corres[] = {6, 3, 0, 7, 4, 1, 8, 5, 2};
    
    int nextMorpion = corres[column+line];
    
    
    if (checkGagnant(&pSuperMorpion->grille[nbMorpion], showNextCase)) {
        pSuperMorpion->valide[nbMorpion] = 0;
    }
    if (!pSuperMorpion->valide[nextMorpion]) {
        pSuperMorpion->valide[NB_CASES] = -1;
        if (showNextCase) {
            printf("Vous pouvez choisir une case\n");
        }
    }
    else
    {
        if (showNextCase) {
            printf("Vous jouez maintenant en case %d\n", nextMorpion + 1);
        }
        pSuperMorpion->valide[NB_CASES] = nextMorpion + 1;
    }
    
    return pSuperMorpion;
}

int checkSuperGagnant(T_superM pSuperMorpion, int showGagnant) {
    int s = 0;
    for (int i = 0 ; i < NB_CASES ; i++) {
        if (!pSuperMorpion->valide[i]) {
            s++;
        }
    }
    if (s < 5) {
        return 0;
    } else if (s == 9) {
        if (showGagnant) {printf("Match nul !");}
        return 1;
    }
    
    int gagnant = 0;
    int column = 0;
    while ((column < 3) && (!gagnant)) {
        if ((pSuperMorpion->grille[column*3].state >= 0) && (pSuperMorpion->grille[column*3].state == pSuperMorpion->grille[column*3 + 1].state) && (pSuperMorpion->grille[column*3].state == pSuperMorpion->grille[column*3 + 2].state)) {
            gagnant = 1;
            if (pSuperMorpion->grille[column*3].state) {
                if (showGagnant) {printf("Le gagnant est le joueur 1 !\n");}
            } else {
                if (showGagnant) {printf("Le gagnant est le joueur 2 !\n");}
            }
        } else if ((pSuperMorpion->grille[column].state > -1) && (pSuperMorpion->grille[column].state == pSuperMorpion->grille[column + 3].state) && (pSuperMorpion->grille[column].state == pSuperMorpion->grille[column + 6].state)) {
            gagnant = 1;
            if (pSuperMorpion->grille[column].state) {
                if (showGagnant) {printf("Le gagnant est le joueur 1 !\n");}
            } else {
                if (showGagnant) {printf("Le gagnant est le joueur 2 !\n");}
            }
        }
        column++;
    }
    
    if (((pSuperMorpion->grille[2].state == pSuperMorpion->grille[4].state) && (pSuperMorpion->grille[2].state == pSuperMorpion->grille[6].state)) || ((pSuperMorpion->grille[0].state == pSuperMorpion->grille[4].state) && (pSuperMorpion->grille[0].state == pSuperMorpion->grille[8].state))) {
        if (pSuperMorpion->grille[4].state > -1) {
            gagnant = 1;
            if (pSuperMorpion->grille[4].state) {
                if (showGagnant) {printf("Le gagnant est le joueur 1 !\n");}
            } else {
                if (showGagnant) {printf("Le gagnant est le joueur 2 !\n");}
            }
        }
    }
    
    return gagnant;
}

void showSuperGrilleState(T_superM pSuperMorpion) {
    for (int i = 0 ; i < NB_CASES ; i++) {
        if (pSuperMorpion->valide[i]) {
            showGrilleState(&pSuperMorpion->grille[i]);
        } else {
            if (pSuperMorpion->grille[i].state == 1) {
                printf("X");
            } else {
                printf("O");
            }
        }
    }
    if (pSuperMorpion->trait) {
        printf(" x\n");
    } else {
        printf(" o\n");
    }
}

void showPosition(T_superM pSuperMorpion, char chemin[MAXLEN]) {
    int ordre[] = {2, 5, 8, 1, 4, 7, 0, 3, 6};
    
    FILE* fichier = NULL;

    fichier = fopen("g.dot", "w+");
        
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier");
        return;
    }
    
    fputs("digraph  {\na0 [shape=none label=<\n<TABLE border=\"0\" cellspacing=\"10\" cellpadding=\"10\" style=\"rounded\" bgcolor=\"black\">\n<TR>\n\n", fichier);
    
    for (int i = 0 ; i <NB_CASES ; i++) {
        if (pSuperMorpion->grille[i].state < 0) {
            fputs("<TD bgcolor=\"white\">\n", fichier);
            fputs("<TABLE border=\"0\" cellspacing=\"10\" cellpadding=\"10\" style=\"rounded\" bgcolor=\"black\">\n", fichier);
            fputs("<TR>\n", fichier);
            for (int j = 0 ; j < NB_CASES ; j++) {
                char chaine[MAXLEN] = "<TD bgcolor=\"white\">A</TD>\n";
                chaine[20] = pSuperMorpion->grille[i].grille[ordre[j]];
                fputs(chaine, fichier);
                if ((j == 2) || (j == 5)) {
                    fputs("</TR>\n<TR>\n", fichier);
                }
            }
            fputs("</TR>\n</TABLE>\n</TD>\n\n", fichier);
            
        } else {
            char gChaine[] = "<TD bgcolor=\"white\">&nbsp;</TD>\n";
            if (pSuperMorpion->grille[i].state == 1) {
                fputs("<TD bgcolor=\"black\">\n<TABLE border=\"0\" cellspacing=\"10\" cellpadding=\"10\" style=\"rounded\" bgcolor=\"white\">\n<TR>\n", fichier);
            } else {
                fputs("<TD bgcolor=\"white\">\n<TABLE border=\"0\" cellspacing=\"10\" cellpadding=\"10\" style=\"rounded\" bgcolor=\"black\">\n<TR>\n", fichier);
                gChaine[13] = 'b';
                gChaine[14] = 'l';
                gChaine[15] = 'a';
                gChaine[16] = 'c';
                gChaine[17] = 'k';
            }
            for (int j = 0 ; j < NB_CASES ; j++) {
                fputs(gChaine, fichier);
                if ((j == 2) || (j == 5)) {
                    fputs("</TR>\n<TR>\n", fichier);
                }
            }
            fputs("</TR>\n</TABLE>\n</TD>\n\n", fichier);
        }
        
        if ((i == 2) || (i == 5)) {
            fputs("</TR>\n<TR>\n\n", fichier);
        }
    }
    fputs("</TR>\n</TABLE>\n\n>];\n\n}\n", fichier);
    
    fclose(fichier);
    
    char commande[MAXLEN];
    sprintf(commande, "dot g.dot -T png -o %s", chemin);
    
    int n = system(commande);
    if (n != 0) {
        fprintf(stderr, "Impossible de créer le fichier image\n");
    }
}

T_superM removeLastSuperPosition(T_superM pSuperMorpion, char position[5], int isCaseAuChoix) {
    int nbMorpion = atoi(&position[0]) - 1;
    int column = (position[2] - 'a')*3 - 1;
    int line = atoi(&position[3]);
    
    if (isCaseAuChoix) {
        pSuperMorpion->valide[NB_CASES] = -1;
    } else {
        pSuperMorpion->valide[NB_CASES] = nbMorpion + 1;
    }
    
    pSuperMorpion->grille[nbMorpion].state = -1;
    
    pSuperMorpion->grille[nbMorpion].valide[column+line] = 1;
    pSuperMorpion->valide[nbMorpion] = 1;
    
    pSuperMorpion->trait = (pSuperMorpion->trait + 1)%2;
    pSuperMorpion->grille[nbMorpion].grille[column+line] = '.';
    
    return pSuperMorpion;
}

T_superM initSuperGrille(T_superM pSuperMorpion, char superPosition[MAXLEN]) {
    int indice = 0;
    
    for (int i = 0 ; i < NB_CASES ; i++) {
        pSuperMorpion->grille[i].state = -1;
        pSuperMorpion->valide[i] = 1;
    }
    pSuperMorpion->valide[9] = -1;
    
    for (int i = 0 ; i < NB_CASES ; i++) {
        char c = superPosition[indice];
        if (isupper(c)) {
            if (c == 'X') {
                pSuperMorpion->grille[i].state = 1;
            } else {
                pSuperMorpion->grille[i].state = 0;
            }
            pSuperMorpion->valide[i] = 0;
            indice++;
        } else {
            int num = c - '0';
            if (num == 9) {
                char position[MAXLEN] = "9 1";
                pSuperMorpion->grille[i] = *initGrille(&pSuperMorpion->grille[i], position);
                indice++;
            } else {
                int n = 0;
                int j = 0;
                char position[MAXLEN];
                
                while (n < 9) {
                    c = superPosition[indice];
                    num = c - '0';
                    if (isalpha(c)) {
                        position[j] = c;
                        j++;
                        n++;
                    } else {
                        position[j] = c;
                        j++;
                        n += num;
                    }
                    indice++;
                }
                
                if (n > 9) {
                    printf("Erreur de synthaxe à l'indice %d !\n", indice);
                    return pSuperMorpion;
                }
                
                position[j++] = ' ';
                position[j++] = '1';
                position[j] = '\0';
                pSuperMorpion->grille[i] = *initGrille(&pSuperMorpion->grille[i], position);
            }
        }
    }
    
    if (superPosition[strlen(superPosition) - 2] == 'x') {
        pSuperMorpion->trait = 1;
    } else {
        pSuperMorpion->trait = 0;
    }
    
    return pSuperMorpion;
}
