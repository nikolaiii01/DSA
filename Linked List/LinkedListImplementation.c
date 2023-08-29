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
    for(trav = A; *trav != NULL; trav = &(*trav)->link){} //traverse the list
    temp = (LIST)malloc(sizeof(nodetype)); //create a new node
    if(temp != NULL){ //check if node was created
        temp->data = elem; //insert element
        temp->link = NULL; //set link to NULL
        *trav = temp; //link the previous node to the new node
    }
}

void insertLastUnique(char elem, LIST *A){
    LIST *trav = A; 
    for(trav = A; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link){} //traverse the list and check if element is already in the list
    if(*trav == NULL){ //if it reached the end of the list
        LIST temp = (LIST)malloc(sizeof(nodetype)); //create a new node
        if(temp != NULL){ //check if node was created
            temp->data = elem; //insert element
            temp->link = NULL; //set link to NULL
            *trav = temp; //link the previous node to the new node
        }
    }
}

void deleteAllOccur(char elem, LIST *A){
    LIST *trav = A;
    LIST temp = NULL;
    while(*trav != NULL){ //traverse the list
        if((*trav)->data == elem){ //check to see if element is equal to the element to be deleted
            temp = *trav; //store the address of the node to be deleted
            *trav = (*trav)->link; //link the previous node to the next node
            free(temp); //free the node
        } else {
            trav = &(*trav)->link; //traverse the list
        }
    }
}


