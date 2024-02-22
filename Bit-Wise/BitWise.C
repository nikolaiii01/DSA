#include <stdio.h>

void displayBitPattern(int num);

int main() {
    int num = 255;

    printf("Bit pattern: ");
    displayBitPattern(num);

    return 0;
}

void displayBitPattern(int num) {
    int numBits = sizeof(num) * 8, bit, i;
    for (i = numBits - 1; i >= 0; i--) {
        bit = (num >> i) & 1;
        printf("%d", bit);
        if (i % 4 == 0){
            printf(" ");
        }
    }
}