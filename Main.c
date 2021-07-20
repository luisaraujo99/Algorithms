#include "Graph.h"

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

int main(int argc, char const *argv[])
{
    Graph llGraph;
    matToList(g1,llGraph);
    listToMat(g1,llGraph);
    matGraphPrettyPrint(g1);
    return 0;
}