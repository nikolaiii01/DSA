#include <string.h>

#define VH_MAX 0XFF
#define MAX 0XA

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
}CBnode;

typedef struct {
    CBnode heap[VH_MAX];
    int avail;
}*Vheap;

typedef int CursorList;

typedef struct node {
    studRec data[MAX];
    int studCtr;
}*ArrayList;

int allocSpace(Vheap VH);
int insertCList(ArrayList A, CursorList *C, Vheap VH);

int main(){

    return 0;
}

int allocSpace(Vheap VH){
    CursorList ret = VH->avail;
    if(ret != -1){
        VH->avail = VH->heap[ret].link;
    }
    return ret;
}

int insertCList(ArrayList A, CursorList *C, Vheap VH){
    CursorList *trav, temp;
    int i, count;
    for(i = 0; i < A->studCtr; i++){
        for(trav = C; *trav != -1 && strcmp(VH->heap[*trav].stud.ID, A->data[i].ID) != 0; trav = &VH->heap[*trav].link){}
        if(*trav == -1){
            for(trav = C; *trav != -1 && strcmp(VH->heap[*trav].stud.ID, A->data[i].ID) < 0; trav = &VH->heap[*trav].link){}
            temp = allocSpace(VH);
            if(temp != -1){
                VH->heap[temp].stud = A->data[i];
                VH->heap[temp].link = *trav;
                *trav = temp;
                count++;
            }
        }
    }
    return count;
}