
#ifndef _STACK_H
#define _STACK_H

//Max Size Of Stack, Need No Bigger than n*m size matrix



//Colour formatting for visualising clusters (small Matricies only)
#define EMPTY -1
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
typedef int **Matrix; 
// Stack And Opertations


//2n * sizeof(int)*5
typedef struct {
	int clusterID;
	int parentClusID;
  	int parentPieceID;
	int clusHeight;
	int clusWidth;
	int *colsOccupied;
	int *rowsOccupied;
	int clusSize;

} cluster;

typedef struct {
    int *c;
    int top;
    int maxSize;
 } Stack;

//sizeof(cluster-including *cols and *rows) + sizeof(int)*6
typedef struct{
 int largestCluster;
 int largestClusterIdx;
 int percolates;
 int numClusters;
 size_t used;
 size_t size;
 cluster *pieceClusters;
} piece; 


typedef struct{
    int upperBond;
    int lowerBond;
    int rightBond;
    int leftBond;
    int siteBond;
} site;

typedef site **bMatrix;

int SizeOfStack(Stack *s);

void stackDestroy(Stack* s);

void stackInit(Stack* s, int maxSize);
	
void push(Stack* s  , int num);

int pop(Stack* s);

int isEmpty(Stack* s);

int isFull(Stack* s);


//Graph
//A Node Of a List
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} node;
 
// Adjacency  List
typedef struct{
   node *head; 
} AdjList ;
 

//Graph 
typedef struct {
    int V;
    AdjList* array;
} Graph ;
 
// Create A Node
node* newAdjListNode(int dest);
 
// A utility function that creates a graph of V vertices
Graph* createGraph(int V) ;

// Adds an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest);
     
// Prints The Graph
void printGraph(Graph* graph);



#endif  /* not defined _STACK_H */
