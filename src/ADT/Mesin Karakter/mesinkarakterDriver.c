#include <stdio.h>
#include "mesinkarakter.h"

int main() {
    // Test case 1: Read from standard input
    printf("Test case 1: Read from standard input\n");
    START();
    while (!IsEOP()) {
        printf("%c", GetCC());
        ADV();
    }
    printf("\n");

    // Test case 2: Read from file
    printf("Test case 2: Read from file\n");
    FILE *f = fopen("test.txt", "r");
    readFileChar(f);
    while (!IsEOP()) {
        printf("%c", GetCC());
        ADV();
    }
    printf("\n");

    // Test case 3: Read empty file
    printf("Test case 3: Read empty file\n");
    FILE *empty = fopen("empty.txt", "r");
    readFileChar(empty);
    while (!IsEOP()) {
        printf("%c", GetCC());
        ADV();
    }
    printf("\n");

    return 0;
}