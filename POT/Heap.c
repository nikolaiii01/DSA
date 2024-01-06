#define MAX 10

typedef struct
{
    int Elem[MAX];
    int lastNdx;
} Heap, *ListHeap;

void insert(Heap *H, int elem)
{
    int indx, ParNdx;
    if (H->lastNdx < MAX - 1)
    {
        ++H->lastNdx;
        indx = H->lastNdx;
        ParNdx = (indx - 1) / 2;

        while (indx > 0 && H->Elem[ParNdx] > elem)
        {
            H->Elem[indx] = H->Elem[ParNdx];
            indx = ParNdx;
            ParNdx = (indx - 1) / 2;
        }
        H->Elem[indx] = elem;
    }
}

void insert(Heap *H, int elem)
{
    int indx, ParNdx;
    if (H->lastNdx < MAX - 1)
    {
        ++H->lastNdx;
        indx = H->lastNdx;
        ParNdx = (indx - 1) / 2;

        while (indx > 0 && H->Elem[ParNdx] > elem)
        {
            H->Elem[indx] = H->Elem[ParNdx];
            indx = ParNdx;
            ParNdx = (indx - 1) / 2;
        }
        H->Elem[indx] = elem;
    }
}

int deleteMin(ListHeap *L)
{
    int ret = -1, trav, child, swap;
    if (L->lastNdx != -1)
    {
        ret = L->Elem[0];
        L->elem[0] = L->elem[L->lastNdx];
        --L->lastNdx;
        trav = 0;
        child = 1;
        while (child <= L->lastNdx)
        {
            if (child <= L->lastNdx && L->elem[child] < L->elem[child])
            {
                child++;
            }
            if (H->elem[trav] > H->elem[child])
            {
                swap = H->elem[trav];
                H->elem[trav] = H->elem[child];
                H->elem[child] = swap;
                trav = child;
                child = trav * 2 + 1;
            }
            else
            {
                break;
            }
        }
    }
    return ret;
}

int deleteMin(ListHeap *L)
{
    int ret = -1, trav, child, swap;
    if (L->lastNdx != -1)
    {
        ret = L->Elem[0];
        L->elem[0] = L->elem[L->lastNdx];
        --L->lastNdx;
        trav = 0;
        child = 1;
        while (child <= L->lastNdx)
        {
            if (child <= L->lastNdx && L->elem[child] < L->elem[child])
            {
                child++;
            }
            if (H->elem[trav] > H->elem[child])
            {
                swap = H->elem[trav];
                H->elem[trav] = H->elem[child];
                H->elem[child] = swap;
                trav = child;
                child = trav * 2 + 1;
            }
            else
            {
                break;
            }
        }
    }
    return ret;
}