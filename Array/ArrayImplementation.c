#include <stdio.h>

#define MAX 10
typedef struct {
    char Elem[MAX];
    int count;
} LIST;

void displayList(LIST A);
void insertLast(char elem, LIST *A);
void insertLastUnique(char elem, LIST *A);
void deleteAllOccur(char elem, LIST *A);

int main(){
    LIST L;
    L.count = 0;
    insertLast('A', &L);
    insertLast('A', &L);
    insertLast('B', &L);
    insertLast('C', &L);
    insertLast('A', &L);
    deleteAllOccur('A', &L);
    displayList(L);
}

void displayList(LIST A){
    int i;
    for(i = 0; i < A.count; i++){
        printf("%c ", A.Elem[i]);
    }
}

void insertLast(char elem, LIST *A){
    A->Elem[A->count] = elem;
    A->count++;
}

void insertLastUnique(char elem, LIST *A){
    int i, j, k;
    if(A->count < MAX){
        for(i = 0; i < A->count && A->Elem[i] != elem; i++){}
        if(i == A->count){
            A->Elem[A->count] = elem;
            A->count++;
        }
    }
}

void deleteAllOccur(char elem, LIST *A) {
    int i, j;
    for (i = 0, j = 0; i < A->count; i++) {
        if (A->Elem[i] != elem) {
            A->Elem[j] = A->Elem[i];
            j++;
        }
    }
    A->count = j;
    
    for (; j < MAX; j++) {
        A->Elem[j] = '\0';
    }
}