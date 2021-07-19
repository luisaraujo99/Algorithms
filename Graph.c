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

int main(int argc, char const *argv[])
{
    Graph llGraph;
    matToList(g1,llGraph);
    llGraphPrettyPrinter(llGraph);
    return 0;
}
