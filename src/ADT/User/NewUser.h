#ifndef newuser_h
#define newuser_h
#include "../MapSet/mapsetCart.h"
#include "../Stack/stack.h"
#include "../linkedlist/listlinier.h"
#define MAX_LEN 20

typedef struct {
  char name[MAX_LEN];
  char password[MAX_LEN];
  int money;
  Map keranjang;
  Stack riwayat_pembelian;
  LinkedList wishlist;
} User;


#endif
