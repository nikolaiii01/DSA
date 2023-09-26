#include <stdio.h>

#define MAX 10

typedef struct {
    char Elem[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *Q);
void enQueue(Queue *Q, char elem);
void deQueue(Queue *Q);
void insertSorted(Queue *Q, char elem);
void display(Queue *Q);

int main(){
    Queue Q;

    initQueue(&Q);
    enQueue(&Q, 'A');
    enQueue(&Q, 'B');
    enQueue(&Q, 'C');
    deQueue(&Q);
    display(&Q);

    return 0;
}

void initQueue(Queue *Q){
    //Clockwise
    Q->front = 1;
    Q->rear = 0;
}

void enQueue(Queue *Q, char elem){
    if((Q->rear + 2) % MAX != Q->front){
        Q->rear = (Q->rear + 1) % MAX;
        Q->Elem[Q->rear] = elem;
    } 
}

void deQueue(Queue *Q){
    if((Q->rear + 1) % MAX != Q->front){
        Q->front = (Q->front + 1) % MAX;
    }
}

void insertSorted(Queue *Q, char elem){
    int newFront;
    if((Q->rear + 2) % MAX != Q->front){
        newFront = (Q->rear + 1) % MAX;
        while(Q->front != newFront && elem > Q->Elem[Q->front]){
            Q->rear = (Q->rear + 1) % MAX;
            Q->Elem[Q->rear] = Q->Elem[Q->front];
            Q->front = (Q->front + 1) % MAX;
        }
        Q->rear = (Q->rear + 1) % MAX;
        Q->Elem[Q->rear] = elem;
        while(Q->front != newFront){
            Q->rear = (Q->rear + 1) % MAX;
            Q->Elem[Q->rear] = Q->Elem[Q->front];
            Q->front = (Q->front + 1) % MAX;
        }
    }
}

void display(Queue *Q){ 
    if((Q->rear + 1) % MAX != Q->front){
        Queue tempQ;
        initQueue(&tempQ);
        while((Q->rear + 1) % MAX != Q->front){
            printf("%c ", Q->Elem[Q->front]);
            enQueue(&tempQ, Q->Elem[Q->front]);
            deQueue(Q);
        }
        while((tempQ.rear + 1) % MAX != tempQ.front){
            enQueue(Q, tempQ.Elem[tempQ.front]);
            deQueue(&tempQ);
        } 
    }
}
