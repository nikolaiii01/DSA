#include <stdio.h>

void displayBitPattern(int num);

int main() {
    int num = 255;

    printf("Bit pattern: ");
    displayBitPattern(num);

    return 0;
}

void displayBitPattern(int num) {
    int numBits = sizeof(num) * 8; // Determine the number of bits in an integer

    // Iterate through each bit from left to right
    for (int i = numBits - 1; i >= 0; i--) {
        // Use a bitmask to extract the current bit
        int bit = (num >> i) & 1;

        // Print the bit
        printf("%d", bit);

        // Add a space after every 4 bits for readability
        if (i % 4 == 0)
            printf(" ");
    }

    printf("\n");
}