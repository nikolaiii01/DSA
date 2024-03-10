#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define EMPTY '@'
#define DELETED '!'

typedef char Dictionary[MAX];
typedef enum {TRUE, FALSE} Boolean;
typedef struct {
	char data[MAX];
	int last;
}LIST;

void initDictionary(Dictionary D);
void displayDictionary(Dictionary D);
int hash(char elem);
void insert(Dictionary D, char elem);
Boolean isMember(Dictionary D, char elem);
int searchLength(Dictionary D, char elem);
Dictionary* convertToDictionary(char* data);

int main(){
	char elem[MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'k'};
	int i;
	
	Dictionary DList;
	initDictionary(DList);
	
	for(i = 0; i < 10; i++){
		insert(DList, elem[i]);
	}
	
	// displayDictionary(DList);

	Dictionary* CDictTwoPass = convertToDictionary(elem);
	// displayDictionary(CDictTwoPass);
	// char data = 'i';
	// printf("Search Length for %c: %d", data, searchLength(DList, data));
	
	return 0;
}

int hash(char elem){
	int Map[2][11] = {{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'},
					   {3,   9,   4,   3,   9,   0,   1,   3,   0,   3,   8}};
	int i;
	for(i = 0; i < 11 && Map[0][i] != elem; i++){}
	return (Map[0][i] == elem) ? Map[1][i] : -1;
}

void initDictionary(Dictionary D){
	int i;
	for(i = 0; i < MAX; i++){
		D[i] = EMPTY; 
	}
}

void displayDictionary(Dictionary D){
	int i;
	printf("INDEX\tELEMENTS\n");
	for(i = 0; i < MAX; i++){
		printf("[%d]\t", i);
		if(D[i] == EMPTY){
			printf("EMPTY\n");
		} else if(D[i] == DELETED) {
			printf("DELETED\n");
		} else {
			printf("%c\n", D[i]);
		}
	}
}

//Insertion using Linear Probing
void insert(Dictionary D, char elem){
	int i, hashVal = hash(elem);
	for(i = hashVal; D[i] != EMPTY && D[i] != DELETED && D[i] != elem && (i+1)%MAX != hashVal; i = (i+1)%MAX){}
	if((i+1)%MAX != hashVal && D[i]!= elem){
		D[i] = elem;
	}
}

Boolean isMember(Dictionary D, char elem){
	int hashVal = hash(elem), i;
	for(i = hashVal; D[i] != elem && (i+1)%MAX != hashVal && D[i] != EMPTY; i = (i+1)%MAX){}
	return (D[i] == elem) ? TRUE : FALSE;
}

void delete(Dictionary D, char elem){
	int hashVal = hash(elem), i;
	for(i = hash(elem); D[i] != elem && (i+1)%MAX != hashVal && D[i] != EMPTY; i = (i+1)%MAX){}
	if(D[i] == elem){
		D[i] = DELETED;
	}
}

int searchLength(Dictionary D, char elem){
	int hashVal = hash(elem), count, i;
	for(i = hashVal, count = 1; D[i] != elem; i = (i+1)%MAX, count++){}
	return (D[i] == elem) ? count : -1;
}

//Accepts and array as a parameter and returns a dictionary using Two-Pass Loading for resolution for collision
Dictionary* convertToDictionary(char* data){
	Dictionary* ret = (Dictionary *)malloc(sizeof(char) * MAX);
	if(ret != NULL){
		initDictionary(*ret);
		int i, j, hashVal;
		LIST synonyms;
		synonyms.last = -1;
		for(i = 0; i < MAX; i++){
			hashVal = hash(data[i]);
			if((*ret)[hashVal] != EMPTY && (*ret)[hashVal] != DELETED){
				synonyms.data[++synonyms.last] = data[i];
			} else {
				(*ret)[hashVal] = data[i];
			}
		}
		displayDictionary(*ret);
		for(i = 0; i <= synonyms.last; i++){
			hashVal = hash(synonyms.data[i]);
			for(j = hashVal; (j+1)%MAX != hashVal && (*ret)[j] != synonyms.data[i] && ((*ret)[j] != EMPTY && (*ret)[j] != DELETED); j = (j+1)%MAX){}
			if((j+1)%MAX != hashVal && (*ret)[j] != synonyms.data[i]){
				(*ret)[j] = synonyms.data[i];
			}
			displayDictionary(*ret);
		}
	}
	return ret;
}