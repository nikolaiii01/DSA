#include <stdio.h>
#include <stdlib.h>

// Write the code for the UID assuming sets are sorted. 
// 1. Write the appropriate datatype SET implemented using singly linked list.
// 2. Using the definition in #1, write the code for each of the folllowing operations assuming the elements are sorted; Union, Intersection, & Difference

typedef struct node{
    char data;
    struct node *link;
}*SET;

void Initialize(SET *A);
void Insert(SET *A, char elem);
void Delete(SET *A, char elem);
SET Union(SET A, SET B);
SET Intersection(SET A, SET B);
SET Difference(SET *A, SET B);
void Display(SET A);

int main(){
    char U[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    SET A, B;
    Initialize(&A);
    Initialize(&B);

    Insert(&A, U[1]);
    Insert(&A, U[2]);
    Insert(&A, U[3]);
    Insert(&A, U[7]);

    Insert(&B, U[0]);
    Insert(&B, U[6]);

    SET C = Difference(&A, B);

    Display(C);

    return 0;
}

void Initialize(SET *A){
    *A = NULL;
}

void Display(SET A){
    SET trav;
    for(trav = A; trav != NULL; trav = trav->link){
        printf("[%c]->", trav->data);
    }
}

void Insert(SET *A, char elem){
    SET *trav, temp;
    for(trav = A; *trav != NULL && ((*trav)->data != elem && elem > (*trav)->data); trav = &(*trav)->link){}
    if(*trav == NULL || elem < (*trav)->data){
        temp = (SET)malloc(sizeof(struct node));
        temp->data = elem;
        temp->link = *trav;
        *trav = temp;
    }
}

void Delete(SET *A, char elem){
    SET *trav, temp;
    for(trav = A; *trav != NULL && ((*trav)->data != elem && elem > (*trav)->data); trav = &(*trav)->link){}
    if(*trav != NULL && (*trav)->data == elem){
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

SET Union(SET A, SET B){
    SET C, trav, *travC, temp;
    Initialize(&C);
    for(trav = A; trav != NULL; trav = trav->link){
        for(travC = &C; *travC != NULL && trav->data > (*travC)->data; travC = &(*travC)->link){}
        temp = (SET)malloc(sizeof(struct node));
        temp->data = trav->data;
        temp->link = *travC;
        *travC = temp;
    }
    for(trav = B; trav != NULL; trav = trav->link){
        if(*travC == NULL || trav->data < (*travC)->data){
            temp = (SET)malloc(sizeof(struct node));
            temp->data = trav->data;
            temp->link = *travC;
            *travC = temp;
        }
    }
    return C;
}

SET Intersection(SET A, SET B){
    SET C, travA = A, travB = B, *travC, temp;
    Initialize(&C);
    travC = &C;
    while(travA != NULL && travB != NULL){
        if(travA->data == travB->data){
            for(travC = &C; *travC != NULL && travA->data > (*travC)->data; travC = &(*travC)->link){}
            temp = (SET)malloc(sizeof(struct node));
            temp->data = travA->data;
            temp->link = *travC;
            *travC = temp;
        }
        if(travA != NULL && travB != NULL){
            if(travA->data < travB->data){
                travA = travA->link;
            } else {
                travB = travB->link;
            }
        }
    } 
    return C;
}

SET Difference(SET *A, SET B){
    SET *travA = A, travB = B, temp;
    while(*travA != NULL && travB != NULL){
        if((*travA)->data == travB->data){
            temp = *travA;
            *travA = temp->link;
            free(temp);
        }
        if(*travA != NULL && travB != NULL){
            if((*travA)->data < travB->data){
                travA = &(*travA)->link;
            } else {
                travB = travB->link;
            }
        }
    } 
    return *A;
}