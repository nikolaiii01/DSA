#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} nodetype, *LIST;

LIST createList();
void displayFullList(LIST A);
void displaySpecificNode(int pos, LIST A);
void insertLast(char elem, LIST *A);
void insertLastUnique(char elem, LIST *A);
void deleteAllOccur(char elem, LIST *A);

int main(){
    int pos = 3;
    LIST List = createList();
    insertLast('A', &List);
    insertLast('A', &List);
    insertLast('B', &List);
    insertLast('A', &List);
    displaySpecificNode(pos, List);
    deleteAllOccur('A', &List);
    displayFullList(List);
}

LIST createList(){
    LIST L = NULL;
    return L;
}

void displayFullList(LIST A){
    LIST trav = A;
    for(trav = A; trav != NULL; trav = trav->link){
        printf("%c ", trav->data);
    }
    printf("\n");
}

void displaySpecificNode(int pos, LIST A){
    LIST trav = A;
    int i;
    for(i = 1; i < pos; trav = trav->link, i++){}
    printf("%c", trav->data);
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
