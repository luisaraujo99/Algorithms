#ifndef HEADER_FILE
#define HEADER_FILE

#define NV 6
#define NE 0  // Non existing edge weight

typedef int GraphMat [NV][NV];

typedef struct edge {
    int dest ; // node itself (edge destination)
    int cost ; // edge weight
    struct edge * next ; //pointer to the adjacent node
} *EList ;

typedef EList Graph [NV] ;

#endif