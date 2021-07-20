#ifndef GRAPH
#define GRAPH

#define NV 6
#define NE 0  // Non existing edge weight
#define NEd 10

//Data Structures

typedef int GraphMat [NV][NV];

typedef struct edge {
    int dest ; // node itself (edge destination)
    int cost ; // edge weight
    struct edge * next ; //pointer to the adjacent node
} *EList ;

typedef EList Graph [NV] ;


typedef struct edgeV {
    int dest ; // node itself (edge destination)
    int cost ; // edge weight
} Edge ;


typedef struct {
    int vertices [NV + 1];
    Edge edges [NEd] ;
} GraphVect ;



//printers
void llGraphPrettyPrinter(Graph);
void matGraphPrettyPrint(GraphMat);

//edge counters
int countEdgesLL(Graph);
int countEdgesMat(GraphMat);

//converters
void matToList(GraphMat, Graph);
void listToMat(GraphMat , Graph );
void listToVect(Graph , GraphVect *);
void vectToList(GraphVect *, Graph );




#endif