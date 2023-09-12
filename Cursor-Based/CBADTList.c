#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int LIST;

typedef struct node {
    char data;
    int link;
} nodetype;

typedef struct VH {
    nodetype Nodes[MAX];
    int Avail;
} VirtualHeap;

void initVirtualHeap(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH, int index);
void displayList(VirtualHeap VH, LIST A);
void insertFirst(VirtualHeap *VH, LIST *A, char elem);

int main(){
    LIST L;
    VirtualHeap VH;
    initVirtualHeap(&VH);
    insertFirst(&VH, &L, 'A');
    displayList(VH);

    return 0;
}

void initVirtualHeap(VirtualHeap *VH){
    int i;
    for(i = MAX-1; i > -1; i--){
        VH->Nodes[i].link = i-1;
    }
    VH->Avail = MAX-1;
}

int allocSpace(VirtualHeap *VH){
    LIST ret = VH->Avail;
    if(ret != -1){
        VH->Avail = VH->Nodes[i].link;
    }
    return ret;
}

void deallocSpace(int ndx, VirtualHeap VH){
    if(ndx != -1; && ndx < MAX){
        VH->Nodes[ndx].link = VH->Avail;
        VH->Avail = ndx;
    }
}

void displayList(VirtualHeap VH, LIST A){
    LIST i;
    for(i = A; i != -1; i = VH.Nodes[i].link){
        printf("%c ", VH.Nodes[i].data);
    }
}

void insertFirst(VirtualHeap *VH, LIST *A, char elem){    
    LIST ndx;
    ndx = allocSpace(VH);  
    if(ndx != -1){
        VH->Nodes[ndx].data = elem;
        VH->Nodes[ndx].link = *A;
        *A = ndx;
    }
}
