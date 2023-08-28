#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ID;
    char LN[16], FN[24], MI;
    char course[8];
    int yearLevel;
} Studrec;

typedef struct node {
    Studrec stud;
    struct node *link;
} *Studlist;

void displayStudList(Studlist List);
void insertFirstUnique(Studrec student, Studlist *List);
Studrec deleteStudRecordByID(int ID, Studlist *List);

int main(){
    Studlist List = NULL;
    Studrec student1, student2, deleted;
    student1.ID = 101;
    strcpy(student1.LN, "Tumapon");
    strcpy(student1.FN, "Nikolai Franz");
    student1.MI = 'R';
    strcpy(student1.course, "BSIT");
    student1.yearLevel = 1;

    student2.ID = 102;
    strcpy(student2.LN, "Tumapon");
    strcpy(student2.FN, "Nikolai Franz");
    student2.MI = 'R';
    strcpy(student2.course, "BSIT");
    student2.yearLevel = 1;

    insertFirstUnique(student1, &List);
    insertFirstUnique(student2, &List);
    deleted = deleteStudRecordByID(103, &List);
    printf("DELETED");
    printf("\nID: %d\n", deleted.ID);
    printf("First Name: %s\n", deleted.FN);
    printf("Last Name: %s\n", deleted.LN);
    printf("Middle Initial: %c\n", deleted.MI);
    printf("Course: %s\n", deleted.course);
    printf("Year Level: %d\n", deleted.yearLevel);
    displayStudList(List);
    return 0;
}

void displayStudList(Studlist A){
    Studlist trav = A;
    for(trav = A; trav != NULL; trav = trav->link){
        printf("\nID: %d\n", trav->stud.ID);
        printf("First Name: %s\n", trav->stud.FN);
        printf("Last Name: %s\n", trav->stud.LN);
        printf("Middle Initial: %c\n", trav->stud.MI);
        printf("Course: %s\n", trav->stud.course);
        printf("Year Level: %d\n", trav->stud.yearLevel);
    }
}

void insertFirstUnique(Studrec newStud, Studlist *A){
    Studlist *trav = A;
    struct node *temp;
    for(trav = A; *trav != NULL && (*trav)->stud.ID != newStud.ID; trav = &(*trav)->link){} //traverse linked list and check if ID already exists
    if(*trav == NULL){ //if ID does not exist, insert new node
        temp = (struct node *)malloc(sizeof(struct node)); //create new node
        if(temp != NULL){ //check if node was created
            temp->stud = newStud; //insert new student record
            temp->link = *A; //link new node to the previous first node
            *A = temp; //set new node as the first node
        }
    }
}

Studrec deleteStudRecordByID(int ID, Studlist *A){
    Studlist *trav = A;
    Studrec ret;
    struct node *temp;
    for(trav = A; *trav != NULL && (*trav)->stud.ID != ID; trav = &(*trav)->link){}
    if(trav == NULL){
        ret = (*trav)->stud;
        temp = *trav;
        *trav = (*trav)->link;
        free(temp);
    } else {
        ret.ID = 0;
        strcpy(ret.FN, "XXXXX");
        strcpy(ret.LN, "XXXXX");
        ret.MI = 'X';
        strcpy(ret.course, "XXXXX");
        ret.yearLevel = 0;
    }
    return ret;
}
