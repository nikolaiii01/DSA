#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    char data;
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
void push(STACK *S, char elem);
void pop(STACK *S);
void displayStack(STACK S);
void displayVirtualHeap(VHeap VH);

int main(){
    STACK studList;
    VHeap VSpace;
    initStack(&studList, &VSpace);
    initVirtualHeap(&VSpace);

    push(&studList, 'A');

    displayStack(studList);
    displayVirtualHeap(VSpace);

    return 0;
}

void initVirtualHeap(VHeap *VH){
    int i;
    for(i = MAX-1; i > -1; i--){
        VH->Nodes[i].link = i-1;
        VH->Nodes[i].data = '-';
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

void push(STACK *S, char elem){
    int ndx = allocSpace(S->vptr);
    if(ndx != -1){
        S->vptr->Nodes[ndx].data = elem;
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
        printf("%c\n", S.vptr->Nodes[trav].data);
        push(&tempStack, S.vptr->Nodes[trav].data);
        pop(&S);
    }
    for(trav = tempStack.top; trav != -1; trav = tempStack.vptr->Nodes[trav].link){
        push(&S, tempStack.vptr->Nodes[trav].data);
        pop(&tempStack);
    }
    displayVirtualHeap(tempVHeap);
}

void displayVirtualHeap(VHeap VH){
    int i;
    printf("AVAIL: %d\n", VH.Avail);
    for(i = 0; i < MAX; i++){
        printf("[%d] %c %d\n", i, VH.Nodes[i].data, VH.Nodes[i].link);
    }
}