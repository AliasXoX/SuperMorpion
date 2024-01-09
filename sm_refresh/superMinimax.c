#include "superMinimax.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

/*
typedef struct {
    char position[5];
    int poids;
} T_superResult;
*/

T_superResult superMinimax(T_superMorpion SuperMorpion, int depth, int traitOrdi) {
    T_superResult resultat = {"", 0};
    T_superM pSuperMorpion = &SuperMorpion;
    int i = checkSuperGagnant(pSuperMorpion,0);
    if (i) {
        resultat.poids = i-1;
        return resultat;
        
    } else if (depth <= 0) {
        return resultat;
        
    } else if (traitOrdi != pSuperMorpion->trait) {
        resultat.poids = -99999;
        if ((pSuperMorpion->valide[NB_CASES] != -1) && (pSuperMorpion->valide[pSuperMorpion->valide[NB_CASES]])) {
            for (int i = 'a' ; i <= 'c' ; i++) {
                for (int j = 1 ; j <= 3 ; j++) {

                    char position[5];
                    sprintf(position,"%d %c%d",pSuperMorpion->valide[NB_CASES],i,j);
                    int nbMorpion = pSuperMorpion->valide[NB_CASES] - 1;
                    int column = (i - 'a')*3 - 1;
                    int line = j;

                    if (!pSuperMorpion->grille[nbMorpion].valide[column+line])
                    {
                        continue;
                    }

                    pSuperMorpion = ajouteSuperPosition(pSuperMorpion, position, 0);
                    int k = superMinimax(SuperMorpion,depth-1,traitOrdi).poids;
                    
                    if (resultat.poids<k)
                    {
                        resultat.poids = k;
                        strcpy(resultat.position,position);
                    }
                }
            }
        }
        else {
            for (int i = 1 ; i <= 9 ; i++) {
                if (!pSuperMorpion->valide[i-1]) {
                    continue;
                }
                for (int j = 'a' ; j <= 'c' ; j++) {
                    for (int k = 1 ; k <= 3 ; k++) {
                        char position[5];
                        sprintf(position,"%d %c%d",i,j,k);
                        int nbMorpion = i - 1;
                        int column = (j - 'a')*3 - 1;
                        int line = k;

                        if (!pSuperMorpion->grille[nbMorpion].valide[column+line]) {
                            continue;
                        }

                        pSuperMorpion = ajouteSuperPosition(pSuperMorpion, position, 0);
                        int k = superMinimax(SuperMorpion,depth-1,traitOrdi).poids;
                        pSuperMorpion = removeLastSuperPosition(pSuperMorpion, position, 1);
                        
                        if (resultat.poids<k)
                        {
                            resultat.poids = k;
                            strcpy(resultat.position,position);
                        }
                    }
                }
            }
        }
    }

    else {
        resultat.poids = 99999;
        if ((pSuperMorpion->valide[NB_CASES] != -1) && (pSuperMorpion->valide[pSuperMorpion->valide[NB_CASES]])) {
            for (int i = 'a' ; i <= 'c'; i++) {
                for (int j = 1 ;j <= 3 ; j++) {
                    
                    char position[5];
                    sprintf(position,"%d %c%d",pSuperMorpion->valide[NB_CASES],i,j);
                    int nbMorpion = pSuperMorpion->valide[NB_CASES] - 1;
                    int column = (i - 'a')*3 - 1;
                    int line = j;

                    if (!pSuperMorpion->grille[nbMorpion].valide[column+line]) {
                        continue;
                    }
                    
                    pSuperMorpion = ajouteSuperPosition(pSuperMorpion,position, 0);
                    int k = superMinimax(SuperMorpion,depth-1,traitOrdi).poids;
                    
                    pSuperMorpion = removeLastSuperPosition(pSuperMorpion, position, 0);
                    
                    if (resultat.poids>k) {
                        resultat.poids = k;
                        strcpy(resultat.position,position);
                    }
                }
            }
        } else {
            for (int i = 1 ; i <= 9 ; i++) {
                if (!pSuperMorpion->valide[i-1]) {
                    continue;
                }
                for (int j = 'a' ; j <= 'c' ; j++) {
                    for (int k = 1 ; k <= 3 ; k++) {
                        
                        char position[5];
                        sprintf(position,"%d %c%d",i,j,k);
                        int nbMorpion = i - 1;
                        int column = (j - 'a')*3 - 1;
                        int line = k;

                        if (!pSuperMorpion->grille[nbMorpion].valide[column+line]) {
                            continue;
                        }

                        pSuperMorpion = ajouteSuperPosition(pSuperMorpion,position, 0);
                        int k = superMinimax(SuperMorpion,depth-1,traitOrdi).poids;
                        pSuperMorpion = removeLastSuperPosition(pSuperMorpion, position, 1);
                        
                        if (resultat.poids>k)
                        {
                            resultat.poids = k;
                            strcpy(resultat.position,position);
                        }
                    }
                }
            }
        }
    }

    return resultat;
}
