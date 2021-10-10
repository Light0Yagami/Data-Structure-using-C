#include <stdio.h>
#include <stdlib.h>
#define max 10

void insert(char queue[],int *rear,int *front, char ch)
{
    if(*front >= max){
        printf("Queue overflow");
    }
    if(*front == -1 ){
        *front = 0;
    }
    *rear = *rear + 1;
    queue[*rear] = ch;
}

void pop(char queue[],int *rear, int *front)
{
    if(*front == -1){
        printf("Queue underflow");
    }
    else{
    *front = *front + 1;
    }
}

void display(char queue[],int *rear,int *front)
{
    for(int i = *front; i <= *rear; i++){
        printf("%c",queue[i]);
    }
}


int main()
{
    char queue[max];
    int rear = -1;
    int front = -1;

    insert(queue,&rear,&front,'a');
    insert(queue,&rear,&front,'b');
    insert(queue,&rear,&front,'c');
    insert(queue,&rear,&front,'d');

    display(queue,&rear,&front);
    printf("\n");

    pop(queue,&rear,&front);

    display(queue,&rear,&front);

    return 0;
}
