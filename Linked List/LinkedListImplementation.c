#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *link;
} nodetype, *LIST;

void displayList(LIST A);
void insertLastUnique(char elem, LIST *A);
void deleteAllOccur(int position, LIST *A);

int main(){
    LIST L = NULL;
    insertLastUnique('N', &L);
    insertLastUnique('A', &L);
    insertLastUnique('S', &L);
    insertLastUnique('A', &L);
    displayList(L);
}

void displayList(LIST A){
    LIST trav = A;
    for(trav = A; trav != NULL; trav = trav->link){
        printf("%c ", trav->data);
    }
    printf("\n");
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

void deleteAllOccur(int position, LIST *A){
    LIST *trav = A;

}
