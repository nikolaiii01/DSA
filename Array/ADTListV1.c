// ADT Linked List Version 1
#include <stdio.h>

#define MAX 10
typedef struct
{
    char Elem[MAX];
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

    insertFirst(&L, 'G');
    insertFirst(&L, 'F');
    insertFirst(&L, 'A');

    deleteLast(&L);

    displayList(L);
    return 0;
}

void initList(LIST *A)
{
    A->count = 0;
}

void displayList(LIST A)
{
    int i;
    for (i = 0; i < A.count; i++)
    {
        printf("[%d]: %c\n", i, A.Elem[i]);
    }
}

void insertFirst(LIST *A, char elem)
{
    if (A->count < MAX)
    {
        int i;
        for (i = A->count; i > 0; i--)
        {
            A->Elem[i] = A->Elem[i - 1];
        }
        A->Elem[0] = elem;
        A->count++;
    }
}

void insertLast(LIST *A, char elem)
{
    if (A->count < MAX)
    {
        A->Elem[A->count] = elem;
        A->count++;
    }
}

void insertSorted(LIST *A, char elem)
{
    if (A->count < MAX)
    {
        int i;
        for (i = 0; i < A->count && A->Elem[i] < elem; i++)
        {
        }
        if (i < A->count)
        {
            int j;
            for (j = A->count; j > i; j--)
            {
                A->Elem[j] = A->Elem[j - 1];
            }
        }
        A->Elem[i] = elem;
        A->count++;
    }
}

void insertFirstUnique(LIST *A, char elem)
{
    if (A->count < MAX)
    {
        int i;
        for (i = 0; i < A->count - 1 && A->Elem[i] != elem; i++)
        {
        }
        if (!(i < A->count - 1))
        {
            for (i = A->count; i > 0; i--)
            {
                A->Elem[i] = A->Elem[i - 1];
            }
            A->Elem[0] = elem;
            A->count++;
        }
    }
}

void insertLastUnique(LIST *A, char elem)
{
    if (A->count < MAX)
    {
        int i;
        for (i = 0; i < A->count - 1 && A->Elem[i] != elem; i++)
        {
        }
        if (!(i < A->count))
        {
            A->Elem[i] = elem;
            A->count++;
        }
    }
}

void deleteFirst(LIST *A)
{
    if (A->count > 0)
    {
        int i;
        for (i = 0; i < A->count - 1; i++)
        {
            A->Elem[i] = A->Elem[i + 1];
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
        for (i = 0; i < A->count && A->Elem[i] != elem; i++)
        {
        }
        if (i < A->count)
        {
            for (; i < A->count; i++)
            {
                A->Elem[i] = A->Elem[i + 1];
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
        for (i = 0; i < A->count - 1; i++)
        {
            if (A->Elem[i] == elem)
            {
                for (j = i; j < A->count - 1; j++)
                {
                    A->Elem[j] = A->Elem[j + 1];
                }
                A->count--;
                i--;
            }
        }
    }
}
