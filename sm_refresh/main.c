#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "morpion.h"
#include "superMorpion.h"
#include "superMinimax.h"
#include "debug.h"

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

int sameStr(const char chaine1[], const char chaine2[]);

int main() {
    T_superMorpion superMorpion = newSuperMorpion();
    T_superM pSuperMorpion = &superMorpion;
    
    printf("Horizon de recherche du minimax (1-9) : ");
    int depth;
    scanf("%d", &depth);
    if ((depth < 1) || (depth > 9)) {
        printf("Valeur non valide, l'horizon de recherche doit être un entier positif\n");
        return 1;
    }
    printf("depth = %d\n", depth);
    
    
    printf("Chemin (relatif ou absolu) complet du fichier image à générer : ");
    char chemin[MAXLEN];
    scanf("%s", chemin);
    printf("chemin saisi = <%s>\n", chemin);
    if ((chemin[strlen(chemin) - 3] != 'p') || (chemin[strlen(chemin) - 2] != 'n') || (chemin[strlen(chemin) - 1] != 'g')) {
        printf("Nom de fichier non valide, il doit être au format '<nom fichier>.png'\n");
        return 1;
    }
    
    
    printf("Pour entrer dans le menu de débogage, entrez <debug> dans le terminal\n");
    
    
    char position[MAXLEN];
    
    printf("Voulez-vous commencer en premier (1) ou en deuxième (0) ? ");
    int traitOrdi;
    scanf("%d", &traitOrdi);
    traitOrdi = (traitOrdi + 1)%2;
    clearInputBuffer();
    
    if (traitOrdi) {
        printf("L'ordinateur commence à jouer\n");
    } else {
        printf("Vous commencez à jouer\n");
    }
    
    if (traitOrdi) {
        T_superResult r = superMinimax(pSuperMorpion, depth, traitOrdi);
        pSuperMorpion = ajouteSuperPosition(pSuperMorpion, r.position, 1);
        showSuperGrille(pSuperMorpion);
        showSuperGrilleState(pSuperMorpion);
        showPosition(pSuperMorpion, chemin);
        
    } else {
        showSuperGrille(pSuperMorpion);
        showSuperGrilleState(pSuperMorpion);
        showPosition(pSuperMorpion, chemin);
        fflush(stdout);
        fgets(position, sizeof(position), stdin);
        
        if (sameStr(position, "debug\n")) {
            while(!sameStr(position, "exit\n")) {
                showMenuDebug();
                
                if (fgets(position, sizeof(position), stdin) == NULL) {
                    break;
                }
                
                //printf("position = %s\n", position);
                
                if ((position[0] == 'n') && (position[1] == 'e') && (position[2] == 'w') && (position[3] == 'C') && (position[4] == 'o') && (position[5] == 'n') && (position[6] == 'f') && (position[7] == 'i') && (position[8] == 'g') && (position[9] == ' ')) {
                    
                    if (!isFormatValide(position)) {
                        printf("Format FEN invalide\n");
                    } else {
                        superMorpion = newConfigSuperGrille(position);
                        pSuperMorpion = &superMorpion;
                    }
                } /*else if ((position[0] == 'r') && (strlen(position) == 24)) {
                    printf("remove ok\n");
                } else if ((position[0] == 'a') && (strlen(position) == 20)) {
                    printf("newPosition ok\n");
                } */else if (!sameStr(position, "exit\n")) {
                    printf("Mauvaise synthaxe !\n");
                }
            }
        }
        
        pSuperMorpion = ajouteSuperPosition(pSuperMorpion, position, 0);
        showSuperGrille(pSuperMorpion);
        showSuperGrilleState(pSuperMorpion);
        showPosition(pSuperMorpion, chemin);
    }
    
    while (!checkSuperGagnant(pSuperMorpion)) {
        
        if (pSuperMorpion->trait != traitOrdi)
        {
            //le joueur
            if (fgets(position, sizeof(position), stdin) == NULL) {
                break;
            }
            
            if (sameStr(position, "debug\n")) {
                while(!sameStr(position, "exit\n")) {
                    showMenuDebug();
                    
                    if (fgets(position, sizeof(position), stdin) == NULL) {
                        break;
                    }
                    
                    //printf("position = %s\n", position);
                    
                    if ((position[0] == 'n') && (position[1] == 'e') && (position[2] == 'w') && (position[3] == 'C') && (position[4] == 'o') && (position[5] == 'n') && (position[6] == 'f') && (position[7] == 'i') && (position[8] == 'g') && (position[9] == ' ')) {
                        
                        if (!isFormatValide(position)) {
                            printf("Format FEN invalide\n");
                        } else {
                            superMorpion = newConfigSuperGrille(position);
                            pSuperMorpion = &superMorpion;
                        }
                    } /*else if ((position[0] == 'r') && (strlen(position) == 24)) {
                        printf("remove ok\n");
                    } else if ((position[0] == 'a') && (strlen(position) == 20)) {
                        printf("newPosition ok\n");
                    } */else if (!sameStr(position, "exit\n")) {
                        printf("Mauvaise synthaxe !\n");
                    }
                }
                
                if (pSuperMorpion->trait != traitOrdi) {
                    printf("À vous de jouer en case %d!\n", pSuperMorpion->valide[NB_CASES]);
                    showSuperGrille(pSuperMorpion);
                    if (fgets(position, sizeof(position), stdin) == NULL) {
                        break;
                    }
                    
                    pSuperMorpion = ajouteSuperPosition(pSuperMorpion, position, 0);
                    showSuperGrille(pSuperMorpion);
                    showSuperGrilleState(pSuperMorpion);
                    showPosition(pSuperMorpion, chemin);
                } else {
                    T_superResult r = superMinimax(pSuperMorpion, 1, traitOrdi);
                    pSuperMorpion = ajouteSuperPosition(pSuperMorpion, r.position, 1);
                    printf("r.position = %s\n", r.position);
                    showSuperGrille(pSuperMorpion);
                    showSuperGrilleState(pSuperMorpion);
                    showPosition(pSuperMorpion, chemin);
                }
                
            } else {
                pSuperMorpion = ajouteSuperPosition(pSuperMorpion, position, 0);
                showSuperGrille(pSuperMorpion);
                showSuperGrilleState(pSuperMorpion);
                showPosition(pSuperMorpion, chemin);
            }
        }
        else
        {
            //le robot
            T_superResult r = superMinimax(pSuperMorpion, depth, traitOrdi);
            pSuperMorpion = ajouteSuperPosition(pSuperMorpion, r.position, 1);
            printf("r.position = %s\n", r.position);
            showSuperGrille(pSuperMorpion);
            showSuperGrilleState(pSuperMorpion);
            showPosition(pSuperMorpion, chemin);
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

int sameStr(const char chaine1[], const char chaine2[]) {
    int lenChaine1 = strlen(chaine1);
    int lenChaine2 = strlen(chaine2);
    
    if (lenChaine1 != lenChaine2) {
        return 0;
    }
    
    for (int i = 0 ; i < lenChaine1 ; i++) {
        if (chaine1[i] != chaine2[i]) {
            return 0;
        }
    }
    return 1;
}
