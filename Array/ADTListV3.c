#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
    char *elemPtr;
    int count;
} LIST;

void initList(LIST *A);
void displayList(LIST A);
void insertFirst(LIST *A, char elem);
void insertLast(LIST *A, char elem);
void insertSorted(LIST *A, char elem);
void insertFirstUnique(LIST *A, char elem);
void insertLastUnique(LIST *A, char elem);
void deleteFirst(LIST *A);
void deleteLast(LIST *A);
void deleteElem(LIST *A, char elem);
void deleteAllOccurrences(LIST *A, char elem);

int main()
{
    LIST L;
    initList(&L);

    insertFirst(&L, 'H');
    insertFirst(&L, 'B');
    insertFirst(&L, 'B');
    insertFirst(&L, 'B');
    insertSorted(&L, 'G');
    insertLastUnique(&L, 'Z');

    // deleteFirst(&L);
    // deleteLast(&L);
    deleteAllOccurrences(&L, 'B');

    displayList(L);
}

void initList(LIST *A)
{
    A->elemPtr = (char *)malloc(sizeof(sizeof(char) * MAX));
    A->count = 0;
}

void displayList(LIST A)
{
    if (A.count > 0)
    {
        int i;
        for (i = 0; i < A.count; i++)
        {
            printf("[%d]: %c\n", i, A.elemPtr[i]);
        }
    }
}

void insertFirst(LIST *A, char elem)
{
    if (A->count < MAX)
    {
        int i;
        for (i = A->count; i > 0; i--)
        {
            A->elemPtr[i] = A->elemPtr[i - 1];
        }
        A->elemPtr[0] = elem;
        A->count++;
    }
}

void insertLast(LIST *A, char elem)
{
    if (A->count < MAX)
    {
        A->elemPtr[A->count] = elem;
        A->count++;
    }
}

void insertSorted(LIST *A, char elem)
{
    if (A->count < MAX)
    {
        int i;
        for (i = 0; i < A->count && A->elemPtr[i] < elem; i++)
        {
        }
        if (i < A->count)
        {
            int j;
            for (j = A->count; j > i; j--)
            {
                A->elemPtr[j] = A->elemPtr[j - 1];
            }
        }
        A->elemPtr[i] = elem;
        A->count++;
    }
}

void insertFirstUnique(LIST *A, char elem)
{
    if (A->count < MAX)
    {
        int i;
        for (i = 0; i < A->count && A->elemPtr[i] != elem; i++)
        {
        }
        if (!(i < A->count))
        {
            for (i = A->count; i > 0; i--)
            {
                A->elemPtr[i] = A->elemPtr[i - 1];
            }
            A->elemPtr[0] = elem;
            A->count++;
        }
    }
}

void insertLastUnique(LIST *A, char elem)
{
    if (A->count < MAX)
    {
        int i;
        for (i = 0; i < A->count && A->elemPtr[i] != elem; i++)
        {
        }
        if (!(i < A->count))
        {
            A->elemPtr[A->count] = elem;
            A->count++;
        }
    }
}

void deleteFirst(LIST *A)
{
    if (A->count > 0)
    {
        int i;
        for (i = 0; i < A->count; i++)
        {
            A->elemPtr[i] = A->elemPtr[i + 1];
        }
        A->count--;
    }
}

void deleteLast(LIST *A)
{
    if (A->count > 0)
    {
        A->count--;
    }
}

void deleteElem(LIST *A, char elem)
{
    if (A->count > 0)
    {
        int i;
        for (i = 0; i < A->count && A->elemPtr[i] != elem; i++)
        {
        }
        if (i < A->count)
        {
            for (; i < A->count; i++)
            {
                A->elemPtr[i] = A->elemPtr[i + 1];
            }
            A->count--;
        }
    }
}

void deleteAllOccurrences(LIST *A, char elem)
{
    if (A->count > 0)
    {
        int i, j;
        for (i = 0; i < A->count; i++)
        {
            if (A->elemPtr[i] == elem)
            {
                for (j = i; j < A->count; j++)
                {
                    A->elemPtr[j] = A->elemPtr[j + 1];
                }
                A->count--;
                i--;
            }
        }
    }
}