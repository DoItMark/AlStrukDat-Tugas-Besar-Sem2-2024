/* File: driver_mesinkata.c */
#include <stdio.h>
#include "mesinkata.h"

int main() {
    printf("=== Mesin Kata Driver ===\n\n");
    
    // Test 1: Membaca dari file
    printf("=== Test Membaca dari File ===\n");
    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("Error: File tidak dapat dibuka\n");
        return 1;
    }

    printf("Isi file test.txt:\n");
    StartWordFile(file);
    
    while (!IsEOF()) {
        // Print kata yang dibaca
        for (int i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        
        if (currentChar == MARK) {
            printf("\n");
            ADVWORD(); // Lanjut ke kata pertama di baris berikutnya
        } else {
            printf(" ");
            ADVWORD(); // Lanjut ke kata berikutnya dalam baris yang sama
        }
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