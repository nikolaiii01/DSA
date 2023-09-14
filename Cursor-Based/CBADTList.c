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
int allocSpace(VirtualHeap *VH);
void displayList(VirtualHeap VH, LIST A);
void insertFirst(VirtualHeap *VH, LIST *A, char elem);
void insertLast(VirtualHeap *VH, LIST *A, char elem);

int main(){
    LIST L = -1;
    VirtualHeap VH;
    initVirtualHeap(&VH);
    insertFirst(&VH, &L, 'A');
    insertFirst(&VH, &L, 'B');
    insertLast(&VH, &L, 'B');
    displayList(VH, L);

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
        VH->Avail = VH->Nodes[ret].link;
    }
    return ret;
}

void deallocSpace(int ndx, VirtualHeap *VH){
    if(ndx != -1 && ndx < MAX){
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
    LIST temp;
    temp = allocSpace(VH);  
    if(temp != -1){
        VH->Nodes[temp].data = elem;
        VH->Nodes[temp].link = *A;
        *A = temp;
    }
}

void insertLast(VirtualHeap *VH, LIST *A, char elem){ 
    LIST *trav, temp; 
    temp = allocSpace(VH); //allocate space
    if(temp != -1){ //check if space was allocated
        for(trav = A; *trav != -1; trav = &VH->Nodes[*trav].link){} //traverse the list
        VH->Nodes[temp].data = elem; //insert element
        VH->Nodes[temp].link = *trav; //
        *trav = temp;
    }
}
