#ifndef user_H
#define user_H
#include "../MapSet/mapsetCart.h"
#include "../Stack/stackHistory.h"
#include "../List_Linear/ListofWishlist.h"
#define MAX_LEN 100

typedef struct {
  char name[MAX_LEN];
  char password[MAX_LEN];
  int money;
  Map *keranjang;
  Stack *riwayat_pembelian;
  LinkedList *wishlist;
} User;


#endif
