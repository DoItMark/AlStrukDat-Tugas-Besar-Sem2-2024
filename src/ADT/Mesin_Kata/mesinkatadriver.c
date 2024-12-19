#include <stdio.h>
#include <stdlib.h>
#include "mesinkata.h"

int main() {
    printf("Membaca data dari file test.txt\n");
    StartFileWord("test.txt");

    while (!endOfFile) {
        for (int i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        printf("\n");

        // Pindah ke kata/baris berikutnya
        ADVFileWordNewLine();
    }
    for (int i = 0; i < currentWord.Length; i++) {
        printf("%c", currentWord.TabWord[i]);
        }
    if(endOfFile){
        printf("\nSelesai\n");
    }

    printf("Membaca data dari input\n");
        printf("Masukkan teks (akhiri dengan ENTER):\n");
        StartWordNewLine();

        while (!isEndWord()) {
            for (int i = 0; i < currentWord.Length; i++) {
                printf("%c", currentWord.TabWord[i]);
            }
            printf("\n");

            // Pindah ke kata/baris berikutnya
            ADVWordNewLine();
        }
        if (isEndWord()) {
            printf("\nSelesai membaca input keyboard\n");
        }

    return 0;
}
        