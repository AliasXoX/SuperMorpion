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

    if (checkGagnant(&superMorpion.grille[nbMorpion],visible)) {
        superMorpion.valide[nbMorpion] = 0;
    }
    
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
    
    return superMorpion;

}

int checkSuperGagnant(T_superM pSuperMorpion,int visible) {
    int corres[9] = {6,3,0,7,4,1,8,5,2};
    T_morpion smorpion = newMorpion();
    for(int i=0;i<9;i++)
    {
        if (pSuperMorpion->grille[i].state==1)
        {
            smorpion.grille[corres[i]]='X';
        }
        else if (pSuperMorpion->grille[i].state==0)
        {
            smorpion.grille[corres[i]]='O';
        }
        else {smorpion.grille[corres[i]]='.';}
        smorpion.valide[corres[i]] = pSuperMorpion->valide[i];
    }
    checkGagnant(&smorpion,0);
    if (smorpion.state==-2)
    {
        int v1 = 0;
        int v2 = 0;
        for (int i=0;i<9;i++)
        {
            if (pSuperMorpion->grille[i].state==1)
            {
                v1++;
            }
            else if (pSuperMorpion->grille[i].state==0)
            {
                v2++;
            }
        }
        if (v1>=5)
        {
            if(visible){printf("Le gagnant est le joueur 1 !\n");}
            return 2;
        }
        else if (v2>=5)
        {
            if (visible) {printf("Le gagnant est le joueur 2 !\n");}
            return 3;
        }

        if(visible){printf("Match nul !\n");}
        return 1;
    }
    else if (smorpion.state==0)
    {
        if(visible){printf("Le gagnant est le joueur 1 !\n");}
        return 2;
    }
    else if (smorpion.state==1)
    {
        if (visible) {printf("Le gagnant est le joueur 2 !\n");}
        return 3;
    }
   return 0;
}

T_superMorpion decryptSuper(char * fen)
{
    int corres[] = {2, 5, 8, 1, 4, 7, 0, 3, 6};
    T_superMorpion morpi = newSuperMorpion();
    int i = 1;
    int j = 0;
    while (i<=9)
    {
        if (fen[j]=='X')
        {
            j++;
            morpi.valide[i-1]=0;
            morpi.grille[i-1].state = 1;
            i++;
            continue;
        }
        else if (fen[j]=='O')
        {
            j++;
            morpi.valide[i-1]=0;
            morpi.grille[i-1].state = 0;
            i++;
            continue;
        }
        int k = 1;
        while(k<=9)
        {
            if (fen[j]>='1'&&fen[j]<='9')
            {
                int index = atoi(&fen[j]);
                k+=index;
            }

            else if (fen[j]=='x')
            {
                morpi.grille[i-1].grille[corres[k-1]] = 'X';
                morpi.grille[i-1].valide[corres[k-1]] = 0;
                k++;
            }

            else if (fen[j]=='o')
            {
                morpi.grille[i-1].grille[corres[k-1]] = 'O';
                morpi.grille[i-1].valide[corres[k-1]] = 0;
                k++;
            }
            j++;
        }
        i++;
    }
    j+=3;
    int temp = atoi(&fen[j-1]);
    if (temp==0) 
    {
        morpi.valide[9] = -1;
    }
    else if (morpi.valide[temp-1])
    {
        morpi.valide[9] = temp;
    }
    else
    {
        morpi.valide[9] = -1;
    }
    j++;
    if (fen[j]=='x')
    {
        morpi.trait = 1;
    }
    else
    {
        morpi.trait = 0;
    }

    return(morpi);
}

int evalTemps(char* fen)
{
    int eval = 0;
    int i = 0;
    while(fen[i]!=' ')
    {
        if (fen[i]=='x'||fen[i]=='o') {eval++;i++;continue;}
        if (fen[i]=='X'||fen[i]=='O') {eval+=9;i++;continue;}
        i++;
    }
    return(eval);
}