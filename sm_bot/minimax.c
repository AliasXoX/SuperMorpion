#include "minimax.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

T_result minimax(T_superM morpi, int depth, int traitOrdi, int visible) //favorise l'ordi
{
    T_result resultat = { "     " , 0}; //On initialise la valeur retournée par défaut
    int i = checkSuperGagnant(morpi,0); //On regarde si la partie est terminée
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
                    sprintf(position,"%d %c%d",morpi->valide[NB_CASES],i,j); //prochaine position à jouer

                    int nbMorpion = atoi(&position[0]) - 1; //Coordonnée de la grille
                    int column = (position[2] - 'a')*3 - 1; //column+line = coordonnée de la case dans la grille
                    int line = atoi(&position[3]);

                    if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion]) //Si la position n'est pas valide on passe à la prochaine
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
                        int nbMorpion = atoi(&position[0]) - 1; //Coordonnée de la grille
                        int column = (position[2] - 'a')*3 - 1; //column+line = coordonnée de la case dans la grille
                        int line = atoi(&position[3]);

                        if (!morpi->grille[nbMorpion].valide[column+line]||!morpi->valide[nbMorpion]) //Si la position n'est pas valide on passe à la prochaine
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

double evalPositionMorpion(T_morpion morpion,int traitOrdi)
{
    //int corres[9] = {6,3,0,7,4,1,8,5,2};
    int corres[] = {2, 5, 8, 1, 4, 7, 0, 3, 6};
    double eval = 0;
    double points[] = {0.2, 0.17, 0.2, 0.17, 0.22, 0.17, 0.2, 0.17, 0.2};

    for(int i=0;i<9;i++)
    {
        eval += convert(morpion.grille[corres[i]],traitOrdi)*3*points[i];
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

double evaluation(T_superMorpion morpi,int traitOrdi) //evalue à quel point une position est avantageuse pour l'ordi
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
            k+=3*evaluatorMul[i];
        }
        else if (morpi.grille[i].state==(traitOrdi+1)%2)
        {
            if (traitOrdi) {smorpion.grille[corres[i]]='O';}
            else {smorpion.grille[corres[i]]='X';}
            k-=3*evaluatorMul[i];
        }
        else {smorpion.grille[corres[i]]='.';}

        smorpion.valide[corres[i]] = morpi.valide[i];
    }
    int i = checkSuperGagnant(&morpi,0);
    if (i==traitOrdi+2) {k+=500000;}
    if (i==3-traitOrdi) {k-=500000;}
    k+=evalPositionMorpion(smorpion,traitOrdi)*150;
    
    return k;
}
