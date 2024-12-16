#ifndef newuser_h
#define newuser_h

#define MAX_LEN 20

typedef struct {
  char name[MAX_LEN];
  char password[MAX_LEN];
  int money;
  Map keranjang;
  Stack riwayat_pembelian;
  Linkedlist wishlist;
} User;


#endif
