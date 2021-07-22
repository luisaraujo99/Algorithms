#include "./Headers/Buffers.h"
#include <stdlib.h>
#include <stdio.h>

void prettyPrintLList(LInt l){
    while(l){
        printf("%d -> ",l->val);
        l=l->prox;
    }
    printf("NULL\n");
}

LInt cons(int x,LInt l){
    LInt new = malloc(sizeof(struct list));
    if(new !=NULL){
        new->val = x;
        new->prox = l;
    }
    return new;
}

LInt snoc (int x, LInt l){
    LInt new,pt;
    new=malloc(sizeof(struct list));
    new->val=x;
    new->prox=NULL;

    if(l==NULL)l=new;
    else{
        pt = l;
        while(pt->prox!=NULL){
            pt=pt->prox;
        }
        pt->prox =new;
    }
    return l;
}

void append(LInt *l , int x){
    LInt *cp = l;
    while(*cp != NULL){
        cp = &((*cp)->prox);
    }
    *cp = malloc(sizeof(struct list));
    (*cp)->val = x;
    (*cp)->prox = NULL;
}


void push(LInt *l , int x){
    int ant;
    int swap = x;
    LInt *it = l; 
    while(*it != NULL){
        ant = (*it)->val;
        (*it)->val=swap;
        swap = ant;
        it = &((*it)->prox);
    }
    (*it)=malloc(sizeof(struct list));
    (*it)->val=swap;
    (*it)->prox=NULL;
}

void appendL(LInt *a,LInt *b){
    if(*a == NULL){
        *a = *b;
        return;
    }
    LInt *it = a;
    while((*it)->prox != NULL){
        it = &((*it)->prox);
    }
    (*it)->prox = *b;
}

LInt concatL(LInt a,LInt b){
    if(a == NULL){
        a = b;
        return a;
    }
    LInt it = a;
    while(it->prox != NULL){
        it = it->prox;
    }
    it-> prox = b;
    return a;
}

LInt reverseRec(LInt l){
    LInt r,pt;
    if(l==NULL || l->prox == NULL) r = l;
    else{
        r = pt = reverseRec(l->prox);
        while(pt->prox!= NULL) pt = pt->prox;
        pt->prox = l;
        l->prox = NULL;
    }
    return r;
}

LInt reverseL ( LInt l ) {
    LInt r , tmp ;
    r=NULL;
    while ( l !=NULL) {
        tmp=l ; l= l -> prox ;
        tmp->prox=r ; r=tmp ;
    }
    return r ;
}

