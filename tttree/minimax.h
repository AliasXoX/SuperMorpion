#ifndef MAXLEN

    #define MAXLEN 1001

#endif


#ifndef NB_CASES

    #define NB_CASES 9

#endif


#ifndef _MINIMAX_H_

    #define _MINIMAX_H_

    typedef struct {
        int state;  // -1 s'il n'a pas été gagné, 0 si O a gagné, 1 si X a gagné
        char grille[NB_CASES + 1];
    } T_minimax, * T_result;

#endif

T_minimax newMinimax(char configuration[MAXLEN]);
char * decryptConfig(char configuration[MAXLEN]);
int isGagnant(char const grille[NB_CASES + 1]);
int isProchainCoupGagnant(char grille[NB_CASES + 1]);
void tourSuivant(T_result result, int identifiantParent, char couleurParent[MAXLEN]);
void createGraph(T_result result, int identifiant, int identifiantParent, char color[MAXLEN], char column, int line);
