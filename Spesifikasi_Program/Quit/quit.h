#ifndef __QUIT_H__
#define __QUIT_H__

/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include "../../ADT/Barang/Barang.h"
#include "../../ADT/List_Dinamis/arraydinamis.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Kalimat/mesinkalimat.h"
#include "../../Spesifikasi_Program/Save/save.h"

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SPEK ** ****** ******** ******** ******** ******** ******** *** */

void QUIT(const Barang *barang_list, const Pengguna *pengguna_list);

#endif