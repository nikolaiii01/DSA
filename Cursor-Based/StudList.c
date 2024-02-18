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
    Studtype student;
    int link;
} StudNode;

typedef int StudList;

typedef struct {
    StudNode studRecords[MAX];
    int avail;
} VirtualHeap;

void initVirtualHeap(VirtualHeap *VH);
void initList(StudList *A);
int allocSpace(VirtualHeap *VH);
void deallocSpace(int ndx, VirtualHeap *VH);
void displayVirtualHeap(VirtualHeap VH);
void displayList(VirtualHeap VH, StudList A);
void insertFirst(VirtualHeap *VH, StudList *A, Studtype stud);
void insertLast(VirtualHeap *VH, StudList *A, Studtype stud);
void insertAtPos(VirtualHeap *VH, StudList *A, Studtype stud, int pos);
void deleteStudByID(VirtualHeap *VH, StudList *A, int ID);
void deleteAllOccurrencesOfLName(VirtualHeap *VH, StudList *A, char LName[24]);

int main(){
    Studtype stud1;
    strcpy(stud1.name.FName, "Inie");
    stud1.name.MI = 'A';
    strcpy(stud1.name.LName, "Barriga");
    strcpy(stud1.course, "BSIT");
    stud1.ID = 21104226;
    stud1.yrLevel = 2;

    Studtype stud2;
    strcpy(stud2.name.FName, "Nikolai");
    stud2.name.MI = 'R';
    strcpy(stud2.name.LName, "Barriga");
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

    StudList L;
    VirtualHeap VHeap;

    initList(&L);
    initVirtualHeap(&VHeap);
    
    insertFirst(&VHeap, &L, stud1);
    insertLast(&VHeap, &L, stud3);
    insertLast(&VHeap, &L, stud2);

    deleteAllOccurrencesOfLName(&VHeap, &L, "Barriga");
    insertFirst(&VHeap, &L, stud1);
    displayVirtualHeap(VHeap);
    // displayList(VHeap, L);
    return 0;
}

void initVirtualHeap(VirtualHeap *VH){
    int i;
    for(i = MAX-1; i > -1; --i){
        VH->studRecords[i].link = i-1;
    }
    VH->avail = MAX-1;
}

void initList(StudList *A){
    *A = -1;
}

int allocSpace(VirtualHeap *VH){
    StudList ret = VH->avail;
    if(ret != -1){
        VH->avail = VH->studRecords[ret].link;
    }
    return ret;
}

void deallocSpace(int ndx, VirtualHeap *VH){
    if(ndx > -1 && ndx < MAX){
        VH->studRecords[ndx].link = VH->avail;
        VH->avail = ndx;
    }
}

void displayVirtualHeap(VirtualHeap VH){
    int i;
    for(i = 0; i < MAX; i++){
        printf("[%d] %d %s %c %s %s %d \tLink: [%d]\n", i, VH.studRecords[i].student.ID, 
        VH.studRecords[i].student.name.FName, VH.studRecords[i].student.name.MI, 
        VH.studRecords[i].student.name.LName, VH.studRecords[i].student.course, 
        VH.studRecords[i].student.yrLevel, VH.studRecords[i].link);
    }
}

void displayList(VirtualHeap VH, StudList A){
    int i;
    StudList trav;
    for(trav = A, i = 0; trav != -1; trav = VH.studRecords[trav].link, i++){
        printf("[%d] %d %s %c %s %s %d \tLink: [%d]\n", i, VH.studRecords[trav].student.ID, 
        VH.studRecords[trav].student.name.FName, VH.studRecords[trav].student.name.MI, 
        VH.studRecords[trav].student.name.LName, VH.studRecords[trav].student.course, 
        VH.studRecords[trav].student.yrLevel, VH.studRecords[trav].link);
    }
}

void insertFirst(VirtualHeap *VH, StudList *A, Studtype stud){
    StudList temp;
    temp = allocSpace(VH);
    if(temp != -1){
        VH->studRecords[temp].student = stud;
        VH->studRecords[temp].link = *A;
        *A = temp;
    }
}

void insertLast(VirtualHeap *VH, StudList *A, Studtype stud){
    StudList *trav, temp;
    for(trav = A; *trav != -1; trav = &VH->studRecords[*trav].link){}
    temp = allocSpace(VH);
    if(temp != -1){
        VH->studRecords[temp].student = stud;
        VH->studRecords[temp].link = -1;
        *trav = temp;
    }
}

void insertAtPos(VirtualHeap *VH, StudList *A, Studtype stud, int pos){
    StudList *trav, temp;
    int count;
    for(trav = A, count = 1; *trav != -1 && count < pos; trav = &VH->studRecords[*trav].link, count++){}
    if(pos >= 1 && pos <= count){
        temp = allocSpace(VH);
        if(temp != -1){
            VH->studRecords[temp].student = stud;
            VH->studRecords[temp].link = *trav;
            *trav = temp;
        }
    }
}

void deleteStudByID(VirtualHeap *VH, StudList *A, int ID){
    StudList *trav, temp;
    for(trav = A; *trav != -1 && VH->studRecords[*trav].student.ID != ID; trav = &VH->studRecords[*trav].link){}
    if(*trav != -1){
        temp = *trav;
        *trav = VH->studRecords[temp].link;
        deallocSpace(temp, VH);
    }
}

void deleteAllOccurrencesOfLName(VirtualHeap *VH, StudList *A, char LName[24]){
    StudList *trav = A, temp;
    while(*trav != -1){
        if(strcmp(VH->studRecords[*trav].student.name.LName, LName) == 0){
            temp = *trav;
            *trav = VH->studRecords[temp].link;
            deallocSpace(temp, VH);
        } else {
            trav = &VH->studRecords[*trav].link;
        }
    }
}