#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "debug.h"

void showMenuDebug(void) {
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");
    printf("Pour définir un nouveau plateau de jeu, tapez 'newConfig <configuration au format FEN> <dernier coup joué> <joueur au trait>'\n");
    //printf("Pour retirer le coup précédent tapez 'removeLastPosition <dernière position jouée>'\n");
    //printf("Pour jouer un nouveau coup, tapez 'ajoutePosition <nouvelle position>'\n");
    printf("Pour sortir du menu de debogage, tapez 'exit'\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");
}

T_superMorpion newConfigSuperGrille(char newSuperConfig[MAXLEN]) {
    int lenNewSuperConfig = strlen(newSuperConfig);
    char superPosition[MAXLEN];
    int i = 10;
    while ((i < strlen(newSuperConfig)) && (newSuperConfig[i] != ' ')) {
        superPosition[i - 10] = newSuperConfig[i];
        i++;
    }
    superPosition[i - 10] = newSuperConfig[i];
    i++;
    superPosition[i - 10] = newSuperConfig[strlen(newSuperConfig) - 1];
    superPosition[i - 10] = '\0';
    
    T_superMorpion superMorpion = newSuperMorpion();
    T_superM pSuperMorpion = &superMorpion;
    
    pSuperMorpion = initSuperGrille(pSuperMorpion, superPosition);
    if (newSuperConfig[lenNewSuperConfig - 2] == 'x') {
        pSuperMorpion->trait = 1;
    } else {
        pSuperMorpion->trait = 0;
    }
    
    int nbCase = newSuperConfig[lenNewSuperConfig - 4] - '0';
    if (nbCase != 0) {
        pSuperMorpion->valide[NB_CASES] = nbCase;
    }
    
    printf("grille initialisée comme suit :\n");
    showSuperGrille(pSuperMorpion);
    showSuperGrilleState(pSuperMorpion);
    
    return superMorpion;
}

T_superM ajouteSuperRootPosition(T_superM pSuperMorpion, char position[5]);

int isFormatValide(char position[MAXLEN]) {
    int verifSynthaxe = 0;
    int i = 10;
    while ((i < strlen(position)) && (position[i] != ' ')) {
        if (isdigit(position[i])) {
            verifSynthaxe += position[i] - '0';
        } else if ((position[i] == 'x') || (position[i] == 'o')) {
            verifSynthaxe++;
        } else if ((position[i] == 'X') || (position[i] == 'O')) {
            verifSynthaxe += 9;
        } else {
            verifSynthaxe = 100;
            i = 1001;
        }
        i++;
    }
    
    if (verifSynthaxe != 81) {
        return 0;
    } else if ((i > strlen(position)) || (position[i++] != ' ')) {
        return 0;
    } else if ((i > strlen(position)) || ((position[strlen(position) - 2] != 'x') && (position[strlen(position) - 2] != 'o'))) {
        printf("position[strlen(position) - 2] = %c\n", position[strlen(position) - 2]);
        printf("ici2\n");
        return 0;
    }
    
    int nbMorpion = position[i] -'0';
    int nbCase = position[i + 1] - '0';
    
    if ((nbMorpion < 1) || (nbMorpion > 9)) {
        if ((nbMorpion == 0) && (nbCase == 0)) {
            return 1;
        } else {
            return 0;
        }
    } else if ((nbCase < 1) || (nbCase > 9)) {
        return 0;
    }
    
    return 1;
}
