#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 10

// Bit-Vector Implementation
typedef int SET[MAX];

SET U = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void Initialize(SET *A);
SET *Union(SET A, SET B);
SET *Intersection(SET A, SET B);
SET *Difference(SET A, SET B);
void Display(SET *A);
bool Member(SET *A, int num);
void Insert(SET *A, int num);
void Delete(SET *A, int num);

int main()
{
    SET A, B;

    Initialize(&A);
    Initialize(&B);

    Insert(&A, 1);
    Insert(&A, 2);
    Insert(&A, 3);
    Insert(&B, 2);
    Insert(&B, 4);
    Insert(&B, 6);

    printf("SET A");
    Display(&A);
    printf("\nSET B");
    Display(&B);

    bool isMember = Member(&B, 9);
    printf("\n");
    (isMember == true) ? printf("true") : printf("false");

    SET *C = Difference(A, B);
    printf("\nSET C");
    Display(C);

    return 0;
}

void Initialize(SET *A)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        (*A)[i] = 0;
    }
}

SET *Union(SET A, SET B)
{
    SET *ret = (SET *)malloc(sizeof(int) * MAX);
    int i;
    for (i = 0; i < MAX; i++)
    {
        (*ret)[i] = A[i] || B[i];
    }
    return ret;
}

SET *Intersection(SET A, SET B)
{
    SET *ret = (SET *)malloc(sizeof(int) * MAX);
    int i;
    for (i = 0; i < MAX; i++)
    {
        (*ret)[i] = A[i] && B[i];
    }
    return ret;
}

SET *Difference(SET A, SET B)
{
    SET *ret = (SET *)malloc(sizeof(int) * MAX);
    int i;
    for (i = 0; i < MAX; i++)
    {
        (*ret)[i] = (A[i] && B[i]) ? 0 : A[i];
    }
    return ret;
}

void Display(SET *A)
{
    int i;
    printf("\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", (*A)[i]);
    }
}

bool Member(SET *A, int num)
{
    return ((*A)[num] == 1) ? true : false;
}

void Insert(SET *A, int num)
{
    (*A)[num] = 1;
}

void Delete(SET *A, int num)
{
    (*A)[num] = 0;
}