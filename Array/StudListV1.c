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

typedef struct {
    Studtype studentList[MAX];
    int count;
} StudList;

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
void deleteAllOccurrencesOfID(StudList *A, char course[8]);

int main(){
    StudList L;
    initList(&L);

    Studtype stud1;
    strcpy(stud1.name.FName, "Nikolai");
    stud1.name.MI = 'R';
    strcpy(stud1.name.LName, "Tumapon");
    strcpy(stud1.course, "BSIT");
    stud1.ID = 21104226;
    stud1.yrLevel = 2;

    Studtype stud2;
    strcpy(stud2.name.FName, "Nikolai");
    stud2.name.MI = 'R';
    strcpy(stud2.name.LName, "Tumapon");
    strcpy(stud2.course, "BSIT");
    stud2.ID = 17102227;
    stud2.yrLevel = 1;

    Studtype stud3;
    strcpy(stud3.name.FName, "Nikolai");
    stud3.name.MI = 'R';
    strcpy(stud3.name.LName, "Tumapon");
    strcpy(stud3.course, "BSCS");
    stud3.ID = 20102002;
    stud3.yrLevel = 4;

    insertFirst(&L, stud1);
    insertLast(&L, stud2);
    insertLastUnique(&L, stud3);

    deleteAllOccurrencesOfCourse(&L, "BSIT");

    displayList(L);

    return 0;
}

void initList(StudList *A){
    A->count = 0;
}

void displayList(StudList A){
    int i;
    printf("Number of Students: %d\n", A.count);
    for(i = 0; i < A.count; i++){
        printf("[%d] %d %s %c %s %s %d\n", i, A.studentList[i].ID, 
        A.studentList[i].name.FName, A.studentList[i].name.MI, 
        A.studentList[i].name.LName, A.studentList[i].course, 
        A.studentList[i].yrLevel);
    }
}

void insertFirst(StudList *A, Studtype stud){
    if(A->count < MAX){
        int i;
        for(i = A->count; i > 0; i--){
            A->studentList[i] = A->studentList[i-1];
        }
        A->studentList[0] = stud;
        A->count++;
    }
}

void insertLast(StudList *A, Studtype stud){
    if(A->count < MAX){
        A->studentList[A->count++] = stud;
    }
}

void insertSorted(StudList *A, Studtype stud){
    if(A->count < MAX){
        int i, j;
        for(i = 0; i < A->count && A->studentList[i].ID < stud.ID; i++){}
        if(i < A->count){
            for(j = A->count; j > i; j--){
                A->studentList[j] = A->studentList[j - 1];
            }
        }
        A->studentList[i] = stud;
        A->count++;
    }
}

void insertFirstUnique(StudList *A, Studtype stud){
    if(A->count < MAX){
        int i;
        for(i = 0; i < A->count && A->studentList[i].ID != stud.ID; i++){}
        if(!(i < A->count)){
            for(i = A->count; i > 0; i--){
                A->studentList[i] = A->studentList[i-1];
            }
            A->studentList[0] = stud;
            A->count++;
        }
    }
}

void insertLastUnique(StudList *A, Studtype stud){
    if(A->count < MAX){
        int i;
        for(i = 0; i < A->count && A->studentList[i].ID != stud.ID; i++){}
        if(!(i < A->count)){
            A->studentList[A->count++] = stud; 
        }
    }
}

void deleteFirst(StudList *A){
    if(A->count > 0){
        int i;
        for(i = 0; i < A->count; i++){
            A->studentList[i] = A->studentList[i + 1];
        }
        A->count--;
    }
}

void deleteLast(StudList *A){
    if(A->count > 0){
        A->count--;
    }
}

void deleteStudByID(StudList *A, int ID){
    int i;
    for(i = 0; i < A->count && A->studentList[i].ID != ID; i++){}
    if(i < A->count){
        for(; i < A->count; i++){
            A->studentList[i] = A->studentList[i + 1];
        }
        A->count--;
    }
}

void deleteAllOccurrencesOfCourse(StudList *A, char course[8]){
    if(A->count > 0){
        int i, j;
        for(i = 0; i < A->count; i++){
            if(strcmp(A->studentList[i].course, course) == 0){
                for(j = i; j < A->count; j++){
                    A->studentList[j] = A->studentList[j + 1];
                }
                A->count--;
                i--;
            }
        }
    }
}