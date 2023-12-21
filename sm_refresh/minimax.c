#include "minimax.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

T_result minimax(T_superM morpi, int depth, int traitOrdi, int visible)
{
    T_result resultat = { "     " , 0};
    int i = checkSuperGagnant(morpi,0);
    if (i==1||i==3-traitOrdi)
    {
        return resultat;
    }
    else if (i==traitOrdi+2)
    {
        resultat.poids++;
        return resultat;
    }

    if (depth==0)
    {
        return resultat;
    }

    if (traitOrdi!=morpi->trait)
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