#include<stdio.h>

typedef char SET;

void displayBitPattern(char A);
int displayThirdBit(char A);
void insert(char *A, int elem);
void delete(char *A, int elem);

int main(){
	SET A;
	
	insert(&A, 2);
	insert(&A, 6);
	insert(&A, 7);
	
	delete(&A, 2);
    delete(&A, 6);
	
	displayBitPattern(A);
	return 0;
}

void displayBitPattern(char A){
	printf("SET: ");
	unsigned char mask = sizeof(char)*8-1;
	int bit, i;
	for(i = mask; i>=0; i--){
		bit=(A>>i)&1;
		printf("%d", bit);
		if(i%4==0){
			printf(" ");
		}
	}
}

int getBit(char A, int elem){
	int mask = 1 << elem;
	return (A & mask) ? 1 : 0;
}

void insert(char *A, int elem){
	*A = (*A | (1 << elem));
}

void delete(char *A, int elem){
	if(getBit(*A, elem) == 1){
		*A = (*A ^ (1 << elem));
	}
}