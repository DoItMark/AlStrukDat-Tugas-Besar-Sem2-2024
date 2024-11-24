#ifndef user_h
#define user_h

#define MAX_LEN 100

typedef struct {
  char name[MAX_LEN];
  char password[MAX_LEN];
  int money;
} User;
#endif