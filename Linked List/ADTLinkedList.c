#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *link;
} *LIST, nodetype;

void initList(LIST *A);
void displayList(LIST A);
void insertFirst(LIST *A, char elem);
void insertLast(LIST *A, char elem);
void insertSorted(LIST *A, char elem);
void insertFirstUnique(LIST *A, char elem);
void insertLastUnique(LIST *A, char elem);
void insertAtPos(LIST *A, char elem, int pos);
void deleteFirst(LIST *A);
void deleteLast(LIST *A);
void deleteElem(LIST *A, char elem);
void deleteAllOccurrences(LIST *A, char elem);

int main()
{
    LIST L;
    initList(&L);

    insertFirst(&L, 'A');
    insertFirst(&L, 'A');
    insertAtPos(&L, 'B', 3);
    // insertFirstUnique(&L, 'A');
    // insertLastUnique(&L, 'G');

    // deleteFirst(&L);
    // deleteLast(&L);
    // deleteElem(&L, 'G');
    // deleteAllOccurrences(&L, 'A');

    displayList(L);
    return 0;
}

void initList(LIST *A)
{
    *A = NULL;
}

void displayList(LIST A)
{
    LIST trav;
    for (trav = A; trav != NULL; trav = trav->link)
    {
        printf("[%c]->", trav->data);
    }
}

void insertFirst(LIST *A, char elem)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp != NULL)
    {
        temp->data = elem;
        temp->link = *A;
        *A = temp;
    }
}

void insertLast(LIST *A, char elem)
{
    LIST *trav;
    for (trav = A; *trav != NULL; trav = &(*trav)->link)
    {
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp != NULL)
    {
        temp->data = elem;
        temp->link = NULL;
        *trav = temp;
    }
}

void insertSorted(LIST *A, char elem)
{
    LIST *trav;
    for (trav = A; *trav != NULL && (*trav)->data < elem; trav = &(*trav)->link)
    {
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp != NULL)
    {
        temp->data = elem;
        temp->link = (*trav != NULL) ? *trav : NULL;
        *trav = temp;
    }
}

void insertFirstUnique(LIST *A, char elem)
{
    LIST *trav;
    for (trav = A; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link)
    {
    }
    if (!(*trav != NULL))
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        if (temp != NULL)
        {
            temp->data = elem;
            temp->link = *A;
            *A = temp;
        }
    }
}

void insertLastUnique(LIST *A, char elem)
{
    LIST *trav;
    for (trav = A; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link)
    {
    }
    if (!(*trav != NULL))
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        if (temp != NULL)
        {
            temp->data = elem;
            temp->link = NULL;
            *trav = temp;
        }
    }
}

void insertAtPos(LIST *A, char elem, int pos){
    int count;
    LIST *trav, temp;
    for(trav = A, count = 0; *trav != NULL && count < pos; trav = &(*trav)->link, count++){}
    if(pos >= 0 && pos <= count ){
        temp = (LIST)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->data = elem;
            temp->link = *trav;
            *trav = temp;
        }
    }
}

void deleteFirst(LIST *A)
{
    if (*A != NULL)
    {
        LIST temp;
        temp = *A;
        *A = (*A)->link;
        free(temp);
    }
}

void deleteLast(LIST *A)
{
    if (*A != NULL)
    {
        LIST *trav, temp;
        for (trav = A; (*trav)->link != NULL; trav = &(*trav)->link)
        {
        }
        temp = *trav;
        *trav = NULL;
        free(temp);
    }
}

void deleteElem(LIST *A, char elem)
{
    if (*A != NULL)
    {
        LIST *trav, temp;
        for (trav = A; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link)
        {
        }
        if (*trav != NULL)
        {
            temp = *trav;
            *trav = temp->link;
            free(temp);
        }
    }
}

void deleteAllOccurrences(LIST *A, char elem)
{
        LIST *trav = A, temp = NULL;
        while (*trav != NULL)
        {
            if ((*trav)->data == elem)
            {
                temp = *trav;
                *trav = (*trav)->link;
                free(temp);
            }
            else
            {
                trav = &(*trav)->link;
            }
        }
}