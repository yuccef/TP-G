#include<stdio.h>
#include<assert.h>
#include"test.h"
#include"graph.h"


#define N 8

// int Matrix1[8][8] = {
//     {0,0,1,0,0,1,0,0},
//     {0,0,0,0,0,0,1,1},
//     {1,0,0,1,1,1,0,1},
//     {0,0,1,0,0,0,1,0},
//     {0,0,1,0,0,0,0,0},
//     {1,0,1,0,0,0,1,1},
//     {0,1,0,1,0,1,0,0},
//     {0,1,1,0,0,1,0,0}
// };


queue *createQueue() {
    queue *q = malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Checks for empty queue
int isEmpty(queue *q) {
    if (q->rear == -1)
        return 1;
    else
        return 0;
}
// Inserts item at start of queue
void enqueue(queue *q, int value) {
    if (q->rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Returns item at front of queue and removes it from queue
int dequeue(queue *q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Returns element at front of queue
int pollQueue(queue *q) { return q->items[q->front]; }

//Parcours le graphe en utilisant la procédure de la vague
void bfs(Graph *graph, int startVertex) {
    queue *q = createQueue();

    // Add to visited list and put in queue
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);
    printf("Breadth first traversal from vertex %d is:\n", startVertex);

    // Iterate while queue not empty
    while (!isEmpty(q)) {
        printf("%d ", pollQueue(q));
        int currentVertex = dequeue(q);
        

        node *temp = graph->adjLists[currentVertex];
        // Add all unvisited neighbours of current vertex to queue to be printed
        // next
        while (temp) {
            int adjVertex = temp->vertex;
            // Only add if neighbour is unvisited
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

/*min distance*/
int minDistance(int mdist[], int vset[], int V) {
    int minVal = INT_MAX;
    static int minInd = -1; 
    for (int i = 0; i < V; i++)
        if (vset[i] == 0 && mdist[i] < minVal) {
            minVal = mdist[i];
            minInd = i;
        }

    return minInd;
}

/*Djikstra */
void Dijkstra(int **graph, int taille, int src) {
    int mdist[taille];  
    int vset[taille];  
                   

    for (int i = 0; i < taille; i++) mdist[i] = INT_MAX, vset[i] = 0;

    mdist[src] = 0;

    for (int count = 0; count < taille - 1; count++) {
        int u = minDistance(mdist, vset, taille);
        vset[u] = 1;

        for (int v = 0; v < taille; v++) {
            if (!vset[v] && graph[u][v] != INT_MAX &&
                mdist[u] + graph[u][v] < mdist[v])
                mdist[v] = mdist[u] + graph[u][v];
        }
    }

    //printmatrix(mdist, taille);

    return;
}

/**Test*/
int main() {  

    //declaation des variables 
    srand(time(NULL)); // initialise le générateur de nombres aléatoires
    int n = 8; // taille de la matrice carrée
    int M = 10; // borne supérieure des éléments de la matrice
    float p=0.5; // le nombre des arrets
    //int s=8 ; // la puissance choisi


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
    


    int numVertex=4,h=1;
    Graph *graph;
    
    graph=graphAlloc(numVertex);
    graph=graphCreat(matrix2,numVertex);
    bfs(graph,h);
    

    // libération de la mémoire allouée pour la matrice
     freematrix(matrix1,n);
     freematrix(matrix2,n);
     freematrix(matrix3,n);
     freematrix(matrix4,n);

     return 0;


}

