#ifndef __START_H__
#define __START_H__

/* *** ******** ******** ******** ******** ******** ****** ** INCLUDED ADT & SPEK ** ****** ******** ******** ******** ******** ******** *** */

#include "../../ADT/Barang/Barang.h"
#include "../../ADT/User/User.h"
#include "../../ADT/Mesin_Karakter/mesinkarakter.h"
#include "../../ADT/Mesin_Kata/mesinkata.h"
#include "../../ADT/Mesin_Kalimat/mesinkalimat.h"

/* *** ******** ******** ******** ******** ******** ****** ** COMMAND SPEK ** ****** ******** ******** ******** ******** ******** *** */

void START(char filename[], const Barang *barang_list, const Pengguna *pengguna_list);

#endif