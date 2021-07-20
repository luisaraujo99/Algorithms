#include "Graph.h"
#include "GraphSearch.h"
#include <stdio.h>
#include <stdlib.h>


//Weight Check

int edgeWMat ( GraphMat g , int o , int d , int *w) {
    *w = g [ o ] [ d ] ;
    return ( *w != NE ) ;
}

int edgeW ( Graph g , int o , int d , int *w) {
    EList it ;
    int found =0;
    for ( it=g [o] ; ( it != NULL) && ! found ; it =it->next){
        found = ( it ->dest == d ) ;
    }
    if ( found ) *w = it ->cost;
    return found ;
}

int edgeWVect(GraphVect * g,int o,int d,int*w){
    int k;
    int found = 0;
    for(k=g->vertices[o+1]-1;k>=g->vertices[o] && !found;k--){
        found = g->edges[k].dest == d;
    }
    if ( found ) *w = g->edges[k].cost;
    return found ;
}

// IO Degree

//Matrix
int indegreeMat(GraphMat g,int v){
    int i,res;
    for(i=res=0;i<NV;i++){
        if(g[i][v]!=NE) res ++;
    }
    return res;
}

int outdegreeMat(GraphMat g,int v){
    int i,res;
    for(i=res=0;i<NV;i++){
        if(g[v][i]!=NE) res ++;
    }
    return res;
}

//Adj List

int outdegree(Graph g,int v){
    int res = 0;
    EList tmp = g[v];
    while(tmp){
        res++;
        tmp=tmp->next;
    }
    return res;
}
// Θ(V + E)
int inDegree(Graph g,int v){
    int res=0;
    EList tmp;
    for(int i = 0;i<NV;i++){
        tmp=g[i];
        while(tmp){
            if(tmp->dest == v)res++;
            tmp=tmp->next;
        }
    }
    return res;
}

//Adj Vector

int outdegreeVect(GraphVect *g, int v){
    return g->vertices[v+1] - g->vertices[v];
}

int indegreeVect(GraphVect *g, int v){
    int res = 0;
    for(int i=0;i<g->vertices[NV];i++){
        if(g->edges[i].dest==v) res++;
    }
    return res;
}
