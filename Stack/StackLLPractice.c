#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} *Stack;

void initializeStack(Stack *S);
void push(Stack *S, int elem);
void pop(Stack *S);
int top(Stack S);
bool isEmpty(Stack S);
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

    display(&S);

    return 0;
}

void initializeStack(Stack *S){
    (*S) = NULL;
}

void push(Stack *S, int elem){
    Stack temp = (Stack)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = elem;
        temp->link = *S;
        *S = temp;
    }
}

void pop(Stack *S){
    Stack temp = *S;
    if(temp != NULL){
        *S = temp->link;
        free(temp);
    }
}

int top(Stack S){
    return (S != NULL) ? S->data : -1;
}

bool isEmpty(Stack S){
    return (S != NULL) ? false : true;
}

void display(Stack *S){
    Stack tempLL;
    initializeStack(&tempLL);
    while(top(*S) != -1){
        printf("%d ", top(*S));
        push(&tempLL, top(S));
        pop(S);
    }
    while(top(tempLL) != -1){
        push(S, top(tempLL));
        pop(&tempLL);
    }
}
