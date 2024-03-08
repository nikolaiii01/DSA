#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char LName[16], FName[24], MI;
}nametype;

typedef struct{
    nametype name;
    int ID;
    char course[8];
    int yrLevel;
}Studtype;

typedef struct node{
    Studtype stud;
    struct node* next;
}*LLStack;

void initStack(LLStack *S);
void displayStack(LLStack *S);
void push(LLStack *S, Studtype stud);
void pop(LLStack *S);
void insertBottom(LLStack *S, Studtype stud);
void pushUnique(LLStack *S, Studtype stud);

int main(){
    LLStack StudStack;
    initStack(&StudStack);

    Studtype stud1;
    strcpy(stud1.name.FName, "Inie");
    stud1.name.MI = 'A';
    strcpy(stud1.name.LName, "Sabado");
    strcpy(stud1.course, "BSIT");
    stud1.ID = 17104226;
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

    push(&StudStack, stud1);
    push(&StudStack, stud2);
    pushUnique(&StudStack, stud3);
    displayStack(&StudStack);

    return 0;
}

void initStack(LLStack *S){
    *S = NULL;
}

void displayStack(LLStack *S){
    LLStack tempS;
    tempS = NULL;
    printf("FN\tLN\tMI\tID\n");
    while(*S != NULL){
        printf("%s\t%s\t%c\t%d\n", (*S)->stud.name.FName, (*S)->stud.name.LName, (*S)->stud.name.MI, (*S)->stud.ID);
        push(&tempS, (*S)->stud);
        pop(S);
    }
    while(tempS != NULL){
        push(S, tempS->stud);
        pop(&tempS);
    }
}

void push(LLStack *S, Studtype stud){
    LLStack temp = (LLStack)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->stud = stud;
        temp->next = *S;
        *S = temp;
    }
}

void pop(LLStack *S){
    LLStack temp;
    if(*S != NULL){
        temp = *S;
        *S = temp->next;
        free(temp);
    }
}

void insertBottom(LLStack *S, Studtype stud){
    LLStack tempS = NULL, temp;
    while(*S != NULL){
        push(&tempS, (*S)->stud);
        pop(S);
    }
    temp = (LLStack)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->stud = stud;
        temp->next = NULL;
        *S = temp;
    }
    while(tempS != NULL){
        push(S, tempS->stud);
        pop(&tempS);
    }
}

void pushUnique(LLStack *S, Studtype stud){
    LLStack tempS = NULL, temp;
    int flag = 0;
    while(*S != NULL && flag == 0){
        if((*S)->stud.ID == stud.ID){
            flag = 1;
        }
        push(&tempS, (*S)->stud);
        pop(S);
    }
    while(tempS != NULL){
        push(S, tempS->stud);
        pop(&tempS);
    }
    if(flag != 1){
        temp = (LLStack)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->stud = stud;
            temp->next = *S;
            *S = temp;
        }
    }
}