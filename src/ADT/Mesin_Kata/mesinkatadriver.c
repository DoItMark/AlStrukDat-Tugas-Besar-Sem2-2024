/* File: driver_mesinkata.c */
#include <stdio.h>
#include "mesinkata.h"

int main() {
    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("Error: File tidak dapat dibuka\n");
        return 1;
    }

    printf("Isi file test.txt:\n");
    
    while (!feof(file)) {
        StartWordFile(file);
        while (!isEndWord() && !feof(file)) {
            for (int i = 0; i < currentWord.Length; i++) {
                printf("%c", currentWord.TabWord[i]);
            }
            
            ADVWORD();
            if (!isEndWord() && !feof(file)) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    fclose(file);
    
    printf("Masukkan beberapa kata (tekan Enter untuk selesai):\n");
    STARTWORD();
    
    while (!isEndWord()) {
        printf("Kata yang dibaca: ");
        for (int i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        printf("\nPanjang kata: %d\n", currentWord.Length);
        ADVWORD();
    }
    
    return 0;
}