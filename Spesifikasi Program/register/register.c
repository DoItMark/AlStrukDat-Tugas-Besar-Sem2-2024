#include <stdio.h>
#include "boolean.h"
#include "ListofUser.h"
#include "mesinkata.h"
#include "user.h"


void RegisterUser (List *Users, char Newname, char NewPW){
    if (IsUser(*Users,Newname)){
        InsertLast(&Users, Newname, NewPW);
    }
}
boolean IsUser (List Users,char name){
    Search(Users, name);
}