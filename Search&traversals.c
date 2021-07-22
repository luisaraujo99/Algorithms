#include "./Headers/Graph.h"
#include "./Headers/GraphSearch.h"
#include "./Headers/GraphExercises.h"
#include "./Headers/Search&traversals.h"
#include <stdio.h>


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
int existPathCyclic(Graph g, int o , int d){
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

// Post order

int traversalDF_PO(Graph g, int o,int p[]){
    int i;
    for(i = 0;i<NV;i++){
        p[i]=-2;
    }
    p[o]=-1;
    return DFRec2(g,o,p);
}

int DFRec_PO(Graph g , int o ,int p[]){
    int count = 1;
    EList it;
    for(it = g[o];it;it=it->next){
        if(p[it->dest]==-2){
            count += DFRec2(g,it->dest,p);
        }
    }
    p[it -> dest] = o;
    return count;
}


//breadth-first

int traversalBF(Graph g,int o){
    int visited[NV];
    int queue[NV];int qinit,qend,i;
    int count = 0;
    EList it;

    for(i=0;i<NV;i++){
        visited[i]=-2;
    }
    qinit=qend=0;
    queue[qend++]=o; //add the origin to the queue
    visited[o]=1;
    while(qinit<qend){
        o = queue[qinit++];
        visited[o]=1;
        count++;
        for(it=g[o];it;it=it->next){
            if(visited[it->dest]==-2){
                queue[qend++]=it->dest;
            }
        }
    }
    return count;
}

int traversalBFTree(Graph g,int o,int ant[]){
    int queue[NV];int qinit,qend,i;
    int count = 0;
    EList it;
    
    for(i=0;i<NV;i++){
        ant[i]=-2;
    }
    qinit=qend=0;
    queue[qend++]=o; //add the origin to the queue
    ant[o]=-1;
    while(qinit<qend){
        o = queue[qinit++];
        count++;
        for(it=g[o];it;it=it->next){
            if(ant[it->dest]==-2){
                ant[it->dest]=o;
                queue[qend++]=it->dest;
            }
        }
    }
    return count;
}

void traversalBFTreeComplete(Graph g,int ant[]){
    int i;
    for(i = 0;i<NV;i++){
        ant[i]=-2;
    };
    for(i = 0;i<NV;i++){
        if(ant[i]==-2){
            traversalBFTree(g,i,ant);
        };
    };
}



int componentes(Graph g, int components[]){
    int ant[NV];
    traversalBFTreeComplete(g,ant);
    int color =  0;
    for(int i = 0;i<NV;i++){
        if(ant[i]==-1){
            components[i] = ++color;
            auxColor(color,i,ant,components);
        }
    }
    return color; 
}

void auxColor(int color,int origin,int ant[],int components[]){
    for(int i = 0;i<NV;i++){
        if(ant[i]==origin){
            components[i]=color;
            auxColor(color,i,ant,components);
        }
    }
}