#include "user.h"
#include <string.h>

User MakeUser() {
    User user;
    strcpy(user.name, "---");
    strcpy(user.password, "---");
    user.money = 0;
    return user;
}