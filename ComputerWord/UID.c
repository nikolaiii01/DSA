#include<stdio.h>

typedef char SET;

void displayBitPattern(char A);
int displayThirdBit(char A);
void insert(char *A, int elem);
void delete(char *A, int elem);
void printThirdBit(char A);
SET Union(char A, char B);
SET Intersection(char A, char B);
SET Difference(char A, char B);

int main(){
	SET A = 0;
	SET B = 0;
	
	insert(&A, 6);
	insert(&A, 7);
	insert(&A, 1);
	insert(&A, 2);

	insert(&B, 6);
	insert(&B, 2);

	displayBitPattern(A);
	displayBitPattern(B);
	SET C = Difference(A, B);

	displayBitPattern(C);
	return 0;
}

void displayBitPattern(char A){
	printf("\nSET: ");
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

void printThirdBit(char A){
	printf("Third Bit: %d\n", ((A & (1 << 2)) != 0)? 1 : 0);
}

SET Union(char A, char B){
	SET C = A | B;
	return C;
}

SET Intersection(char A, char B){
	SET C = A & B;
	return C;
}

SET Difference(char A, char B){
	SET C = A & (~B);
	return C;
}