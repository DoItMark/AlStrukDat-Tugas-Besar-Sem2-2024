#include <stdio.h>
#include "../../boolean.h"
#include "ListofUser.h"
#include "../Mesin_Kata/mesinkata.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
ListUser MakeListUser() {
    ListUser L;
    for (int i = 0; i < MaxEl; i++) {
        stringCopy(L.A[i].name,"---"); // Initialize all elements with Mark
    }
    return L;
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(ListUser L){
    return stringComp(L.A[0].name,"---");
}
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
ElType Get(ListUser L, IdxType i){
    ElType Elm;
    User MarkUser;
    stringCopy(MarkUser.name,"---");
    if (!IsEmpty(L)){
        if(i > InvalidIdx && i < LastIdx(L)){
            *Elm.name = L.A[i].name;
        }
    }
    else{return MarkUser;}
    return Elm;
}
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(ListUser *L, IdxType i, ElType v){
    if (!IsEmpty(*L)){
        if(i > InvalidIdx && i < LastIdx(*L)){
            if (!stringComp(v.name, "---")){
                L->A[i] = v;
            }
            else{printf("value tidak valid");}
           
        }
        else{printf("Idx tidak valid");}
    }
    else{printf("List Kosong");}
    
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int LengthUser(ListUser L){
    int i = 0;
    while (!stringComp(L.A[i].name, "---")){
        i++;
    }
    return i;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxType FirstIdx(ListUser L){
    IdxType Idx = 0;
    return Idx;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdx(ListUser L){
    return Length(L) - 1;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (ListUser L, IdxType i){
    return i < MaxEl && IsIdxEff(L,i) && i != InvalidIdx;
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEff (ListUser L, IdxType i){
    return i < Length(L) && i != InvalidIdx;
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean Search(ListUser L, char name){
    for(int i; i = 0; i < Length(L),i++){
        if (stringComp(L.A[i].name, name)){
            return true;
        }
    }
    return false;
}
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertFirst(ListUser *L, ElType X) {
    InsertAt(L, X, 0); // Insert at index 0
}

void InsertAt(ListUser *L, ElType X, IdxType i) {
    int len = Length(*L);
    if (len < MaxEl && IsIdxValid(*L, i)) {
        for (int j = len; j > i; j--) {
            (*L).A[j] = (*L).A[j - 1]; // Shift elements to the right
        }
        (*L).A[i] = X; // Insert the element at index i
    }
}

void InsertLast(ListUser *L, char name, char password) {
    int len = Length(*L);
    if (len < MaxEl) {
        stringCopy((*L).A[len].name,name); // Insert at the end
        stringCopy((*L).A[len].password , password);

    }
}

void DeleteFirst(ListUser *L) {
    DeleteAt(L, 0); // Delete the first element
}

void DeleteAt(ListUser *L, IdxType i) {
    int len = Length(*L);
    if (len > 0 && IsIdxEff(*L, i)) {
        for (int j = i; j < len - 1; j++) {
            (*L).A[j] = (*L).A[j + 1]; // Shift elements to the left
        }
        stringCopy((*L).A[len - 1].name, "---"); // Mark the last element as undefined
    }
}

void DeleteLast(ListUser *L) {
    int len = Length(*L);
    if (len > 0) {
        stringCopy((*L).A[len - 1].name , "---"); // Remove the last element
    }
}

ListUser Concat(ListUser L1, ListUser L2) {
    ListUser L = MakeListUser();
    int len1 = Length(L1);
    int len2 = Length(L2);

    // Copy elements from L1
    for (int i = 0; i < len1; i++) {
        L.A[i] = L1.A[i];
    }

    // Copy elements from L2
    for (int i = 0; i < len2; i++) {
        L.A[len1 + i] = L2.A[i];
    }

    return L; // Return the concatenated list
}