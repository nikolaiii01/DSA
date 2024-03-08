#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    char FN[24], LN[16], MI;
}nametype;

typedef struct {
    char ID[10];
    nametype name;
    char course[8];
    int yrLevel;
}studRec;

typedef struct {
    studRec stud;
    int link;
}nodetype;

typedef struct {
    nodetype VSpace[MAX];
    int firstAvail;
}VHeap;

typedef struct {
    int start;
    int end;
    int cnt;
    VHeap *vptr;
}queue;

void initQueue(queue *Q, VHeap *VH);
void initVHeap(VHeap *VH);
studRec removeFirst(queue *Q);
void enQueue(queue *Q, studRec stud);
int allocSpace(VHeap *VH);
void displayVirtualHeap(VHeap VH);
void displayQueueStr(queue Q);
void displayStud(studRec stud);

int main(){
    studRec stud1;
    strcpy(stud1.name.FN, "Inie");
    stud1.name.MI = 'A';
    strcpy(stud1.name.LN, "Sabado");
    strcpy(stud1.course, "BSIT");
    strcpy(stud1.ID, "STUD-001");
    stud1.yrLevel = 2;

    studRec stud2;
    strcpy(stud2.name.FN, "Horeb");
    stud2.name.MI = 'A';
    strcpy(stud2.name.LN, "Barriga");
    strcpy(stud2.course, "BSIT");
    strcpy(stud2.ID, "STUD-002");
    stud2.yrLevel = 3;

    studRec stud3;
    strcpy(stud3.name.FN, "Nikolai");
    stud3.name.MI = 'A';
    strcpy(stud3.name.LN, "Tumapon");
    strcpy(stud3.course, "BSIT");
    strcpy(stud3.ID, "STUD-003");
    stud3.yrLevel = 4;

    VHeap VH;
    queue studList;
    initQueue(&studList, &VH);
    initVHeap(&VH);

    enQueue(&studList, stud1);
    enQueue(&studList, stud2);
    // enQueue(&studList, stud3);

    // studRec stud = removeFirst(&studList);
    // displayStud(stud);

    displayQueueStr(studList);
    displayVirtualHeap(VH);

    return 0;
}

void displayVirtualHeap(VHeap VH){
    int i;
    printf("-------------------------\n");
    for (i = 0; i < MAX; i++) {
        printf("[%d] data: %s link: %d\n", i, VH.VSpace[i].stud.name.FN,
               VH.VSpace[i].link);
    }
    printf("firstAvail: %d", VH.firstAvail);
}

void displayQueueStr(queue Q){
    printf("Start: %d End: %d Count: %d\n", Q.start, Q.end, Q.cnt);
}

void displayStud(studRec stud){
    printf("Name: %s %s %c\n", stud.name.FN, stud.name.LN, stud.name.MI);
    printf("ID: %s\n", stud.ID);
    printf("Course: %s\n", stud.course);
    printf("Year Level: %d\n", stud.yrLevel);
}

void initQueue(queue *Q, VHeap *VH){
    Q->vptr = VH;
    Q->start = -1;
    Q->end = -1;
    Q->cnt = 0;
}

void initVHeap(VHeap *VH){
    int i;
    for(i = MAX-1; i > -1; i--){
        VH->VSpace[i].link = i-1;
    }
    VH->firstAvail = MAX-1;
}

void enQueue(queue *Q, studRec stud){
    int temp;
    temp = allocSpace(Q->vptr);
    if(temp != -1){
        Q->vptr->VSpace[temp].stud = stud;
        Q->vptr->VSpace[temp].link = Q->end;
        Q->end = temp;
        if(Q->start == -1){
            Q->start = temp;
        }
    }
}

int allocSpace(VHeap *VH){
    int ret = VH->firstAvail;
    if(ret != -1){
        VH->firstAvail = VH->VSpace[ret].link;
    }
    return ret;
}

void deallocSpace(int ndx, VHeap *VH){
    if(ndx > -1 && ndx < MAX){
        VH->VSpace[ndx].link = VH->firstAvail;
        VH->firstAvail = ndx;
    }
}

studRec removeFirst(queue *Q){ // Something is wrong
    studRec dummy;
    strcpy(dummy.name.FN, "XXXXX");
    strcpy(dummy.name.FN, "XXXXX");
    dummy.name.MI = 'X';
    strcpy(dummy.ID, "XXXXX");
    strcpy(dummy.course, "XXXXX");
    dummy.yrLevel = 0;
    if((Q->end+1)%MAX != Q->start){
        dummy = Q->vptr->VSpace[Q->start].stud;
        Q->vptr->VSpace[Q->start].link = Q->vptr->firstAvail;
        Q->vptr->firstAvail=Q->start--;
    }
    return dummy;
}