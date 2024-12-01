
#include <stdio.h>
#include "boolean.h"
#include "ListofUser.h"
#include "user.h"
#include "string.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
List MakeList() {
    List L;
    for (int i = 0; i < MaxEl; i++) {
        salin_string(L.A[i].name,"---"); // Initialize all elements with Mark
    }
    return L;
}
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmpty(List L){
    return banding_string(L.A[0].name,"---");
}
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* *** Menghasilkan sebuah elemen *** */
ElType Get(List L, IdxType i){
    ElType Elm;
    User MarkUser;
    salin_string(MarkUser.name,"---");
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
void Set(List *L, IdxType i, ElType v){
    if (!IsEmpty(*L)){
        if(i > InvalidIdx && i < LastIdx(*L)){
            if (banding_string(v.name != "---")){
                L->A[i] = v;
            }
            else{printf("value tidak valid");}
           
        }
        else{printf("Idx tidak valid");}
    }
    else{printf("Lis Kosong");}
    
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int Length(List L){
    int i = 0;
    while (banding_string(L.A[i].name != "---")){
        i++;
    }
    return i;
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Selektor INDEKS *** */
IdxType FirstIdx(List L){
    IdxType Idx = 0;
    return Idx;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType LastIdx(List L){
    return Length(L) - 1;
}
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (List L, IdxType i){
    return i < MaxEl && IsIdxEff(L,i) && i != InvalidIdx;
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container*/

boolean IsIdxEff (List L, IdxType i){
    return i < Length(L) && i != InvalidIdx;
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

/* ********** Operasi-operasi ********** */
boolean Search(List L, char name){
    for(int i; i = 0; i < Length(L),i++){
        if (banding_string(L.A[i].name, name)){
            return true;
        }
    }
    return false;
}
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdx(L)..LastIdx(L) */

void InsertFirst(List *L, ElType X) {
    InsertAt(L, X, 0); // Insert at index 0
}

void InsertAt(List *L, ElType X, IdxType i) {
    int len = Length(*L);
    if (len < MaxEl && IsIdxValid(*L, i)) {
        for (int j = len; j > i; j--) {
            (*L).A[j] = (*L).A[j - 1]; // Shift elements to the right
        }
        (*L).A[i] = X; // Insert the element at index i
    }
}

void InsertLast(List *L, char name, char password) {
    int len = Length(*L);
    if (len < MaxEl) {
        salin_string((*L).A[len].name,name); // Insert at the end
        salin_string((*L).A[len].password , password);

    }
}

void DeleteFirst(List *L) {
    DeleteAt(L, 0); // Delete the first element
}

void DeleteAt(List *L, IdxType i) {
    int len = Length(*L);
    if (len > 0 && IsIdxEff(*L, i)) {
        for (int j = i; j < len - 1; j++) {
            (*L).A[j] = (*L).A[j + 1]; // Shift elements to the left
        }
        salin_string((*L).A[len - 1], "---"); // Mark the last element as undefined
    }
}

void DeleteLast(List *L) {
    int len = Length(*L);
    if (len > 0) {
        salin_string((*L).A[len - 1] , "---"); // Remove the last element
    }
}

List Concat(List L1, List L2) {
    List L = MakeList();
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