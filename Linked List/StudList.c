#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

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

typedef struct node {
    Studtype student;
    struct node *next;
} *StudList;

void initList(StudList *A);
void displayList(StudList A);
void insertFirst(StudList *A, Studtype stud);
void insertLast(StudList *A, Studtype stud);
void insertSorted(StudList *A, Studtype stud);
void insertFirstUnique(StudList *A, Studtype stud);
void insertLastUnique(StudList *A, Studtype stud);
void deleteFirst(StudList *A);
void deleteLast(StudList *A);
void deleteStudByID(StudList *A, int ID);
void deleteAllOccurrencesOfID(StudList *A, int ID);

int main(){
    StudList L;
    initList(&L);

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

    insertFirst(&L, stud1);
    insertFirst(&L, stud1);
    insertFirst(&L, stud1);
    // insertFirst(&L, stud3);
    // insertSorted(&L, stud2);
    insertLastUnique(&L, stud3);
    // deleteStudByID(&L, 21104226);
    // insertLast(&L, stud2);

    deleteAllOccurrencesOfID(&L, 21104226);

    displayList(L);

    return 0;
}

void initList(StudList *A){
    *A = NULL;
}

void displayList(StudList A){
    int i;
    StudList trav;
    for(trav = A, i = 0; trav != NULL; trav = trav->next, i++){
        printf("[%d] %d %s %c %s %s %d\n", i, trav->student.ID, 
        trav->student.name.FName, trav->student.name.MI, 
        trav->student.name.LName, trav->student.course, 
        trav->student.yrLevel);
    }
}

void insertFirst(StudList *A, Studtype stud){
    StudList temp;
    temp = (StudList)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->student = stud;
        temp->next = *A;
        *A = temp;
    }
}

void insertLast(StudList *A, Studtype stud){
    StudList *trav, temp;
    for(trav = A; *trav != NULL; trav = &(*trav)->next){}
    temp = (StudList)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->student = stud;
        temp->next = NULL;
        *trav = temp;
    }
}

void insertSorted(StudList *A, Studtype stud){
    StudList *trav, temp;
    for(trav = A; *trav != NULL && (*trav)->student.ID < stud.ID; trav = &(*trav)->next){}
    temp = (StudList)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->student = stud;
        temp->next = *trav;
        *trav = temp;
    }
}

void insertFirstUnique(StudList *A, Studtype stud){
    StudList *trav, temp;
    for(trav = A; *trav != NULL && (*trav)->student.ID != stud.ID; trav = &(*trav)->next){}
    if(*trav == NULL){
        temp = (StudList)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->student = stud;
            temp->next = *A;
            *A = temp;
        }
    }
}

void insertLastUnique(StudList *A, Studtype stud){
    StudList *trav, temp;
    for(trav = A; *trav != NULL && (*trav)->student.ID != stud.ID; trav = &(*trav)->next){}
    if(*trav == NULL){
        temp = (StudList)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->student = stud;
            temp->next = NULL;
            *trav = temp;
        }
    }
}

void deleteFirst(StudList *A){
    if(*A != NULL){
        StudList temp;
        temp = *A;
        *A = temp->next;
        free(temp);
    }
}

void deleteLast(StudList *A){
    if(*A != NULL){
        StudList *trav, temp;
        for(trav = A; (*trav)->next != NULL; trav = &(*trav)->next){}
        temp = *trav;
        *trav = NULL;
        free(temp);
    }
}

void deleteStudByID(StudList *A, int ID){
    StudList *trav, temp;
    for(trav = A; *trav != NULL && (*trav)->student.ID != ID; trav = &(*trav)->next){}
    if(*trav != NULL){
        temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

void deleteAllOccurrencesOfID(StudList *A, int ID){
    StudList *trav, temp;
    trav = A;
    while(*trav != NULL){
        if((*trav)->student.ID == ID){
            temp = *trav;
            *trav = temp->next;
            free(temp);
        } else {
            trav = &(*trav)->next;
        } 
    }
}