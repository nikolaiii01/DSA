#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef enum {FALSE, TRUE} Boolean;

typedef struct {
    char FName[16];
    char MI;
    char LName[24];
} nametype;

typedef struct {
    nametype name;
    int ID;
    char course[8];
    int yrLevel;
} Studtype;

typedef struct {
    Studtype studentList[MAX];
    int top;
} Stack;

void initStack(Stack *S);
void push(Stack *S, Studtype stud);
void pop(Stack *S);
Studtype top(Stack S);
void displayStack(Stack S);
Boolean isEmpty(Stack S);
Boolean isFull(Stack S);
void makeNull(Stack *S);
void insertBottom(Stack *S, Studtype stud);

int main(){
    Stack studList;
    initStack(&studList);

    Studtype stud1;
    strcpy(stud1.name.FName, "Inie");
    stud1.name.MI = 'A';
    strcpy(stud1.name.LName, "Sabado");
    strcpy(stud1.course, "BSIT");
    stud1.ID = 21104226;
    stud1.yrLevel = 2;

    Studtype stud2;
    strcpy(stud2.name.FName, "Nikolai");
    stud2.name.MI = 'R';
    strcpy(stud2.name.LName, "Tumapon");
    strcpy(stud2.course, "BSIT");
    stud2.ID = 18104226;
    stud2.yrLevel = 3;

    Studtype stud3;
    strcpy(stud3.name.FName, "Horeb");
    stud3.name.MI = 'M';
    strcpy(stud3.name.LName, "Barriga");
    strcpy(stud3.course, "BSCS");
    stud3.ID = 20102002;
    stud3.yrLevel = 4;

    push(&studList, stud1);
    push(&studList, stud2);
    insertBottom(&studList, stud3);
    displayStack(studList);

    return 0;
}

void initStack(Stack *S){
    S->top = MAX;
}

void push(Stack *S, Studtype stud){
    if(S->top != 0){
        S->studentList[--(S->top)] = stud;
    }
}

void pop(Stack *S){
    if(S->top != MAX){
        S->top++;
    }
}

Studtype top(Stack S){
    return S.studentList[S.top];
}

void displayStack(Stack S){
    Stack temp;
    initStack(&temp);
    int i;
    for(i = S.top; i < MAX; i++){
        printf("%s\n", S.studentList[S.top].name.LName);
        push(&temp, S.studentList[S.top]);
        pop(&S);
    }
}

Boolean isEmpty(Stack S){
    return (S.top == MAX) ? TRUE : FALSE; 
}

Boolean isFull(Stack S){
    return (S.top == 0) ? TRUE : FALSE;
}

void insertBottom(Stack *S, Studtype stud){
    Stack temp;
    initStack(&temp);
    int i;
    for(i = S->top; i < MAX; i++){
        push(&temp, S->studentList[S->top]);
        pop(S);
    }
    push(S, stud);
    for(i = temp.top; i < MAX; i++){
        push(S, temp.studentList[temp.top]);
        pop(&temp);
    }
}