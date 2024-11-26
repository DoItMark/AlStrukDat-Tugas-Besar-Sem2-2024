#ifndef __STORE_REQUEST_H__
#define __STORE_REQUEST_H__

/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include "../../ADT/Barang/Barang.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Karakter/mesinkrakter.h"
#include "../../ADT/String/string.h"
#include "../../ADT/Queue/queue.h"
#include "../../ADT/Queue/QueueBarang.h"
#include "../../ADT/List_Statis/arraystatis.h"
#include "../../ADT/List_Dinamis/arraydinamis.h"
#include "../../ADT/List_Dinamis/arraydinamisbarang.h"

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SPEK ** ****** ******** ******** ******** ******** ******** *** */

void Store_Request(Queue *antrian, Arraydin *toko);

#endif