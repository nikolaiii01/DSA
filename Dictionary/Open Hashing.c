#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
	int elem;
	struct node* next;
}*SET;

typedef SET Dictionary[MAX];

typedef enum { TRUE /*0*/, FALSE /*1*/} Boolean;

void initDictionary(Dictionary D);
int hash(int elem);
void insert(Dictionary A, int elem);
void delete(Dictionary A, int elem);
Boolean isMember(Dictionary A, int elem);
void display(Dictionary A);

int main(){
	Dictionary D;
	initDictionary(D);
	
	int elements[] = {0, 13, 20, 28, 30, 33, 45, 48, 108};
	
	int i;
	for(i = 0; i < MAX; i++){
		insert(D, elements[i]);
	}
		
	display(D);
	
	delete(D, 28);
	printf("After Deletion of 28:\n");
	display(D);
	
	(isMember(D, 20) == 0) ? printf("TRUE\n") : printf("FALSE\n");
	(isMember(D, 28) == 0) ? printf("TRUE\n") : printf("FALSE\n");
	return 0;
}

void initDictionary(Dictionary D){
	int i;
	for(i = 0; i < MAX; i++){
		D[i] = NULL;
	}
}

int hash(int elem){
	return elem%MAX;
}

void insert(Dictionary D, int elem){
	SET *trav, temp;
	temp = (SET)malloc(sizeof(struct node));
	if(temp != NULL){
		for(trav = &D[hash(elem)]; *trav != NULL && (*trav)->elem < elem; trav = &(*trav)->next){}
		if(*trav == NULL || (*trav)->elem != elem){
			temp->elem = elem;
			temp->next = *trav;
			*trav = temp;
		}
	}
}

void delete(Dictionary D, int elem){
	SET *trav, temp;
	for(trav = &D[hash(elem)]; *trav != NULL && (*trav)->elem != elem; trav = &(*trav)->next){}
	if(*trav != NULL){
		temp = *trav;
		*trav = temp->next;
		free(temp);
	}
}

Boolean isMember(Dictionary D, int elem){
	SET trav;
	for(trav = D[hash(elem)]; trav != NULL && trav->elem != elem; trav = trav->next){}
	return (trav != NULL) ? TRUE : FALSE;
}

void display(Dictionary D){
	SET trav;
	int i;
	printf("SET # \tElements\n");
	for(i = 0; i < MAX; i++){
		printf("[%d] \t", i);
		if(D[i] != NULL){
			for(trav = D[i]; trav != NULL; trav = trav->next){
			printf("%d  ", trav->elem);
			}
		} else {
			printf("EMPTY");	
		}
		printf("\n");
	}
}
