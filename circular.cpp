#include "circular.h"
addressJ allocateJ(infojuri x){
    addressJ P = new elmJ;
    info(P)= x;
    next(P)=NULL;
    return P;
}
addressP allocateP(infoP x){
    addressP P;
    P = new elmP;
    info(P) = x;
    next(P) = NULL;
    return P;
}
void deallocateJ (addressJ &P){
    delete P;
    P =NULL ;
}
void deallocateP (addressP &P){
    delete P;
    P =NULL ;
}
void createlistJ(ListJ &L){
    first(L)=NULL;
}
void createlistP(ListP &L){
    first(L)=NULL;
}
void insertpeserta(ListP &L,addressP P){

    if (first(L)==NULL){
        first(L)=P;
        next(P)=P;
    }
    else{
        addressP Q= first(L);
        while(next(Q)!=first(L)) Q=next(Q);
        next(P) = first(L);
        next(Q)=P;
    }

}
addressP findElmP(ListP L, int x){
    addressP P = first(L);
    if(P!=NULL){
        while(next(P)!= first(L)&&info(P).no!=x) {
            P = next(P);
        }
        if (info(P).no==x) return P;
        else return NULL;
    }
    return NULL;

}
//void insertjuri(ListJ &L,addressJ J){
//    if (first(L)==NULL){
//        first(L)=J;
//        next(J)=J;
//    }
//    else{
//        next(J)=first(L);
//        first(L)=J;
//    }
//}
void insertFirstJ(ListJ &L, addressJ P){
    if(first(L) == NULL){
        first(L) = P;
        next(P) = P;
    }
    else {
        addressJ Q = first(L);
        while(next(Q) != first(L)) Q = next(Q);
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertAfterJ(addressJ &Prec, addressJ &P){
    next(P) = next(Prec);
    next(Prec) = P;
}

void insertLastJ(ListJ &L, addressJ P){
    if(first(L) == NULL){
        first(L) = P;
        next(P) = P;
    }
    else {
        addressJ Q = first(L);
        while(next(Q) != first(L)) Q = next(Q);
        next(P) = first(L);
        next(Q) = P;
    }
}

void delFirstJ(ListJ &L, addressJ &P){
    if(next(first(L)) == first(L)){
        P = first(L);
        next(P)= NULL;
        first(L) = NULL;
    }
    else {
        addressJ Q = first(L);
        while(next(Q) != first(L)) Q = next(Q);
        P = first(L);
        next(Q) = next(P);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void delAfterJ(ListJ &L, addressJ Prec, addressJ &P){
    if(next(Prec) == first(L)) delFirstJ(L,P);
    else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

void delLastJ(ListJ &L, addressJ &P){
    if(next(first(L)) == first(L)){
        P = first(L);
        next(P)= NULL;
        first(L) = NULL;
    }
    else {
        addressJ Q = first(L);
        while(next(next(Q)) != first(L)) Q = next(Q);
        P = next(Q);
        next(Q) = next(P);
        next(P) = NULL;
    }
}

addressJ findElmJ(ListJ L, string x){
    addressJ P = first(L);
    if(P!=NULL){
        while(next(P)!= first(L)&&info(P).username!=x) {
            P = next(P);
        }
        if (info(P).username==x) return P;
        else return NULL;
    }
    return NULL;

}



void delFirstP(ListP &L, addressP &P) {
    if(next(first(L)) == first(L)){
        P = first(L);
        next(P)= NULL;
        first(L) = NULL;
    }
    else {
        addressP Q = first(L);
        while(next(Q) != first(L)) Q = next(Q);
        P = first(L);
        next(Q) = next(P);
        first(L) = next(P);
        next(P) = NULL;
    }
}
void delAfterP(ListP &L, addressP Prec, addressP &P){
    if(next(Prec) == first(L)) delFirstP(L,P);
    else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}


void delLastP(ListP &L, addressP &P) {
    if(next(first(L)) == first(L)){
        P = first(L);
        next(P)= NULL;
        first(L) = NULL;
    }
    else {
        addressP Q = first(L);
        while(next(next(Q)) != first(L)) Q = next(Q);
        P = next(Q);
        next(Q) = next(P);
        next(P) = NULL;
    }
}
void insertJuri(ListJ &L,addressJ x){
    addressJ P=first(L);
        if(first(L)==NULL){
            insertFirstJ(L,x);
        }else{
            if(info(P).username<info(first(L)).username) insertFirstJ(L,x);
            //else if(info(P).username<=info(first(L)).username) insertLastJ(L,x);
            else{
                addressJ Q=first(L);
                while (info(x).username>info(next(Q)).username && next(Q)!=first(L)) Q=next(Q);
                insertAfterJ(Q,x);
            }
        }
}
bool cekuser(ListJ &L,string x){
    addressJ P=first(L);
    if (P!=NULL){
        while ((info(P).username!=x) && (next(P)!=first(L))) P=next(P);
        if (info(P).username==x) return true;
        else return false;
    }
    return false;
}
void printJuri(ListJ L) {
    addressJ P=first(L);
    if (P!=NULL){
        while (next(P)!=first(L)){
            cout<<"user : "<<info(P).username<<endl;
            P=next(P);
        }
        cout<<"user : "<<info(P).username<<endl;
    }
    cout<<endl;
}
void checkCircularP(ListP L) {
    cout<<"    ...CHECKING CIRCULAR..."<<endl;
    addressP P = first(L);
    if(P!=NULL)
        while(next(P)!= first(L)) {
            P = next(P);
        }
    cout<<"    circular OK"<<endl;
}

void checkCircularJ(ListJ L) {
    cout<<"    ...CHECKING CIRCULAR..."<<endl;
    addressJ P = first(L);
    if(P!=NULL)
        while(next(P)!= first(L)) {
            P = next(P);
        }
    cout<<"    circular OK"<<endl;
}

void updateP(ListP &L,int x){
    string namaP;
    addressP P = first(L);
    if (P!=NULL){
        while(next(P)!= first(L)&&info(P).no!=x) {
            P = next(P);
        }
        if (info(P).no==x){
            cout<<"Input Nama Lengkap : \n";cin>>namaP;
            info(P).nama=namaP;
        }
        else if (info(P).no!=x){
            cout<<"tidak ditemukan\n";
        }
    }
    else{
        cout<<"kosong\n";
    }

}

void updateJ(ListJ &L,string x){
    string namaP;
    string passj;
    addressJ P = first(L);
    if (P!=NULL){
        while(next(P)!= first(L)&&info(P).username!=x) {
            P = next(P);
        }
        if (info(P).username==x){
            cout<<"Input Nama Lengkap : \n";cin>>namaP;
            info(P).username=namaP;
            cout<<"Input Password Baru : \n";cin>>passj;
            info(P).password=passj;
        }
        else if (info(P).username!=x){
            cout<<"NOT FOUND!\n";
        }
    }
    else{
        cout<<"kosong\n";
    }

}

//void deleteP(ListP &L,int x){
//    addressP P=first(L);
//    if (info(P).no==x){
//        delFirstP(L,P);
//    }
//
//



