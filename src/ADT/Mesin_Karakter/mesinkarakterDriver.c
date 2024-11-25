#include <stdio.h>
#include "mesinkarakter.h"

void testStdin() {
    printf("Ketik beberapa karakter dan tekan Enter untuk mengakhiri:\n");
    START();
    while (!IsEOP()) {
        printf("%c", GetCC());
        ADV();
    }
    printf("\nSelesai membaca dari stdin\n");
}

void testFile(const char* filename) {
    FILE *f = fopen(filename, "r");

    readFileChar(f);
    if (IsEOF()) {
        printf("File kosong\n");
    } else {
        printf("Isi file:\n");
        while (!IsEOP() && !IsEOF()) {
            printf("%c", GetCC());
            ADV();
        }
        printf("\n");
    }
    closePita();
}

int main() {
    testStdin();

    testFile("test.txt");

    testFile("empty.txt");

    printf("\nPengujian selesai\n");
    return 0;
}