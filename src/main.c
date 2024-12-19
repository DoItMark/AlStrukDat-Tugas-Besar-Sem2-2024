#include <stdio.h>
#include <stdlib.h>
#include "console.h"
#include "ADT/Queue/queueBarang.h"

int main() {
    char username[MAX_LEN]; // Nama username di file konfigurasi
    int username_idx = -1; // Index username di file konfigurasi
    ArrayDin arrayItems; // ListofBarang
    TabInt arrayUsers; // ListofUser
    arrayItems = MakeArrayDin();
    MakeEmpty(&arrayUsers);
    Queuebarang barang;
    CreateQueuebarang(&barang);
    boolean sessionStatus = false; // START Status
    boolean loginStatus = false; // LOGIN Status
    char filename[] = "../save/save1.txt";

    printf("\n");
    printf("  ███████████████████████████████████████████████████████████████████████████████████████\n");
    printf("  █                                                                                     █\n");
    printf("  █                               W E L C O M E   T O                                   █\n");
    printf("  █                                                                                     █\n");
    

    printf("  █  ██████    ██    ██   ██████    ██████    ███    ███    █████    ██████    ████████ █\n");
    printf("  █  ██   ██   ██    ██   ██   ██   ██   ██   ████  ████   ██   ██   ██   ██      ██    █\n");
    printf("  █  ██████    ██    ██   ██████    ██████    ██ ████ ██   ███████   ██████       ██    █\n");
    printf("  █  ██        ██    ██   ██   ██   ██   ██   ██  ██  ██   ██   ██   ██   ██      ██    █\n");
    printf("  █  ██         ██████    ██   ██   ██   ██   ██      ██   ██   ██   ██   ██      ██    █\n");
    
 
    printf("  █                                                                                     █\n");
    printf("  █                       YOUR ONE-STOP WORLD DOMINATION SHOP                           █\n");
    printf("  █                                                                                     █\n");
    printf("  ███████████████████████████████████████████████████████████████████████████████████████\n");
    printf("\n");
    printf("              Select:  << START >>  or  << LOAD >>  or  << QUIT >>\n");
    printf("==========================================================================\n");
    

        while (!compareKalimatToString(CurrentKalimat, "QUIT")) // Program akan berjalan terus hingga user memasukkan input QUIT
        {
        while (!sessionStatus && !loginStatus) { // Loop untuk ketika pengguna belum memulai sesi (belum START atau LOAD)
            printf("Masukkan command: ");
            STARTWORD(); // Menerima masukan berupa satu kata
            if (compareWordToString(currentWord, "START")) {
                startStore(&arrayItems, &arrayUsers);
                sessionStatus = true;
            } else if (compareWordToString(currentWord, "LOAD")) {
                STARTWORD(); // Khusus untuk LOAD, jika masukan kata pertama berupa "LOAD", maka akan membaca masukan berikutnya yaitu filename
                load(currentWord, &arrayItems, &arrayUsers, &sessionStatus);
            } else if (compareWordToString(currentWord, "HELP")) {
                help(sessionStatus, loginStatus);
            } else if (compareWordToString(currentWord, "QUIT")) {
                printf("Program berhasil dihentikan.\n"); // Khusus QUIT pada fungsi ini tidak dapat melakukan SAVE, karena sesi belum dimulai
                exit(1);
            } else { // Untuk kasus input invalid
                printf("Input command tidak valid!\nKetik \"HELP\" untuk command-command yang valid!\n");
            }
        }

        while (sessionStatus && !loginStatus) { // Loop untuk ketika pengguna sudah memulai sesi namun belum login
            printf("Masukkan command: ");
            STARTKALIMAT(); // Menerima masukan berupa semua kata pada input hingga bertemu newline
            if (compareKalimatToString(CurrentKalimat, "REGISTER")) {
                Register_User(&arrayUsers);
            } else if (compareKalimatToString(CurrentKalimat, "LOGIN")) {
                Login_User(arrayUsers, &loginStatus, username, &username_idx);
            } else if (compareKalimatToString(CurrentKalimat, "HELP")) {
                help(sessionStatus, loginStatus);
            } else if (compareKalimatToString(CurrentKalimat, "QUIT")) {
                quit(filename, &arrayItems, &arrayUsers); // Meskipun belum login, pengguna dapat melakukan SAVE melalui QUIT, untuk menyimpan data user baru (jika ada)
                break;
            } else { // Untuk kasus input invalid
                printf("Input command tidak valid!\nKetik \"HELP\" untuk command-command yang valid!\n");
            }
        }

        while (sessionStatus && loginStatus && !compareWordToString(currentWord, "QUIT")) { // Loop Main Menu (sudah memulai sesi dan sudah login)
            printf("Masukkan command: ");
            STARTKALIMAT(); // Menerima masukan berupa semua kata yang ada pada input hingga bertemu newline
            char forsave[50]; // Khusus untuk fungsi SAVE
            salin_string(forsave, CurrentKalimat.TabWord);
            if (compareKalimatToString(CurrentKalimat, "WORK")) {
                work_(&arrayUsers, username_idx);
            } else if (compareKalimatToString(CurrentKalimat, "WORK CHALLENGE")) {
                workChallenge(&arrayUsers, username_idx);
            } else if (compareKalimatToString(CurrentKalimat, "STORE LIST")) {
                storelist(arrayItems);
            } else if (compareKalimatToString(CurrentKalimat, "STORE REQUEST")) {
                storerequest(arrayItems, &barang);
            } else if (compareKalimatToString(CurrentKalimat, "STORE SUPPLY")) {
                storesupply(&arrayItems, &barang);
            } else if (compareKalimatToString(CurrentKalimat, "STORE REMOVE")) {
                storeremove(&arrayItems);
            } else if (bandingkan_string(CurrentKalimat.TabWord, "WISHLIST")) {
                wishlist(&arrayUsers, username_idx, arrayItems, CurrentKalimat.TabWord);
            } else if (bandingkan_string(CurrentKalimat.TabWord, "CART")) {
                cartfunction(&arrayUsers, username_idx, arrayItems, CurrentKalimat.TabWord);
            } else if (bandingkan_string(CurrentKalimat.TabWord, "HISTORY")) {
                history(*arrayUsers.TI[username_idx].riwayat_pembelian, CurrentKalimat.TabWord);
            } else if(compareKalimatToString(CurrentKalimat, "PROFILE")) {
                profile(arrayUsers, username_idx);
            } else if (compareKalimatToString(CurrentKalimat, "LOGOUT")) {
                logout_User(username, &username_idx);
                loginStatus=false;
            } else if (bandingkan_string(CurrentKalimat.TabWord, "SAVE")) {
                hapuskarakter(CurrentKalimat.TabWord, 5); // Khusus untuk SAVE, perlu dilakukan pemisahan antara command "SAVE" dengan masukan "<filename.txt>"
                save(CurrentKalimat.TabWord, &arrayItems, &arrayUsers);
            } else if (compareKalimatToString(CurrentKalimat, "QUIT")) {
                quit(filename, &arrayItems, &arrayUsers);
            } else if (compareKalimatToString(CurrentKalimat, "LOGIN")){ // Ini dibuat untuk mengatasi kasus ketika pengguna sudah login, kemudian mencoba login lagi
                Login_User(arrayUsers, &loginStatus, username, &username_idx);
            } else if (compareKalimatToString(CurrentKalimat, "HELP")) {
                help(sessionStatus, loginStatus);
            } else { // Untuk kasus ketika input tidak valid
                printf("Input command tidak valid!\nKetik \"HELP\" untuk command-command yang valid!\n");
            }
        }
    }
}
