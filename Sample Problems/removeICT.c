#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char FN[24], LN[16], MI;
}nametype;

typedef struct {
    char ID[10];
    nametype name;
    char course[8];
    int yrLevel;
}studRec;

#define LSIZE 50

typedef struct {
    nametype names[LSIZE];
    int lastNdx;
}*NameList;

typedef struct node{
    studRec sElem;
    struct node *sLink;
}*LinkList;

void initLinkedList(LinkList *A);
NameList removeICT(LinkList *A);
void insertFirst(LinkList *A, studRec stud);
void displayLinkList(LinkList A);
void displayNameList(NameList A);

int main(){
    studRec stud1;
    strcpy(stud1.name.FN, "Inie");
    stud1.name.MI = 'A';
    strcpy(stud1.name.LN, "Sabado");
    strcpy(stud1.course, "BSIT");
    strcpy(stud1.ID, "STUD-001");
    stud1.yrLevel = 2;

    studRec stud2;
    strcpy(stud2.name.FN, "Horeb");
    stud2.name.MI = 'A';
    strcpy(stud2.name.LN, "Barriga");
    strcpy(stud2.course, "BSICT");
    strcpy(stud2.ID, "STUD-002");
    stud2.yrLevel = 3;

    studRec stud3;
    strcpy(stud3.name.FN, "Nikolai");
    stud3.name.MI = 'A';
    strcpy(stud3.name.LN, "Tumapon");
    strcpy(stud3.course, "BSICT");
    strcpy(stud3.ID, "STUD-003");
    stud3.yrLevel = 4;

    LinkList studList;
    initLinkedList(&studList);
    insertFirst(&studList, stud1);
    insertFirst(&studList, stud2);
    insertFirst(&studList, stud3);

    NameList BSICTList = removeICT(&studList);
    displayLinkList(studList);
    displayNameList(BSICTList);

    return 0;
}

void displayLinkList(LinkList A){
    LinkList trav;
    for(trav = A; trav != NULL; trav = trav->sLink){
        printf("Name: %s Course: %s\n", trav->sElem.name.LN, trav->sElem.course);
    }
}

void displayNameList(NameList A){
    int i;
    for(i = 0; i <= A->lastNdx; i++){
        printf("Name: %s\n", A->names[i].LN);
    }
}

void initLinkedList(LinkList *A){
    *A = NULL;
}

void insertFirst(LinkList *A, studRec stud){
    LinkList temp;
    temp = (LinkList)malloc(sizeof(studRec) + sizeof(struct node*));
    if(temp != NULL){
        temp->sElem = stud;
        temp->sLink = *A;
        *A = temp;
    }
}

NameList removeICT(LinkList *A){
    NameList ret = (NameList)malloc((sizeof(nametype)*LSIZE) + sizeof(int));
    if(ret != NULL){
        LinkList *trav, temp;
        int i, j;
        ret->lastNdx = -1;
        trav = A;
        while(*trav != NULL){
            if(strcmp((*trav)->sElem.course, "BSICT") == 0){
                if(ret->lastNdx != LSIZE-1){
                    for(i = 0; i <= ret->lastNdx && strcmp(ret->names[i].LN, (*trav)->sElem.name.LN) < 0 ; i++){}
                    for(j = ret->lastNdx + 1; j > i; j--){
                        ret->names[j] = ret->names[j-1];
                    }
                    ret->names[i] = (*trav)->sElem.name;
                    ret->lastNdx++;
                }
                temp = *trav;
                *trav = temp->sLink;
                free(temp);
            } else {
                trav = &(*trav)->sLink;
            }
        }
    }
    return ret;
}