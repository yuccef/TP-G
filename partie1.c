#include<stdio.h>
#include"partie1.h"

/**Test*/
int main() {  

    //declaation des variables 


    srand(time(NULL)); // initialise le générateur de nombres aléatoires
    int n = 8; // taille de la matrice carrée
    int M = 10; // borne supérieure des éléments de la matrice
    float p=0.5; // le nombre des arrets
    int s=8 ; // la puissance choisi


    int **matrix1 = generate_matrix(n, M, p);
    int **matrix11= diagonale0(matrix1,n);
    int **matrix12= diagonale1(matrix1,n);

    printf("la matrice aleaoire :\n");
    printmatrix(matrix1,n);
    printmatrix(matrix11,n);
    printmatrix(matrix12,n);
printf("-----------------------------------------------------\n");
   
    int **matrix2= matriceadjacente(n, M,p);
    int **matrix21= diagonale0(matrix2,n);
    int **matrix22= diagonale1(matrix2,n);

    printf("la matrice adjacente :\n");
    printmatrix(matrix2,n);
    printmatrix(matrix21,n);
    printmatrix(matrix22,n);
printf("-----------------------------------------------------\n");



    int d1 = degreentrant(n,M,p);
    int d2 =  degresortant(n,M,p);
    int d3 =  DegresGraphes( matrix2,n);
    
    printf("le degre est %d :\n", d3);
    printf("\n");
    printf("le degre entrant est %d \n", d1);
    printf("le degre sortant est %d \n", d2);
    printf("\n");
    printf("-----------------------------------------------------\n");


    int **matrix3 = ProduitMatriceConnex(matrix2,matrix2,n);
    int **matrix31=PuissanceMatriceConnex(matrix3,n,s);

    printf("le calcul de connexité :\n");
    printmatrix(matrix3,n);
    printmatrix(matrix31,n);
    testconnexe(matrix3,n,s);
    printf("-----------------------------------------------------\n");
   

    int **matrix4 = ProduitMatricePlusCousChemin(matrix2,matrix2,n);
    int **matrix41=PuissanceMatricepluscourtschemin(matrix4,n,s);

    printf("le calcul de plus cours chemin :\n");
    printmatrix(matrix4,n);
    printmatrix(matrix41,n);
    printf("-----------------------------------------------------\n");


    
   

 


   
//    printf("la matrice de plus cours chemin \n");
//    int ** matrix4=PuissanceMatricepluscourtschemin(matrix1,n,s );   
//    printmatrix(matrix4,n);


      

    // int graph[N][N] = { {0, 5, INT_MAX, 10},
    //                     {INT_MAX, 0, 3, INT_MAX},
    //                     {INT_MAX, INT_MAX, 0, 1},
    //                     {INT_MAX, INT_MAX, INT_MAX, 0} };

    
    // printf("Matrice d'adjacence :\n");
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
    //         if(graph[i][j] == INT_MAX) {
    //             printf("INF ");j
    //         }
    //         else {
    //             printf("%d ", graph[i][j]);
    //         }
    //     }
    //     printf("\n");

    // }
    
    // floydWarshall(graph);
    
    // return 0;
     

    // libération de la mémoire allouée pour la matrice
     freematrix(matrix1,n);
     freematrix(matrix2,n);
     freematrix(matrix3,n);


}
