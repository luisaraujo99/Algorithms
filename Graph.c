#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

//Graph examples

GraphMat g1
= { { NE, 2 , 7 , NE, NE, NE} ,
    { NE, NE, NE, 1 , NE, NE} ,
    { NE, NE, NE, NE, NE, 1 } ,
    { 5 , NE, NE, NE, 8 , NE} ,
    { 3 , NE, NE, NE, NE, NE} ,
    { 4 , NE, NE, 3 , 2 , NE} ,
} ;

GraphMat g3
= { { NE, 2 , 7 , 5 , 3  , 4 } ,
    { 2 , NE, NE, 1 , NE , NE} ,
    { 7 , NE, NE, NE, NE , 1 } ,
    { 5 , 1 , NE, NE, 8  , 3 } ,
    { 3 , NE, NE, 8 , NE , 2 } ,
    { 4 , NE, 1 , 3 , 2  , NE} ,
} ;


/**
 * Functions to help in graph visualization
 **/

//Linked list array Graph pretty printer 
void llGraphPrettyPrinter(Graph g){
    for(int i=0; i < NV;i++){
        printf("Node: %d\n",i);
        EList tmp = g[i];
        while (tmp != NULL)
        {
            printf("  --|%d|--> %d\n",tmp->cost,tmp->dest);
            tmp=tmp->next;
        }
        printf("\n");
    }
}
//Matrix Graph pretty printer
void matGraphPrettyPrint(GraphMat g){
    for(int i=0; i<NV ; i++){
        printf("Node: %d\n",i);
        for (int j = 0; j < NV; j++){
            if(g[i][j]!=NE){
                printf("  --|%d|--> %d\n",g[i][j],j);
            }
        }
        printf("\n");
    }
}


// Count the number of edges in a ll graph
// O(V+E)
int countEdgesLL(Graph g){
    int res = 0;
    EList tmp;
    for(int i=0; i < NV;i++){
        tmp=g[i];
        while (tmp) {
            res++;
            tmp=tmp->next;
        }
    }
    return res;
}

// Count the number of edges in a graph
// O(V^2)
int countEdgesMat(GraphMat g){
    int res = 0;
    for(int i=0;i<NV;i++){
        for(int j=0;j<NV;j++){
            if(g[i][j]!=NE)res++;
        }
    }
    return res;
}
   
    
//Convert Matrix Graph to adjency list graph
void matToList(GraphMat go, Graph gd){
    int i,j;
    EList tmp;
    for(i=0;i<NV;i++){
        gd[i]=NULL;
        for (j = NV-1; j>=0; j--)
        {
            if(go[i][j]!= NE){
                tmp = malloc(sizeof(struct edge));
                tmp -> dest = j;
                tmp -> cost = go[i][j];
                tmp -> next = gd[i];
                gd[i]=tmp;
            }
        }                
    }
}
//Convert adjency list graph to Matrix Graph 
void listToMat(GraphMat go, Graph gd){
    for(int i = 0; i < NV; i++){
        for(int j = 0; j < NV; j++){
            go[i][j] = NE;
        }
        EList tmp = gd[i];
        while(tmp){
            go[i][tmp->dest] = tmp->cost;
            tmp=tmp->next;
        }
    }
}
//Convert adjency list graph to adjency vector
void listToVect(Graph go, GraphVect *gd){
    EList tmp;
    int i,j,node;
    for(i = node = 0;i<NV;i++){
        gd->vertices[i]= node;
        EList tmp = go[i];
        for(;tmp;tmp=tmp->next,node++){
            gd->edges[node].dest = tmp->dest;
            gd->edges[node].cost = tmp->cost;
        }
    }
    gd->vertices[i]= node;
}

void vectToList(GraphVect *go, Graph gd){
    int node ,edge_index;
    EList tmp;
    //iterate over nodes
    for(node=0;node<NV;node++){
        gd[node] = NULL;
        //start iterating from the last to the first edge
        for(edge_index=go->vertices[node+1]-1;edge_index>=go->vertices[node];edge_index--){
            EList tmp = malloc(sizeof(struct edge));
            tmp->cost = go->edges[edge_index].cost;
            tmp->dest = go->edges[edge_index].dest;
            tmp->next=gd[node];
            gd[node]= tmp;
        }
    }
}


int main(int argc, char const *argv[])
{
    Graph llGraph;
    matToList(g1,llGraph);
    listToMat(g1,llGraph);
    matGraphPrettyPrint(g1);
    return 0;
}
