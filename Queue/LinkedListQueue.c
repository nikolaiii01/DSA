#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char LName[16], FName[24], MI;
}nametype;

typedef struct{
    nametype name;
    int ID;
    char course[8];
    int yrLevel;
}Studtype;

typedef struct node{
    Studtype stud;
    struct node* next;
}*LinkQueue;

typedef struct{
    struct node* front;
    struct node* rear;
}QHead;

typedef enum {TRUE, FALSE} Boolean;

void initQueue(QHead *Q);
void enQueue(QHead *Q, Studtype stud);
void deQueue(QHead *Q);
void displayQueue(QHead *Q);
Boolean isEmpty(QHead Q);
void makeNull(QHead *Q);
void insertSorted(QHead *Q, Studtype stud);

int main(){
    QHead StudQueue;
    initQueue(&StudQueue);  

    Studtype stud1;
    strcpy(stud1.name.FName, "Inie");
    stud1.name.MI = 'A';
    strcpy(stud1.name.LName, "Sabado");
    strcpy(stud1.course, "BSIT");
    stud1.ID = 17104226;
    stud1.yrLevel = 2;

    Studtype stud2;
    strcpy(stud2.name.FName, "Nikolai");
    stud2.name.MI = 'R';
    strcpy(stud2.name.LName, "Tumapon");
    strcpy(stud2.course, "BSIT");
    stud2.ID = 18104226;
    stud2.yrLevel = 3;

    Studtype stud3;
    strcpy(stud3.name.FName, "Horeb");
    stud3.name.MI = 'M';
    strcpy(stud3.name.LName, "Barriga");
    strcpy(stud3.course, "BSCS");
    stud3.ID = 20102002;
    stud3.yrLevel = 4;

    enQueue(&StudQueue, stud3);
    enQueue(&StudQueue, stud2);
    enQueue(&StudQueue, stud1);
    displayQueue(&StudQueue);
    
    return 0;
}

void initQueue(QHead *Q){
    Q->front = NULL;
    Q->rear = NULL;
}

void displayQueue(QHead *Q){
    QHead tempQ;
    tempQ.front = NULL;
    tempQ.rear = NULL;
    printf("FN\tLN\tMI\tID\n");
    while(Q->front != NULL){
        printf("%s\t%s\t%c\t%d\n", Q->front->stud.name.FName, Q->front->stud.name.LName, Q->front->stud.name.MI, Q->front->stud.ID);
        enQueue(&tempQ, Q->front->stud);
        deQueue(Q);
    }
    while(tempQ.front != NULL){
        enQueue(Q, tempQ.front->stud);
        deQueue(&tempQ);
    }
}

void enQueue(QHead *Q, Studtype stud){
    LinkQueue temp = (LinkQueue)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->stud = stud;
        temp->next = NULL;
        if (Q->front == NULL) {
            Q->front = temp;
        } else {
            Q->rear->next = temp;
        }
        Q->rear = temp;
    }
}

void deQueue(QHead *Q){
    if(Q->front != NULL){
        LinkQueue temp = Q->front;
        if(Q->rear == Q->front){
            Q->rear = NULL;
        }
        Q->front = temp->next;
        free(temp);
    }
}

Boolean isEmpty(QHead Q){
    return (Q.front == NULL) ? TRUE : FALSE;
}

Studtype front(QHead Q){
    Studtype dummy;
    strcpy(dummy.name.FName, "XXXXXX");
    strcpy(dummy.name.LName, "XXXXXX");
    dummy.name.MI = 'X';
    strcpy(dummy.course, "XXXXX");
    dummy.ID = 0;
    dummy.yrLevel = 0;
    return (Q.front != NULL) ? Q.front->stud : dummy; 
}

void makeNull(QHead *Q){
    while(Q->front != NULL){
        deQueue(Q);
    }
}