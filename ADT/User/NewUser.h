typedef struct {
  char name[MAX_LEN];
  char password[MAX_LEN];
  integer money;
  Map keranjang;
  Stack riwayat_pembelian;
  Linkedlist wishlist;
} User;
