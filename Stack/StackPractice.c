#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int Elem[MAX];
    int top;
} Stack;

void initializeStack(Stack *S);
void push(Stack *S, int elem);
void pop(Stack *S);
int top(Stack S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void display(Stack *S);

int main(){
    Stack S;

    initializeStack(&S);
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    printf("Top: %d\n", top(S));
    printf("Is Empty? ");
    if(isEmpty(S)){
        printf("Yes\n");
    } else {
        printf("Nope\n");
    }

    printf("Is Full? ");
    if(isFull(S)){
        printf("Yes\n");
    } else {
        printf("Nope\n");
    }

    display(&S);
    
    return 0;
}

void initializeStack(Stack *S){
    S->top = MAX;
}

void push(Stack *S, int elem){
    S->Elem[--S->top] = elem;
}

void pop(Stack *S){
    S->top++;
}

int top(Stack S){
    return S.Elem[S.top];
}

bool isEmpty(Stack S){
    return (S.top == MAX) ? true : false;
}

bool isFull(Stack S){
    return (S.top == 0) ? true : false;
}

void display(Stack *S){
    printf("Display Stack: ");
    Stack temp;
    initializeStack(&temp);
    while(S->top != MAX){
        printf("%d ", S->Elem[S->top]);
        push(&temp, S->Elem[S->top]);
        pop(S);
    }
    while(temp.top != MAX){
        push(S, temp.Elem[temp.top]);
        pop(&temp);
    }
}