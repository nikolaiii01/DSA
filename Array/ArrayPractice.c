#include <stdio.h>

#define SIZE 10

typedef struct {
    char elements[SIZE];
    int count;
}List;

typedef enum {TRUE, FALSE} Boolean;

void initializeList(List *L);
int findElem(List L, char elem);
void insertFirst(List *L, char elem);
int deleteElem(List *L, char elem);
void display(List L);

int main(){
    List L;

    initializeList(&L);
    insertFirst(&L, 'A');
    Boolean ret = findElem(L, 'A');
    printf("%d\n", ret);
    insertFirst(&L, 'B');
    ret = findElem(L, 'A');
    display(L);
}

void initializeList(List *L){
    L->count = 0;
}

int findElem(List L, char elem){
    int i;
    for(i = 0; i < L.count && L.elements[i] != elem; i++){}
    return (i < L.count) ? TRUE : FALSE;
}

void insertFirst(List *L, char elem){
    int i;
    for(i = 0; i < L->count; i++){
        L->elements[i + 1] = L->elements[i];
    }
    L->elements[0] = elem;
    L->count++;
}

int deleteElem(List *L, char elem){
    int i, retVal;
    for(i = 0; i < L->count && L->elements[i] != elem; i++){}
    if(i < L->count){
        for(; i < L->count; i++){
            L->elements[i] = L->elements[i + 1];
        }
        retVal = 1;
    } else {
        retVal = 0;
    }
    return retVal;
}

void display(List L){
    int i;
    for(i = 0; i < L.count; i++){
        printf("%c ", L.elements[i]);
    }
}