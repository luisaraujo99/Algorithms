#ifndef HEADER_FILE
#define HEADER_FILE

#define NV 6
#define NE 0  // Non existing edge weight
#define NEd 10

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


#endif