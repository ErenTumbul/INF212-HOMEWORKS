#include <iostream>
#include "sinema.h"
#include "salon.h"
#include "film.h"
#include "musteri.h"
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
using namespace std;
Sinema::Sinema(){
    salonsayisi=0;
    arsivdekifilmsayisi=0;
}
void Sinema::Ana_menu(){
    system("cls");
    int ch;
    menu:
    cout<<"\n\n\t\t===== ANA   MENU =====\n"
        <<"\t\t|1. Yonetici Arayuzu |\n"
        <<"\t\t|2. Gorevli Arayuzu  |\n"
        <<"\t\t|3. Cikis            |\n"
        <<"\t\t----------------------"
        <<"\n\n\tGirmek istediginiz arayuzunu seciniz: ";
        cin>>ch;

        if(ch==1)
        {

            admin_menu();
        }
        else if(ch==2)
        {
            stuff_menu();
        }
        else if(ch==3)
            exit(0);
        else
        {
            cout<<"Boyle bir secenek yok!"<<endl;
            goto menu;
        }
}

void Sinema::admin_menu()
{
    system("cls");
    cout<<"\n\t\t====== YONETICI MENU ======"<<endl;
    int choice;
    menu:
    cout<<"\t\t|1. Salonlari Yonet     |\n"
        <<"\t\t|2. Film Arsivini Yonet |\n"
        <<"\t\t|3. Istatistiklere Gozat|\n"
        <<"\t\t|4. Geri don            |\n"
        <<"\n\t\tSeciminizi giriniz: ";
        cin>>choice;

        if(choice==1)
        {
            salonmenusu();
        }
        else if(choice==2)
        {
            film_menu();
        }
        else if(choice==3)
        {
            istatistik_menu();
        }
        else if(choice==4){
            Ana_menu();
        }
        else{
            cout<<"Boyle bir secenek yok!"<<endl;
            goto menu;
        }
        goto menu;
}
void Sinema::stuff_menu(){
    system("cls");
    int ch;
    menu:
    cout<<"\n\n\t\t===== GOREVLI   MENU =====\n"
        <<"\t\t|1. Ekranlari Goster |\n"
        <<"\t\t|2. Bilet olustur    |\n"
        <<"\t\t|3. Geri don            |\n"
        <<"\t\t----------------------"
        <<"\n\n\tGirmek istediginiz arayuzunu seciniz: ";
        cin>>ch;

        if(ch==1)
        {
            ekranlarigoster();
        }
        else if(ch==2)
        {
            biletkes();
        }
        else if(ch==3)
            Ana_menu();
        else
        {
            cout<<"Boyle bir secenek yok!"<<endl;
            goto menu;
        }
        goto menu;
}
void Sinema::istatistik_menu(){
    ma.analiz_goster();
    cout<<"Devam etmek icin bir tusa basiniz..."<<endl;
    getch();
    system("cls");
}
void Sinema::film_menu()
{
    system("cls");
    Film f;
    int choice;
    f.tarih();
    menu:
    cout<<"\n\t\t|1. Arsive Film Ekle             |\n"
        <<"\t\t|2. Arsivdeki Filmleri Goruntule |\n"
        <<"\t\t|3. Arsivdeki Filmleri Duzenle   |\n"
        <<"\t\t|4. Vizyondaki Filmleri Goster   |\n"
        <<"\t\t|5. Admin Arayuzune Don          |\n"
        <<"\n\t\t Seceneginizi Giriniz: ";
        cin>>choice;

    if(choice==1){
        f.film_arsivi_olustur();}

    else if(choice==2){
        f.film_arsivini_goster();}

    else if(choice==3)
    {
        f.film_arsivini_goster();
        f.film_arsivi_duzenle();
    }

    else if(choice==4)
    {
        f.vizyon_sifirla();
        f.vizyon_durumu();
        f.vizyondakileri_goster();
    }

    else if(choice==5)
        admin_menu();
    else{
        cout<<"Boyle bir secenek bulunmamaktadir!"<<endl;
        goto menu;
    }
    goto menu;
}

void Sinema::salonmenusu(){
    system("cls");
    int ch;
    menu:
    cout<<"\n\t\t|1. Salon ekle                   |\n"
        <<"\t\t|2. Salon bilgilerini goster     |\n"
        <<"\t\t|3. Seans filmini belirle        |\n"
        <<"\t\t|4. Seans filmini goruntule      |\n"
        <<"\t\t|5. Geri don                     |\n"
        <<"\n\t\t Seceneginizi Giriniz: ";
        cin>>ch;
    if(ch==1){salonekle(salonsayisi);}
    else if(ch==2){salondatagoster(salonsayisi);}
    else if(ch==3){seansfilminibelirle();}
    else if(ch==4){seansfilminigoster();}
    else if(ch==5){Ana_menu();}
    goto menu;
}
void Sinema::salonekle(int salonsayisi){
    if(salonsayisi==0){
        int x,y;
        cout<<"SALON OLUSTURMA SAYFASINA HOSGELDINIZ"<<endl;
        cout<<"Olusturacaginiz ilk salon bilgileri template olacaktir"<<endl;
        cout<<"Template ile diger salonlari otomatik sekilde ekleyebilirsiniz"<<endl;
        cout<<"XxY giriniz: ";
        cin>>x>>y;
        //salonlar = new Salon(salonsayisi,"standart",x,y);memory allocation
        salonlar[salonsayisi].setalldata(salonsayisi,"standart",x,y);
        salonlar[salonsayisi].seansolustur();
        //cout<<salonlar[salonsayisi];
        this->salonsayisi++;}
    else{
    int ch,number;
    cout<<"Kac salon eklemek istiyorsunuz"<<endl;
    cin>>number;
    cout<<"Template kullanarak kopyalar olusturulsun mu?(1:Y|N:2): ";
    cin>>ch;
    if(ch==1){
        cout<<"::";
        for(int i=0;i<number;i++){
                cout<<":::salonsayisi"<<this->salonsayisi;
                salonlar[salonsayisi+i].setalldata(salonsayisi+i,salonlar[0].gettip(),salonlar[0].getx(),salonlar[0].gety());
                salonlar[salonsayisi+i].seansolustur();
                this->salonsayisi++;
                //cout<<salonlar[salonsayisi+i];
                //salonlar[salonsayisi] = salonlar[0];//assignment operator calismadi
                //salon s; s=salonlar[0];cout<<s;//sorunsuz calisiyor

        }
    }//if end
    else if(ch == 2){
        for(int i=0;i<number;i++){
                int x,y;
                string tip;
                cout<<"XxY giriniz: ";
                cin>>x>>y;
                cout<<"salon tipi giriniz: ";
                cin>>tip;
                salonlar[salonsayisi+i].setalldata(salonsayisi+i,tip,x,y);
                salonlar[salonsayisi+i].seansolustur();//K bunu otomatik hale getir
                this->salonsayisi++;
                //cout<<salonlar[salonsayisi+i];
            }
        }//else if end
    }//else end
}//function end
void Sinema::salondatagoster(int salonsayisi){for(int i=1;i<salonsayisi;i++){cout<<salonlar[i];}}
void Sinema::seansfilminibelirle(){
    int ch;
    cout<<"Hangi salonun seanslarini yonetmek istiyorsunuz: ";
    cin>>ch;
    salonlar[ch].seansafilmekle();
}
void Sinema::seansfilminigoster(){
    int ch;
    cout<<"Hangi salon?: ";
    cin>>ch;
    salonlar[ch].seansfilmigoster();
}
void Sinema::ekranlarigoster(){
    for(int i=1;i<10;i++){
    if(salonlar[i].getnumara()!=0){
    cout<<"\t**********************SALON:"<<salonlar[i].getnumara()<<"******************************\n"<<endl;
    salonlar[i].tumseanslardakifilmigoster();
    salonlar[i].koltukduzeninigoster();
        }
    }
}
void Sinema::salonugoster(){}


int musterianaliz::imaxnum=0;
int musterianaliz::tdnum=0;
int musterianaliz::toplam=0;

void Sinema::biletkes(){


    musterianaliz ma;

    string isim, soyisim;
    char cinsiyet;
    int yas;
    int kimlikno;


    cout<<"\n Musteri ismi: ";
    cin>>isim;
    cout<<"\n Musteri soyisim: ";
    cin>>soyisim;
    cout<<"\n Musteri yas : ";
    cin>>yas;
    cout<<"\n Musteri cinsiyet (E/K):";
    cin>>cinsiyet;
    cout<<"\n Musteri kimlik no :";
    cin>>kimlikno;

    musteri m(isim,soyisim,cinsiyet,kimlikno,yas);


    flag:
    ekranlarigoster();

    int ch,sch,mode=1;
    int numara;
    cout<<"Salon secin: ";
    cin>>ch;
    cout<<"Seans secin: ";
    cin>>sch;

    Film film = salonlar[ch].getfilmverileri(sch);

    if(film.get_yas_siniri()<= m.get_yas())
    {
        numara =salonlar[ch].koltuklariyonet(sch,mode);
        ma.toplam++;
    }
    else
    {
        cout<<"\n |Bu filmde yas sinirina takildiniz|"<<endl
            <<"tekrar deneyin"
            <<endl;

            goto flag;
    }

    m.set_koltuktercih(numara);
    m.set_salontercih(ch);
    m.set_salontipi(salonlar[ch].gettip());
  //  m.set_saat(salonlar[ch].seanslar[sch].getsaat());
    m.set_saat(salonlar[ch].getseanssaati(sch));
    double total_ucret=0;
    total_ucret=film.get_salon_ucreti()+total_ucret;

    char c='n';
    cout<<"\n |Imax olsun mu? (Y/N)|"<<endl;
    c=getche();
    if(c=='Y' || c=='y')
    {
        total_ucret=total_ucret+film.get_imax_ucreti();
        int i=1;
        ma.set_imax(i);
        ma.imaxnum++;
    }

    char x='n';
    if(film.get_TD()==1)
    {
        ma.tdnum++;
        int i=1;
        ma.set_trd(i);
        cout<<"\n |gozluk ister misiniz? (Y/N)|"<<endl;
        x=getche();
        if(x=='Y' || x=='y')
        {
            total_ucret=total_ucret+film.get_gozluk_ucreti();
        }
    }

    m.set_verilenucret(total_ucret);
    ma.set_musterianaliz(m);
    ma.analizyaz();
    ma.set_filmadi(film.get_film_adi());


    cout<<"\n |işlem bitti|"<<endl
        <<"|n |fatura almayı unutmayın|"
        <<endl;
        m.fatura_yaz(ma);
        Ana_menu();
}


void Sinema::predefination(){
    salonlar[0].setalldata(0,"standart",8,5);
    salonlar[1].setalldata(1,"standart",8,5);
    salonlar[1].seansolustur();
    salonsayisi=2;
}




