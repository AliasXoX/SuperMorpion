#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        if ((a == -1) && (b == -1) && (c == -1)) {
            printf("|%c %c %c|%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i].grille[2], pSuperMorpion->grille[i].grille[5], pSuperMorpion->grille[i].grille[8], pSuperMorpion->grille[i+1].grille[2], pSuperMorpion->grille[i+1].grille[5], pSuperMorpion->grille[i+1].grille[8], pSuperMorpion->grille[i+2].grille[2], pSuperMorpion->grille[i+2].grille[5], pSuperMorpion->grille[i+2].grille[8]);
            printf("|%c %c %c|%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i].grille[1], pSuperMorpion->grille[i].grille[4], pSuperMorpion->grille[i].grille[7], pSuperMorpion->grille[i+1].grille[1], pSuperMorpion->grille[i+1].grille[4], pSuperMorpion->grille[i+1].grille[7], pSuperMorpion->grille[i+2].grille[1], pSuperMorpion->grille[i+2].grille[4], pSuperMorpion->grille[i+2].grille[7]);
            printf("|%c %c %c|%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i].grille[0], pSuperMorpion->grille[i].grille[3], pSuperMorpion->grille[i].grille[6], pSuperMorpion->grille[i+1].grille[0], pSuperMorpion->grille[i+1].grille[3], pSuperMorpion->grille[i+1].grille[6], pSuperMorpion->grille[i+2].grille[0], pSuperMorpion->grille[i+2].grille[3], pSuperMorpion->grille[i+2].grille[6]);
        } else if ((a != -1) && (b == -1) && (c == -1)) {
            if (a) {
                printf("|/   /|%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i+1].grille[2], pSuperMorpion->grille[i+1].grille[5], pSuperMorpion->grille[i+1].grille[8], pSuperMorpion->grille[i+2].grille[2], pSuperMorpion->grille[i+2].grille[5], pSuperMorpion->grille[i+2].grille[8]);
                printf("|  X  |%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i+1].grille[1], pSuperMorpion->grille[i+1].grille[4], pSuperMorpion->grille[i+1].grille[7], pSuperMorpion->grille[i+2].grille[1], pSuperMorpion->grille[i+2].grille[4], pSuperMorpion->grille[i+2].grille[7]);
                printf("|/   /|%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i+1].grille[0], pSuperMorpion->grille[i+1].grille[3], pSuperMorpion->grille[i+1].grille[6], pSuperMorpion->grille[i+2].grille[0], pSuperMorpion->grille[i+2].grille[3], pSuperMorpion->grille[i+2].grille[6]);
            } else {
                printf("|/---/|%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i+1].grille[2], pSuperMorpion->grille[i+1].grille[5], pSuperMorpion->grille[i+1].grille[8], pSuperMorpion->grille[i+2].grille[2], pSuperMorpion->grille[i+2].grille[5], pSuperMorpion->grille[i+2].grille[8]);
                printf("||   ||%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i+1].grille[1], pSuperMorpion->grille[i+1].grille[4], pSuperMorpion->grille[i+1].grille[7], pSuperMorpion->grille[i+2].grille[1], pSuperMorpion->grille[i+2].grille[4], pSuperMorpion->grille[i+2].grille[7]);
                printf("|/___/|%c %c %c|%c %c %c|\n", pSuperMorpion->grille[i+1].grille[0], pSuperMorpion->grille[i+1].grille[3], pSuperMorpion->grille[i+1].grille[6], pSuperMorpion->grille[i+2].grille[0], pSuperMorpion->grille[i+2].grille[3], pSuperMorpion->grille[i+2].grille[6]);
            }
        } else if ((a == -1) && (b != -1) && (c == -1)) {
            if (b) {
                printf("|%c %c %c|/   /|%c %c %c|\n", pSuperMorpion->grille[i].grille[2], pSuperMorpion->grille[i].grille[5], pSuperMorpion->grille[i].grille[8], pSuperMorpion->grille[i+2].grille[2], pSuperMorpion->grille[i+2].grille[5], pSuperMorpion->grille[i+2].grille[8]);
                printf("|%c %c %c|  X  |%c %c %c|\n", pSuperMorpion->grille[i].grille[1], pSuperMorpion->grille[i].grille[4], pSuperMorpion->grille[i].grille[7], pSuperMorpion->grille[i+2].grille[1], pSuperMorpion->grille[i+2].grille[4], pSuperMorpion->grille[i+2].grille[7]);
                printf("|%c %c %c|/   /|%c %c %c|\n", pSuperMorpion->grille[i].grille[0], pSuperMorpion->grille[i].grille[3], pSuperMorpion->grille[i].grille[6], pSuperMorpion->grille[i+2].grille[0], pSuperMorpion->grille[i+2].grille[3], pSuperMorpion->grille[i+2].grille[6]);
            } else {
                printf("|%c %c %c|/---/|%c %c %c|\n", pSuperMorpion->grille[i].grille[2], pSuperMorpion->grille[i].grille[5], pSuperMorpion->grille[i].grille[8], pSuperMorpion->grille[i+2].grille[2], pSuperMorpion->grille[i+2].grille[5], pSuperMorpion->grille[i+2].grille[8]);
                printf("|%c %c %c||   ||%c %c %c|\n", pSuperMorpion->grille[i].grille[1], pSuperMorpion->grille[i].grille[4], pSuperMorpion->grille[i].grille[7], pSuperMorpion->grille[i+2].grille[1], pSuperMorpion->grille[i+2].grille[4], pSuperMorpion->grille[i+2].grille[7]);
                printf("|%c %c %c|/___/|%c %c %c|\n", pSuperMorpion->grille[i].grille[0], pSuperMorpion->grille[i].grille[3], pSuperMorpion->grille[i].grille[6], pSuperMorpion->grille[i+2].grille[0], pSuperMorpion->grille[i+2].grille[3], pSuperMorpion->grille[i+2].grille[6]);
            }
        } else if ((a == -1) && (b == -1) && (c != -1)) {
            if (c) {
                printf("|%c %c %c|%c %c %c|/   /|\n", pSuperMorpion->grille[i].grille[2], pSuperMorpion->grille[i].grille[5], pSuperMorpion->grille[i].grille[8], pSuperMorpion->grille[i+1].grille[2], pSuperMorpion->grille[i+1].grille[5], pSuperMorpion->grille[i+1].grille[8]);
                printf("|%c %c %c|%c %c %c|  X  |\n", pSuperMorpion->grille[i].grille[1], pSuperMorpion->grille[i].grille[4], pSuperMorpion->grille[i].grille[7], pSuperMorpion->grille[i+1].grille[1], pSuperMorpion->grille[i+1].grille[4], pSuperMorpion->grille[i+1].grille[7]);
                printf("|%c %c %c|%c %c %c|/   /|\n", pSuperMorpion->grille[i].grille[0], pSuperMorpion->grille[i].grille[3], pSuperMorpion->grille[i].grille[6], pSuperMorpion->grille[i+1].grille[0], pSuperMorpion->grille[i+1].grille[3], pSuperMorpion->grille[i+1].grille[6]);
            } else {
                printf("|%c %c %c|%c %c %c|/---/|\n", pSuperMorpion->grille[i].grille[2], pSuperMorpion->grille[i].grille[5], pSuperMorpion->grille[i].grille[8], pSuperMorpion->grille[i+1].grille[2], pSuperMorpion->grille[i+1].grille[5], pSuperMorpion->grille[i+1].grille[8]);
                printf("|%c %c %c|%c %c %c||   ||\n", pSuperMorpion->grille[i].grille[1], pSuperMorpion->grille[i].grille[4], pSuperMorpion->grille[i].grille[7], pSuperMorpion->grille[i+1].grille[1], pSuperMorpion->grille[i+1].grille[4], pSuperMorpion->grille[i+1].grille[7]);
                printf("|%c %c %c|%c %c %c|/___/|\n", pSuperMorpion->grille[i].grille[0], pSuperMorpion->grille[i].grille[3], pSuperMorpion->grille[i].grille[6], pSuperMorpion->grille[i+1].grille[0], pSuperMorpion->grille[i+1].grille[3], pSuperMorpion->grille[i+1].grille[6]);
            }
        } else if ((a != -1) && (b != -1) && (c == -1)) {
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
        } else if ((a != -1) && (b == -1) && (c != -1)) {
            if (a == c) {
                if (a) {
                    printf("|/   /|%c %c %c|/   /|\n", pSuperMorpion->grille[i+1].grille[2], pSuperMorpion->grille[i+1].grille[5], pSuperMorpion->grille[i+1].grille[8]);                    printf("|  X  |%c %c %c|  X  |\n", pSuperMorpion->grille[i+1].grille[1], pSuperMorpion->grille[i+1].grille[4], pSuperMorpion->grille[i+1].grille[7]);
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
        } else if ((a == -1) && (b != -1) && (c != -1)) {
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
                if (a) {
                    printf("|%c %c %c|/   /|/---/|\n", pSuperMorpion->grille[i].grille[2], pSuperMorpion->grille[i].grille[5], pSuperMorpion->grille[i].grille[8]);
                    printf("|%c %c %c|  X  ||   ||\n", pSuperMorpion->grille[i].grille[1], pSuperMorpion->grille[i].grille[4], pSuperMorpion->grille[i].grille[7]);
                    printf("|%c %c %c|/   /|/___/|\n", pSuperMorpion->grille[i].grille[0], pSuperMorpion->grille[i].grille[3], pSuperMorpion->grille[i].grille[6]);
                } else {
                    printf("|%c %c %c|/---/|/   /|\n", pSuperMorpion->grille[i].grille[2], pSuperMorpion->grille[i].grille[5], pSuperMorpion->grille[i].grille[8]);
                    printf("|%c %c %c||   ||  X  |\n", pSuperMorpion->grille[i].grille[1], pSuperMorpion->grille[i].grille[4], pSuperMorpion->grille[i].grille[7]);
                    printf("|%c %c %c|/___/|/   /|\n", pSuperMorpion->grille[i].grille[0], pSuperMorpion->grille[i].grille[3], pSuperMorpion->grille[i].grille[6]);
                }
            }
        } else if ((a != -1) && (b != -1) && (c != -1)) {
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

T_superMorpion ajouteSuperPosition(T_superMorpion superMorpion, char position[5],int visible) {
    int nbMorpion = atoi(&position[0]) - 1;
    int column = (position[2] - 'a')*3 - 1;
    int line = atoi(&position[3]);
    
    if ((superMorpion.valide[NB_CASES] != -1) && (nbMorpion + 1 != superMorpion.valide[NB_CASES])) {
        if (visible) {printf("Coup invalide, rejouez en case %d !\n", superMorpion.valide[NB_CASES]);}
        return superMorpion;
    } else if (!superMorpion.grille[nbMorpion].valide[column+line]) {
        if (superMorpion.valide[NB_CASES]==-1)
        {
            if (visible) {printf("Coup invalide, rejouez votre coup !\n");}
        }
        else
        {
            if (visible) {printf("Coup invalide, rejouez en case %d !\n", nbMorpion + 1);}
        }
        return superMorpion;
    }
    
    char nPosition[3];
    nPosition[0] = position[2];
    nPosition[1] = position[3];
    nPosition[2] = '\n';
    superMorpion.grille[nbMorpion].trait = superMorpion.trait;
    superMorpion.grille[nbMorpion] = *ajoutePosition(&superMorpion.grille[nbMorpion], nPosition);
    
    superMorpion.trait = (superMorpion.trait + 1)%2;
    
    int corres[] = {6, 3, 0, 7, 4, 1, 8, 5, 2};
    
    int nextMorpion = corres[column+line];
    
    if (superMorpion.valide[nextMorpion])
    {
        superMorpion.valide[NB_CASES] = nextMorpion + 1;
        if (visible) {printf("Vous jouez maintenant en case %d\n", nextMorpion + 1);}
    }
    else
    {
        superMorpion.valide[NB_CASES] = -1;
        if (visible) {printf("Vous pouvez choisir votre case maintenant\n");}
    }
    
    
    if (checkGagnant(&superMorpion.grille[nbMorpion],visible)) {
        superMorpion.valide[nbMorpion] = 0;
    }
    
    return superMorpion;

}

int checkSuperGagnant(T_superM pSuperMorpion,int visible) {
    int s = 0;
    for (int i = 0 ; i < NB_CASES ; i++) {
        if (!pSuperMorpion->valide[i]) {
            s++;
        }
    }
    if (s < 3) {
        return 0;
    } else if (s == 9) {
        int nbr1;
        for (int i=0;i<9;i++)
        {
            nbr1 += pSuperMorpion->grille[i].state;
        }
        if (nbr1>5)
        {
            if (visible) {printf("Le gagnant est le joueur 1 !\n");}
            return 2;
        }
        else if (nbr1<5)
        {
            if (visible) {printf("Le gagnant est le joueur 2 !\n");}
            return 3;
        }
        
        printf("Match nul !");
        return 1;
    }
    
    int gagnant = 0;
    int column = 0;
    while ((column < 3) && (!gagnant)) {
        if ((pSuperMorpion->grille[column*4].state >= 0) && (pSuperMorpion->grille[column*4].state == pSuperMorpion->grille[column*4 + 1].state) && (pSuperMorpion->grille[column*4].state == pSuperMorpion->grille[column*4 + 2].state)) {
            if (pSuperMorpion->grille[column].state) {
                if (visible) {printf("Le gagnant est le joueur 1 !\n");}
                gagnant = 2;
            } else {
                if (visible) {printf("Le gagnant est le joueur 2 !\n");}
                gagnant = 3;
            }
            return gagnant;
        } else if ((pSuperMorpion->grille[column].state != -1) && (pSuperMorpion->grille[column].state == pSuperMorpion->grille[column + 3].state) && (pSuperMorpion->grille[column].state == pSuperMorpion->grille[column + 6].state)) {
            if (pSuperMorpion->grille[column].state) {
                if (visible) {printf("Le gagnant est le joueur 1 !\n");}
                gagnant = 2;
            } else {
                if (visible) {printf("Le gagnant est le joueur 2 !\n");}
                gagnant = 3;
            }
            return gagnant;
        }
        column++;
    }
    
    if (((pSuperMorpion->grille[2].state == pSuperMorpion->grille[4].state) && (pSuperMorpion->grille[2].state == pSuperMorpion->grille[6].state)) || ((pSuperMorpion->grille[0].state == pSuperMorpion->grille[4].state) && (pSuperMorpion->grille[0].state == pSuperMorpion->grille[8].state))) {
        if (pSuperMorpion->grille[4].state != -1) 
        {
            if (pSuperMorpion->grille[column].state) {
                if (visible) {printf("Le gagnant est le joueur 1 !\n");}
                gagnant = 2;
            } else {
                if (visible) {printf("Le gagnant est le joueur 2 !\n");}
                gagnant = 3;
            }
        }
        return gagnant;
    }

    return gagnant;
}


void showSuperGrilleState(T_superM pSuperMorpion) {
    for (int i = 0 ; i < NB_CASES ; i++) {
        if (pSuperMorpion->valide[i]) {
            showGrilleState(&pSuperMorpion->grille[i]);
        } else {
            if (pSuperMorpion->grille[i].state) {
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

void showPosition(T_superM pSuperMorpion) {
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
    
    int n = system("dot g.dot -T png -o g.png");
    if (n != 0) {
        fprintf(stderr, "Impossible de créer le fichier g.png\n");
    }
}
