#include <stdio.h>
#include <stdlib.h>
#include "load.h"

void concat(char *dest, const char *src1, const char *src2) {
    while (*src1) {
        *dest++ = *src1++;
    }
    while (*src2) {
        *dest++ = *src2++;
    }
    *dest = '\0'; 
}

//file load
void loadFile(const char *filename) {
//filepath perlu diganti menjadi main.c 
    char filepath[100]; //tidak perlu diganti jd main.c, menyimpan path
    concat(filepath, "save %s", filename);

    FILE *file = fopen(filename, "r"); // Membuka file
    if (file == NULL) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return;
    }

    printf("Save file berhasil ditemukan. PURRMART berhasil dijalankan.\n");
    printf("Meload...");
    
    //mencetak isi file
    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file); // Jangan lupa menutup file
}

// Fungsi sederhana untuk memeriksa apakah sebuah string diawali oleh substring tertentu
int startsWith(const char *str, const char *prefix) {
    while (*prefix) {
        if (*str++ != *prefix++) {
            return 0;
        }
    }
    return 1;
}