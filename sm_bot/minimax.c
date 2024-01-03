#include "minimax.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

T_result minimax(T_superM morpi, int depth, int traitOrdi, int visible) //favorise l'ordi
{
    T_result resultat = { "     " , 0};
    int i = checkSuperGagnant(morpi,0);
    if (i==1||i==traitOrdi+2)
    {
        return resultat;
    }
    else if (i==3-traitOrdi)
    {
        resultat.poids = 100;
        return resultat;
    }

    if (depth==0)
    {
        resultat.poids = evaluation(*morpi,traitOrdi);
        return resultat;
    }

    if (traitOrdi==morpi->trait)
    {
        resultat.poids = -99999;
        if (morpi->valide[NB_CASES]!=-1)
        {
            for (int i = 'a'; i<='c';i++)
            {
                for (int j = 1 ;j<=3 ;j++)
                {

                    
                    char position[5];
                    sprintf(position,"%d %c%d",morpi->valide[NB_CASES],i,j);
                    int nbMorpion = atoi(&position[0]) - 1;
                    int column = (position[2] - 'a')*3 - 1;
                    int line = atoi(&position[3]);

                    if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion])
                    {
                        continue;
                    }

                    T_superMorpion next = ajouteSuperPosition(*morpi,position,visible);
                    int k = minimax(&next,depth-1,traitOrdi,visible).poids;
                    if (resultat.poids<k)
                    {
                        resultat.poids = k;
                        strcpy(resultat.position,position);
                    }
                }
            }
                
                
        }
        else
        {
            for (int i=1 ;i<=9;i++)
            {
                for (int j = 'a' ; j<='c' ; j++)
                {
                    for (int k = 1 ; k<=3 ; k++)
                    {
                        char position[5];
                        sprintf(position,"%d %c%d",i,j,k);
                        int nbMorpion = atoi(&position[0]) - 1;
                        int column = (position[2] - 'a')*3 - 1;
                        int line = atoi(&position[3]);

                        if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion])
                        {
                            continue;
                        }

                        T_superMorpion next = ajouteSuperPosition(*morpi,position,visible);
                        int k = minimax(&next,depth-1,traitOrdi,visible).poids;
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

    else
    {
        resultat.poids = 99999;
        if (morpi->valide[NB_CASES]!=-1)
        {
            for (int i = 'a'; i<='c';i++)
            {
                for (int j = 1 ;j<=3 ;j++)
                {

                    
                    char position[5];
                    sprintf(position,"%d %c%d",morpi->valide[NB_CASES],i,j);
                    int nbMorpion = atoi(&position[0]) - 1;
                    int column = (position[2] - 'a')*3 - 1;
                    int line = atoi(&position[3]);

                    if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion])
                    {
                        continue;
                    }

                    T_superMorpion next = ajouteSuperPosition(*morpi,position,visible);
                    int k = minimax(&next,depth-1,traitOrdi,visible).poids;
                    if (resultat.poids>k)
                    {
                        resultat.poids = k;
                        strcpy(resultat.position,position);
                    }
                }
            }
                
                
        }
        else
        {
            for (int i=1 ;i<=9;i++)
            {
                for (int j = 'a' ; j<='c' ; j++)
                {
                    for (int k = 1 ; k<=3 ; k++)
                    {
                        char position[5];
                        sprintf(position,"%d %c%d",i,j,k);
                        int nbMorpion = atoi(&position[0]) - 1;
                        int column = (position[2] - 'a')*3 - 1;
                        int line = atoi(&position[3]);

                        if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion])
                        {
                            continue;
                        }

                        T_superMorpion next = ajouteSuperPosition(*morpi,position,visible);
                        int k = minimax(&next,depth-1,traitOrdi,visible).poids;
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

T_result alphabeta(T_superM morpi, int depth, int traitOrdi,double alpha,double beta, int visible) //favorise l'ordi
{
    T_result resultat = { "     " , 0};
    int i = checkSuperGagnant(morpi,0);

    if (depth==0||i)
    {
        resultat.poids = evaluation(*morpi,traitOrdi);
        return resultat;
    }
    if (traitOrdi==morpi->trait)
    {
        resultat.poids = -99999;
        if (morpi->valide[NB_CASES]!=-1)
        {
            for (int i = 'a'; i<='c';i++)
            {
                for (int j = 1 ;j<=3 ;j++)
                {
                    
                    char position[5];
                    sprintf(position,"%d %c%d",morpi->valide[NB_CASES],i,j);
                    int nbMorpion = atoi(&position[0]) - 1;
                    int column = (position[2] - 'a')*3 - 1;
                    int line = atoi(&position[3]);

                    if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion])
                    {
                        continue;
                    }

                    T_superMorpion next = ajouteSuperPosition(*morpi,position,visible);
                    double k = alphabeta(&next,depth-1,traitOrdi,alpha,beta,visible).poids;
                    if (resultat.poids<k)
                    {
                        resultat.poids = k;
                        strcpy(resultat.position,position); 
                    }
                    if (resultat.poids>beta)
                    {
                        return resultat;
                    }
                    alpha = max(resultat.poids,alpha);
                }
            }
                
                
        }
        else
        {
            for (int i=1 ;i<=9;i++)
            {
                for (int j = 'a' ; j<='c' ; j++)
                {
                    for (int k = 1 ; k<=3 ; k++)
                    {
                        char position[5];
                        sprintf(position,"%d %c%d",i,j,k);
                        int nbMorpion = atoi(&position[0]) - 1;
                        int column = (position[2] - 'a')*3 - 1;
                        int line = atoi(&position[3]);

                        if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion])
                        {
                            continue;
                        }

                        T_superMorpion next = ajouteSuperPosition(*morpi,position,visible);
                        double mnm = alphabeta(&next,depth-1,traitOrdi,alpha,beta,visible).poids;
                        if (resultat.poids<mnm)
                        {
                            resultat.poids = mnm;
                            strcpy(resultat.position,position);
                        }
                        if (resultat.poids>beta)
                        {
                            return resultat;
                        }
                        alpha = max(resultat.poids,alpha);
                    }
                }
            }
        }

    }

    else
    {
        resultat.poids = 99999;
        if (morpi->valide[NB_CASES]!=-1)
        {
            for (int i = 'a'; i<='c';i++)
            {
                for (int j = 1 ;j<=3 ;j++)
                {

                    
                    char position[5];
                    sprintf(position,"%d %c%d",morpi->valide[NB_CASES],i,j);
                    int nbMorpion = atoi(&position[0]) - 1;
                    int column = (position[2] - 'a')*3 - 1;
                    int line = atoi(&position[3]);

                    if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion])
                    {
                        continue;
                    }

                    T_superMorpion next = ajouteSuperPosition(*morpi,position,visible);
                    double k = alphabeta(&next,depth-1,traitOrdi,alpha,beta,visible).poids;
                    if (resultat.poids>k)
                    {
                        resultat.poids = k;
                        strcpy(resultat.position,position);
                    }
                    if (resultat.poids<alpha)
                    {
                        return resultat;
                    }
                    beta = min(beta,resultat.poids);
                }
            }
                
                
        }
        else
        {
            for (int i=1 ;i<=9;i++)
            {
                for (int j = 'a' ; j<='c' ; j++)
                {
                    for (int k = 1 ; k<=3 ; k++)
                    {
                        char position[5];
                        sprintf(position,"%d %c%d",i,j,k);
                        int nbMorpion = atoi(&position[0]) - 1;
                        int column = (position[2] - 'a')*3 - 1;
                        int line = atoi(&position[3]);

                        if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion])
                        {
                            continue;
                        }

                        T_superMorpion next = ajouteSuperPosition(*morpi,position,visible);
                        double mnms = alphabeta(&next,depth-1,traitOrdi,alpha,beta,visible).poids;
                        if (resultat.poids>mnms)
                        {
                            resultat.poids = mnms;
                            strcpy(resultat.position,position);
                        }
                        if (resultat.poids<alpha)
                        {
                            return resultat;
                        }
                        beta = min(beta,resultat.poids);
                    }
                }
            }
        }
    }

    return resultat; 
}

T_result negamax(T_superM morpi, int depth, int visible) //calcul la meilleure position pour le joueur au trait
{
    T_result resultat = { "     " , 0};
    int i = checkSuperGagnant(morpi,0);
    if (i)
    {
        resultat.poids = 100;
        return resultat;
    }
    if (depth==0)
    {
        resultat.poids = evaluation(*morpi,morpi->trait);
        return resultat;
    }

    resultat.poids = -999999;
    if (morpi->valide[NB_CASES]!=-1)
        {
            for (int i = 'a'; i<='c';i++)
            {
                for (int j = 1 ;j<=3 ;j++)
                {
                    char position[5];
                    sprintf(position,"%d %c%d",morpi->valide[NB_CASES],i,j);
                    int nbMorpion = atoi(&position[0]) - 1;
                    int column = (position[2] - 'a')*3 - 1;
                    int line = atoi(&position[3]);

                    if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion])
                    {
                        continue;
                    }

                    T_superMorpion next = ajouteSuperPosition(*morpi,position,visible);
                    int k = -negamax(&next,depth-1,visible).poids;
                    if (resultat.poids<k)
                    {
                        resultat.poids = k;
                        strcpy(resultat.position,position);
                    }
                }
            }
                
                
        }
        else
        {
            for (int i=1 ;i<=9;i++)
            {
                for (int j = 'a' ; j<='c' ; j++)
                {
                    for (int k = 1 ; k<=3 ; k++)
                    {
                        char position[5];
                        sprintf(position,"%d %c%d",i,j,k);
                        int nbMorpion = atoi(&position[0]) - 1;
                        int column = (position[2] - 'a')*3 - 1;
                        int line = atoi(&position[3]);

                        if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion])
                        {
                            continue;
                        }

                        T_superMorpion next = ajouteSuperPosition(*morpi,position,visible);
                        int k = -negamax(&next,depth-1,visible).poids;
                        if (resultat.poids<k)
                        {
                            resultat.poids = k;
                            strcpy(resultat.position,position);
                        }
                    }
                }
            }
        }

return resultat;

}

T_result negalphabeta(T_superM morpi, int depth,int alpha,int beta, int visible) //calcul la meilleure position pour le joueur au trait
{
    T_result resultat = { "     " , 0};
    int i = checkSuperGagnant(morpi,0);
    if (i)
    {
        resultat.poids = 100;
        return resultat;
    }
    if (depth==0)
    {
        resultat.poids = evaluation(*morpi,morpi->trait);
        return resultat;
    }

    resultat.poids = -999999;
    if (morpi->valide[NB_CASES]!=-1)
        {
            for (int i = 'a'; i<='c';i++)
            {
                for (int j = 1 ;j<=3 ;j++)
                {

                    
                    char position[5];
                    sprintf(position,"%d %c%d",morpi->valide[NB_CASES],i,j);
                    int nbMorpion = atoi(&position[0]) - 1;
                    int column = (position[2] - 'a')*3 - 1;
                    int line = atoi(&position[3]);

                    if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion])
                    {
                        continue;
                    }

                    T_superMorpion next = ajouteSuperPosition(*morpi,position,visible);
                    int k = -negalphabeta(&next,depth-1,-beta,-alpha,visible).poids;
                    if (resultat.poids<k)
                    {
                        resultat.poids = k;
                        strcpy(resultat.position,position);
                    }
                    if (resultat.poids>beta)
                    {
                        return resultat;
                    }
                    alpha = max(alpha,resultat.poids);
                }
            }
                
                
        }
        else
        {
            for (int i=1 ;i<=9;i++)
            {
                for (int j = 'a' ; j<='c' ; j++)
                {
                    for (int k = 1 ; k<=3 ; k++)
                    {
                        char position[5];
                        sprintf(position,"%d %c%d",i,j,k);
                        int nbMorpion = atoi(&position[0]) - 1;
                        int column = (position[2] - 'a')*3 - 1;
                        int line = atoi(&position[3]);

                        if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion])
                        {
                            continue;
                        }

                        T_superMorpion next = ajouteSuperPosition(*morpi,position,visible);
                        int k = -negalphabeta(&next,depth-1,-beta,-alpha,visible).poids;
                        if (resultat.poids<k)
                        {
                            resultat.poids = k;
                            strcpy(resultat.position,position);
                        }
                        if (resultat.poids>beta)
                        {
                            return resultat;
                        }
                        alpha = max(alpha,resultat.poids);
                    }
                }
            }
        }

return resultat;

}

double max(double a, double b)
{
    if (a<b)
    {
        return b;
    }
    return a;
}

double min(double a,double b)
{
    if (a<b)
    {
        return a;
    }
    return b;
}

T_superMorpion rotation(T_superMorpion morpi,int k)
{
    if (k==0)
    {
        return morpi;
    }
    T_morpion temp = morpi.grille[0]; //temp = 0
    T_morpion temp2 = morpi.grille[1];//temp2 = 1
    morpi.grille[0] = morpi.grille[3];// 3->0
    morpi.grille[1] = temp;// 0->1
    temp = morpi.grille[2];// temp = 2
    morpi.grille[2]=temp2;// 1->2
    temp2 = morpi.grille[5];// temp2 = 5
    morpi.grille[5]=temp; // 2->5
    temp = morpi.grille[6]; //temp = 6
    morpi.grille[6]=morpi.grille[7]; //7->6
    morpi.grille[3]=temp;// 6->3
    temp = morpi.grille[8];//temp = 8
    morpi.grille[8]=temp2; //5->8
    morpi.grille[7]=temp; //8->7

    return rotation(morpi,k-1);
}

int grilleGagnee(T_superMorpion morpi, int trait)
{
    int nbr1 = 0;
    for (int i=0;i<9;i++)
    {
        if (morpi.grille[i].state==trait)
        {
            nbr1++;
        }
    }
    return nbr1;
}

int convert(char c,int traitOrdi) //Converti le symbole sur une grille de morpion en chiffre (1 pour l'IA et -1 pour l'adversaire)
{
    if (traitOrdi)
    {
        if(c=='X')
        {
            return(1);
        }
        else if (c=='O')
        {
            return(-1);
        }
    }
    else
    {
        if(c=='O')
        {
            return(1);
        }
        else if (c=='X')
        {
            return(-1);
        }
    }
    return 0;
}

int evalPositionMorpion(T_morpion morpion,int traitOrdi)
{
    //int corres[9] = {6,3,0,7,4,1,8,5,2};
    int corres[] = {2, 5, 8, 1, 4, 7, 0, 3, 6};
    float eval = 0;
    float points[] = {0.2, 0.17, 0.2, 0.17, 0.22, 0.17, 0.2, 0.17, 0.2};

    for(int i=0;i<9;i++)
    {
        eval += convert(morpion.grille[corres[i]],traitOrdi)*points[i];
    }

    int a = -2;
    if (convert(morpion.grille[corres[0]],traitOrdi)+convert(morpion.grille[corres[1]],traitOrdi)+convert(morpion.grille[corres[2]],traitOrdi) == a)
    {
        eval -= 6;
        //printf("Ligne -6\n");
    }
    if (convert(morpion.grille[corres[3]],traitOrdi)+convert(morpion.grille[corres[4]],traitOrdi)+convert(morpion.grille[corres[5]],traitOrdi) == a)
    {
        eval -= 6;
        //printf("Ligne -6\n");
    }
    if (convert(morpion.grille[corres[6]],traitOrdi)+convert(morpion.grille[corres[7]],traitOrdi)+convert(morpion.grille[corres[8]],traitOrdi) == a)
    {
        eval -= 6;
        //printf("Ligne -6\n");
    }

    if (convert(morpion.grille[corres[0]],traitOrdi)+convert(morpion.grille[corres[3]],traitOrdi)+convert(morpion.grille[corres[6]],traitOrdi) == a)
    {
        eval-=6;
        //printf("Colonne -6\n");
    }
    if (convert(morpion.grille[corres[1]],traitOrdi)+convert(morpion.grille[corres[4]],traitOrdi)+convert(morpion.grille[corres[7]],traitOrdi) == a)
    {
        eval-=6;
        //printf("Colonne -6\n");
    }
    if (convert(morpion.grille[corres[2]],traitOrdi)+convert(morpion.grille[corres[5]],traitOrdi)+convert(morpion.grille[corres[8]],traitOrdi) == a)
    {
        eval-=6;
        //printf("Colonne -6\n");
    }

    if (convert(morpion.grille[corres[0]],traitOrdi)+convert(morpion.grille[corres[4]],traitOrdi)+convert(morpion.grille[corres[8]],traitOrdi) == a)
    {
        eval-=7;
        //printf("Diagonale -7\n");
    }
    if (convert(morpion.grille[corres[2]],traitOrdi)+convert(morpion.grille[corres[4]],traitOrdi)+convert(morpion.grille[corres[6]],traitOrdi) == a)
    {
        eval-=7;
        //printf("Diagonale -7\n");
    }



    a = 2;
    if (convert(morpion.grille[corres[0]],traitOrdi)+convert(morpion.grille[corres[1]],traitOrdi)+convert(morpion.grille[corres[2]],traitOrdi) == a)
    {
        eval += 6;
        //printf("Ligne +6\n");
    }
    if (convert(morpion.grille[corres[3]],traitOrdi)+convert(morpion.grille[corres[4]],traitOrdi)+convert(morpion.grille[corres[5]],traitOrdi) == a)
    {
        eval += 6;
        //printf("Ligne +6\n");
    }
    if (convert(morpion.grille[corres[6]],traitOrdi)+convert(morpion.grille[corres[7]],traitOrdi)+convert(morpion.grille[corres[8]],traitOrdi) == a)
    {
        eval += 6;
        //printf("Ligne +6\n");
    }

    if (convert(morpion.grille[corres[0]],traitOrdi)+convert(morpion.grille[corres[3]],traitOrdi)+convert(morpion.grille[corres[6]],traitOrdi) == a)
    {
        eval+=6;
        //printf("Colonne +6\n");
    }
    if (convert(morpion.grille[corres[1]],traitOrdi)+convert(morpion.grille[corres[4]],traitOrdi)+convert(morpion.grille[corres[7]],traitOrdi) == a)
    {
        eval+=6;
        //printf("Colonne +6\n");
    }
    if (convert(morpion.grille[corres[2]],traitOrdi)+convert(morpion.grille[corres[5]],traitOrdi)+convert(morpion.grille[corres[8]],traitOrdi) == a)
    {
        eval+=6;
        //printf("Colonne +6\n");
    }

    if (convert(morpion.grille[corres[0]],traitOrdi)+convert(morpion.grille[corres[4]],traitOrdi)+convert(morpion.grille[corres[8]],traitOrdi) == a)
    {
        eval+=7;
        //printf("Diagonale +7\n");
    }
    if (convert(morpion.grille[corres[2]],traitOrdi)+convert(morpion.grille[corres[4]],traitOrdi)+convert(morpion.grille[corres[6]],traitOrdi) == a)
    {
        eval+=7;
        //printf("Diagonale +7\n");
    }

    a = -1;

    if((convert(morpion.grille[corres[0]],traitOrdi) + convert(morpion.grille[corres[1]],traitOrdi) == 2*a && convert(morpion.grille[corres[2]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if ((convert(morpion.grille[corres[1]],traitOrdi) + convert(morpion.grille[corres[2]],traitOrdi) == 2*a && convert(morpion.grille[corres[0]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[0]],traitOrdi) + convert(morpion.grille[corres[2]],traitOrdi) == 2*a && convert(morpion.grille[corres[1]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[3]],traitOrdi) + convert(morpion.grille[corres[4]],traitOrdi) == 2*a && convert(morpion.grille[corres[5]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[3]],traitOrdi) + convert(morpion.grille[corres[5]],traitOrdi) == 2*a && convert(morpion.grille[corres[4]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[5]],traitOrdi) + convert(morpion.grille[corres[4]],traitOrdi) == 2*a && convert(morpion.grille[corres[3]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[6]],traitOrdi) + convert(morpion.grille[corres[7]],traitOrdi) == 2*a && convert(morpion.grille[corres[8]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[6]],traitOrdi) + convert(morpion.grille[corres[8]],traitOrdi) == 2*a && convert(morpion.grille[corres[7]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[7]],traitOrdi) + convert(morpion.grille[corres[8]],traitOrdi) == 2*a && convert(morpion.grille[corres[6]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[0]],traitOrdi) + convert(morpion.grille[corres[3]],traitOrdi) == 2*a && convert(morpion.grille[corres[6]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[0]],traitOrdi) + convert(morpion.grille[corres[6]],traitOrdi) == 2*a && convert(morpion.grille[corres[3]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[3]],traitOrdi) + convert(morpion.grille[corres[6]],traitOrdi) == 2*a && convert(morpion.grille[corres[0]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[1]],traitOrdi) + convert(morpion.grille[corres[4]],traitOrdi) == 2*a && convert(morpion.grille[corres[7]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[1]],traitOrdi) + convert(morpion.grille[corres[7]],traitOrdi) == 2*a && convert(morpion.grille[corres[4]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[4]],traitOrdi) + convert(morpion.grille[corres[7]],traitOrdi) == 2*a && convert(morpion.grille[corres[1]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[2]],traitOrdi) + convert(morpion.grille[corres[5]],traitOrdi) == 2*a && convert(morpion.grille[corres[8]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[2]],traitOrdi) + convert(morpion.grille[corres[8]],traitOrdi) == 2*a && convert(morpion.grille[corres[5]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[5]],traitOrdi) + convert(morpion.grille[corres[8]],traitOrdi) == 2*a && convert(morpion.grille[corres[2]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[0]],traitOrdi) + convert(morpion.grille[corres[4]],traitOrdi) == 2*a && convert(morpion.grille[corres[8]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[0]],traitOrdi) + convert(morpion.grille[corres[8]],traitOrdi) == 2*a && convert(morpion.grille[corres[4]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[4]],traitOrdi) + convert(morpion.grille[corres[8]],traitOrdi) == 2*a && convert(morpion.grille[corres[0]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[2]],traitOrdi) + convert(morpion.grille[corres[4]],traitOrdi) == 2*a && convert(morpion.grille[corres[6]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[2]],traitOrdi) + convert(morpion.grille[corres[6]],traitOrdi) == 2*a && convert(morpion.grille[corres[4]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }
    if((convert(morpion.grille[corres[4]],traitOrdi) + convert(morpion.grille[corres[6]],traitOrdi) == 2*a && convert(morpion.grille[corres[2]],traitOrdi) == -a))
    {
        eval+=9;
        //printf("Bloquage +9\n");
    }

    a = 1;

    if((convert(morpion.grille[corres[0]],traitOrdi) + convert(morpion.grille[corres[1]],traitOrdi) == 2*a && convert(morpion.grille[corres[2]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if ((convert(morpion.grille[corres[1]],traitOrdi) + convert(morpion.grille[corres[2]],traitOrdi) == 2*a && convert(morpion.grille[corres[0]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[0]],traitOrdi) + convert(morpion.grille[corres[2]],traitOrdi) == 2*a && convert(morpion.grille[corres[1]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[3]],traitOrdi) + convert(morpion.grille[corres[4]],traitOrdi) == 2*a && convert(morpion.grille[corres[5]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[3]],traitOrdi) + convert(morpion.grille[corres[5]],traitOrdi) == 2*a && convert(morpion.grille[corres[4]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[5]],traitOrdi) + convert(morpion.grille[corres[4]],traitOrdi) == 2*a && convert(morpion.grille[corres[3]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[6]],traitOrdi) + convert(morpion.grille[corres[7]],traitOrdi) == 2*a && convert(morpion.grille[corres[8]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[6]],traitOrdi) + convert(morpion.grille[corres[8]],traitOrdi) == 2*a && convert(morpion.grille[corres[7]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[7]],traitOrdi) + convert(morpion.grille[corres[8]],traitOrdi) == 2*a && convert(morpion.grille[corres[6]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[0]],traitOrdi) + convert(morpion.grille[corres[3]],traitOrdi) == 2*a && convert(morpion.grille[corres[6]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[0]],traitOrdi) + convert(morpion.grille[corres[6]],traitOrdi) == 2*a && convert(morpion.grille[corres[3]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[3]],traitOrdi) + convert(morpion.grille[corres[6]],traitOrdi) == 2*a && convert(morpion.grille[corres[0]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[1]],traitOrdi) + convert(morpion.grille[corres[4]],traitOrdi) == 2*a && convert(morpion.grille[corres[7]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[1]],traitOrdi) + convert(morpion.grille[corres[7]],traitOrdi) == 2*a && convert(morpion.grille[corres[4]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[4]],traitOrdi) + convert(morpion.grille[corres[7]],traitOrdi) == 2*a && convert(morpion.grille[corres[1]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[2]],traitOrdi) + convert(morpion.grille[corres[5]],traitOrdi) == 2*a && convert(morpion.grille[corres[8]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[2]],traitOrdi) + convert(morpion.grille[corres[8]],traitOrdi) == 2*a && convert(morpion.grille[corres[5]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[5]],traitOrdi) + convert(morpion.grille[corres[8]],traitOrdi) == 2*a && convert(morpion.grille[corres[2]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[0]],traitOrdi) + convert(morpion.grille[corres[4]],traitOrdi) == 2*a && convert(morpion.grille[corres[8]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[0]],traitOrdi) + convert(morpion.grille[corres[8]],traitOrdi) == 2*a && convert(morpion.grille[corres[4]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[4]],traitOrdi) + convert(morpion.grille[corres[8]],traitOrdi) == 2*a && convert(morpion.grille[corres[0]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[2]],traitOrdi) + convert(morpion.grille[corres[4]],traitOrdi) == 2*a && convert(morpion.grille[corres[6]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[2]],traitOrdi) + convert(morpion.grille[corres[6]],traitOrdi) == 2*a && convert(morpion.grille[corres[4]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }
    if((convert(morpion.grille[corres[4]],traitOrdi) + convert(morpion.grille[corres[6]],traitOrdi) == 2*a && convert(morpion.grille[corres[2]],traitOrdi) == -a))
    {
        eval-=9;
        //printf("Bloquage -9\n");
    }

    if (morpion.state==traitOrdi)
    {
        eval+=50;
        //printf("gagne +50\n");
    }
    else if (morpion.state==(traitOrdi+1)%2)
    {
        eval-=50;
        //printf("perd -50\n");
    }

    return eval;
}

int evaluation(T_superMorpion morpi,int traitOrdi) //evalue à quel point une position est avantageuse pour l'ordi
{
    //int corres[9] = {6,3,0,7,4,1,8,5,2};
    int corres[] = {2, 5, 8, 1, 4, 7, 0, 3, 6};
    double k = 0;
    double evaluatorMul[] = {1.4, 1, 1.4, 1, 1.75, 1, 1.4, 1, 1.4};

    T_morpion smorpion = newMorpion();
    for (int i=0;i<9;i++)
    {
        k += evalPositionMorpion(morpi.grille[i],traitOrdi)*1.5*evaluatorMul[i];
        if (i==morpi.valide[NB_CASES])
        {
            k+=evalPositionMorpion(morpi.grille[i],traitOrdi)*evaluatorMul[i];
        }

        if (morpi.grille[i].state==traitOrdi)
        {
            if (traitOrdi) {smorpion.grille[corres[i]]='X';}
            else {smorpion.grille[corres[i]]='O';}
            k+=evaluatorMul[i];
        }
        else if (morpi.grille[i].state==(traitOrdi+1)%2)
        {
            if (traitOrdi) {smorpion.grille[corres[i]]='O';}
            else {smorpion.grille[corres[i]]='X';}
            k-=evaluatorMul[i];
        }
        else {smorpion.grille[corres[i]]='.';}

        smorpion.valide[corres[i]] = morpi.valide[i];
    }
    int i = checkSuperGagnant(&morpi,0);
    if (i==traitOrdi+2) {k+=50000;}
    if (i==3-traitOrdi) {k-=50000;}
    k+=evalPositionMorpion(smorpion,traitOrdi)*150;
    
    return k;
}

T_result show_alphabeta(T_superM morpi, int depth, int traitOrdi,double alpha,double beta, int visible,int parent,FILE* fichier)
{
    static int x = 0;
    int indice_actuel = ++x;
    if (parent!=-1)
    {
        showPosition(morpi,indice_actuel,fichier);
        fprintf(fichier,"a%d -> a%d [label=\"coup\"];\n",parent,indice_actuel);
    }
    else
    {
        showPosition(morpi,indice_actuel,fichier);
    }


    T_result resultat = { "     " , 0};
    int i = checkSuperGagnant(morpi,0);

    if (depth==0||i)
    {
        resultat.poids = evaluation(*morpi,traitOrdi);
        fprintf(fichier,"a%d [xlabel=\"%lf\"];\n",indice_actuel,resultat.poids);
        return resultat;
    }

    fprintf(fichier,"a%d [xlabel=\"%lf\"];\n",indice_actuel,alphabeta(morpi,depth,traitOrdi,alpha,beta,visible).poids);

    if (traitOrdi==morpi->trait)
    {
        resultat.poids = -99999;
        if (morpi->valide[NB_CASES]!=-1)
        {
            for (int i = 'a'; i<='c';i++)
            {
                for (int j = 1 ;j<=3 ;j++)
                {
                    
                    char position[5];
                    sprintf(position,"%d %c%d",morpi->valide[NB_CASES],i,j);
                    int nbMorpion = atoi(&position[0]) - 1;
                    int column = (position[2] - 'a')*3 - 1;
                    int line = atoi(&position[3]);

                    if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion])
                    {
                        continue;
                    }

                    T_superMorpion next = ajouteSuperPosition(*morpi,position,visible);
                    double k = show_alphabeta(&next,depth-1,traitOrdi,alpha,beta,visible,indice_actuel,fichier).poids;
                    if (resultat.poids<k)
                    {
                        resultat.poids = k;
                        strcpy(resultat.position,position); 
                    }
                    if (resultat.poids>beta)
                    {
                        fprintf(fichier,"a%d [xlabel=\"%lf\"];\n",indice_actuel,resultat.poids);
                        return resultat;
                    }
                    alpha = max(resultat.poids,alpha);
                }
            }
                
                
        }
        else
        {
            for (int i=1 ;i<=9;i++)
            {
                for (int j = 'a' ; j<='c' ; j++)
                {
                    for (int k = 1 ; k<=3 ; k++)
                    {
                        char position[5];
                        sprintf(position,"%d %c%d",i,j,k);
                        int nbMorpion = atoi(&position[0]) - 1;
                        int column = (position[2] - 'a')*3 - 1;
                        int line = atoi(&position[3]);

                        if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion])
                        {
                            continue;
                        }

                        T_superMorpion next = ajouteSuperPosition(*morpi,position,visible);
                        double mnm = show_alphabeta(&next,depth-1,traitOrdi,alpha,beta,visible,indice_actuel,fichier).poids;
                        if (resultat.poids<mnm)
                        {
                            resultat.poids = mnm;
                            strcpy(resultat.position,position);
                        }
                        if (resultat.poids>beta)
                        {
                            fprintf(fichier,"a%d [xlabel=\"%lf\"];\n",indice_actuel,resultat.poids);
                            return resultat;
                        }
                        alpha = max(resultat.poids,alpha);
                    }
                }
            }
        }

    }

    else
    {
        resultat.poids = 99999;
        if (morpi->valide[NB_CASES]!=-1)
        {
            for (int i = 'a'; i<='c';i++)
            {
                for (int j = 1 ;j<=3 ;j++)
                {

                    
                    char position[5];
                    sprintf(position,"%d %c%d",morpi->valide[NB_CASES],i,j);
                    int nbMorpion = atoi(&position[0]) - 1;
                    int column = (position[2] - 'a')*3 - 1;
                    int line = atoi(&position[3]);

                    if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion])
                    {
                        continue;
                    }

                    T_superMorpion next = ajouteSuperPosition(*morpi,position,visible);
                    double k = show_alphabeta(&next,depth-1,traitOrdi,alpha,beta,visible,indice_actuel,fichier).poids;
                    if (resultat.poids>k)
                    {
                        resultat.poids = k;
                        strcpy(resultat.position,position);
                    }
                    if (resultat.poids<alpha)
                    {
                        fprintf(fichier,"a%d [xlabel=\"%lf\"];\n",indice_actuel,resultat.poids);
                        return resultat;
                    }
                    beta = min(beta,resultat.poids);
                }
            }
                
                
        }
        else
        {
            for (int i=1 ;i<=9;i++)
            {
                for (int j = 'a' ; j<='c' ; j++)
                {
                    for (int k = 1 ; k<=3 ; k++)
                    {
                        char position[5];
                        sprintf(position,"%d %c%d",i,j,k);
                        int nbMorpion = atoi(&position[0]) - 1;
                        int column = (position[2] - 'a')*3 - 1;
                        int line = atoi(&position[3]);

                        if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion])
                        {
                            continue;
                        }

                        T_superMorpion next = ajouteSuperPosition(*morpi,position,visible);
                        double mnms = show_alphabeta(&next,depth-1,traitOrdi,alpha,beta,visible,indice_actuel,fichier).poids;
                        if (resultat.poids>mnms)
                        {
                            resultat.poids = mnms;
                            strcpy(resultat.position,position);
                        }
                        if (resultat.poids<alpha)
                        {
                            fprintf(fichier,"a%d [xlabel=\"%lf\"];\n",indice_actuel,resultat.poids);
                            return resultat;
                        }
                        beta = min(beta,resultat.poids);
                    }
                }
            }
        }
    }

    return resultat;
}