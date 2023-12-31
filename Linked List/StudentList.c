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
} *StudList;

void displayStudList(StudList List);
void insertFirstUnique(Studrec student, StudList *List);
Studrec deleteStudRecordByIDPPN(int ID, StudList *List); //Pointer to pointer to node method
Studrec deleteStudRecordByIDPN(int ID, StudList *List); //Pointer to node method
Studrec deleteStudRecordByIDTP(int ID, StudList *List); //Trailing Pointers method

int main(){
    StudList List = NULL;
    Studrec student1, student2, student3, deleted;
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

    student3.ID = 103;
    strcpy(student3.LN, "Tuma");
    strcpy(student3.FN, "Nikolai Franz");
    student3.MI = 'R';
    strcpy(student3.course, "BSIT");
    student3.yearLevel = 1;

    insertFirstUnique(student1, &List);
    insertFirstUnique(student2, &List);
    insertFirstUnique(student3, &List);

    deleted = deleteStudRecordByIDTP(101, &List);

    printf("-------DELETED-------");
    printf("\nID: %d\n", deleted.ID);
    printf("First Name: %s\n", deleted.FN);
    printf("Last Name: %s\n", deleted.LN);
    printf("Middle Initial: %c\n", deleted.MI);
    printf("Course: %s\n", deleted.course);
    printf("Year Level: %d\n", deleted.yearLevel);

    displayStudList(List);
    return 0;
}

void displayStudList(StudList A){
    StudList trav = A;
    printf("\n-------STUDENT RECORD LIST-------");
    for(trav = A; trav != NULL; trav = trav->link){
        printf("\nID: %d\n", trav->stud.ID);
        printf("First Name: %s\n", trav->stud.FN);
        printf("Last Name: %s\n", trav->stud.LN);
        printf("Middle Initial: %c\n", trav->stud.MI);
        printf("Course: %s\n", trav->stud.course);
        printf("Year Level: %d\n", trav->stud.yearLevel);
    }
}

void insertFirstUnique(Studrec newStud, StudList *A){
    StudList *trav = A;
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

Studrec deleteStudRecordByIDPPN(int ID, StudList *A){
    StudList *trav = A;
    Studrec ret = {0, "XXXXX", "XXXXX", 'X', "XXXXX", 0};
    struct node *temp;
    for(trav = A; *trav != NULL && (*trav)->stud.ID != ID; trav = &(*trav)->link){} //traverse linked list and check if ID to be deleted exists
    if(*trav != NULL){ //if ID exists, delete node
        ret = (*trav)->stud; //copy student record
        temp = *trav; //copy node
        *trav = (*trav)->link; //link previous node to the next node
        free(temp); //free node
    }
    return ret;
}

Studrec deleteStudRecordByIDPN(int ID, StudList *A){
    Studrec ret = {0, "XXXXX", "XXXXX", 'X', "XXXXX", 0};
    if(*A != NULL){
        if((*A)->stud.ID == ID){
            StudList temp = *A;
            ret = temp->stud;
            *A = temp->link;
            free(temp);
        } else {
            StudList trav = *A;
            for(trav = *A; trav->link != NULL && trav->link->stud.ID != ID; trav = trav->link){}
            if(trav->link != NULL){
                StudList temp = trav->link;
                ret = temp->stud;
                trav->link = temp->link;
                free(temp);
            }
        }
    }
    return ret;
}

Studrec deleteStudRecordByIDTP(int ID, StudList *A){
    Studrec ret = {0, "XXXXX", "XXXXX", 'X', "XXXXX", 0};
    if(*A != NULL){
        if((*A)->stud.ID == ID){
            StudList temp = *A;
            ret = temp->stud;
            *A = temp->link;
            free(temp);
        } else {
            StudList prev = *A;
            StudList curr = (*A)->link;
            for(; curr != NULL && curr->stud.ID != ID; prev = curr, curr = curr->link){}
            if(curr != NULL){
                StudList temp = curr;
                ret = temp->stud;
                prev->link = curr->link;
                free(temp);
            }
        }
    }
    return ret;
}