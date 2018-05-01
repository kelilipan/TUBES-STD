#include "double.h"
#include "circular.h"
#include "head.h"
int main()
{
    int id=0;//nomer peserta
    bool Quit = false;
    bool adminstatus=false;
    bool statjuri=false;
    char choice;
    ListJ LJ;
    ListP LP;
    ListR LR;
    createlistJ(LJ);
    createlistP(LP);
    createlistR(LR);
    infojuri test;
    test.username="1";
    test.password="1";
    insertJuri(LJ,allocateJ(test));
    while(!Quit) {
        system("CLS");
        ShowMenu();
        choice=getch();
        switch (choice) {
            case '1':
                system("CLS");
                while (!adminstatus){
                    admin(adminstatus);//login admin
                    if (adminstatus){
                        system("CLS");
                        gotoxy(51,11) ;cout<<"LOGIN SUCCESS"<<endl;
                        cin.get();
                        adminstatus=true;
                    }else{
                        system("CLS");
                        gotoxy(51,16) ;cout<<"LOGIN FAIL"<<endl;
                        cin.get();
                  }
                }
                cin.get();
                menuadmin(LP,LJ,LR,id);
                adminstatus=false;
                break;
            case '2':{
                system("CLS");
                addressJ loggedin;
                while (!statjuri){
                    loginjuri(statjuri,LJ,loggedin);
                }
                cin.get();
                menujuri(LP,LJ,LR,loggedin);
                statjuri=false;
                break;}
            case '3':
                system("CLS");
                cout<<"Menu 3\n";
                menuguest(LP,LR);
                cin.get();
                break;
            case '4':
                system("CLS");
                cout<<"Menu 4\n";cin.get();
                break;
            case '5': //Quit
                 Quit = true;
                 cout<<"Realy??\n";
                 cin.get();
                break;
            default:
                  cout << "Whoops... " <<endl;cin.get();
                break;
        }
    }
    return 0;
}
