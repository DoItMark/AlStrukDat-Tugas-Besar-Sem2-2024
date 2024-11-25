#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../header/mesinkata.h"

void TebakAngka(int biayaMain, int *saldo) {
    if (*saldo < biayaMain) {
        printf("Saldo tidak mencukupi untuk memainkan game ini.\n");
        return;
    }

    printf("=====TEBAK ANGKA=====\n");
    *saldo -= biayaMain;  // Kurangi saldo untuk biaya main
    srand(time(NULL));
    int target = rand() % 100 + 1;  // Angka target antara 1-100
    int kesempatan = 10;
    int tebakan;

    printf("Tebak Angka (1-100):\n");
    while (kesempatan > 0) {
        currentWord.Length = 0;
        printf("Masukkan tebakan Anda (1-100): ");
        STARTWORD();  // Gunakan Mesin Kata untuk membaca input
        tebakan = atoi(currentWord.TabWord);


        if (tebakan == target) {
            int hadiah = 50 * kesempatan;  // Hitung hadiah berdasarkan kesempatan tersisa
            printf("Tebakanmu benar! +%d rupiah telah ditambahkan ke saldo Anda.\n", hadiah);
            *saldo += hadiah;
            return;
        } else if (tebakan < target) {
            printf("Tebakanmu lebih kecil!\n");
        } else if(tebakan > target){
            printf("Tebakanmu lebih besar!\n");
        }

        kesempatan--;
        if (kesempatan > 0) {
            printf("Kesempatan tersisa: %d\n", kesempatan);
        }
    }

    printf("Maaf, kesempatanmu habis. Angka yang benar adalah %d.\n", target);
}
