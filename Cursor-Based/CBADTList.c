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
void initList(LIST *A);
int allocSpace(VirtualHeap *VH);
void deallocSpace(int ndx, VirtualHeap *VH);
void displayVirtualHeap(VirtualHeap VH);
void displayList(VirtualHeap VH, LIST A);
void insertFirst(VirtualHeap *VH, LIST *A, char elem);
void insertLast(VirtualHeap *VH, LIST *A, char elem);
void insertAtPos(VirtualHeap *VH, LIST *A, char elem, int pos);
void deleteElem(VirtualHeap *VH, LIST *A, char elem);
void deleteAllOccurrences(VirtualHeap *VH, LIST *A, char elem);

int main(){
    LIST L;
    VirtualHeap VH;
    initList(&L);
    initVirtualHeap(&VH);
    insertFirst(&VH, &L, 'B');
    insertFirst(&VH, &L, 'A');
    insertFirst(&VH, &L, 'A');
    insertFirst(&VH, &L, 'A');
    insertFirst(&VH, &L, 'B');
    // insertAtPos(&VH, &L, 'C', -1);

    // deleteElem(&VH, &L, 'P');
    deleteAllOccurrences(&VH, &L, 'C');

    displayVirtualHeap(VH);
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

void initList(LIST *A){
    *A = -1;
}

void displayVirtualHeap(VirtualHeap VH) {
    int i;
    for (i = 0; i < MAX; i++) {
        printf("[%d] data: %c link: %d\n", i, VH.Nodes[i].data,
               VH.Nodes[i].link);
    }
}

int allocSpace(VirtualHeap *VH){
    LIST ret = VH->Avail;
    if(ret != -1){
        VH->Avail = VH->Nodes[ret].link;
    }
    return ret;
}

void deallocSpace(int ndx, VirtualHeap *VH){
    if(ndx > -1 && ndx < MAX){
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
    temp = allocSpace(VH);
    if(temp != -1){
        for(trav = A; *trav != -1; trav = &VH->Nodes[*trav].link){}
        VH->Nodes[temp].data = elem;
        VH->Nodes[temp].link = *trav;
        *trav = temp;
    }
}

void insertAtPos(VirtualHeap *VH, LIST *A, char elem, int pos){
    int count;
    LIST *trav, temp;
    for(trav = A, count = 0; *trav != -1 && count < pos; trav = &(VH->Nodes[*trav]).link, count++){}
    if(pos >= 0 && pos <= count){
        temp = allocSpace(VH);
        if(temp != -1){
            VH->Nodes[temp].data = elem;
            VH->Nodes[temp].link = (*trav != -1) ? *trav : -1;
            *trav = temp;
        }
    }
}

void deleteElem(VirtualHeap *VH, LIST *A, char elem){
    LIST *trav, temp;
    for(trav = A; *trav != -1 && VH->Nodes[*trav].data != elem; trav = &VH->Nodes[*trav].link){}
    if(*trav != -1){
        temp = *trav;
        *trav = VH->Nodes[temp].link;
        deallocSpace(temp, VH);
    }
}

void deleteAllOccurrences(VirtualHeap *VH, LIST *A, char elem){
    LIST *trav = A, temp;
    while(*trav != -1){
        if(VH->Nodes[*trav].data == elem){
            temp = *trav;
            *trav = VH->Nodes[*trav].link;
            deallocSpace(temp, VH);
        }else{
            trav = &VH->Nodes[*trav].link;
        }
    }
}