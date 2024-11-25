#include <stdio.h>
#include <stdlib.h>
#include "save.h"

// saving
void saveFile(const char *filename) {
    char filepath[100];
    concat(filepath, "save %s", filename);

    FILE *file = fopen(filepath, "f");
    if (file == NULL) {
        printf("Gagal menyimpan file.\n");
        return;
    }

//menggunakan mesinkata
STARTWORD();

    while (!EndWord) {

        for (int i = 0; i < currentWord.Length; i++) {
            fputc(currentWord.TabWord[i], file);
        }
        fputc(' ', file); 

        ADVWORD();
    }

    fclose(file); 
    printf("Save file berhasil disimpan.\n");
//tambahan opsional: printf("// File disimpan pada /save/%s\n", filename);
}