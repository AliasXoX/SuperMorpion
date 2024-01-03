#include <stdio.h>
#include <string.h>

#include "morpion.h"
#include "superMorpion.h"
#include "minimax.h"

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
int toPos(char * s);

int main(int argc, char *argv[])
{
    if (argc>5)
    {
        printf("ERREUR ARGUMENTS ERRONÉS\n");
        return(1);
    }

    int depth = 5;
    char fen[100];
    int temps = atoi(argv[2]);
    sprintf(fen,"%s",argv[1]);
    

    //sprintf(temps,"%s",argv[2]);
    int evalt = evalTemps(fen);
    if (evalt<27) {depth = 5;}
    if (evalt>=27&&evalt<54) {depth = 6;}
    if (evalt>=54) {depth = 7;}
    if (temps<6) {depth = 3;}
    int traitOrdi = -1;
    T_superMorpion m = decryptSuper(fen);
    traitOrdi = m.trait;
    T_result r = alphabeta(&m,depth,traitOrdi,-99999,99999,0);
    //printf("%d\n",toPos(r.position));
    //char retour[4];
    //sprintf(retour,"%c%c%c",r.position[0],r.position[2],r.position[3]);
    printf("%d",toPos(r.position));
    return(0);
    
    /*
    remove("print.txt");
    int coup = 0;
    int depth = 7;

    T_superMorpion superMorpion = newSuperMorpion();
    
    T_superM pSuperMorpion = &superMorpion;

    T_superMorpion S = newSuperMorpion();
    

    char position[5];
    
    printf("Voulez vous commencer en premier (0) ou en deuxième (1) ?\n");
    int traitOrdi;
    scanf("%d", &traitOrdi);
    clearInputBuffer();

    if (traitOrdi)
    {
        showSuperGrille(pSuperMorpion);
        showSuperGrilleState(pSuperMorpion);
        //showPosition(pSuperMorpion);
        fflush(stdout);
        T_result r = minimax(pSuperMorpion,2,0,0);
        S = ajouteSuperPosition(*pSuperMorpion, r.position,1);
        pSuperMorpion = &S;
        showSuperGrille(pSuperMorpion);
        showSuperGrilleState(pSuperMorpion);
        //showPosition(pSuperMorpion);
        fflush(stdout);
        coup++;
    }
    else
    {   
        showSuperGrille(pSuperMorpion);
        showSuperGrilleState(pSuperMorpion);
        //showPosition(pSuperMorpion);
        fflush(stdout);
        fgets(position, sizeof(position), stdin);
        S = ajouteSuperPosition(*pSuperMorpion, position,1);
        pSuperMorpion = &S;
        showSuperGrille(pSuperMorpion);
        showSuperGrilleState(pSuperMorpion);
        //showPosition(pSuperMorpion);
        fflush(stdout);
        coup++;
    }
    
    while (!checkSuperGagnant(pSuperMorpion,1)) {
        if (pSuperMorpion->trait==(traitOrdi+1)%2)
        {
            //clearInputBuffer();
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            if (c == EOF) {
                clearerr(stdin); // Clear the end-of-file indicator if encountered
            }
            if (fgets(position, sizeof(position), stdin) == NULL) {
                break;
            }
            S = ajouteSuperPosition(*pSuperMorpion, position,1);
            pSuperMorpion = &S;
            showSuperGrille(pSuperMorpion);
            showSuperGrilleState(pSuperMorpion);
            //showPosition(pSuperMorpion);
            fflush(stdout);
            coup++;
        }
        else
        {
            remove("print.txt");
            //if(coup<20) {depth = 5;}
            if (coup>30) {depth = 8;}
            //if (coup<40) {depth = 7;}
            T_result r = alphabeta(pSuperMorpion,depth,traitOrdi,-999999,999999,0);
            FILE * fp = fopen("print.txt","w");
            fprintf(fp,"%s",r.position);
            fclose(fp);
            S = ajouteSuperPosition(*pSuperMorpion,r.position,1);
            pSuperMorpion = &S;
            showSuperGrille(pSuperMorpion);
            showSuperGrilleState(pSuperMorpion);
            //showPosition(pSuperMorpion);
            coup++;
        }
        
    }
    */
   
    /*
    char * s = "xoooxoxo1xoxxx1o1ooxxoo1x2xoxo2xoxOXO1x3o1x1O 05 x";
    T_superMorpion m = decryptSuper(s);
    printf("%d\n",m.trait);
    printf("%d\n",m.valide[NB_CASES]);
    //for(int i=0;i<9;i++)
    //{
    //    printf("%d : %d\n",i+1,evalPositionMorpion(m.grille[i],1));
    //}
    //printf("%d : %d\n",2,evalPositionMorpion(m.grille[1],1));
    FILE * fp = fopen("g.dot","w");
    fputs("digraph {\n",fp);
    show_alphabeta(&m,0,1,-999999,999999,0,-1,fp);
    fputs("}\n",fp);
    fclose(fp);
    */
    
    /*
    FILE * fp = fopen("g.dot","w");
    fputs("digraph {\n",fp);
    show_alphabeta(pSuperMorpion,2,1,-999999,999999,0,-1,fp);
    fputs("}\n",fp);
    fclose(fp);
    */
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    if (c == EOF) {
        clearerr(stdin); // Clear the end-of-file indicator if encountered
    }
}

int toPos(char * s)
{
    int i = atoi(&s[0])-1;
    int j = 0;
    if (s[2]=='a')
    {
        j = 6 - (atoi(&s[3])-1)*3;
    }
    if (s[2]=='b')
    {
        j = 7 - (atoi(&s[3])-1)*3;
    } 
    if (s[2]=='c')
    {
        j = 8 - (atoi(&s[3])-1)*3;
    }
    i++;
    j++;
    return(i*10+j);
}