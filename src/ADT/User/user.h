#ifndef user_h
#define user_h

#include "../Mesin_Kata/mesinkata.h"
#include "../Mesin_Karakter/mesinkarakter.h"

#define MAX_LEN 15

typedef struct {
  char name[MAX_LEN];
  char password[MAX_LEN];
  int money;
} User;

User MakeUser();


#endif