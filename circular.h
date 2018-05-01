#ifndef CIRCULAR_H_INCLUDED
#define CIRCULAR_H_INCLUDED
#include <iostream>

#define first(L) L.first
#define next(P) P->next
#define last(L) L.last
#define prev(P) P->prev
#define info(P) P->info

using namespace std;
/* PARENT */
typedef struct infojuri{
     string username;
     string password;
 };
typedef struct elmJ *addressJ;
typedef struct elmP *addressP;
typedef struct infoP {
     string  nama;
     int     no;
 };
struct elmJ {
    infojuri info;
    addressJ next;
};

struct elmP {
    infoP info;
    addressP next;
};

struct ListJ {
    addressJ first;
};
struct ListP {
    addressP first;
};

//PESERTA
void createlistP(ListP &L);
addressP allocateP(infoP x);
void deallocateP (addressP &P);

void insertpeserta(ListP &L,addressP P);

void delFirstP(ListP &L, addressP &P);
void delAfterP(ListP &L, addressP Prec, addressP &P);
void delLastP(ListP &L, addressP &P);


void checkCircularP(ListJ L);
addressP findElmP(ListP P, int x);
// JURI
void createlistJ(ListJ &L);
addressJ allocateJ(infojuri x);
void deallocateJ (addressJ &P);

void insertFirstJ(ListJ &L, addressJ P);
void insertAfterJ(addressJ &Prec, addressJ &P);
void insertLastJ(ListJ &L, addressJ P);
void insertJuri(ListJ &L,addressJ x);

void delFirstJ(ListJ &L, addressJ &P);
void delAfterJ(ListJ &L, addressJ Prec, addressJ &P);
void delLastJ(ListJ &L, addressJ &P);


addressJ findElmJ(ListJ L, string x);

bool cekuser(ListJ &L,string x);
void printJuri(ListJ L);
//test
void checkCircularJ(ListJ L);
void checkCircularP(ListP L);
void updateP(ListP &L,int x);
void updateJ(ListJ &L,string x);

#endif // CIRCULAR_H_INCLUDED
