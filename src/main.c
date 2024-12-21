#include <stdio.h>
#include <stdlib.h>
#include "console.h"
#include "ADT/Queue/queueBarang.h"

int main() {
    char username[MAX_LEN]; // Nama username di file konfigurasi
    int username_idx; // Index username di file konfigurasi
    ArrayDin arrayItems; // ListofBarang
    TabInt arrayUsers; // ListofUser
    arrayItems = MakeArrayDin();
    MakeEmpty(&arrayUsers);
    Queuebarang barang;
    CreateQueuebarang(&barang);
    boolean sessionStatus = false; // START Status
    boolean loginStatus = false; // LOGIN Status
    char filename[] = "autosave.txt"; // Config Save ketika Quit

    printf("\n");
printf("  ***************************************************************************************\n");
printf("  *                                                                                     *\n");
printf("  *                               W E L C O M E   T O                                   *\n");
printf("  *                                                                                     *\n");
printf("  *  ******    **    **   ******    ******    ***    ***    *****    ******    ******** *\n");
printf("  *  **   **   **    **   **   **   **   **   ****  ****   **   **   **   **      **    *\n");
printf("  *  ******    **    **   ******    ******    ** **** **   *******   ******       **    *\n");
printf("  *  **        **    **   **   **   **   **   **  **  **   **   **   **   **      **    *\n");
printf("  *  **         ******    **   **   **   **   **      **   **   **   **   **      **    *\n");
printf("  *                                                                                     *\n");
printf("  *                       YOUR ONE-STOP WORLD DOMINATION SHOP                           *\n");
printf("  *                                                                                     *\n");
printf("  ***************************************************************************************\n");
printf("\n");
printf("                   Select:  << START >>  or  << LOAD >>  or  << QUIT >>\n");
printf("===========================================================================================\n");
    

        while (!compareWordToString(currentWord, "QUIT")) // Program akan berjalan terus hingga user memasukkan input QUIT
        {
        while (!sessionStatus && !loginStatus) { // Loop untuk ketika pengguna belum memulai sesi (belum START atau LOAD)
            printf("Masukkan command: ");
            STARTWORD(); // Menerima masukan berupa satu kata
            if (compareWordToString(currentWord, "START")) {
                // printf("Debugging0.\n");
                STARTConfig(&arrayItems, &arrayUsers);
                sessionStatus = true;
            } else if (compareWordToString(currentWord, "LOAD")) {
                STARTWORD(); // Khusus untuk LOAD, jika masukan kata pertama berupa "LOAD", maka akan membaca masukan berikutnya yaitu filename
                LOAD(currentWord, &arrayItems, &arrayUsers, &sessionStatus);
            } else if (compareWordToString(currentWord, "HELP")) {
                HELP(sessionStatus, loginStatus);
            } else if (compareWordToString(currentWord, "QUIT")) {
                printf("Program berhasil dihentikan.\n"); // Khusus QUIT pada fungsi ini tidak dapat melakukan SAVE, karena sesi belum dimulai
                exit(1);
            } else { // Untuk kasus input invalid
                printf("Input command tidak valid!\nKetik \"HELP\" untuk command-command yang valid!\n");
            }
        }

        while (sessionStatus && !loginStatus) { // Loop untuk ketika pengguna sudah memulai sesi namun belum login
            printf("Masukkan command: ");
            STARTWORD();// Menerima masukan berupa semua kata pada input hingga bertemu newline
            if (compareWordToString(currentWord, "REGISTER")) {
                REGISTER(&arrayUsers);
            } else if (compareWordToString(currentWord, "LOGIN")) {
                LOGIN(arrayUsers, &loginStatus, username, &username_idx);
            } else if (compareWordToString(currentWord, "HELP")) {
                HELP(sessionStatus, loginStatus);
            } else if (compareWordToString(currentWord, "QUIT")) {
                QUIT(filename, &arrayItems, &arrayUsers); // Meskipun belum login, pengguna dapat melakukan SAVE melalui QUIT, untuk menyimpan data user baru (jika ada)
                // break;
            } else { // Untuk kasus input invalid
                printf("Input command tidak valid!\nKetik \"HELP\" untuk command-command yang valid!\n");
            }
        }

        while (sessionStatus && loginStatus && !compareWordToString(currentWord, "QUIT")) { // Loop Main Menu (sudah memulai sesi dan sudah login)
            printf("Masukkan command: ");
            STARTWORD();// Menerima masukan berupa semua kata yang ada pada input hingga bertemu newline
            char forsave[50]; // Khusus untuk fungsi SAVE
            salin_string(forsave, currentWord.TabWord);
            if (compareWordToString(currentWord, "WORK")) {
                WORK(&arrayUsers, username_idx);
            } else if (compareWordToString(currentWord, "WORKCHALLENGE")) {
                workChallenge(&arrayUsers, username_idx);
            // } else if (compareWordToString(currentWord, "STORE LIST")) {
            //     storelist(arrayItems);
            // } else if (compareWordToString(currentWord, "STORE REQUEST")) {
            //     storerequest(arrayItems, &barang);
            // } else if (compareWordToString(currentWord, "STORE SUPPLY")) {
            //     storesupply(&arrayItems, &barang);
            // } else if (compareWordToString(currentWord, "STORE REMOVE")) {
            //     storeremove(&arrayItems);
            // } else if (bandingkan_string(currentWord.TabWord, "WISHLIST")) {
            //     wishlist(&arrayUsers, username_idx, arrayItems, currentWord.TabWord);
            } else if (bandingkan_string(currentWord.TabWord, "CART")) {
                STARTWORD();
                cartfunction(&arrayUsers, username_idx, arrayItems, currentWord);
            } else if (bandingkan_string(currentWord.TabWord, "HISTORY")) {
                STARTWORD();
                HISTORY(&arrayUsers, username_idx, currentWord);
            } else if(compareWordToString(currentWord, "PROFILE")) {
                PROFILE(&arrayUsers, username_idx);
            } else if (compareWordToString(currentWord, "LOGOUT")) {
                LOGOUT(username, &username_idx);
                loginStatus=false;
            } else if (bandingkan_string(currentWord.TabWord, "SAVE")) {
                STARTWORD();
                SAVE(currentWord.TabWord, &arrayItems, &arrayUsers);
            } else if (compareWordToString(currentWord, "QUIT")) {
                QUIT(filename, &arrayItems, &arrayUsers);
            } else if (compareWordToString(currentWord, "LOGIN")){ // Ini dibuat untuk mengatasi kasus ketika pengguna sudah login, kemudian mencoba login lagi
                LOGIN(arrayUsers, &loginStatus, username, &username_idx);
            } else if (compareWordToString(currentWord, "HELP")) {
                HELP(sessionStatus, loginStatus);
            } else { // Untuk kasus ketika input tidak valid
                printf("Input command tidak valid!\nKetik \"HELP\" untuk command-command yang valid!\n");
            }
        }
    }
}
