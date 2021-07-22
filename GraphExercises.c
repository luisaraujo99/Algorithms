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

/**
 *  ----- SEARCH  AND TRANVERSALS 
**/

// An undirected graph is bipartite iff it is possible to
// break the Nodes' set into two disjunt subsets such as every edge in the
//graph has one extremity in each subset

int biPartite(Graph g){
    // bipartite[i] = 1 (resp. -1) if is in Subset 1 (resp. -1) 
    int bip[NV];
    for(int i=0;i<NV;i++){
        bip[i]=0;
    }
    for(int i = 0;i<NV;i++){
        EList it=g[i];
        if(bip[i]==0 && it) bip[i] = 1;
        for(; it ; it = it->next){
            //the adjacents must be in the opposite set of 'o'
            if(bip[it->dest]==bip[i]) return -1;
            //add adjacents to the opposite set of 'o' if they are not in any
            else if(bip[it->dest]==0) bip[it->dest] = -(bip[i]);
        }
    }
    return 1;
}


//This version only works if the numbers of layers is smaller or equal to 'k'
int adist(Graph g,int o, int k){
    int visited[NV];
    int queue[NV];int qinit,qend,i;
    int count = 0;
    int layer = 0;
    int layerbound = o; //last elem in a layer
    EList it;

    for(i=0;i<NV;i++){
        visited[i]=-2;
    }
    qinit=qend=0;
    queue[qend++]=o; //add the origin to the queue
    visited[o]=1;
    int npaths = 0;
    while(qinit<qend && layer<k){
        o = queue[qinit++];
        count++;
        for(it=g[o];it;it=it->next){
            if(visited[it->dest]==-2){
                queue[qend++]=it->dest;
                visited[it->dest]=1;                
                if(layer == k-1){
                    npaths++;
                }
            }
        }
        if(layerbound==o){
            layer++;
            layerbound=queue[qend-1];   
        }
        
    }
    return npaths;
}




// exists connection

int existsConnection(Graph g, int o,int d,int sec){
    int visited[NV];
    for(int i = 0;i<NV;i++){
        visited[i]=0;
    }
    return DFRecSec(g,o,d,sec,visited);
}

int DFRecSec(Graph g, int o, int d, int sec, int vis[]){
    int found = 0;
    EList it;
    vis[o]=1;
    for(it =g[o];it && !found; it=it->next){
        if(it->dest == d && it->cost >sec){
            found= 1;
        }
        else if(!vis[it->dest] && it->cost > sec){
            found = DFRecSec(g,it->dest,d,sec,vis);
        }     
    }
    return found;
}


// and edge (v,c) exists iff 'c' is a multiple of 'v'
void multipleGraph(Graph g){
    int i;
    for(i = 0;i<NV;i++){
        g[i] = NULL;
    };
    EList it;
    for(i=0;i<NV;i++){
        for(int j = 0;j<NV;j++){
            if(i==0 || (j % i) == 0){
                it = malloc(sizeof(struct edge));
                it->dest = j;
                it->cost = 1;
                it->next = g[i];
                g[i] = it;
            }
        }
    }
}

