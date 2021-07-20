#include "./Headers/Graph.h"
#include "./Headers/GraphSearch.h"
#include "./Headers/GraphExercises.h"
#include <stdio.h>

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

GraphMat g4
= { { NE, 1 , NE, NE, NE, NE } ,
    { NE, NE, 1 , NE, NE, NE } ,
    { NE, NE, NE, 1 , NE, NE } ,
    { NE, NE, NE, NE, 1 , NE } ,
    { 1 , NE, NE, NE, NE, 1  } ,
    { 1 , NE, NE, NE, NE, NE } ,
} ;

//valid topological sorting to Graph g4
int sequece1[6] = {0,1,2,3,4,5};

//invalid topological sorting to Graph g4
int sequece2[6] = {5,1,2,3,4,0};

int main(int argc, char const *argv[])
{   
    Graph llGraph;
    matToList(g4,llGraph);
    //listToMat(g1,llGraph);
    // matGraphPrettyPrint(g1);
    printf("%d\n",biPartite(llGraph));
    return 0;
}