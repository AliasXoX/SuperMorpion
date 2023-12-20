#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "minimax.h"

/*
typedef struct {
    int state;  // 0 s'il n'a pas été gagné, -1 si O a gagné, 1 si X a gagné
    char grille[MAXLEN];
} T_minimax; * T_result;
*/

T_minimax newMinimax(char configuration[MAXLEN]) {
    T_minimax minimax = {0, ""};
    char * grille = decryptConfig(configuration);
    for (int i = 0 ; i < NB_CASES + 1 ; i++) {
        minimax.grille[i] = grille[i];
    }
    
    return minimax;
}

char * decryptConfig(char configuration[MAXLEN]) {
    int indice = 0;
    
    char * grille = malloc(sizeof(char)*(NB_CASES + 1));
    if (grille == NULL) {
        fprintf(stderr, "Échec malloc decryptConfig\n");
        exit(EXIT_FAILURE);
    }
    
    int n = 0;
    int j = 0;
    
    while (n < 9) {
        char c = configuration[indice];
        int num = c - '0';
        if (isdigit(c)) {
            if (num + n > 9) {
                printf("Erreur de synthaxe à l'indice %d !\n", indice);
                return grille;
            }
            while (num > 0) {
                grille[j] = '.';
                j++;
                n++;
                num--;
            }
        } else {
            grille[j] = c;
            j++;
            n++;
        }
        indice++;
    }
    grille[NB_CASES] = configuration[strlen(configuration) - 1];
    return grille;
}

int isGagnant(char const grille[NB_CASES + 1]) {
    int column = 0;
    while (column < 3) {
        if ((grille[column*3] != '.') && (grille[column*3] == grille[column*3 + 1]) && (grille[column*3] == grille[column*3 + 2])) {
            if (grille[column*3] == 'x') {
                return 1;
            }
            return -1;
        } else if ((grille[column] != '.') && (grille[column] == grille[column + 3]) && (grille[column] == grille[column + 6])) {
            if (grille[column] == 'x') {
                return 1;
            }
            return -1;
        }
        column++;
    }
    
    if (((grille[2] == grille[4]) && (grille[2] == grille[6])) || ((grille[0] == grille[4]) && (grille[0] == grille[8]))) {
        if (grille[4] == 'x') {
            return 1;
        } else if (grille[4] == 'o') {
            return -1;
        }
    }
    return 0;
}

int isProchainCoupGagnant(char grille[NB_CASES + 1]) {
    char nGrille[NB_CASES + 1];
    
    for (int i = 0 ; i < NB_CASES + 1 ; i++) {
        nGrille[i] = grille[i]; //il faut copier le tableau pour ne pas modifier l'original lorsque la fonction sera appelée
    }
    
    if (nGrille[NB_CASES] == 'x') {
        nGrille[NB_CASES] = 'o';
    } else {
        nGrille[NB_CASES] = 'x';
    }
    
    for (int i = 0 ; i < NB_CASES ; i++) {
        if (nGrille[i] == '.') {
            nGrille[i] = nGrille[NB_CASES];
            int temp = isGagnant(nGrille);
            nGrille[i] = '.';
            if (temp) {
                return temp;
            }
        }
    }
    
    return 0;
}

void tourSuivant(T_result result, int identifiantParent, char couleurParent[MAXLEN]) {
    static int identifiant = 0;
    static int red[MAXLEN] = {0};
    red[0] = 1;
    char * grille = result->grille;
    
    if (grille[NB_CASES] == 'x') {
        grille[NB_CASES] = 'o';
    } else {
        grille[NB_CASES] = 'x';
    }
    
    if (!isGagnant(grille)) {
        for (int i = 0 ; i < NB_CASES ; i++) {
            if (grille[i] == '.') {
                grille[i] = grille[NB_CASES];
                
                int temp = isGagnant(grille);
                int aux = isProchainCoupGagnant(grille);
                if (temp) {
                    result->state = temp;
                } else if (aux) {
                    result->state = aux;
                } else {
                    result->state = 0;
                }
                
                char column;
                int line;
                
                if (i <= 2) {
                    line = 3;
                    if (i == 0) {
                        column = 'a';
                    } else if (i == 1) {
                        column = 'b';
                    } else {
                        column = 'c';
                    }
                } else if (i <= 5) {
                    line = 2;
                    if (i == 3) {
                        column = 'a';
                    } else if (i == 4) {
                        column = 'b';
                    } else {
                        column = 'c';
                    }
                } else {
                    line = 1;
                    if (i == 6) {
                        column = 'a';
                    } else if (i == 7) {
                        column = 'b';
                    } else {
                        column = 'c';
                    }
                }
                
                if (red[identifiantParent]) {
                    createGraph(result, ++identifiant, identifiantParent, "green", column, line);
                } else {
                    createGraph(result, ++identifiant, identifiantParent, "red", column, line);
                    red[identifiant] = 1;
                }
                
                tourSuivant(result, identifiant, couleurParent);
                grille[i] = '.';
                
                if (grille[NB_CASES] == 'x') {
                    grille[NB_CASES] = 'o';
                } else {
                    grille[NB_CASES] = 'x';
                }
            }
        }
    }
}

void createGraph(T_result result, int identifiant, int identifiantParent, char color[MAXLEN], char column, int line) {
    char * grille = result->grille;
    printf("  m%d [shape=none label=<\n", identifiant);
    printf(" <TABLE border=\"0\" cellspacing=\"10\" cellpadding=\"10\" style=\"rounded\" bgcolor=\"black\">\n");
    printf("<TR>\n");
    printf("<TD bgcolor=\"white\">%c</TD>\n", toupper(grille[0]));
    printf("<TD bgcolor=\"white\">%c</TD>\n", toupper(grille[1]));
    printf("<TD bgcolor=\"white\">%c</TD>\n", toupper(grille[2]));
    printf("</TR>\n");
    printf("<TR>\n");
    printf("<TD bgcolor=\"white\">%c</TD>\n", toupper(grille[3]));
    printf("<TD bgcolor=\"white\">%c</TD>\n", toupper(grille[4]));
    printf("<TD bgcolor=\"white\">%c</TD>\n", toupper(grille[5]));
    printf("</TR>\n");
    printf("<TR>\n");
    printf("<TD bgcolor=\"white\">%c</TD>\n", toupper(grille[6]));
    printf("<TD bgcolor=\"white\">%c</TD>\n", toupper(grille[7]));
    printf("<TD bgcolor=\"white\">%c</TD>\n", toupper(grille[8]));
    printf("</TR>\n");
    printf("<TR><TD bgcolor=\"%s\" colspan=\"3\">m%d</TD></TR>\n", color, identifiant);
    printf("</TABLE>>];\n\n");
    
    printf("m%d [xlabel=\"%d\"]", identifiant, result->state);
    
    if (identifiantParent != -1) {
        printf("m%d-> m%d [label=\"%c%d\"];\n\n", identifiantParent, identifiant, column, line);
    }
}
