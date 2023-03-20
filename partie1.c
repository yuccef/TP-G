#include<stdio.h>
#include<assert.h>
#include"partie1.h"


#define N 8
/**Test*/
int main() {  

    //declaation des variables 
    srand(time(NULL)); // initialise le générateur de nombres aléatoires
    int n = 8; // taille de la matrice carrée
    int M = 10; // borne supérieure des éléments de la matrice
    float p=0.5; // le nombre des arrets
    int s=8 ; // la puissance choisi


    int **matrix1 = generate_matrix(n, M, p);


    printf("\n");
    printf("-------------la matrice aleaoire -------------------\n");
    printmatrix(matrix1,n);
    printf("-----------------------------------------------------\n");
    printf("\n");

   
    int **matrix2= matriceadjacente(n, M,p);

    printf("-----------------la matrice adjacente------------------\n");
    printmatrix(matrix2,n);
    printf("-----------------------------------------------------\n");
    printf("\n");


    int d3 =  DegresGraphes( matrix2,n);
    printf("le degre est %d :\n", d3);
    printf("\n");
    printf("\n");
    printf("-----------------------------------------------------\n");


    int **matrix4=PlusCourtChemin(matrix1,n);
    int **matrix5=PlusCourtChemin(matrix2,n);


    
    printf("----------------le plus court chemin pour la matrice adjacednte ----------------\n");
    printmatrix(matrix5,n);
    printf("\n");


    printf("----------------le chemin le plus leger chemin pour la matrice aleatoire ----------------\n");
    printmatrix(matrix4,n);
    printf("\n");
    printf("-----------------------------------------------------\n");
    

    int **matrix3 = ProduitMatriceConnex(matrix2,matrix2,n);

    printf("---------------le calcul de connexite ------------------\n");
    printmatrix(matrix3,n);
    printf("\n");
    testOne(matrix3);
    printf("-----------------------------------------------------\n");
    printf("\n");
    

    // libération de la mémoire allouée pour la matrice
     freematrix(matrix1,n);
     freematrix(matrix2,n);
     freematrix(matrix3,n);
     freematrix(matrix4,n);


}

