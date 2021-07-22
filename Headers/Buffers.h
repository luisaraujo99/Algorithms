#ifndef BUFFERS
#define BUFFERS

typedef struct list{
    int val;
    struct list *prox;
} *LInt;

void prettyPrintLList(LInt );
LInt cons(int ,LInt );
LInt snoc (int , LInt );
void append(LInt * , int );
void push(LInt * , int );
void appendL(LInt *,LInt *);
LInt concatL(LInt ,LInt );



#endif