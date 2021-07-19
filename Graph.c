#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>



GraphMat g1
= { { NE, 2 , 7 , NE, NE, NE} ,
    { NE, NE, NE, 1 , NE, NE} ,
    { NE, NE, NE, NE, NE, 1 } ,
    { 5 , NE, NE, NE, 8 , NE} ,
    { 3 , NE, NE, NE, NE, NE} ,
    { 4 , NE, NE, 3 , 2 , NE} ,
} ;


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

// Count the number of edges in a ll graph
// O(V+E)
int countEdgesLL(Graph g){
    int res = 0;
    EList tmp;
    for(int i=0,tmp=g[i]; i < NV;i++){
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


int main(int argc, char const *argv[])
{
    Graph llGraph;
    matToList(g1,llGraph);
    listToMat(g1,llGraph);
    matGraphPrettyPrint(g1);
    return 0;
}
