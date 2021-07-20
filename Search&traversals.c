#include "./Headers/Graph.h"
#include "./Headers/GraphSearch.h"
#include "./Headers/GraphExercises.h"

// find if exists a path between two nodes in a graph

//Acyclic graph
int existPathAcyclic(Graph g, int o , int d){
    int found = 0;
    EList it;
    if(o==d) found = 1;
    else{
        for(it = g[o];it;it=it->next){
            found = existPathAcyclic(g,it->dest,d);
        }
    }
    return found;
}

//Works with cyclic graphs
int existPathAcyclic(Graph g, int o , int d){
    int visited[NV];
    for(int i = 0;i<NV;i++){
        visited[i]=0;
    }
    return recSearchCyclic(g,o,d,visited);
};

int recSearchCyclic(Graph g, int o, int d,int vis[]){
    int found = 0;
    EList it;
    vis[o]=1;
    if(o==d) found = 1;
    else{
        for(it=g[o]; it ;it=it->next){
            if(!vis[it->dest]){
                found=recSearchCyclic(g,it->dest,d,vis);
            }
        }
    }
    return found;
}

//Depth-first traversal
int traversalDF(Graph g, int o){
    int visited[NV];
    for(int i = 0;i<NV;i++){
        visited[i]=0;
    }
    return DFRec(g,o,visited);
}
int DFRec(Graph g,int o,int vis[]){
    int count = 1;
    EList it;
    vis[o]=1;
    for(it=g[o]; it ; it = it->next){
        if(!vis[it->dest]){
            count+= DFRec(g,it->dest,vis);
        }
    }
    return count;
}

// Given an undirected graph, it is connected iff there is at least
// one path between each pair of nodes

// Returns the number of nodes of the biggest connected component
int biggestConComp(Graph g){
    int visited[NV];
    int max = 0,c,i;
    for(int i=0;i<NV;i++){
        visited[i]=0;
    }
    for(i = 0;i<NV;i++){
        if(!visited[i]){
            c=DFRec(g,i,visited);
            if(c>max) max = c;
        }
    }
    return max;
}


// DF traversal that saves the path in array p
int traversalDF2(Graph g, int o,int p[]){
    int i;
    for(i = 0;i<NV;i++){
        p[i]=-2;
    }
    p[o]=-1;
    return DFRec2(g,o,p);
}
int DFRec2(Graph g , int o ,int p[]){
    int count = 1;
    EList it;
    for(it = g[o];it;it=it->next){
        if(p[it->dest]==-2){
            p[it -> dest] = o;
            count += DFRec2(g,it->dest,p);
        }
    }
    return count;
}

