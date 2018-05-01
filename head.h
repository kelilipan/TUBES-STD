#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include "double.h"
#include "circular.h"
#define pause system("pause")


using namespace std;


const string useradmin="admin";
const string passadmin="admin";
void gotoxy(const int x, const int y);
void ShowMenu();
void admin(bool &status);
void menuadmin(ListP &LP,ListJ &LJ,ListR &LR,int &id);
void loginjuri(bool &status,ListJ LJ,addressJ &loggedin);
void menujuri(ListP &LP,ListJ &LJ,ListR &LR,addressJ loggedin);
void testing();
void menuguest(ListP LP,ListR LR);
void deletePeserta(ListR &LR,ListP &LJ);
void deleteJuri(ListR &LR,ListJ &LJ);
#endif // HEAD_H_INCLUDED
