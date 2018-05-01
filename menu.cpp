#include "double.h"
#include "circular.h"
#include "head.h"
void ShowMenu() {
    cout << ">>>>>PROGRAM TALENT CONTEST<<<<<\n";
	cout << "***    1 - LOGIN ADMIN       ***\n";
	cout << "!!!    2 - LOGIN JURI        !!!\n";
	cout << "###    3 - LOGIN GUEST       ###\n";
    cout << "xxx    5 - EXIT              xxx\n\n";
	cout << "Your move: " << endl;

}

void admin(bool &status){
    string user;
    string pass;
    int marginright=10;
    int margintop=3;
    gotoxy(25+marginright,9+margintop) ;cout<<"==========================================\n";
    gotoxy(25+marginright,12+margintop);cout<<"==========================================\n";
    gotoxy(41+marginright,8+margintop) ;cout<<"ADMIN PAGE";
    gotoxy(30+marginright,10+margintop);cout<<"Masukkan Username : ";
    gotoxy(30+marginright,11+margintop);cout<<"Masukkan Password : ";
    gotoxy(50+marginright,10+margintop);cin>>user;
    gotoxy(50+marginright,11+margintop);cin>>pass;
    if ((user==useradmin)&&(pass==passadmin)) status = true;
    else status= false;
}
void loginjuri(bool &status,ListJ LJ,addressJ &loggedin){
    string user;
    string pass;
    int marginright=10;
    int margintop=3;
    //system("CLS");
    gotoxy(25+marginright,9+margintop) ;cout<<"==========================================\n";
    gotoxy(25+marginright,12+margintop);cout<<"==========================================\n";
    gotoxy(41+marginright,8+margintop) ;cout<<" JURI PAGE ";
    gotoxy(30+marginright,10+margintop);cout<<"Masukkan Username : ";
    gotoxy(30+marginright,11+margintop);cout<<"Masukkan Password : ";
    gotoxy(50+marginright,10+margintop);cin>>user;
    gotoxy(50+marginright,11+margintop);cin>>pass;
    addressJ P=findElmJ(LJ,user);
    //addressJ P=NULL;//for testing
    if (P==NULL) {
        system("CLS");
        gotoxy(48,16) ;cout<<"USERNAME NOT FOUND"<<endl;
    }
    else{
        if (pass==info(P).password && user==info(P).username){
            system("CLS");
            gotoxy(51,11) ;cout<<"LOGIN SUCCESS"<<endl;
            cin.get();
            status=true;
            loggedin=P;
        }
        else if (pass!=info(P).password){
            system("CLS");
            gotoxy(50,16) ;cout<<"WRONG PASSWORD"<<endl;
        }
        else{
            gotoxy(51,16) ;cout<<"UNKNOWN ERROR"<<endl;
            status=false;
        }
    }
 //    if ((user==useradmin)&&(pass==passadmin)) status = true;

}
void showmenuadmin(){
    cout << "*---^HELLO ADMIN^---*\n";
	cout << "1 - REGISTER PESERTA\n";
	cout << "2 - REGISTER JURI\n";
	cout << "3 - EDIT PESERTA\n";
	cout << "4 - EDIT JURI\n";
	cout << "5 - DELETE PESERTA\n";
	cout << "6 - DELETE JURI\n";
    cout << "7 - VIEW DETAIL PESERTA\n";
    cout << "8 - VIEW DETAIL JURI\n";
    cout << "9 - TESTING\n";
    cout << "X - EXIT\n";
	cout << "Your move: " << endl;

}
void menuadmin(ListP &LP,ListJ &LJ,ListR &LR,int &id){
    bool Quit = false;
    char choice;
    infojuri juri;
    bool sama = false;
    string stop;
    while(!Quit) {
        system("CLS");
        showmenuadmin();
        choice=getch();
        switch (choice) {
            case '1':{
                string nama;
                system("CLS");
                id++;
                cout<<"==================================\n";
                cout<<"++++++===REGISTER PESERTA===++++++\n";
                cout<<"----------------------------------\n";
                cout<<"No Registrasi\t\t : "<<id<<endl;
                cout<<"Input Nama Lengkap\t : ";cin>>nama;
                infoP peserta;
                peserta.nama=nama;
                peserta.no=id;
                insertpeserta(LP,allocateP(peserta));
                //cin.ignore() ;
                cout<<"INPUT BERHASIL";
                stop=getch();
                break;}
            case '2':
                system("CLS");
                cout<<"===================================\n";
                cout<<"+++++++++==REGISTER JURI==+++++++++\n";
                cout<<"Input username\t : ";cin>>juri.username;
                sama=cekuser(LJ,juri.username);
                if (sama) {
                        cout<<"USER SUDAH DIPAKAI";
                }
                    else {
                        cout<<"Input password\t : ";cin>>juri.password;
                        insertJuri(LJ,allocateJ(juri));
                        //insertFirstJ(LJ,allocateJ(juri));
                        cout<<"Input Successful";sama=true;
                }
                stop=getch();
                sama=false;
                break;
            case '3':{
                system("CLS");
                int nop;
                cout<<"======================================\n";
                cout<<"++++++++++==UPDATE PESERTA==++++++++++\n";cin.get();
                cout<<"Berapa no ID Peserta : ";cin>>nop;
                updateP(LP,nop);
                break;}
            case '4':{
                system("CLS");
                string nemJ;
                cout<<"======================================\n";
                cout<<"+++++++++++==UPDATE  JURI==+++++++++++\n";cin.get();
                cout<<"Nama juri yang ingin dicari : ";cin>>nemJ;
                updateJ(LJ,nemJ);
                break;}
            case '5': //delete pes
                system("CLS");
                cout<<"=======DELETE PESERTA=======\n";
                deletePeserta(LR,LP);
                pause;
                break;
            case '6': //delete juri
                system("CLS");
                cout<<"--------DELETE JURI--------\n";
                deleteJuri(LR,LJ);
                pause;
                break;
            case '7': //view pes
                system("CLS");
                cout<<"VIEW DETAIL PESERTA\n";
                printPeserta(LP,LR);
                pause;
                break;
            case '8': //view juri
                system("CLS");
                cout<<"VIEW DETAIL JURI\n";
                printJuri(LJ);
                //print
                pause;
                break;
            case '9': //testing
                system("CLS");
                cout<<"TESTING\n";
                printR(LR);cin.get();
                break;
            case 'x':
                Quit = true;
                cout<<"Realy??\n";
                cin.get();
                break;
            default:
                  cout << "Whoops... " <<endl;cin.get();
                break;
        }
    }
}
void menujuri(ListP &LP,ListJ &LJ,ListR &LR,addressJ loggedin){
    //system("CLS");
    char choice;
	int no;
	int nilai;
	bool Quit = false;
    while(!Quit) {
        system("CLS");
        cout << "HI JURY! "<<info(loggedin).username<<" !\n";
        cout << "1 - Detail Peserta\n";
        cout << "2 - Nilai Peserta\n";
        cout << "3 - Hapus Nilai\n";
        cout << "4 - History\n";
        cout << "5 - EXIT\n\n";
        cout << "Your move: " << endl;choice=getch();
        switch (choice) {
                case '1':
                    system("CLS");
                    //cout<<"Menu 7\n";
                    printPeserta(LP,LR);
                    pause;
                    break;
                case '2':{
                    system("CLS");
                    cout<<"MASUKAN ID PESERTA :";cin>>no;
                    addressP found=findElmP(LP,no);
                    if (found ==NULL){
                        cout<<"ID "<<no<<"  NOT FOUND"<<endl;pause;
                    }
                    else{
                        cout<<"ID FOUND\n";
                        bool cek=cekpenilaian(LR,loggedin,found);
                        if (cek){
                            cout<<"ANDA SUDAH MENILAI ID "<<no<<endl;pause;
                        }
                        else{
                            cout<<"NAMA\t\t : "<<info(found).nama<<endl;

                            cout<<"MASUKAN NILAI\t : ";cin>>nilai;
                            while (nilai>100||nilai<0){
                                if(nilai>100||nilai<0) {
                                        //gotoxy(0,4);
                                        cout<<"NILAI HARUS 1-100"<<endl;
                                }
                                //gotoxy(0,5);
                                cout<<"MASUKAN NILAI\t : ";cin>>nilai;
                            }
                            infotype penilaian;
                            penilaian.juri=loggedin;
                            penilaian.peserta=found;
                            penilaian.nilai=nilai;
                            insertR(LR,allocateR(penilaian));
                            pause;
                        }
                    }

                    break;}
                case '3':{//HAPUS PENILAIAN
                    system("CLS");
                    cout<<"Masukan ID yang akan dihapus\n";
                    cout<<"ID Peserta : ";cin>>no;
                    addressP found=findElmP(LP,no);
                    addressR R;
                    if (found==NULL){
                        cout<<"ID "<<no<<"  NOT FOUND"<<endl;pause;
                    }
                    else{
                        cout<<"ID FOUND\n";
                        bool cek=cekpenilaian(LR,loggedin,found);
                        if (cek){
                            cout<<"Deleting... "<<no<<endl;
                            deleteRelasi(LR,loggedin,found,R);
                            if (R!=NULL) cout<<"DELETE SUCCESSFUL\n";
                            else cout<<"UNKNOWN ERROR\n";
                            pause;
                        }
                        else{

                        }
                    }

                    cin.get();
                    break;}
                case '4':
                    system("CLS");
                    cout<<"History\n";
                    printRjuri(LR,loggedin);
                    pause;
                    break;
                case '5': //Quit
                     Quit = true;
                     loggedin=NULL;
                     cout<<"Realy??\n";
                     cin.get();
                    break;
                default:
                    cout << "Whoops... " <<endl;cin.get();
                    break;
            }
    }
}
void printPeserta(ListP L,ListR R) {
    addressP P=first(L);
    int i=2;
    //int space=0;
    //cout<<
    gotoxy(15,0);cout << "| ID |" << endl;gotoxy(43,0);cout << "NAMA" << endl;gotoxy(68,0);cout << "| NILAI |" << endl;
    gotoxy(85,0);cout << " DETAIL" << endl;gotoxy(100,0);cout << "|" << endl;
    gotoxy(15,1);cout << "======================================================================================" << endl;
    if (P!=NULL){
        while (next(P)!=first(L)){
            gotoxy(16,i);cout<<info(P).no;
            gotoxy(22,i);cout<<info(P).nama;
            gotoxy(71,i);cout<<hitungnilai(R,P);
            printpenilaian(R,P,i);
            P=next(P);
            i++;
        }
        gotoxy(16,i);cout<<info(P).no;
        gotoxy(22,i);cout<<info(P).nama;
        gotoxy(71,i);cout<<hitungnilai(R,P);
        printpenilaian(R,P,i);
    }
    cout<<endl;
}
void menuguest(ListP LP,ListR LR){
    char choice;
    bool Quit=false;
    ListR dummy;
    createlistR(dummy);
    while(!Quit) {
        system("CLS");
        cout << "HELLO GUEST?\n";
        cout << "1 - TOP 3\n";
        cout << "2 - HASIL PENILAIAN\n";
        cout << "3 - EXIT \n";
        cout << "Your move: " << endl;choice=getch();
        switch (choice) {
                case '1':{
                    system("CLS");
                    //cout<<"Menu 7\n";
                    if (first(LR)!=NULL) dummymake(LR,LP,dummy);
                    addressR wadaw=first(dummy);
                    //addressR wadaw=NULL;
                    cout<<"============TOP 3===============\n";
                    if (wadaw!=NULL) {
                        int i=0;
                        while (wadaw!=NULL&&i<3){
                            if (info(wadaw).nilai!=0){
                                cout<<i<<". "<<info(info(wadaw).peserta).nama<<"("<<info(info(wadaw).peserta).no<<")\n";
                                cout<<"\tNilai >>"<<info(wadaw).nilai<<"<<"<<endl;
                            }
                            i++;
                            wadaw=next(wadaw);
                        }
                    }
                    else cout<<"KOSONG\n";

                    pause;}
                    break;
                case '2':{
                    system("CLS");
                    printPeserta(LP,LR);pause;
                    break;}
                case '3':
                    Quit = true;
                    cout<<"Realy??\n";
                    //cin.get();
                    break;
                default:
                    cout << "Whoops... " <<endl;cin.get();
                    break;            }
    }
}
void deletePeserta(ListR &LR,ListP &LJ){
    int user;
    addressR aduh;
    addressP wa;
    bool firstCek=false;
    cout<<"Masukan NO ID Peserta : ";cin>>user;
    addressP P=findElmP(LJ,user);
    if (P==NULL){
        cout<<"USERNAME NOT FOUND\n";
    }
    else{
        cout<<"USERNAME FOUND\n";
        if (P==first(LJ)) delFirstP(LJ,P);
        else {
               addressP X=first(LJ);
               while (next(X)!=first(LJ)&& next(X)!=P) X=next(X);
               delAfterP(LJ,X,wa);
        }
        addressR Q=first(LR);
        if (Q==NULL){
            cout<<"ALREADY DELETED\n";
        }
        else{
            while(Q!=NULL){
                firstCek=false;
                if(info(info(Q).peserta).no==info(P).no){
                    if(first(LR)==last(LR)){
                        first(LR)=NULL;
                        last(LR)=NULL;
                    }
                    else if (Q==first(LR)){
                        addressR G=first(LR);
                        first(LR)=next(G);

                        Q=first(LR);
                        firstCek=true;
                        prev(next(G))=NULL;
                        next(G)=NULL;
                        //delete(G);
                    }
                    else if (Q==last(LR)){
                        addressR G=last(LR);
                        last(LR)=prev(G);



                        prev(G)=NULL;
                        next(G)=NULL;
                    }
                    else {
                        addressR prec=prev(Q);
                        addressR G=next(prec);

                        next(prec)=next(G);
                        prev(next(G))=prec;

                        Q=next(Q);

                        next(G)=NULL;
                        prev(G)=NULL;

                        Q=prev(Q);

                    }
                }
                else if (!firstCek) Q=next(Q);
            }


            cout<<"DELETE SUCCESSFUL"<<endl;
        }
    }
}

void deleteJuri(ListR &LR,ListJ &LJ){
    string user;
    addressR aduh;
    bool firstCek=false;
    cout<<"Masukan Username Juri : ";cin>>user;
    addressJ P=findElmJ(LJ,user);
    if (P==NULL){
        cout<<"USERNAME NOT FOUND\n";
    }
    else{
        cout<<"USERNAME FOUND\n";
        if (P==first(LJ)) delFirstJ(LJ,P);
        else {
               addressJ X=first(LJ);
               while (next(X)!=first(LJ)&& next(X)!=P) X=next(X);
               delAfterJ(LJ,X,P);
        }
        addressR Q=first(LR);
        if (Q==NULL){
            cout<<"ALREADY DELETED\n";
        }
        else{
            while(Q!=NULL){
                firstCek=false;
                if(info(info(Q).juri).username==info(P).username){
                    if(first(LR)==last(LR)){
                        first(LR)=NULL;
                        last(LR)=NULL;
                    }
                    else if (Q==first(LR)){
                        addressR G=first(LR);
                        first(LR)=next(G);

                        Q=first(LR);
                        firstCek=true;
                        prev(next(G))=NULL;
                        next(G)=NULL;
                        //delete(G);
                    }
                    else if (Q==last(LR)){
                        addressR G=last(LR);
                        last(LR)=prev(G);



                        prev(G)=NULL;
                        next(G)=NULL;
                    }
                    else {
                        addressR prec=prev(Q);
                        addressR G=next(prec);

                        next(prec)=next(G);
                        prev(next(G))=prec;

                        Q=next(Q);

                        next(G)=NULL;
                        prev(G)=NULL;

                        Q=prev(Q);

                    }
                }
                else if (!firstCek) Q=next(Q);
            }
            cout<<"DELETE SUCCESSFUL"<<endl;
        }
    }
}





























