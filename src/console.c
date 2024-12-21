#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"


static User currentUser;
static boolean isLoggedIn = false;

void STARTConfig(ArrayDin* arrayItems, TabInt* arrayUsers) { 
    int total = 0; // representasi jumlah barang atau user yang tercatat
    int n_riwayat_pembelian, n_wishlist;
    Barang currentBarang; // menyimpan barang yg sedang diproses
    User currentUser; // menyimpan user yg sedang diproses
    // printf("Debugging1.\n");

    // Membuka file konfigurasi
    StartFileWord("../save/default.txt");

     // Membaca total barang yang tersimpan dalam file
    total = wordToInt(currentWord);
    // printf("Jumlah barang: %d.\n", total);

    // Memasukkan informasi barang ke arrayItems
    for (int i = 0; i < total; i++) {
        ADVFileWordSpace();
        currentBarang.price = wordToInt(currentWord);

        ADVFileWordNewLine();
        for (int j = 0; j < currentWord.Length; j++) {
            currentBarang.name[j] = currentWord.TabWord[j];
        }
        currentBarang.name[currentWord.Length] = '\0';

        InsertLastArrDin(arrayItems, currentBarang);
        // printf("Debugging2.\n");
    }

    // Membaca total user yang tersimpan dalam file
    ADVFileWordNewLine();
    total = wordToInt(currentWord);
    // printf("Jumlah user: %d.\n", total);

    // Memasukkan informasi user ke arrayUsers
    for (int i = 0; i < total; i++) {
        currentUser.riwayat_pembelian = malloc(sizeof(Stack));
        currentUser.wishlist = malloc(sizeof(LinkedList));
        currentUser.keranjang = malloc(sizeof(Map));

        CreateEmptyStack(currentUser.riwayat_pembelian);
        CreateEmptyListLinier(currentUser.wishlist);
        CreateEmptyMap(currentUser.keranjang);

        ADVFileWordSpace();
        currentUser.money = wordToInt(currentWord);

        ADVFileWordSpace();
        for (int j = 0; j < currentWord.Length; j++) {
            currentUser.name[j] = currentWord.TabWord[j];
        }
        currentUser.name[currentWord.Length] = '\0';

        ADVFileWordNewLine();
        for (int j = 0; j < currentWord.Length; j++) {
            currentUser.password[j] = currentWord.TabWord[j];
        }
        currentUser.password[currentWord.Length] = '\0';

        ADVFileWordNewLine();
        n_riwayat_pembelian = wordToInt(currentWord);
        for (int i = 0; i < n_riwayat_pembelian; i++) {
            pembelian X;

            ADVFileWordSpace();
            X.totalharga = wordToInt(currentWord);

            ADVFileWordNewLine();
            for (int j = 0; j < currentWord.Length; j++) {
                X.name[j] = currentWord.TabWord[j];
            }
            X.name[currentWord.Length] = '\0';
            PushStack(currentUser.riwayat_pembelian, X);
        }

        ADVFileWordNewLine();
        n_wishlist = wordToInt(currentWord);
        for (int i = 0; i < n_wishlist; i++) {
            nama_barang X;

            ADVFileWordNewLine();
            for (int j = 0; j < currentWord.Length; j++) {
                X[j] = currentWord.TabWord[j];
            }
            X[currentWord.Length] = '\0';
            InsVLast(currentUser.wishlist, X);
        }

        SetEl(arrayUsers, i, currentUser);
        // printf("Debugging3.\n");
    }

    arrayUsers->Neff = total;
    // printf("Debugging4.\n");
    printf("File konfigurasi berhasil dibaca. PURRMART berhasil dijalankan.\n");
}

void LOAD(Word filename, ArrayDin* arrayItems, TabInt* arrayUsers, boolean * SessionStatus) {
    int total = 0;
    int n_riwayat_pembelian, n_wishlist;
    Barang currentBarang;
    User currentUser;
    boolean exists;

    char filenameStr[50];
    char fullPath[200];
    for (int i = 0; i < filename.Length; i++) {
        filenameStr[i] = filename.TabWord[i];
    }
    filenameStr[filename.Length] = '\0';
    snprintf(fullPath, sizeof(fullPath), "%s%s", "../save/", filenameStr); // Menggabungkan folder (../save/) dengan filename input user

    if (isFileValid(fullPath)) {   
        // Membuka file
        StartFileWord(fullPath);
        if (!EndWord) {
            // Membaca total barang yang tersimpan dalam file
            total = wordToInt(currentWord);

            // Memasukkan informasi barang ke arrayItems
            for (int i = 0; i < total; i++) {
                ADVFileWordSpace();
                currentBarang.price = wordToInt(currentWord);

                ADVFileWordNewLine();
                for (int j = 0; j < currentWord.Length; j++) {
                    currentBarang.name[j] = currentWord.TabWord[j];
                }
                currentBarang.name[currentWord.Length] = '\0';

                InsertLastArrDin(arrayItems, currentBarang);
            }

            // Membaca total user yang tersimpan dalam file
            ADVFileWordNewLine();
            total = wordToInt(currentWord);

            // Memasukkan informasi user ke arrayUsers
            for (int i = 0; i < total; i++) {
                currentUser.riwayat_pembelian = malloc(sizeof(Stack));
                currentUser.wishlist = malloc(sizeof(LinkedList));
                currentUser.keranjang = malloc(sizeof(Map));

                CreateEmptyStack(currentUser.riwayat_pembelian);
                CreateEmptyListLinier(currentUser.wishlist);
                CreateEmptyMap(currentUser.keranjang);

                ADVFileWordSpace();
                currentUser.money = wordToInt(currentWord);

                ADVFileWordSpace();
                for (int j = 0; j < currentWord.Length; j++) {
                    currentUser.name[j] = currentWord.TabWord[j];
                }
                currentUser.name[currentWord.Length] = '\0';

                ADVFileWordNewLine();
                for (int j = 0; j < currentWord.Length; j++) {
                    currentUser.password[j] = currentWord.TabWord[j];
                }
                currentUser.password[currentWord.Length] = '\0';

                ADVFileWordNewLine();
                n_riwayat_pembelian = wordToInt(currentWord);
                for (int i = 0; i < n_riwayat_pembelian; i++) {
                    pembelian X;

                    ADVFileWordSpace();
                    X.totalharga = wordToInt(currentWord);

                    ADVFileWordNewLine();
                    for (int j = 0; j < currentWord.Length; j++) {
                        X.name[j] = currentWord.TabWord[j];
                    }
                    X.name[currentWord.Length] = '\0';
                    PushStack(currentUser.riwayat_pembelian, X);
                }

                ADVFileWordNewLine();
                n_wishlist = wordToInt(currentWord);
                for (int i = 0; i < n_wishlist; i++) {
                    nama_barang X;

                    ADVFileWordNewLine();
                    for (int j = 0; j < currentWord.Length; j++) {
                        X[j] = currentWord.TabWord[j];
                    }
                    X[currentWord.Length] = '\0';
                    InsVLast(currentUser.wishlist, X);
                }

                SetEl(arrayUsers, i, currentUser);
            }
            arrayUsers->Neff = total;
        }

        if (Length(*arrayItems) == 0 || NbElmt(*arrayUsers) == 0) {
            printf("File tidak memuat data yang sesuai. PURRMART gagal dijalankan.\n");
        }
        else {
            *SessionStatus = true;
            printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
        }
    }
    else {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
    }
}

void HELP(boolean sessionStatus, boolean loginStatus) {
    if (sessionStatus == false) { // Menampilkan menu untuk kondisi ketika program baru saja dimulai
        printf("================= [Selamat datang di PURRMART] ==================\n");
        printf("| Berikut adalah Command yang dapat Anda lakukan:\t\t|\n");
        printf("|    1. START\t\t\t\t\t\t\t|\n");
        printf("|       Untuk masuk sesi baru\t\t\t\t\t|\n");
        printf("|    2. LOAD <filename.txt>\t\t\t\t\t|\n");
        printf("|       Untuk memulai sesi berdasarkan suatu file konfigurasi\t|\n");
        printf("|    3. QUIT\t\t\t\t\t\t\t|\n");
        printf("|       Untuk keluar dari program\t\t\t\t|\n");
        printf("=================================================================\n");
    } else if (sessionStatus == true && loginStatus == false) { // Menampilkan menu ketika user sudah me-load file dan memulai sesi
        printf("================== [Login Menu Help PURRMART] ===================\n");
        printf("| Berikut adalah Command yang dapat Anda lakukan:\t\t|\n");
        printf("|    1. REGISTER\t\t\t\t\t\t|\n");
        printf("|       Untuk melakukan pendaftaran akun baru\t\t\t|\n");
        printf("|    2. LOGIN\t\t\t\t\t\t\t|\n");
        printf("|       Untuk masuk ke dalam akun dan memulai sesi\t\t|\n");
        printf("|    3. QUIT\t\t\t\t\t\t\t|\n");
        printf("|       Untuk keluar dari program\t\t\t\t|\n");
        printf("=================================================================\n");
    } else if (sessionStatus == true && loginStatus == true) { // Menampilkan menu ketika user sudah melakukan login/register
        printf("================== [Main Menu Help PURRMART] ====================\n");
        printf("| Berikut adalah Command yang dapat Anda lakukan:\t\t|\n");
        printf("|    1. WORK\t\t\t\t\t\t\t|\n");
        printf("|       Untuk bekerja\t\t\t\t\t\t|\n");
        printf("|    2. WORKCHALLENGE\t\t\t\t\t\t|\n");
        printf("|       Untuk mengerjakan challenge\t\t\t\t|\n");
        printf("|    3. STORE LIST\t\t\t\t\t\t|\n");
        printf("|       Untuk melihat barang-barang di toko\t\t\t|\n");
        printf("|    4. STORE REQUEST\t\t\t\t\t\t|\n");
        printf("|       Untuk meminta penambahan barang\t\t\t\t|\n");
        printf("|    5. STORE SUPPLY\t\t\t\t\t\t|\n");
        printf("|       Untuk menambahkan barang dari permintaan\t\t|\n");
        printf("|    6. STORE REMOVE\t\t\t\t\t\t|\n");
        printf("|       Untuk menghapus barang\t\t\t\t\t|\n");
        printf("|    7. CART ADD <nama barang> <jumlah barang>\t\t\t|\n");
        printf("|       Untuk menambahkan barang ke dalam keranjang\t\t|\n");
        printf("|    8. CART REMOVE <nama barang> <jumlah barang>\t\t|\n");
        printf("|       Untuk mengurangi/menghapus barang dari keranjang\t|\n");
        printf("|    9. CART SHOW\t\t\t\t\t\t|\n");
        printf("|       Untuk menampilkan barang yang ada di keranjang\t\t|\n");
        printf("|    10. CART PAY\t\t\t\t\t\t|\n");
        printf("|       Untuk membeli barang yang ada di keranjang\t\t|\n");
        printf("|    11. WISHLIST ADD\t\t\t\t\t\t|\n");
        printf("|       Untuk menambahkan barang ke dalam wishlist\t\t|\n");
        printf("|    12. WISHLIST SWAP <i> <j>\t\t\t\t\t|\n");
        printf("|       Untuk menukar posisi dua barang pada wishlist\t\t|\n");
        printf("|    13. WISHLIST REMOVE <i>\t\t\t\t\t|\n");
        printf("|       Untuk menghapus sebuah barang pada wishlist\t\t|\n");
        printf("|       berdasarkan posisi barang di wishlist\t\t\t|\n");
        printf("|    14. WISHLIST REMOVE\t\t\t\t\t|\n");
        printf("|       Untuk menghapus sebuah barang pada wishlist\t\t|\n");
        printf("|       berdasarkan nama barang\t\t\t\t\t|\n");
        printf("|    15. WISHLIST CLEAR\t\t\t\t\t\t|\n");
        printf("|       Untuk menghapus semua barang pada wishlist\t\t|\n");
        printf("|    16. HISTORY <n>\t\t\t\t\t\t|\n");
        printf("|       Untuk menampilkan n riwayat pembelian terakhir\t\t|\n");
        printf("|    17. PROFILE\t\t\t\t\t\t|\n");
        printf("|       Untuk menampilkan data diri user\t\t\t|\n");
        printf("|    18. LOGOUT\t\t\t\t\t\t\t|\n");
        printf("|       Untuk keluar dari sesi\t\t\t\t\t|\n");
        printf("|    19. SAVE <filename.txt>\t\t\t\t\t|\n");
        printf("|       Untuk menyimpan state ke dalam file\t\t\t|\n");
        printf("|    20. QUIT\t\t\t\t\t\t\t|\n");
        printf("|       Untuk keluar dari program\t\t\t\t|\n");
        printf("=================================================================\n");
    }
}

void QUIT (char* filename, ArrayDin* arrayItems, TabInt* arrayUsers) { // Fungsi untuk command QUIT
    char input;
    do {
        printf("Apakah kamu ingin menyimpan data sesi kali ini (Y/N)? ");
        START(); // Menerima masukan dari pengguna
        input = currentChar;
        if ((input != 'Y' && input != 'y') && (input != 'N' && input != 'n')) { // Untuk kasus input invalid
            printf("Masukkan anda tidak valid!\n");
        }
    } while ((input != 'Y' && input != 'y') && (input != 'N' && input != 'n')); // Meminta masukan terus hingga input valid

    if (input == 'Y' || input == 'y') { // Jika pengguna menjawab yes, maka akan dilakukan SAVE pada default.txt
        SAVE(filename, arrayItems, arrayUsers);
        printf("Data sesi kali ini telah berhasil disimpan!\n\n");
    }

    printf("Anda telah keluar dari PURRMART\n"); // Menampilkan pesan pengguna berhasil keluar dari program
    printf("Sampai jumpa! Semoga datang kembali ke PURRMART!\n");
}

void SAVE (char* fileName, ArrayDin* arrayItems, TabInt* arrayUsers) { // Fungsi untuk command SAVE
    char fullPath[200];
    Stack tempStack;
    CreateEmptyStack(&tempStack);

    snprintf(fullPath, sizeof(fullPath), "%s%s", "../save/", fileName); // Menggabungkan folder (../save/) dengan filename input user

    FILE *file = fopen(fullPath, "w"); // Membuka file (jika sudah ada) untuk di-overwrite atau membuat file baru (jika file belum ada)
    if (!file) { // Ketika file gagal dibuka
        // printf("Gagal membuka file untuk overwrite\n");
        perror("Gagal membuka file untuk write/overwrite");
        // exit(EXIT_FAILURE);
    } else {
        fprintf(file, "%d\n", Length(*arrayItems)); // Memasukkan baris pertama: Total Items
        for (int i = 0; i < Length(*arrayItems); i++) { // Memasukkan baris-baris yang menjabarkan Item yang ada dari arrayItems
            fprintf(file, "%d %s\n", arrayItems->A[i].price, arrayItems->A[i].name);
        }

        fprintf(file, "%d\n", NbElmt(*arrayUsers)); // Memasukkan baris Total Users
        for (int i = 0; i < NbElmt(*arrayUsers); i++) {
            fprintf(file, "%d %s %s\n", arrayUsers->TI[i].money, arrayUsers->TI[i].name, arrayUsers->TI[i].password);

            // Perlu atribut size untuk hitung jumlah elemen
            int total = (GetElmt(*arrayUsers, i)).riwayat_pembelian->size;
            fprintf(file, "%d\n", total);
            
            // Memasukkan riwayat_pembelian user ke tempStack dahulu
            // untuk menjaga urutan penulisan pembelian yang terbalik
            pembelian currentBarangDibeli;
            while (!IsEmptyStack(*arrayUsers->TI[i].riwayat_pembelian)) {
                PopStack(arrayUsers->TI[i].riwayat_pembelian, &currentBarangDibeli);
                PushStack(&tempStack, currentBarangDibeli);
            }

            // Memasukkan pembelian ke file
            // dan memasukkannya kembali ke stack riwayat_pembelian
            // karena user mungkin tidak quit setelah save
            while (!IsEmptyStack(tempStack)) {
                PopStack(&tempStack, &currentBarangDibeli);
                fprintf(file, "%d %s\n", currentBarangDibeli.totalharga, currentBarangDibeli.name);
                PushStack(arrayUsers->TI[i].riwayat_pembelian, currentBarangDibeli);
            }

            // Menghitung jumlah barang wishlist dan memasukkannya ke file
            total = 0;
            address currentAddress = First(*(arrayUsers->TI[i].wishlist));
            while (currentAddress != Nil) {
                total++;
                currentAddress = currentAddress->next;
            }
            fprintf(file, "%d\n", total);

            // Memasukkan baris nama barang di wishlist
            currentAddress = First(*(arrayUsers->TI[i].wishlist));
            for (int i = 0; i < total; i++) {
                fprintf(file, "%s\n", Info(currentAddress));
                currentAddress = currentAddress->next;
            }
        }

        fclose(file); // Menutup file .txt
        printf("File konfigurasi berhasil disimpan di %s\n", fileName);
    }
}

void REGISTER(TabInt * arrayUsers){ // Fungsi untuk command REGISTER
    char username[MAX_LEN];
    char password[MAX_LEN];
    printf("Username: ");
    STARTWORD(); // Menerima masukan Username
    for (int j = 0; j < currentWord.Length; j++) {
        username[j] = currentWord.TabWord[j];
    }
    username[currentWord.Length] = '\0';
    printf("Password: ");
    STARTWORD(); // Menerima masukan Password
    for (int j = 0; j < currentWord.Length; j++) {
        password[j] = currentWord.TabWord[j];
    }
    password[currentWord.Length] = '\0';
    boolean exist = false; // Boolean untuk pengecekan apakah username sudah ada pada array
    for(int i = 0; i<arrayUsers->Neff; i++){ // Mengecek apakah username sudah ada
        exist = validity_check(arrayUsers->TI[i], username, password);
        if(exist){
            break;
        }
    }
    if(exist){ // Kasus jika username sudah ada
        printf("Akun dengan username %s gagal dibuat. Silakan lakukan REGISTER ulang.\n", username);
    }
    else{ // Jika username belum dibuat
        int idx = 0;
        while(username[idx]!='\0'){
            arrayUsers->TI[arrayUsers->Neff].name[idx] = username[idx];
            idx++;
        }
        idx = 0;
        while(password[idx]!='\0'){
            arrayUsers->TI[arrayUsers->Neff].password[idx] = password[idx];
            idx++;
        }
        arrayUsers->TI[arrayUsers->Neff].money = 0;
        arrayUsers->TI[arrayUsers->Neff].riwayat_pembelian = malloc(sizeof(Stack));
        arrayUsers->TI[arrayUsers->Neff].wishlist = malloc(sizeof(LinkedList));
        arrayUsers->TI[arrayUsers->Neff].keranjang = malloc(sizeof(Map));

        CreateEmptyStack(arrayUsers->TI[arrayUsers->Neff].riwayat_pembelian);
        CreateEmptyListLinier(arrayUsers->TI[arrayUsers->Neff].wishlist);
        CreateEmptyMap(arrayUsers->TI[arrayUsers->Neff].keranjang);
        
        arrayUsers->Neff++;
        printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", username);
    }
}

boolean validity_check(User users, char username[], char password[]){
    int idx = 0;
    while(users.name[idx]!='\0' && username[idx]!='\0' && users.name[idx]==username[idx]){
        idx++;
    }
    if(username[idx]!=users.name[idx]){
        return false;
    }
    idx = 0;
    while(users.password[idx]!='\0' && password[idx]!='\0' && users.password[idx]==password[idx]){
        idx++;
    }
    if(password[idx]!=users.password[idx]){
        return false;
    }
    return true;
}

void LOGIN(TabInt arrayUsers, boolean * loginStatus, char username_sekarang[], int * username_idx){
    char username[MAX_LEN];
    char password[MAX_LEN];
    printf("Username: ");
    STARTWORD();
    for (int j = 0; j < currentWord.Length; j++) {
        username[j] = currentWord.TabWord[j];
    }
    username[currentWord.Length] = '\0';
    printf("Password: ");
    STARTWORD();
    for (int j = 0; j < currentWord.Length; j++) {
        password[j] = currentWord.TabWord[j];
    }
    password[currentWord.Length] = '\0';
    if(*loginStatus){
        printf("Anda masih tercatat sebagai ");
        int idx = 0;
        while(username_sekarang[idx]!='\0'){
            printf("%c", username_sekarang[idx]);
            idx++;
        }
        printf(". Silakan LOGOUT terlebih dahulu.\n");
    }
    else{
        for(int i = 0; i<arrayUsers.Neff; i++){
            int j = 0;
            *loginStatus = validity_check(arrayUsers.TI[i], username, password);
            if(*loginStatus){
                int idx = 0;
                while(username[idx]!='\0'){
                    username_sekarang[idx] = username[idx];
                    idx++;
                }
                *username_idx = i;
                break;
            }
        }
        if(*loginStatus){
            printf("Anda telah login ke PURRMART sebagai %s.\n", username);
        }
        else{
            printf("Username atau password salah.\n");
        }
    }
}

void LOGOUT (char * username, int * username_idx){
    while(*username!='\0'){
        printf("%c", *username);
        *username = '\0';
        username++;
    }
    *username_idx = -1;
    printf(" telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n");
}

void WORK(TabInt *arrayUsers, int username_idx) {
    const char *pekerjaan[] = {
        "Evil Lab Assistant",
        "OWCA Hiring Manager",
        "Cikapundunginator Caretaker",
        "Mewing Specialist",
        "Inator Connoisseur"
    };
    int pendapatan[] = {100, 4200, 7000, 10000, 997};
    int durasi[] = {14, 21, 30, 22, 15};
    int num_works = 5;

    printf("Daftar pekerjaan:\n");
    for (int i = 0; i < num_works; i++) {
        printf("%d. %s (pendapatan=%d, durasi=%ds)\n", i + 1, pekerjaan[i], pendapatan[i], durasi[i]);
    }

    char pilih[100];
    int choice = -1;

    while (choice == -1) {
        printf("Masukkan nama pekerjaan yang dipilih: ");
        readString(pilih, sizeof(pilih));

        for (int i = 0; i < num_works; i++) {
            if (bandingkan_string(pilih, pekerjaan[i])) {
                choice = i;
                break;
            }
        }

        if (choice == -1) {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }

    printf("Anda sedang bekerja sebagai %s... harap tunggu.\n", pekerjaan[choice]);

    time_t start_time = time(NULL);
    while (time(NULL) - start_time < durasi[choice]) {
        // Menunggu hingga durasi pekerjaan selesai
    }
    arrayUsers->TI[username_idx].money += pendapatan[choice]; // Tambah uang user
    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", pendapatan[choice]);
}

void workChallenge(TabInt *arrayUsers, int username_idx){
    const char *challenges[] = {
        "Tebak Angka (biaya main = 200)",
        "WORDL399 (biaya main = 500)"
    };
    int biaya[] = {200, 500};
    const char *index[] = {
        "1",
        "2"
    };
    int num_challenges= 2;

    printf("Daftar challenge:\n");
    for (int i = 0; i < num_challenges; i++) {
        printf("    %d. %s (biaya=%d)\n", i+1, challenges[i], biaya[i]);
    }

    char pilih[100];
    int choice = -1;

    while (choice == -1) {
        printf("Masukkan challenge yang hendak dimainkan: ");
        readString(pilih, sizeof(pilih));

        for (int i = 0; i < num_challenges; i++) {
            if (bandingkan_string(pilih, index[i])) {
                choice = i;
                break;
            }
        }

        if (choice == -1) {
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }

    switch (choice)
    {
    case 0: // Case memilih Challenge TebakAngka
        if (arrayUsers->TI[username_idx].money < biaya[choice]) // Cek apakah uang user cukup
        {
            printf("Uang Anda Tidak Cukup (Uang Sekarang = %d)\n", arrayUsers->TI[username_idx].money);
            break;
        }
        arrayUsers->TI[username_idx].money -= biaya[choice]; // Kurangi uang user
        printf("Uang Berkurang %d (Uang Sekarang = %d)\n", biaya[choice], arrayUsers->TI[username_idx].money);
        TebakAngka(arrayUsers, username_idx);
        break;
    case 1: // Case memilih Challenge TebakAngka
        if (arrayUsers->TI[username_idx].money < biaya[choice]) // Cek apakah uang user cukup
        {
            printf("Uang Anda Tidak Cukup (Uang Sekarang = %d)\n", arrayUsers->TI[username_idx].money);
            break;
        }
        arrayUsers->TI[username_idx].money -= biaya[choice]; // Kurangi uang user
        printf("Uang Berkurang %d (Uang Sekarang = %d)\n", biaya[choice], arrayUsers->TI[username_idx].money);
        WORDL3(arrayUsers, username_idx);
        break;
    default:
        printf("Challenge Yang Dipilih Tidak Valid\n");
        break;
    }
}

void WORDL3(TabInt *arrayUsers, int username_idx) {
    const int PANJANG_KATA = 5;
    const int CHANCE = 6;
    const char *kata_kunci[] = {
        "BALAP", "BOGOR", "HITAM", "KAPAL", "KARAM",
        "RUSDI", "JOMOK", "HERTA", "IKUYO", "MEKAR"
    };
    srand(time(NULL));
    const char *jawaban = kata_kunci[rand() % 10];

    char tebakan[PANJANG_KATA + 1];
    char tampilan[CHANCE][PANJANG_KATA * 3 + 1];
    int count = 0;

    // Inisialisasi tampilan
    for (int i = 0; i < CHANCE; i++) {
        for (int j = 0; j < PANJANG_KATA; j++) {
            tampilan[i][j * 3] = '_';
            tampilan[i][j * 3 + 1] = ' ';
            tampilan[i][j * 3 + 2] = ' ';
        }
        tampilan[i][PANJANG_KATA * 3] = '\0';
    }

    printf("WELCOME TO W0RDL3, YOU HAVE %d CHANCES TO ANSWER BEFORE YOU LOSE!\n\n", CHANCE);

    // Cetak tampilan awal
    for (int i = 0; i < CHANCE; i++) {
        printf("%s\n", tampilan[i]);
    }
    printf("\n");

    while (count < CHANCE) {
        printf("Masukan kata tebakan Anda (%d huruf): ", PANJANG_KATA);
        readString(tebakan, PANJANG_KATA + 1);

        // Validasi panjang kata
        if (hitung_panjang(tebakan) != PANJANG_KATA) {
            printf("Kata harus berisi tepat %d huruf!\n\n", PANJANG_KATA);
            continue;
        }

        // Proses tebakan dan update tampilan
        for (int i = 0; i < PANJANG_KATA; i++) {
            tampilan[count][i * 3] = tebakan[i];
            if (tebakan[i] == jawaban[i]) {
                tampilan[count][i * 3 + 1] = ' '; // Benar posisi
                tampilan[count][i * 3 + 2] = ' ';
            } else if (cari_karakter(jawaban, tebakan[i])) {
                tampilan[count][i * 3 + 1] = '*'; // Benar huruf, salah posisi
                tampilan[count][i * 3 + 2] = ' ';
            } else {
                tampilan[count][i * 3 + 1] = '%'; // Huruf tidak ada
                tampilan[count][i * 3 + 2] = ' ';
            }
        }

        // Tampilkan hasil
        printf("\nHasil:\n");
        for (int i = 0; i <= count; i++) {
            printf("%s\n", tampilan[i]);
        }
        for (int i = count + 1; i < CHANCE; i++) {
            printf("_ _ _ _ _\n");
        }
        printf("\n");

        // Cek kemenangan
        if (bandingkan_string(tebakan, jawaban)) {
            printf("\nSelamat, Anda menang!\n");
            arrayUsers->TI[username_idx].money += 1500; // Tambah uang user
            printf("+1500 rupiah telah ditambahkan ke akun Anda.\n");
            return;
        }
        count++;
    }
    printf("Maaf, Anda kalah. Jawaban yang benar adalah: %s\n", jawaban);
}

void TebakAngka(TabInt *arrayUsers, int username_idx) {
   srand(time(NULL)); // Inisialisasi random seed
    int target = rand() % 100 + 1; 
    int kesempatan = 10;          
    int tebakan;                  

    printf("=====TEBAK ANGKA=====\n");

    while (kesempatan > 0) {
        printf("Tebak Angka (1-100): ");
        
        STARTWORD();
        if (isEndWord()) {
            printf("Input tidak valid. Silakan masukkan angka.\n");
            continue;
        }

        tebakan = wordToInt(currentWord);
        if (tebakan < 1 || tebakan > 100) {
            printf("Angka harus berada di antara 1-100. Silakan coba lagi.\n");
            continue;
        }

        if (tebakan == target) {
            int hadiah = 50 * kesempatan;
            arrayUsers->TI[username_idx].money += hadiah;
            printf("Tebakanmu benar! +%d rupiah telah ditambahkan ke saldo Anda.\n", hadiah);
            return;
        } else if (tebakan < target) {
            printf("Tebakanmu lebih kecil!\n");
        } else {
            printf("Tebakanmu lebih besar!\n");
        }

        kesempatan--; 
        if (kesempatan > 0) {
            printf("Kesempatan tersisa: %d\n", kesempatan);
        } else {
            printf("Maaf, kesempatanmu habis. Angka yang benar adalah %d.\n", target);
        }
    }
}

void PROFILE(TabInt *arrayUsers, int username_idx) {
    printf(">> PROFILE\n");
    printf("Nama: %s\n", arrayUsers->TI[username_idx].name);
    printf("Saldo: %d\n", arrayUsers->TI[username_idx].money);
}

void HISTORY(TabInt *arrayUsers, int username_idx, Word M) {
    int N;
    N = wordToInt(M);
    if (IsEmptyStack(*arrayUsers->TI[username_idx].riwayat_pembelian)) {
        printf("Kamu belum membeli barang apapun.\n");
        return;
    }

    printf(">> HISTORY %d\n", N);
    printf("Riwayat pembelian barang:\n");

    Stack tempStack = *arrayUsers->TI[username_idx].riwayat_pembelian; 
    int count = 0;

    while (!IsEmptyStack(tempStack) && count < N) {
        pembelian barang_dibeli;
        PopStack(&tempStack, &barang_dibeli);

        printf("%d. %s %d\n", count + 1, barang_dibeli.name, barang_dibeli.totalharga);
        count++;
    }
    printf("> Command mati; Kembali ke menu utama\n");
}


/*------------------------------ Help ------------------------------*/


/*-------------------------Program Cart------------------------------*/

void cartfunction(TabInt *arrayUsers, int username_idx, ArrayDin arrayitems, Word currentWord){
        if (compareWordToString(currentWord,"ADD")){
            ADD(arrayUsers->TI[username_idx].keranjang, arrayitems);
        }
        else if(compareWordToString(currentWord,"REMOVE")){
           REMOVE(arrayUsers->TI[username_idx].keranjang, arrayitems); 
        }
        else if(compareWordToString(currentWord,"SHOW")){
           SHOW(*arrayUsers->TI[username_idx].keranjang); 
        }
        else if(compareWordToString(currentWord,"PAY")){
           PAY(arrayUsers->TI[username_idx].keranjang, arrayUsers, username_idx); 
        }
}
void ADD(Map* UserCart, ArrayDin arrayItems){
    STARTWORD(); //baca nama barang
    char Name;
    salin_string(&Name,currentWord.TabWord);
    if (SearchArrayDin(arrayItems,&Name)){
        STARTWORD();
        int qty = wordToInt(currentWord);
        Barang item;
        item.price = Get(arrayItems,SearchArrayDin(arrayItems,&Name)).price;
        salin_string(item.name, Get(arrayItems,SearchArrayDin(arrayItems,&Name)).name);

        InsertMap(UserCart,item,qty);
        printf("Barang berhasil ditambah:%s %d",Name,qty);
    }
    else{printf("Barang tidak ada di toko");}
}
void REMOVE(Map* UserCart, ArrayDin arrayItems){
    STARTWORD();
    char Name;
    salin_string(&Name,currentWord.TabWord);
    Barang item  = Get(arrayItems,SearchArrayDin(arrayItems,&Name));
    if(IsMemberMap(*UserCart,item)){
        STARTWORD();
        int qty = wordToInt(currentWord);
        if (qty > ValueMap(*UserCart,item)){
                UserCart->Elements->Value -= qty;
                printf("Barang berhasil dikurangi, akhir: %s %d",Name,UserCart->Elements->Value);
        }
        else{printf("Input kuantitas berlebih");}
    }
    else{printf("Barang tidak ada di keranjang");}
}
void SHOW(Map UserCart){
    printf("Barang yang ada di keranjang:\n");
    printf("Nama            Qty         total\n");
    int totalprice = 0;
    for (int i; i=0; i < UserCart.Count, i++){
        int totalitem = UserCart.Elements[i].Key.price * UserCart.Elements[i].Value;
        totalprice += totalitem;
        printf("%s          %d          %d\n",UserCart.Elements[i].Key.name,UserCart.Elements[i].Value,totalitem);
    }
    printf("Total harga keranjang anda: %d\n",totalprice);
}

void PAY (Map* UserCart, TabInt *arrayUsers, int username_idx){
    int totalprice = 0;
    boolean PayStatus = false; // status pembayaran, (yes/no = true), else = false
    SHOW(*UserCart);
    for (int i; i=0; i < UserCart->Count, i++){
        int priceitem = UserCart->Elements[i].Key.price * UserCart->Elements[i].Value;
        totalprice += priceitem;
    }
    
    printf("apa anda ingin melakukan transaksi? (y/n)\n");
    START();
    if (currentChar == 'y'){
        if (arrayUsers->TI[username_idx].money > totalprice){
            arrayUsers->TI[username_idx].money -= totalprice;
            printf("Transaksi berhasil sisa uang anda: %d\n",arrayUsers->TI[username_idx].money);
            CreateEmptyMap(arrayUsers->TI[username_idx].keranjang);
            PayStatus = true;
        }
        else{printf("maaf uang anda tidak cukup\n");}
        
    }
    else if(currentChar == 'n'){
        printf("Kembali ke menu utama\n");
        PayStatus = true;
    }
    else{printf("Input tidak valid\n");}
    
}