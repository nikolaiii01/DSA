#include <stdio.h>

#define MAX 10

typedef struct
{
    int elem[MAX];
    int count;
} LIST;

void initList(LIST *A);
void displayList(LIST A);
void insertLast(LIST *A, int elem);
LIST getEven(LIST A);

int main()
{
    LIST L;
    initList(&L);

    insertLast(&L, 1);
    insertLast(&L, 2);
    insertLast(&L, 3);
    insertLast(&L, 4);
    insertLast(&L, 5);
    insertLast(&L, 6);

    displayList(L);

    LIST evenArr = getEven(L);

    displayList(evenArr);

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
        printf("[%d]: %d\n", i, A.elem[i]);
    }
}

void insertLast(LIST *A, int elem)
{
    if (A->count < MAX)
    {
        A->elem[A->count] = elem;
        A->count++;
    }
}

LIST getEven(LIST A)
{
    LIST ret;
    int i, j = 0;
    for (i = 0; i < A.count; i++)
    {
        if (A.elem[i] % 2 == 0)
        {
            ret.elem[j++] = A.elem[i];
            ret.count++;
        }
    }
    return ret;
}
