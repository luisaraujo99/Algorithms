#ifndef GRAPH_TRAVERSALS
#define GRAPH_TRAVERSALS

//Exercises

int existPathAcyclic(Graph , int  , int );

//Works with cyclic graphs
int existPathCyclic(Graph , int  , int );

int recSearchCyclic(Graph , int , int ,int []);

//Depth-first traversal
int traversalDF(Graph , int );
int DFRec(Graph ,int ,int []);

// Given an undirected graph, it is connected iff there is at least
// one path between each pair of nodes

// Returns the number of nodes of the biggest connected component
int biggestConComp(Graph );


// DF traversal that saves the path in array p
int traversalDF2(Graph , int ,int []);

int DFRec2(Graph , int ,int []);

//breadth-first

int traversalBF(Graph ,int );

int traversalBFTree(Graph ,int ,int []);

void traversalBFTreeComplete(Graph ,int []);



int componentes(Graph , int []);

void auxColor(int ,int ,int [],int []);


#endif