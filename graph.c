// A C Program to demonstrate adjacency list representation of graphs
 
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
 
// Create A Node
node* newAdjListNode(int dest) {
    node* newNode = (node*) malloc(
            sizeof(node));
    if(newNode==NULL){
	printf("Malloc Error");
	exit(EXIT_FAILURE);
    }
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
// Creates A Graph With V nodes/verticies each node only needs 4  
Graph* createGraph(int V) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  
    graph->array = (AdjList*) malloc(V * sizeof(AdjList));
 
    // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
  
    return graph;
}
 
// Adds an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    
    node* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
 
// Prints The Graph
void printGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->V; ++v) {
        node* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
 
