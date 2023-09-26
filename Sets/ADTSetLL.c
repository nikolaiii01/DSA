#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX 10

typedef struct node{
    int data;
    struct node* link;
} *SET;

void Initialize(SET *A);
SET Union(SET A, SET B);
SET Intersection(SET A, SET B);
SET Difference(SET A, SET B);
void Display(SET A);
bool Member(SET A, int elem);
void Insert(SET* A, int elem);
void Delete(SET* A, int elem); 

int main(){
    SET X, Y;

    bool isMember;

    Initialize(&X);
    Initialize(&Y);

    Insert(&X, 1);
    Insert(&X, 3);
    Insert(&Y, 2);
    Insert(&Y, 4);

    Delete(&X, 1);
    (isMember = Member(X, 1)) ? printf("true") : printf("false");

    SET C = Union(X, Y);

    return 0;
}

void Initialize(SET *A){
    *A = NULL;
}

void Insert(SET *A, int elem){
    SET *trav = A;
    for(trav = A; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link){}
    if(*trav == NULL){
        SET temp = (SET)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->data = elem;
            temp->link = NULL;
            *trav = temp;
        }
    }
}

void Delete(SET *A, int elem){
    SET *trav;
    for(trav = A; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link){}
    if(*trav != NULL){
        SET temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

void Display(SET A){
    SET trav; 
    for(trav = A; trav != NULL; trav = trav->link){
        printf("%d ", trav->data);
    }
}

bool Member(SET A, int elem){
    SET trav;
    for(trav = A; trav != NULL && trav->data != elem; trav = trav->link){}
    return (trav != NULL) ? true : false;
}

SET Union(SET A, SET B){
    SET ptrA, ptrB, C, *ptrC = &C, temp;
    for(ptrA = A, ptrB = B; ptrA != NULL || ptrB != NULL; ptrA = ptrA->link, ptrB = ptrB->link)
}





