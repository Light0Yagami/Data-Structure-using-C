#include <stdio.h>
#include<stdlib.h>

struct Edge;

typedef struct Vertex{
    int info;
    struct Vertex *nextVertex;
    struct Edge *firstEdge;
}Vertex;

Vertex *start = NULL;

typedef struct Edge{
    Vertex *destVertex;
    struct Edge *nextEdge;
}Edge;

void insertVertex(int u){
    Vertex *tmp, *ptr;
    tmp = (Vertex*)malloc(sizeof(Vertex));
    tmp->info = u;
    tmp->nextVertex = NULL;
    tmp->firstEdge = NULL;
    if(start == NULL){
        start = tmp;
        return;
    }
    ptr = start;
    while(ptr->nextVertex != NULL){
        ptr = ptr->nextVertex;
    }
    ptr->nextVertex = tmp;
}


Vertex *findVertex(int u){
    Vertex *loc,*ptr = start;
    while(ptr!=NULL){
        if(ptr->info == u){
            loc = ptr;
            return loc;
        }
        else{
            ptr = ptr->nextVertex;
        }
    }
    loc = NULL;
    return loc;
}

void insertEdge(int origin, int destination){
    Vertex *locOrigin, *locDest;
    Edge *tmp, *ptr;
    locOrigin = findVertex(origin);
    locDest = findVertex(destination);
    if(locOrigin  == NULL){
        printf("\nStart vertex not present\n");
        return;
    }if(locDest  == NULL){
        printf("\nDestination vertex not present\n");
        return;
    }
    tmp = (Edge*)malloc(sizeof(Edge));
    tmp->destVertex = locDest;
    tmp->nextEdge = locOrigin->firstEdge;
    locOrigin->firstEdge = tmp;
}

void display(){
    Vertex *ptr;
    Edge *q;
    ptr = start;
    while(ptr != NULL){
        printf("%d->",ptr->info);
        q = ptr->firstEdge;
        while(q!= NULL){
            printf(" %d",q->destVertex->info);
            q = q->nextEdge;
        }
        printf("\n");
        ptr = ptr->nextVertex;
    }
}

int main()
{
    insertVertex(0);
    insertVertex(1);
    insertVertex(2);
    insertVertex(3);
    
    insertEdge(0,1);
    insertEdge(1,0);
    insertEdge(1,2);
    insertEdge(1,3);
    insertEdge(2,3);
    insertEdge(2,0);
    insertEdge(3,0);
    insertEdge(3,2);
    
    display();
    
    return 0;
    
    
}
