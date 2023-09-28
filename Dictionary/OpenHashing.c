#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
	int data;
	struct node *link;
}*LIST;

typedef LIST Dictionary[MAX];

int Hash(int N);
void insert(Dictionary D, int elem);
void InitDictionary(Dictionary *D);
void DisplayDictionary(Dictionary D);
void Delete(Dictionary D, int elem);
void isMember(Dictionary, int elem);

int main(){
	Dictionary D; 
	
	InitDictionary(&D);
	
	int A[MAX] = {48,3,4,28,108,45,38,95,33,43};
	
	int i;
	for(i = 0; i < MAX; i++){
		insert(D, A[i]);
	}
	
	DisplayDictionary(D);
	Delete(D, 6);
	isMember(D, 4);
	
	return 0;
}

int Hash(int N){
	return N % 10;
}

void insert(Dictionary D, int elem){
	int hashVal;
	hashVal = Hash(elem);
	LIST *trav;
	for(trav = D + hashVal; *trav != NULL && (*trav)->data < elem; trav = &(*trav)->link){}
	if(*trav == NULL || (*trav)->data != elem){
		LIST temp = (LIST)malloc(sizeof(struct node));
		if(temp != NULL){
			temp->data = elem;
			temp->link = *trav;
			*trav = temp;
		}
	}
}

void InitDictionary(Dictionary *D){
	int i;
	for(i = 0; i < MAX; i++){
		(*D)[i] = NULL;
	}
}

void DisplayDictionary(Dictionary D){
	printf("\n------DISPLAY DICTIONARY------\n");
	LIST trav;
	int i;
	for(i = 0; i < MAX; i++){
		printf("[%d] ", i);
		for(trav = D[i]; trav != NULL; trav = trav->link){
			printf("-> %d ", trav->data);
		}
		printf("\n");
	}
}

void Delete(Dictionary D, int elem){
	printf("\n---------------DELETE %d----------------", elem);
	int hashVal;
	hashVal = Hash(elem);
	LIST *trav;
	for(trav = D + hashVal; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link){}
	if(*trav != NULL){
		LIST temp = *trav;
		*trav = temp->link;
		free(temp);
	} else {
		printf("\nResult: Sorry, %d doesn't exist in this Dictionary!", elem);
	}
	printf("\n");
	DisplayDictionary(D);
	printf("---------------------------------------\n");
}

void isMember(Dictionary D, int elem){
	printf("\n------------ISMEMBER %d----------------", elem);
	int hashVal;
	hashVal = Hash(elem);
	LIST *trav;
	for(trav = D + hashVal; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link){}
	if(*trav != NULL){
		printf("\nResult: %d is a member of this Dictionary!", elem);
	} else {
		printf("\nResult: %d is not a member of this Dictionary!", elem);
	}
	printf("\n");
	DisplayDictionary(D);
	printf("--------------------------------------\n");
}







