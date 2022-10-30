#include <iostream>
#include "salon.h"
#include "film.h"
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
ostream &operator << (ostream &output,Salon &s){
    cout<<"====Salon Bilgileri===="<<endl;
    output<<"numara: "<<s.numara<<"\n"
    <<"tip: "<<s.tip<<"\n"
    <<"kapasite: "<<s.kapasite<<"("<<s.x<<"x"<<s.y<<")\n"
    <<"seans saatleri: |";
    for(int i=0;i<10;i++)if(s.seanslar[i].getsaat()!=0){output<<s.seanslar[i].getsaat()<<"|";}
    cout<<"\n=========================================="<<endl;
    return output;
}//operator end
Salon &Salon::operator=(const Salon &obj){
     this->numara = obj.numara;
     this->tip = tip;
     this->x = obj.x;
     this->y = obj.y;
     this->kapasite = obj.kapasite;
     for(int i=0;i<obj.x;i++){
        for(int j=0;j<obj.y;j++){
           this->koltuknumaralari[i][j]= obj.koltuknumaralari[i][j];
        }
     }
    for(int i=0;i<10;i++){this->seanslar[i]=obj.seanslar[i];}
    return *this;
}
bool operator== (const Salon &obj1, const Salon &obj2){
    if(obj1.numara==obj2.numara && obj1.tip == obj2.tip && obj1.x == obj2.x && obj1.y == obj2.y){
       for(int i=0;i<10;i++){if(obj1.seanslar[i].getsaat()!=obj2.seanslar[i].getsaat()){return false;}
       }
       return true;
    }

    else{ return false;}
}

Salon::Salon(){
 numara=0;
 tip="belirtilmedi";
 x=0;
 y=0;
 kapasite=x*y;
 seanslar = new Seans[10];//burasi custom yapilabilir
 koltuknumaralari = new int*[y];
 int i,j;
 for(i=0;i<x;i++){
    koltuknumaralari[i]= new int[x];
 }

 for(i=0;i<x;i++){
    for(j=0;j<y;j++){
        this->koltuknumaralari[i][j]=0;}}
}
Salon::Salon(int numara,string tip,int x, int y){
    this->numara = numara;
    this->tip = tip;
    this->x = x;
    this->y = y;
    kapasite=x*y;
    seanslar = new Seans[10];
    koltuknumaralari = new int*[y];
    int i;
    for(i=0;i<x;i++){
        koltuknumaralari[i]= new int[x];
    }

    int counter=1;
    for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
        koltuknumaralari[i][j]=counter;counter++;}}
}
//ctors
void Salon::setnumara(int numara){this->numara=numara;}
void Salon::settip(string tip){this->tip=tip;}
void Salon::setxy(int x, int y){
    this->x = x;
    this->y = y;
    kapasite=x*y;
    seanslar = new Seans[10];
        koltuknumaralari = new int*[y];
    int i;
    for(i=0;i<x;i++){
        koltuknumaralari[i]= new int[x];
    }
    int counter=1;
    for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
        koltuknumaralari[i][j]=counter;counter++;}}
}

void Salon::setalldata(int numara,string tip,int x,int y){
    setnumara(numara);
    settip(tip);
    setxy(x,y);
}
int Salon::getnumara(){return numara;}
string Salon::gettip(){return tip;}
int Salon::getx(){return x;}
int Salon::gety(){return y;}

void Salon::koltukduzeninigoster(){
    int i,j;
    cout<<"\t**********************************************************"<<endl;
    cout<<"\t|__________________________________________________|"<<endl;
    for(i=x-1;i>=0;--i){
        for(j=0;j<y;++j){
            cout<<"\t| ";if(koltuknumaralari[i][j]<10){cout<<" ";}
            cout<<koltuknumaralari[i][j]<< "|";}
        cout<<"\n\t|_______________________________________________|"<<endl;}
    cout<<"\n\t*********************************************************"<<endl;
}//function end
void Salon::seansolustur(){
    int i,ch,sset,sayi;
    double seanssaatleri1[8]={11.00,13.30,16.00,18.30,21.00,22.30,23.45,00.30};
    double seanssaatleri2[8]={09.00,11.30,13.00,14.30,16.00,19.00,21.00,22.45};
    system("cls");
    cout<<"1: |";
    for(i=0;i<8;i++){cout<<fixed<<showpoint;cout<<i+1<<"-"<<setprecision(2)<<seanssaatleri1[i]<<"|";}
    cout<<endl;
    cout<<"2: |";
    for(i=0;i<8;i++){cout<<fixed<<showpoint;cout<<i+1<<"-"<<setprecision(2)<<seanssaatleri2[i]<<"|";}
    cout<<"Hangi seans saat setini kullanmak istersiniz?: ";
    cin>>sset;
    cout<<"Saat degistirmek istiyor musunuz? 1:YES|NO:2"<<endl;
    cin>>ch;
    if(ch==1&&sset==1){
        double yenisaat;
        cout<<"Kac tane: ";
        cin>>sayi;
        for(i=0;i<sayi;i++){
        cout<<"hangisi:";
        cin>>ch;
        cout<<"yeni saat: ";
        cin>>yenisaat;
        seanssaatleri1[ch-1]=yenisaat;}}
    else if(ch==1&&sset==2){
        double yenisaat;
        cout<<"Kac tane: ";
        cin>>sayi;
        for(i=0;i<sayi;i++){
        cout<<"hangisi:";
        cin>>ch;
        cout<<"yeni saat: ";
        cin>>yenisaat;
        seanssaatleri2[ch-1]=yenisaat;}}

        i=0;
        if(sset==1){
            //while(seanssaatleri1[i+1]!=NULL){
                while(i!=8){
                seanslar[i].setsaat(seanssaatleri1[i]);
                //cout<<seanslar[i].getsaat()<<"-";
                seanslar[i].setdurum(true);
                seanslar[i].setdolukoltuklarlistesi(kapasite);
            ++i;}
        }
        else if(sset==2){
            //while(seanssaatleri1[i+1]!=NULL){
           while(i!=8){
                seanslar[i].setsaat(seanssaatleri2[i]);
                seanslar[i].setdurum(true);
                seanslar[i].setdolukoltuklarlistesi(kapasite);
            i++;}
        }
}//function end

void Salon::boskoltuklarigoster(int seans){
    int i,j;
    for(i=x-1;i>=0;--i){
        for(j=0;j<y;++j){
            if(seanslar[seans-1].dolukoltuklar[koltuknumaralari[i][j]]!=koltuknumaralari[i][j]){
            //cout<<elm<<":"<<seanslar[seans].dolukoltuklar[elm]<<"--"<<i*j<<":"<<koltuknumaralari[i][j]<<endl;
            cout<<"____";
            cout<<"|"<<koltuknumaralari[i][j]<<"|";}
            else if(seanslar[seans-1].dolukoltuklar[koltuknumaralari[i][j]]==koltuknumaralari[i][j]){
            cout<<"____";
            cout<<"|"<<"X"<<koltuknumaralari[i][j]<<"X"<<"|";}

            }//for end
        cout<<"__________"<<endl;
    }//out for end
}//function end
int Salon::koltuklariyonet(int seans, int mode){
    //koltuýk seciminde surekli menu secmeyle ugrasilmamali
    //bu yuzden mode ile tasarladim
    cout<<"\t==Seans: "<<seans<<" =="<<endl;
    boskoltuklarigoster(seans);
    int numara;
    if(mode==1){//doldur
            cin>>numara;
            seanslar[seans-1].koltukdoldur(numara);
    }
    else if(mode==2){//bosalt
        cin>>numara;
        seanslar[seans-1].koltukbosalt(numara);
    }
    return numara;

}//function end
void Salon::salonozelliklerinigoster(){
    system("cls");
    cout<<"=====Salon: "<<numara<<"====="<<endl;
    cout<<"tip: "<<tip<<endl;
    cout<<"Kapasite: "<<kapasite<<"("<<x<<"x"<<y<<")"<<endl;
    cout<<seanslar[0].getsaat()<<"-"<<seanslar[1].getsaat()<<endl;
    cout<<"Seanslar: |";for(int i=0;i<8;i++){if(seanslar[i].getdurum()==1){cout<<seanslar[i].getsaat()<<"|";}}
    cout<<"==============================="<<endl;
}
void Salon::seansafilmekle(){
    system("cls");
    int ch;
    cout<<"Seanslar: |";for(int i=0;i<10;i++){if(seanslar[i].getdurum()){cout<<i+1<<":"<<seanslar[i].getsaat()<<"|";}}
    while(ch!=10){
    cout<<"\nHangi seansa film ekleyeceksiniz:(geri donmek icin 0 girin) ";
    cin>>ch;
    if(ch==0){break;}
    ch-=1;
    seanslar[ch].filmekle();
    }

    }
void Salon::seansfilmigoster(){
    system("cls");
    int ch;
    cout<<"Seanslar: |";for(int i=0;i<10;i++){if(seanslar[i].getdurum()){cout<<i+1<<":"<<seanslar[i].getsaat()<<"|";}}
    while(ch!=10){
    cout<<"\nHangi seansin filmini goruntuleyeceksiniz:(geri donmek icin 0 girin) ";
    cin>>ch;
    if(ch==0){break;}
    ch-=1;
    seanslar[ch].filmgoster();
}
}
void Salon::tumseanslardakifilmigoster(){
    cout<<"\t**************************************************************"<<endl;
    cout<<"\t|********************====FILMLER====***********************|"<<endl;
    cout<<"\t--------------------------------------"<<endl;
    for(int i=0;i<8;i++){
    cout<<"\t|\t\t"
    <<i+1<<". |"<<seanslar[i].getsaat()<<"|"<<seanslar[i].seansfilmi.get_film_adi()<<"|"<<"\t\t|"<<endl;}
    cout<<"\t--------------------------------------"<<endl;

}
Film& Salon::getfilmverileri(int seans){
    return seanslar[seans-1].seansfilmi;
}
double Salon::getseanssaati(int seans){
   return seanslar[seans-1].getsaat();
}

//Seans class functions/////
Seans::Seans(){
    saat=0;
    durum=false;

}
Seans::Seans(double saat, bool durum, int kapasite){
    this->saat = saat;
    this->durum = durum;
    dolukoltuklar= new int[kapasite+1];
    for(int i=0;i<kapasite+1;i++){
        dolukoltuklar[i]=0;
    }
}
//ctors
void Seans::setsaat(double saat){this->saat=saat;}
void Seans::setdurum(bool durum){this->durum=durum;}
void Seans::setdolukoltuklarlistesi(int kapasite){
    dolukoltuklar= new int[kapasite+1];
    for(int i=0;i<kapasite+1;i++){dolukoltuklar[i]=0;}
}
double Seans::getsaat(){return saat;}
bool Seans::getdurum(){return durum;}

void Seans::getdolukoltuklar(int kapasite){
    kapasite+=1;
    int i=0;
    for(i=0;i<kapasite;i++){
        //if(dolukoltuklar[i]<kapasite&&dolukoltuklar[i]>0){
        cout<<dolukoltuklar[i]<<endl;
        //}
    }
}
void Seans::koltukdoldur(int numara){
    if(dolukoltuklar[numara]==0){
    dolukoltuklar[numara]=numara;
    cout<<dolukoltuklar[numara]<<endl;}
    }
void Seans::koltukbosalt(int numara){
    if(dolukoltuklar[numara]==0){
        cout<<"Zaten bos"<<endl;
    }
    else{dolukoltuklar[numara]=0;}
}
void Seans::filmekle(){
    int ch;
    seansfilmi.vizyondakileri_goster();
    fstream file;
    file.open("vizyondaki_filmler.txt", ios::in);
    cout<<"Sectiginiz filmin kodunu giriniz: ";
    cin>>ch;
    int film_kodu;
    while(file>>film_kodu)
    {
		if(ch==film_kodu){
		string film_adi,genre;
        int yas_siniri;
        bool TD;
        double salon_ucreti,gozluk_ucreti,imax_ucreti;
        int vizyon_gun,vizyon_ay,vizyon_yil,haftalik_vizyon_suresi;

        file>>film_adi;
        file>>genre;
        file>>yas_siniri;
        file>>TD;
        file>>salon_ucreti;
        file>>gozluk_ucreti;
        file>>imax_ucreti;
        file>>vizyon_gun;
        file>>vizyon_ay;
        file>>vizyon_yil;
        file>>haftalik_vizyon_suresi;
     seansfilmi.set_film_kodu(film_kodu);
     seansfilmi.set_film_adi( film_adi);
     seansfilmi.set_genre( genre);
     seansfilmi.set_yas_siniri( yas_siniri);
     seansfilmi.set_TD( TD);
     seansfilmi.set_salon_ucreti(salon_ucreti);
     seansfilmi.set_gozluk_ucreti(gozluk_ucreti);
     seansfilmi.set_imax_ucreti(imax_ucreti);
     seansfilmi.set_vizyon_gun(vizyon_gun);
     seansfilmi.set_vizyon_ay(vizyon_ay);
     seansfilmi.set_vizyon_yil(vizyon_yil);
     seansfilmi.set_haftalik_vizyon(haftalik_vizyon_suresi);
     cout<<seansfilmi;
		}
    }
    file.close();
}
void Seans::filmgoster(){if(saat!=0){cout<<saat<<":"<<seansfilmi;}}



