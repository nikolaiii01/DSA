#include <stdio.h>
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
}dataNode;

typedef struct {
    dataNode Nodes[MAX];
    int Avail;
}VHeap;

typedef struct {
    int top;
    VHeap *vptr;
}STACK;

void initVirtualHeap(VHeap *VH);
int allocSpace(VHeap *VH);
void deallocSpace(VHeap *VH, int ndx);
void initStack(STACK *S, VHeap *VH);
void push(STACK *S, studRec stud);
void pop(STACK *S);
void displayStack(STACK S);
void displayVirtualHeap(VHeap VH);

int main(){
    studRec stud1;
    strcpy(stud1.name.FN, "Inie");
    stud1.name.MI = 'A';
    strcpy(stud1.name.LN, "Sabado");
    strcpy(stud1.course, "BSIT");
    strcpy(stud1.ID, "21104226");
    stud1.yrLevel = 2;

    studRec stud2;
    strcpy(stud2.name.FN, "Nikolai");
    stud2.name.MI = 'R';
    strcpy(stud2.name.LN, "Tumapon");
    strcpy(stud2.course, "BSIT");
    strcpy(stud2.ID, "18104226");
    stud2.yrLevel = 3;

    studRec stud3;
    strcpy(stud3.name.FN, "Horeb");
    stud3.name.MI = 'M';
    strcpy(stud3.name.LN, "Barriga");
    strcpy(stud3.course, "BSCS");
    strcpy(stud3.ID, "19104287");
    stud3.yrLevel = 4;

    STACK studList;
    VHeap VSpace;
    initStack(&studList, &VSpace);
    initVirtualHeap(&VSpace);

    push(&studList, stud1);

    displayStack(studList);
    // displayVirtualHeap(VSpace);

    return 0;
}

void initVirtualHeap(VHeap *VH){
    int i;
    for(i = MAX-1; i > -1; i--){
        VH->Nodes[i].link = i-1;
    }
    VH->Avail = MAX-1;
}

int allocSpace(VHeap *VH){
    int ret = VH->Avail;
    if(ret != -1){
        VH->Avail = VH->Nodes[ret].link;
    }
    return ret;
}

void deallocSpace(VHeap *VH, int ndx){
    if(ndx > -1 && ndx < MAX){
        VH->Nodes[ndx].link = VH->Avail;
        VH->Avail = ndx;
    }
}

void initStack(STACK *S, VHeap *VH){
    S->top = -1;
    S->vptr = VH;
}

void push(STACK *S, studRec stud){
    int ndx = allocSpace(S->vptr);
    if(ndx != -1){
        S->vptr->Nodes[ndx].stud = stud;
        S->vptr->Nodes[ndx].link = S->top;
        S->top = ndx;
    }
}

void pop(STACK *S){
    if(S->top != -1){
        int temp = S->top;
        S->top = S->vptr->Nodes[S->top].link;
        deallocSpace(S->vptr, temp);
    }
}

void displayStack(STACK S){
    STACK tempStack;
    VHeap tempVHeap;
    initVirtualHeap(&tempVHeap);
    initStack(&tempStack, &tempVHeap);
    int trav;
    printf("TOP: %d\n", S.top);
    for(trav = S.top; trav != -1; trav = S.vptr->Nodes[trav].link){
        printf("%s %s\n", S.vptr->Nodes[trav].stud.name.FN, S.vptr->Nodes[trav].stud.name.LN);
        push(&tempStack, S.vptr->Nodes[trav].stud);
        pop(&S);
    }
    for(trav = tempStack.top; trav != -1; trav = tempStack.vptr->Nodes[trav].link){
        push(&S, tempStack.vptr->Nodes[trav].stud);
        pop(&tempStack);
    }
    displayVirtualHeap(tempVHeap);
}

void displayVirtualHeap(VHeap VH){
    int i;
    printf("AVAIL: %d\n", VH.Avail);
    for(i = 0; i < MAX; i++){
        printf("[%d] %s %d\n", i, VH.Nodes[i].stud.name.FN, VH.Nodes[i].link);
    }
}