// Struct untuk menyimpan data pengguna
typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money; // Jumlah uang pengguna
} User;

// Struct untuk menyimpan list pengguna
typedef struct {
    User elements[MAX_USERS];
    int size;
} List;
