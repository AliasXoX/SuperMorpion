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
        resultat.poids++;
        return resultat;
    }

    if (depth==0)
    {
        resultat.poids = grilleGagnee(*morpi,traitOrdi);
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

T_result alphabeta(T_superM morpi, int depth, int traitOrdi,int alpha,int beta, int visible) //favorise l'ordi
{
    T_result resultat = { "     " , 0};
    int i = checkSuperGagnant(morpi,0);
    if (i==1||i==traitOrdi+2)
    {
        return resultat;
    }
    else if (i==3-traitOrdi)
    {
        resultat.poids++;
        return resultat;
    }

    if (depth==0)
    {
        resultat.poids = grilleGagnee(*morpi,traitOrdi);
        return resultat;
    }

    //FILE * file = fopen("print.txt","w");
    //fprintf(file,"EEEEEEEEH\n");

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
                    int k = alphabeta(&next,depth-1,traitOrdi,alpha,beta,visible).poids;
                    //fprintf(file,"%d\n",k);
                    if (resultat.poids<k)
                    {
                        resultat.poids = k;
                        strcpy(resultat.position,position);
                        if (k>beta)
                        {
                            return resultat;
                        }
                        alpha = max(k,alpha);
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
                        int k = alphabeta(&next,depth-1,traitOrdi,alpha,beta,visible).poids;
                        //fprintf(file,"%d\n",k);
                        if (resultat.poids<k)
                        {
                            resultat.poids = k;
                            strcpy(resultat.position,position);
                            if (k>beta)
                            {
                                return resultat;
                            }
                            alpha = max(k,alpha);
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
                    int k = alphabeta(&next,depth-1,traitOrdi,alpha,beta,visible).poids;
                    //fprintf(file,"%d\n",k);
                    if (resultat.poids>k)
                    {
                        resultat.poids = k;
                        strcpy(resultat.position,position);
                        if (k<alpha)
                        {
                            return resultat;
                        }
                        beta = min(beta,k);
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
                        int k = alphabeta(&next,depth-1,traitOrdi,alpha,beta,visible).poids;
                        //fprintf(file,"%d\n",k);
                        if (resultat.poids>k)
                        {
                            resultat.poids = k;
                            strcpy(resultat.position,position);
                            if (k<alpha)
                            {
                                return resultat;
                            }
                            beta = min(beta,k);
                        }
                    }
                }
            }
        }
    }

    return resultat; 
}

int max(int a, int b)
{
    if (a<b)
    {
        return b;
    }
    return a;
}

int min(int a,int b)
{
    if (a<b)
    {
        return a;
    }
    return b;
}

int grilleGagnee(T_superMorpion morpi, int traitOrdi)
{
    int nbr1 = 0;
    for (int i=0;i<9;i++)
    {
        if (morpi.grille[i].state==traitOrdi)
        {
            nbr1++;
        }
    }
    return nbr1;
}