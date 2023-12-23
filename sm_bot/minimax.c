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
        resultat.poids = eval(*morpi,traitOrdi);
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
        resultat.poids = 100;
        return resultat;
    }

    if (depth==0)
    {
        resultat.poids = eval(*morpi,traitOrdi);
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
                    int k = alphabeta(&next,depth-1,traitOrdi,alpha,beta,visible).poids;
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
                        int k = alphabeta(&next,depth-1,traitOrdi,alpha,beta,visible).poids;
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
                        int k = alphabeta(&next,depth-1,traitOrdi,alpha,beta,visible).poids;
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
        resultat.poids = eval(*morpi,morpi->trait);
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
        resultat.poids = eval(*morpi,morpi->trait);
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

int evalPositionMorpion(T_superMorpion morpi,int trait,int stop)
{
    if (stop==0)
    {
        return 0;
    }
    int nbMorpionGagnes = 0; //Nombre de grilles de morpions gagnées au total par les deux joeurs confondus
    int * tabState[NB_CASES]; //tableau qui va stocker le numéro des grilles qui sont gagnées et le joueur qui les a gagnées
    int j = 0;
    for (int i=0;i<NB_CASES;i++) //On stock les bonnes valeurs dans tabState
    {
        if (morpi.grille->state==trait)
        {
            int t[2] = {i+1,trait};
            tabState[j++] = t;
            nbMorpionGagnes++;
        }
        else if (morpi.grille->state==((trait+1)%2))
        {
            int t[2] = {i+1,morpi.grille->state};
            tabState[j++] = t;
            nbMorpionGagnes++;
        }
    }

    switch (nbMorpionGagnes) //On résonne selon le nombre de grilles gagnées par tout le monde
    {
    case 0: //S'il n'y en a aucune on ne fait rien
        break;
    case 1: //S'il y en a une on regarde s'il s'agit du joueur au trait ou pas
        if (tabState[0][1]==trait)
        {
            if (tabState[0][0]==5){return 10*(stop-1);}
            else {return 20*(stop-1);}; //Commencer sur les côtés est généralement plus avantageux
        }
        break;
    case 2: //S'il y en a 2 il faut commencer à distinguer les cas
        if (tabState[0][1]==tabState[1][1]==trait) //Si les deux ont été gagnées par le joueur au trait
        {
            if (tabState[0][0]==5||tabState[1][0]) //Dans ce cas prendre le milieu est plus favorable
            {
                return 30*(stop-1);
            }
            else
            {
                return 15*(stop-1);
            }
        }
        else if (tabState[0][1]!=tabState[1][1]) //Si les deux ont été gagnées par chacun des deux joueurs
        {
            if (tabState[0][0]==5) //Si le joueur au trait a pris le milieu on favorise, sinon on ne fait rien
            {
                if (tabState[0][1]==trait){return 10*(stop-1);}
            }
            else if (tabState[1][0]==5)
            {
                if (tabState[1][1]==trait){return 10*(stop-1);}   
            }
            else //Laisser l'autre joueur prendre le milieu est dangereux, on favorise donc les autres situations
            {
                return 5*(stop-1);
            }
        }
        break;
    case 3 : //Ici on peut avoir un gagnant, mais ces cas sont déjà gérés par la fonction qui détermine les gagnants à chaque tour. On s'intéresse donc aux autres cas
        if(tabState[0][1]==tabState[1][1]==tabState[2][1])
        {
            if(tabState[0][1]==trait)
            {
                return 30*(stop-1);
            }
        }
        else if (tabState[0][1]==tabState[2][1])
        {
            if (tabState[0][0]==1&&tabState[2][0]==3)
            {
                if(tabState[0][1]==trait)
                {
                    return 20*(stop-1);
                }
            }
            else if (tabState[0][0]==1&&tabState[2][0]==9)
            {
                if(tabState[0][1]==trait)
                {
                    return 10*stop; //Rappel : Il faut initialiser stop à 2
                }
                else if (tabState[1][0]==5)
                {
                    return 5*stop;
                }
            }
            
        }
        else
        {
            T_superMorpion temp = morpi;
            int k = 0;
            for(int i=0;i<4;i++)
            {
                temp = rotation(temp,2);
                k+=evalPositionMorpion(temp,trait,--stop);
            }
            return k;
        }
        break;
    case 4:
        if (tabState[0][1]==tabState[1][1]==tabState[2][1]==tabState[3][1])
        {
            if(tabState[0][1]==trait)
            {
                return 30;
            }
        }
        int k = 0;
        for (int i=0;i<4;i++)
        {
            T_superMorpion temp = morpi;
            temp.grille[tabState[i][0]].state = -1;
            k += evalPositionMorpion(temp,trait,2);
        }
        return k/4;
        break;
    case 5:
        if (tabState[0][1]==tabState[1][1]==tabState[2][1]==tabState[3][1]==tabState[4][1])
        {
            if(tabState[0][1]==trait)
            {
                return 40;
            }
        }
        int asd = 0;
        for (int i=0;i<5;i++)
        {
            T_superMorpion temp = morpi;
            temp.grille[tabState[i][0]].state = -1;
            asd += (asd,evalPositionMorpion(temp,trait,2));
        }
        return asd/5;
        break;
    case 6:
        int qwe = 0;
        for (int i=0;i<6;i++)
        {
            T_superMorpion temp = morpi;
            temp.grille[tabState[i][0]].state = -1;
            qwe += (qwe,evalPositionMorpion(temp,trait,2));
        }
        return qwe/6;
        break;
    case 7:
        int zxc = 0;
        for (int i=0;i<7;i++)
        {
            T_superMorpion temp = morpi;
            temp.grille[tabState[i][0]].state = -1;
            zxc += (zxc,evalPositionMorpion(temp,trait,2));
        }
        return zxc/7;
        break;
    case 8:
        int xcv = 0;
        for (int i=0;i<8;i++)
        {
            T_superMorpion temp = morpi;
            temp.grille[tabState[i][0]].state = -1;
            xcv += (xcv,evalPositionMorpion(temp,trait,2));
        }
        return xcv/8;
        break;
    default:
        break;
    }

    return 0;
}

int eval(T_superMorpion morpi,int trait) //evalue à quel point une position est avantageuse
{
    int k = grilleGagnee(morpi,trait);
    k+=evalPositionMorpion(morpi,trait,2);
    return k;
}