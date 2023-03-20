#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#include<limits.h>


#define N 4


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

/**retourne la valeur de degré entrante*/
int degreentrant(int n , int M , float p){
    int max1=0;
    int res1=0;
    int ** matrix = matriceadjacente(n, M , p);
    for( i = 0; i < n; i++) {
        for( j = 0; j < n; j++) {
           if(matrix[i][j]==1){
              res1++;
           }      
    }
    if(res1>max1){
            max1=res1;
           }
    res1=0;
    }
return max1;
}

/**retourne la valeur de degré Sortante*/
int degresortant(int n , int M , float p){
 int max2=0;
 int res2=0;
    int ** matrix = matriceadjacente(n, M , p);
for( j = 0; j < n; j++) {
        for( i = 0; i < n; i++) {
           if(matrix[i][j]==1){
              res2++;
           }
    }   
    if(res2>max2){
            max2=res2;
           }    
    res2=0;
}
return max2;
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
void testconnexe(int ** matrix , int n , int s){
    int **newMatrice = (int**)malloc(n*sizeof(int*));
    for ( i=0; i<n; i++){
        newMatrice[i] = (int*)malloc(n*sizeof(int));
    }
    newMatrice = PuissanceMatriceConnex(matrix,n,s);
    for(i=0 ; i<n ; i++){
        for(j=0 ; j<n ; j++){
              if(newMatrice[i][j]==0){
                   printf("cette matrice n'est pas connex\n");
                   break;
              }
        }
    }
    printf("cette matrice est connexe \n");
}


void floydWarshall(int graph[N][N]) {
    int dist[N][N], i, j, k;
    
    // Initialiser la matrice des distances
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    
    // Calculer les distances minimales
    for(k = 0; k < N; k++) {
        for(i = 0; i < N; i++) {
            for(j = 0; j < N; j++) {
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX
                   && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    // Afficher les distances minimales
    printf("Matrice des distances minimales :\n");
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            if(dist[i][j] == INT_MAX) {
                printf("INF ");
            }
            else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");

    }
}

int **ProduitMatricePlusCousChemin(int **matrice1, int **matrice2, int taille)
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
                newMatrice[i][j]= fmin(newMatrice[i][j],matrice1[i][n]+matrice2[n][j]);
            }
        }
    }
    return newMatrice;
}


int **PuissanceMatricepluscourtschemin(int **matrice, int taille, int puissance)
{    

    matrice = diagonale0(matrice,taille);
    int **newMatrice = (int**)malloc(taille*sizeof(int*));
    for ( i=0; i<taille; i++){
        newMatrice[i] = (int*)malloc(taille*sizeof(int));
        newMatrice=ProduitMatricePlusCousChemin(matrice,matrice,taille);
    }
    for( i=2;i<puissance;i=i+1)
    {
        newMatrice=ProduitMatricePlusCousChemin(matrice,newMatrice,taille);
    }
     return newMatrice;
}





