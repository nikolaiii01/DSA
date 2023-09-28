#include <stdio.h>

#define MAX 10
#define EMPTY ''
#define DELETED '!'

typedef int Dictionary[MAX];

int Hash(char elem);

int main() {
    char elem[] = "ABCDEFGH";
    int hashVal, i;

    for (i = 0; i < sizeof(elem) - 1; i++) {
        hashVal = Hash(elem[i]);
        printf("%d ", hashVal);
    }

    return 0;
}

int Hash(char elem) {
    int hashVal = ((elem - 'A' + 1) * (elem - 'A' + 1)) % (MAX - 2) + 1;
    return hashVal;
}
