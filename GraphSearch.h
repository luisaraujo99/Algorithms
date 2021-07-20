#ifndef GRAPH_SEARCH
#define GRAPH_SEARCH
/**
*   WEDGE WEIGHT 
**/

int edgeWMat ( GraphMat , int , int , int *);

int edgeW ( Graph , int , int , int *);


int edgeWVect(GraphVect * ,int ,int ,int*);


/**
 *  IO DEGREES 
**/

//Matrix
int indegreeMat(GraphMat ,int );

int outdegreeMat(GraphMat ,int );

//Adj List

int outdegree(Graph ,int );
// Θ(V + E)
int inDegree(Graph ,int );

//Adj Vector

int outdegreeVect(GraphVect *, int);

int indegreeVect(GraphVect *, int);

#endif