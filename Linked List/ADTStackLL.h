#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    char data;
    struct node *next;
} nodetype, *Stack;

void initialize(Stack *S);
void push(Stack *S, char elem);
void pop(Stack *S);
char top(Stack S);
bool empty(Stack S);
bool full(Stack S);
void makeNull(Stack *S);
void display(Stack *S);

void initialize(Stack *S) {
    *S = NULL;
}

void push(Stack *S, char elem){
    Stack temp = (Stack)malloc(sizeof(nodetype));
    if(temp != NULL){
        temp->data = elem;
        temp->next = *S;
        *S = temp;
    }
}

void pop(Stack *S){
    Stack temp;
    if(*S != NULL){
        temp = *S;
        *S = temp->next;
        free(temp);
    }
}

char top(Stack S){
    return (S != NULL) ? S->data : '\0';
}

bool empty(Stack S){
    return (S != NULL) ? false: true;
}

void makeNull(Stack *S){
    while(*S != NULL){
        pop(S);
    }
}

void display(Stack *S){
    Stack tempLL;
    initialize(&tempLL);
    Stack temp = (Stack)malloc(sizeof(nodetype));
    if(temp != NULL){
        while(top(*S) != '\0'){
            temp = *S;
            printf("%c ", temp->data);
            push(&tempLL, temp->data);
            pop(S);
        }
        while(top(tempLL) != '\0'){
            temp = tempLL;
            push(S, temp->data);
            pop(&tempLL);
        }
    }
}





