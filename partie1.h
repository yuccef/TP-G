#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<assert.h>
#include<math.h>
#include<limits.h>


#define N 8


//n c'est la taille de la matrice carréé
//M cest le RANDMAX

int  i,j; // les deux indice i et j de la matrice 

/**Geneation d'une matrice à des valeurs aléatoires*/
int** generate_matrix(int n, int M, float p) {     // la fonction qui genere une matrice 
    int** matrix = (int**)malloc(n * sizeof(int*));
  
    for( i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        for( j = 0; j < n; j++) {
            matrix[i][j] = rand() % (M + 1);
        }
    }
    return matrix;
}

int ** diagonale0(int **matrix, int n){
    int **newMatrice = (int**)malloc(n*sizeof(int*));
    for (int i=0; i<n; i++)
        newMatrice[i] = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i=i+1)
    {
        for(int j=0;j<n;j=j+1)
        {
            newMatrice[i][j]=matrix[i][j];
        }
        newMatrice[i][i]=0;
    }
    return newMatrice;
}

int ** diagonale1(int **matrix, int n){
    int **newMatrice = (int**)malloc(n*sizeof(int*));
    for (int i=0; i<n; i++)
        newMatrice[i] = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i=i+1)
    {
        for(int j=0;j<n;j=j+1)
        {
            newMatrice[i][j]=matrix[i][j];
        }
        newMatrice[i][i]=1;
    }
    return newMatrice;
}

/**Une matrice adjacente remplie que avec des 0 et 1*/
int** matriceadjacente(int n, int M , float p){
    int i,j;
    int** matrix= generate_matrix(n,M,p);

     for( i = 0; i < n; i++) {
        for( j = 0; j < n; j++) {
            double v= matrix[i][j];
            double u=(float) v/M ;

            if(u<p){
                 matrix[i][j]=1  ;

            }
            else{
                matrix[i][j]=0;
            }
       }
    }
        return matrix;

}

/**les degres des matrices*/
int DegresGraphes(int **matrice,int taille)
{
    int degres = 0;
    int nb = 0;
    for(int i=0;i<taille;i=i+1)
    {
        for(int j=0;j<taille;j=j+1)
        {
            if(matrice[i][j]==1)
            {
                nb=nb+1;
            }
        }
        
        if(degres<nb)
        {
            degres=nb;
        }
        nb = 0;
    }
    return degres;
}

/**la Mtrice diagonale*/
int **DiagonalMatrice(int **matrice,int taille)
{
    int **newMatrice = (int**)malloc(taille*sizeof(int*));
    for (i=0; i<taille; i++)
        newMatrice[i] = (int*)malloc(taille*sizeof(int));
    for( i=0;i<taille;i=i+1)
    {
        for( j=0;j<taille;j=j+1)
        {
            newMatrice[i][j]=matrice[i][j];
        }
        newMatrice[i][i]=1;
    }
    return newMatrice;
}

/**le produit matricial*/
int **ProduitMatriceConnex(int **matrice1, int **matrice2, int taille)
{    
    int n;
    int **newMatrice = (int**)malloc(taille*sizeof(int*));
    for ( i=0; i<taille; i++)
        newMatrice[i] = (int*)malloc(taille*sizeof(int));
    for( i=0;i<taille;i=i+1)
    {
        for( j=0;j<taille;j=j+1)
        {
            newMatrice[i][j]=0;
            for( n=0;n<taille;n=n+1)
            {
                newMatrice[i][j]= fmax(newMatrice[i][j],matrice1[i][n]*matrice2[n][j]);
            }
        }
    }
    return newMatrice;
}

/**calculer la puissance d'une matrice (connexité)*/
int **PuissanceMatriceConnex(int **matrice, int taille, int puissance)
{    
    matrice=diagonale1(matrice,taille);
    int **newMatrice = (int**)malloc(taille*sizeof(int*));
    for ( i=0; i<taille; i++){
        newMatrice[i] = (int*)malloc(taille*sizeof(int));
        newMatrice=ProduitMatriceConnex(matrice,matrice,taille);
    }
    for( i=2;i<puissance;i=i+1)
    {
        newMatrice=ProduitMatriceConnex(matrice,newMatrice,taille);
    }
     return newMatrice;
}


/**fonction qui fait free à une matrice*/
void freematrix(int **matrix , int n){
     for( i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

/**print matrix*/
void printmatrix(int ** matrix , int n){
    for( i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("  \n");
    }
    printf("\n");
}

/**fonction qui teste la connnexité */
int allOnes(int **m) {
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (m[i][j] != 1) {
                return 0;  // renvoie 0 si un élément n'est pas égal à 1
            }
        }
    }
    return 1;  // renvoie 1 si tous les éléments sont égaux à 1
}

void testOne(int **m) {

    if (allOnes(m)) {
        printf("le graphe  est connex\n");
    } else {
        printf("le graphes n'est pas connex\n");
    }
}


/**fonction qui detemine le plus court chemin  */
int **ProduitMatriceFloyd(int **matrice1, int **matrice2, int taille)
{
    int **newMatrice = (int**)malloc(taille*sizeof(int*));
    for (int i=0; i<taille; i++)
        newMatrice[i] = (int*)malloc(taille*sizeof(int));

    for(int i=0;i<taille;i=i+1)
    {
        for(int j=0;j<taille;j=j+1)
        {
            newMatrice[i][j]=matrice1[i][j];
            for(int n=0;n<taille;n=n+1)
            {
                newMatrice[i][j]=fmin(newMatrice[i][j],matrice1[i][n]+matrice2[n][j]);
            }
        }
    }
    return newMatrice;
}

int** PlusCourtChemin(int **matrice, int taille)
{
    int **newMatrice = (int**)malloc(taille*sizeof(int*));
    for (int i=0; i<taille; i++)
        newMatrice[i] = (int*)malloc(taille*sizeof(int));
    
    int **newMatrice2 = (int**)malloc(taille*sizeof(int*));
    for (int i=0; i<taille; i++)
        newMatrice2[i] = (int*)malloc(taille*sizeof(int));

    for(int i=0;i<taille;i=i+1)
    {
        for(int j=0;j<taille;j=j+1)
        {

            if(matrice[i][j]==0)
            {
                newMatrice[i][j]=50000;
                newMatrice2[i][j]=50000;
            }
            else
            {
                newMatrice[i][j]=matrice[i][j];
                newMatrice2[i][j]=matrice[i][j];
            }
        }
    }
    newMatrice=diagonale0(newMatrice,taille);
    newMatrice2=diagonale0(newMatrice,taille);
    newMatrice=ProduitMatriceFloyd(newMatrice,newMatrice,taille);

    for(int i=2;i<taille;i=i+1)
    {
        newMatrice=ProduitMatriceFloyd(newMatrice2,newMatrice,taille);
    }

    return newMatrice;
}


