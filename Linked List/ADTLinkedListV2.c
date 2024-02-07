#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int elem;
    struct node *link;
} *LIST;

typedef enum
{
    TRUE,
    FALSE
} Boolean;

void displayList(LIST A);
void insertFirst(LIST *A, int x);
void insertFirstUnique(LIST *A, int elem);
void insertLast(LIST *A, int elem);
void insertLastUnique(LIST *A, int elem);
Boolean deleteFirstOccurrence(LIST *A, int x);

int main()
{
    LIST L = NULL;

    // insertFirst(&L, 48);
    // insertFirst(&L, 15);

    // insertLast(&L, 31);
    // insertLastUnique(&L, 31);
    // insertLastUnique(&L, 35);
    // insertLastUnique(&L, 36);
    // insertFirst(&L, 60);
    // insertFirstUnique(&L, 40);
    // insertFirstUnique(&L, 40);

    // Boolean isDeleted = deleteFirstOccurrence(&L, 47);

    // printf("isDeleted: %d\n", isDeleted);

    displayList(L);

    return 0;
}

void displayList(LIST A)
{
    LIST trav;
    for (trav = A; trav != NULL; trav = trav->link)
    {
        printf("[%d]->", trav->elem);
    }
}

void insertFirst(LIST *A, int x)
{
    LIST temp = (LIST)malloc(sizeof(struct node));
    if (temp != NULL)
    {
        temp->link = *A;
        temp->elem = x;
        *A = temp;
    }
}

void insertFirstUnique(LIST *A, int elem)
{
    LIST *trav, temp;
    for (trav = A; *trav != NULL && (*trav)->elem != elem; trav = &(*trav)->link)
    {
    }
    if (*trav == NULL)
    {
        temp = (LIST)malloc(sizeof(struct node));
        temp->elem = elem;
        temp->link = *A;
        *A = temp;
    }
}

void insertLast(LIST *A, int elem)
{
    LIST temp = (LIST)malloc(sizeof(struct node));
    temp->link = NULL;
    temp->elem = elem;
    LIST *trav;
    for (trav = A; *trav != NULL; trav = &(*trav)->link)
    {
    }
    *trav = temp;
}

void insertLastUnique(LIST *A, int elem)
{
    LIST *trav, temp;
    for (trav = A; *trav != NULL && (*trav)->elem != elem; trav = &(*trav)->link)
    {
    }
    if (*trav == NULL)
    {
        temp = (LIST)malloc(sizeof(struct node));
        temp->elem = elem;
        temp->link = NULL;
        *trav = temp;
    }
}

Boolean deleteFirstOccurrence(LIST *A, int x)
{
    Boolean ret = FALSE;
    LIST *trav, temp;
    for (trav = A; *trav != NULL && (*trav)->elem != x; trav = &(*trav)->link)
    {
    }
    if (*trav != NULL)
    {
        temp = *trav;
        *trav = temp->link;
        free(temp);
        ret = TRUE;
    }
    return ret;
}