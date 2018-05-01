#include "double.h"
#include <windows.h>
void gotoxy(const int x, const int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD PlaceCursorHere;
    PlaceCursorHere.X = x;
    PlaceCursorHere.Y = y;
    SetConsoleCursorPosition(hConsole, PlaceCursorHere);
    return;
}
addressR allocateR(infotype x){
    addressR P = new elmD;
    info(P)= x;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}

void deallocateR (addressR &P){
    delete P;
    P =NULL ;
}
void createlistR(ListR &L){
    first(L)=NULL;
    last(L)=NULL;
}
void insertR(ListR &L ,addressR P){
       if (first(L)== NULL){
        first(L)=P;
        last(L)=P;
    }
    else{

        prev(P)=last(L);
        next(last(L))=P;
        last(L)=P;
        }
}
void insertFirstR(ListR &L, addressR P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }else{
        next(P)=first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}
void insertLastR(ListR &L, addressR P){
    if(first(L) == NULL){
        first(L) = P;
        last(L)= P;
    }else{
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}
void insertAfterR(addressR Prec, addressR P){
    next(P) = next(Prec);
    prev(P) = Prec;

    prev(next(Prec)) = P;
    next(Prec) = P;
}
void deletefirstR(ListR &L ,addressR &P){
    P=first(L);
    if (first(L)!=NULL){
        if (next(P)!=NULL){
            first(L)=next(P);
            prev(next(P))=NULL;
            next(P)=NULL;
        }
        else{
            first(L)=NULL;
            last(L)=NULL;
        }
    }
}

void deletelastR (ListR &L ,addressR &P){
    P=last(L);
    if (P!=NULL){
        if (prev(P)!=NULL){
            last(L)=prev(P);
            prev(P)=NULL;
            next(P)=NULL;
        }
        else{
            first(L)=NULL;
            last(L)=NULL;
        }
    }
}
void deleteafterR(addressR prec,addressR &P){
    P=next(prec);
    next(prec)=next(P);
    prev(next(P))=prec;
    next(P)=NULL;
    prev(P)=NULL;
}
void deleteRelasi(ListR &L,addressJ x,addressP y,addressR &out){
    addressR P=first(L);
    if (P!=NULL){
        while(next(P) != NULL && (info(P).juri!=x||info(P).peserta!=y)){
            P=next(P);
        }
        if (info(P).juri==x && info(P).peserta==y) {
            if(P==first(L)) deletefirstR(L,P);
            else if (P==last(L)) deletelastR(L,P);
            else deleteafterR(prev(P),P);
        } else P=NULL;
    }
    else P=NULL;

    out=P;

}
void printR(ListR L){
    addressR P;
    P=first(L);
    int i=1;
    while (P!=NULL){
        cout<<i<<" . "<<info(info(P).juri).username<<" TO "<<info(info(P).peserta).nama<<" +"<<info(P).nilai<<endl;
        P=next(P);
        i++;
    }
}
void printRjuri(ListR L,addressJ x){
    addressR P;
    P=first(L);
    while (P!=NULL){
        if(info(P).juri==x){
            cout<<"Nama "<<info(info(P).peserta).nama<<"\tNilai\t +"<<info(P).nilai<<endl;
        }
        P=next(P);
    }
}

addressR RfindElmJ(ListR L, addressJ x){
    addressR P = first(L);
    while(next(P) != NULL && info(P).juri!=x){
        P=next(P);
    }
    if (x==info(P).juri) return P;
    else return NULL;
}

addressR RfindElmP(ListR L, addressP x){
    addressR P = first(L);
    while(next(P) != NULL && info(P).peserta!=x){
        P=next(P);
    }
    if (x==info(P).peserta) return P;
    else return NULL;
}
int hitungnilai(ListR L,addressP x){
    addressR P = first(L);
    int total=0;
    while(P != NULL){
        if (x==info(P).peserta) total=total+info(P).nilai;
        P=next(P);
    }
    return total;
}
void printpenilaian(ListR L,addressP x,int &i){
    addressR P = first(L);
    //space=0;
    while(P != NULL){
        if (x==info(P).peserta){
            gotoxy(78,i);cout<<info(info(P).juri).username<<" +"<<info(P).nilai<<endl;
            i++;
        }P=next(P);
    }
    //if(first(L)!=NULL) i--;
}
bool cekpenilaian(ListR R,addressJ x,addressP y){
    addressR P = first(R);
    if (P!=NULL){
        while(next(P) != NULL && (info(P).juri!=x||info(P).peserta!=y)){
            P=next(P);
        }
        if (info(P).juri==x && info(P).peserta==y) return true;
        else return false;
    }
    return false;
}
void dummymake(ListR LR,ListP LP,ListR &out){
    ListR temp;
    createlistR(temp);
    addressP P=first(LP);
    infotype dummy;
    dummy.juri=NULL;
    while (next(P)!=first(LP)){
        dummy.peserta=P;
        dummy.nilai=hitungnilai(LR,P);
        addressR Q=first(temp);
        if (Q==NULL) insertFirstR(temp,allocateR(dummy));
        else{
            if (dummy.nilai>info(first(temp)).nilai) insertFirstR(temp,allocateR(dummy));
            else if(dummy.nilai<info(last(temp)).nilai) insertLastR(temp,allocateR(dummy));
            else{
                //addressR waduh=first(temp);
                while(dummy.nilai<info(next(Q)).nilai) Q=next(Q);
                insertAfterR(Q,allocateR(dummy));
            }
        }
        P=next(P);
    }
    dummy.peserta=P;
    dummy.nilai=hitungnilai(LR,P);
    addressR Q=first(temp);
    if (Q==NULL) insertFirstR(temp,allocateR(dummy));
    else{
        if (dummy.nilai>info(first(temp)).nilai) insertFirstR(temp,allocateR(dummy));
        else if(dummy.nilai<info(last(temp)).nilai) insertLastR(temp,allocateR(dummy));
        else{
            //addressR waduh=first(temp);
            while(dummy.nilai<info(next(Q)).nilai) Q=next(Q);
            insertAfterR(Q,allocateR(dummy));
        }
    }
    out=temp;
}
//void printJ()
//
//    }
//
//}





