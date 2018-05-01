#ifndef DOUBLE_H_INCLUDED
#define DOUBLE_H_INCLUDED
#include <iostream>
#include "circular.h"
#define first(L) L.first
#define next(P) P->next
#define last(L) L.last
#define prev(P) P->prev
#define info(P) P->info

using namespace std;
/* RELASI */
typedef struct elmD *addressR;
typedef struct infotype {
     addressJ juri;
     addressP peserta;
     int nilai;
 };

struct elmD {
    infotype info;
    addressR next;
    addressR prev;
};using namespace std;

struct ListR {
    addressR first;
    addressR last;
};
int hitungnilai(ListR L,addressP x);
addressR allocateR(infotype x);
void deallocateR (addressR &P);
void createlistR(ListR &L);
void insertR(ListR &L ,addressR P);
void deletefirstR(ListR &L ,addressR &P);
void deletelastR (ListR &L ,addressR &P);
void deleteafterR(addressR prec,addressR &P);

void deleteRelasi(ListR &L,addressJ x,addressP y,addressR &out);

void printR(ListR L);
void printRjuri(ListR L,addressJ x);
addressR RfindElmJ(ListR L, addressJ x);
addressR RfindElmP(ListR L, addressP x);
bool cekpenilaian(ListR R,addressJ x,addressP y);
void printPeserta(ListP L,ListR R);
void printpenilaian(ListR L,addressP x,int &i);
void insertFirstR(ListR &L, addressR P);
void insertLastR(ListR &L, addressR P);
void insertAfterR(addressR Prec, addressR P);

void dummymake(ListR LR,ListP LP,ListR &out);

#endif // DOUBLE_H_INCLUDED
