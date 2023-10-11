#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char FN[24];
    char MI;
    char LN[16];
}Nametype;

typedef struct {
    Nametype name;
    int ID;
    char course[8];
    int yrLevel;
}Studtype;

void displayHeader();
void displayStudent(Studtype S);
void readFile();

int main(){
    Studtype S;
    readFile();
    return 0;
}

void displayHeader(){
    printf("\n\n");
    printf("%-10s", "ID No.");
    printf("%-16s", "Lastname");
    printf("%-24s", "Firstname");
    printf("%-3s", "MI");
    printf("%-8s", "Course");
    printf("%5s", "Year");
    printf("\n");
    printf("%-10s", "======");
    printf("%-16s", "========");
    printf("%-24s", "=========");
    printf("%-3s", "==");
    printf("%-8s", "======");
    printf("%5s", "===="); 
}

void readFile(){
    Studtype S;
    char fileName[40];
    printf("Enter File Name: ");
    scanf("%s", &fileName);
    FILE *fptr;
    fptr = fopen(fileName, "rb");
    if(fptr != NULL){
        if(!(fptr = fopen(fileName, "rb"))){
            printf("Cannot open file\n");
        } else {
            displayHeader();
            int i;
            while(fread(&S, sizeof(Studtype), 1, fptr) != 0){
                displayStudent(S);
                i++;
                if(i == 20){
                    system("\npause");
                    i = 1;
                }
            }
        }
    }
}

void displayStudent(Studtype S){
    printf("\n%-10d", S.ID);
    printf("%-16s", S.name.LN);
    printf("%-24s", S.name.FN);
    printf("%-3c", S.name.MI);
    printf("%-8s", S.course);
    printf("%5d", S.yrLevel);
}
