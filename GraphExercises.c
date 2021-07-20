#include "./Headers/Graph.h"
#include "./Headers/GraphSearch.h"
#include "./Headers/GraphExercises.h"
#include <stdio.h>
#include <stdlib.h>

// Define a capacity function that calculates the capacity of a given node
// Given an weighted digraph, the capacity of a node is the difference between
// the sum of input edge weights and the sum of output edge weights. 

int capacity(Graph g,int v){
    int in_sum=0;
    int out_sum=0;
    EList it;
    //input edges costs
    for(int i=0;i<NV;i++){
        it = g[i];
        while(it){
            if(it->dest==v){
                in_sum+=it->cost;
            }
            if(i==v)out_sum+=it->cost;
            it=it->next;
        }
    }

    return in_sum - out_sum;
}

// Define the function maxCap, that given a weighted digraph, calculates the node with
// maximum capacity. Ensure it executes in linear time (regarding to the graph size).

// TC: O(2*V + E)
int maxCap(Graph g){
    int input_output_difs[NV]={0};
    EList it;
    //input edges' costs
    for(int i=0;i<NV;i++){
        it = g[i];
        while(it){
            input_output_difs[i]-=it->cost;
            input_output_difs[it->dest]+=it->cost;
            it=it->next;
        }
    };
    int max=0;
    for(int j=1;j<NV;j++){
        if(input_output_difs[j]> input_output_difs[max]){
            max = j;
        }
    }
    return max;
}

// Define a function that tests if a subset C from the set of nodes in a graph is a 
// coverage.(i.e. iff for every (o,d) in E (edges set), either 'o' or 'd' belongs to C)

int vCoverage(Graph g, int c[]){
    EList it;
    int cover[NV]={0};
    for(int i=0;i<NV;i++){
        it = g[i];
        //check if node i is in C and has adjecents
        if(c[i] && it!=NULL) cover[i]=c[i];
        //iterate over the adjacents and
        while(it){
            if(c[it->dest] && !cover[it->dest]){
                cover[it->dest]=c[it->dest];
            }
            it=it->next;
        }
    };
    //Check if the arrays are equal
    for(int j=0;j<NV;j++){
        if(cover[j]!=c[j]) return -1;
    }
    return 1;
}

// check if a given graph is well colored by a set "color[]"

int colorOK(Graph g, int color[NV]){
    EList it;
    for(int i = 0;i<NV;i++){
        it = g[i];
        while(it){
            if(color[i]==color[it->dest]) return -1;
            it=it->next;
        }
    }
    return 1;
}

// Given a digraph define a function that checks if a sequence <v1,v2,...vn>
// of nodes, is a topological sorting (i.e. iff for every edge (o,d) 'o' appears
// always before 'd' in the sequence)
// Assume that the given sequece contains every node in the graph, with no repetitions
// The solution must execute in linear time in the graph size

int testTop(Graph g, int v[]){
    EList it;
    int cannot_appear[NV]={0};
    //iterate the sequence from the end
    for(int i = NV-1;i>=0;i--){
        if(cannot_appear[v[i]]) return -1;
        //Mark the adjecents of the visited nodes in the sequence
        //As nodes that cannot appear anymore in the sequence
        for(it = g[v[i]];it;it=it->next) cannot_appear[it->dest]=1;
    }
    return 1;
}

