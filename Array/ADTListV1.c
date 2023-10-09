// ADT Linked List Version 1
#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct list{
    char Elem[MAX];
    int count;
} LIST;

LIST initList(LIST *A);
void displayList(LIST A);
void insertFirst(char elem, LIST *A);
void insertSorted(char elem, LIST *A);
int indexOfFirstOccurence(char elem, LIST *A);
void deleteLast(LIST *A);

int main(){
    LIST L;
    L = initList(&L);
    char name[] = "AFG";
    char elem = 'A';
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

LIST initList(LIST *A){
    A->count = 0;
    return *A;
}

void displayList(LIST A){
    int i;
    for(i = 0; i < A.count; i++){
        printf("%c ", A.Elem[i]);
    }
}

void insertFirst(char elem, LIST *A){
    if(A->count < MAX){
        int i;
        for(i = A->count; i > 0; i--){
            A->Elem[i] = A->Elem[i - 1];
        }
        A->Elem[0] = elem;
        A->count++;
    } 
}

void insertSorted(char elem, LIST *A){
    if(A->count < MAX){
        int i, j;
        for(i = 0; i < A->count && A->Elem[i] < elem; i++){}
        if(i < A->count){
            for(j = A->count; j > i; j--){
                A->Elem[j] = A->Elem[j - 1];
            }
        }
        A->Elem[i] = elem;
        A->count++;
    }
}

int indexOfFirstOccurence(char elem, LIST *A){
    int i;
    for(i = 0; i < A->count && A->Elem[i] != elem; i++){}
    return (i < A->count) ? i : -1;
}

void deleteLast(LIST *A){
    if(A->count > 0){
        A->Elem[A->count] = NULL;
        A->count--;
    }
}
    