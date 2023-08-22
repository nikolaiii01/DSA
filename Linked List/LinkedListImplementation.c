#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} nodetype, *LIST;

void displayList(LIST A);
void insertLast(char elem, LIST *A);
void insertLastUnique(char elem, LIST *A);
void deleteAllOccur(char elem, LIST *A);

int main(){
    LIST L = NULL;
    insertLast('A', &L);
    insertLast('A', &L);
    insertLast('B', &L);
    insertLast('A', &L);
    deleteAllOccur('A', &L);
    displayList(L);
}

void displayList(LIST A){
    LIST trav = A;
    for(trav = A; trav != NULL; trav = trav->link){
        printf("%c ", trav->data);
    }
    printf("\n");
}

void insertLast(char elem, LIST *A){
    LIST *trav = A;
    LIST temp = NULL;
    for(trav = A; *trav != NULL; trav = &(*trav)->link){}
    temp = (LIST)malloc(sizeof(nodetype));
    if(temp != NULL){
        temp->data = elem;
        temp->link = NULL;
        *trav = temp;
    }
}

void insertLastUnique(char elem, LIST *A){
    LIST *trav = A;
    for(trav = A; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link){}
    if(*trav == NULL){
        LIST temp = (LIST)malloc(sizeof(nodetype));
        if(temp != NULL){
            temp->data = elem;
            temp->link = NULL;
            *trav = temp;
        }
    }
}

void deleteAllOccur(char elem, LIST *A){
    LIST *trav = A;
    LIST temp = NULL;
    while(*trav != NULL){
        if((*trav)->data == elem){
            temp = *trav;
            *trav = (*trav)->link;
            free(temp);
        } else {
            trav = &(*trav)->link;
        }
    }
}
