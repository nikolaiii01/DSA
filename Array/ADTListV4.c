#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct node{
    char *elemPtr; 
    int count;
} *LIST, nodetype;

void initList(LIST *A);
void displayList(LIST A);
void insertFirst(char elem, LIST *A);
void insertSorted(char elem, LIST *A);
int indexOfFirstOccurence(char elem, LIST *A);

int main(){
    LIST L;
    initList(&L);
    char name[] = "BFG";
    char elem = 'G';
    int i;
    for(i = strlen(name)-1; i >= 0; i--){
        insertFirst(name[i], &L);
    }
    insertSorted('C', &L);
    displayList(L);
    int ndx = indexOfFirstOccurence(elem, &L);
    printf("\nIndex of %c: %d", elem,ndx);

    return 0;
}

void initList(LIST *A){
    (*A) = (LIST)malloc(sizeof(nodetype));
    if((*A) != NULL){
        (*A)->elemPtr = (char*)malloc((MAX)*sizeof(char)); 
        (*A)->count = 0;
    }
}

void displayList(LIST A){
    int i;
    for(i = 0; i < A->count; i++){
        printf("%c ", A->elemPtr[i]);
    }
}

void insertFirst(char elem, LIST *A){
    if((*A)->count < MAX){
        int i;
        for(i = (*A)->count; i > 0; i--){
            (*A)->elemPtr[i] = (*A)->elemPtr[i-1];
        }
        (*A)->elemPtr[0] = elem;
        (*A)->count++; 
    }
}

void insertSorted(char elem, LIST *A){
    if((*A)->count < MAX){
        int i, j;
        for(i = 0; i < (*A)->count && (*A)->elemPtr[i] < elem; i++){}
        if(i <= (*A)->count){
            for(j = (*A)->count; j > i; j--){
                (*A)->elemPtr[j] = (*A)->elemPtr[j-1];
            }
            (*A)->elemPtr[i] = elem;
            (*A)->count++;
        }
    }
}

int indexOfFirstOccurence(char elem, LIST *A){
    int i;
    for(i = 0; i < (*A)->count && (*A)->elemPtr[i] != elem; i++){}
    return (i < (*A)->count) ? i : -1;
}
