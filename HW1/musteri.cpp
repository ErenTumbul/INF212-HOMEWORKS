#include <iostream>
#include <string>
#include "musteri.h"
#include "film.h"
#include "salon.h"
#include "sinema.h"
#include <fstream>
#include <cstdlib>
#include <windows.h>

using namespace std;

musteri::musteri()
{
    isim="none";
    soyisim="none";
    yas=0;
    cinsiyet='0';
    koltuktercihsayi=0;
    salontipi="none";
    verilenucret=0.0;
    saat=0.0;

}

musteri::musteri(string isim,string soyisim,char cinsiyet,int kimlikno,int yas)
{
    this->isim=isim;
    this->soyisim=soyisim;
    this->cinsiyet=cinsiyet;
    this->kimlikno=kimlikno;
    this->yas=yas;
}



void musterianaliz::set_musterianaliz(musteri m)
{
    this->salontercihi=m.get_salontercih();
    this->cinsiyet=m.get_cinsiyet();
    this->salontipi=m.get_salontipi();

    if(m.get_yas()>0 && m.get_yas()<7)
    {
        this->yasgrubu="0-7";
    }
    else if(m.get_yas()<=13 && m.get_yas()<18)
    {
        this->yasgrubu="7-13";
    }
    else if(m.get_yas()>13 && m.get_yas()<=17)
    {
        this->yasgrubu="13-17";
    }
    else if(m.get_yas()>=18)
    {
        this->yasgrubu="18+";
    }


}


void musterianaliz::analizyaz()
{

    fstream file;
    file.open("analiz.dat",ios::in | ios::out | ios::app);

    file.setf(ios::left);
    file<<setw(18)<<this->salontercihi
        <<setw(18)<<this->salontipi
        <<setw(18)<<this->cinsiyet
        <<setw(18)<<this->yasgrubu
        <<setw(18)<<this->imax
        <<setw(18)<<this->td
        <<endl;

    file.close();

}

void musterianaliz::maxcinsiyet()
{
    fstream file;
    int counter1=0,counter2=0;
    int max;
    double sum;
    double oran;
    musterianaliz m;

    file.open("analiz.dat",ios::in | ios::out);
    while(file>>m.salontercihi)
    {
        file>>m.salontipi;
        file>>m.cinsiyet;
        file>>m.yasgrubu;
        file>>imax;
        file>>m.td;

        if(m.cinsiyet=='e' || m.cinsiyet=='E')
        {
            counter1++;
        }
        else if(m.cinsiyet=='k' || m.cinsiyet=='K')
        {
            counter2++;
        }
    }

    sum=counter1+counter2;

     if(counter2>counter1)
    {

            oran=(counter2/sum)*100;
            max=counter2;
            cout<<"\nCinsiyet cogunlugu kadin|| %"<<oran<<" cogunluk"<<endl;
    }
    else if(counter1>counter2)
        {
            oran=(counter1/sum)*100;
            max=counter1;
            cout<<"\nCinsiyet cogunlugu erkek|| %"<<oran<<" cogunluk"<<endl;
        }
        else if(counter1==counter2)
        {
            oran=(counter1/sum)*100;
            max=counter1;
            cout<<"\nCinsiyet orani esit %50|%50"<<endl;
        }

    file.close();
}

void musterianaliz::maxsalon()
{
    fstream file;
    int counter1=0,counter2=0,counter3=0;
    int max;

    file.open("analiz.dat",ios::in | ios::out);

    while(file>>salontercihi)
    {
        file>>salontipi;
        file>>cinsiyet;
        file>>yasgrubu;
        file>>imax;
        file>>td;

        if(salontercihi==1){counter1++;}
        else if(salontercihi==2){counter2++;}
        else if(salontercihi==3){counter3++;}

    }
    if(counter1>counter2 && counter1>counter3)
    {
        cout<<"\nEn cok tercih edilen salon 1"<<endl;
        cout<<"tip1 : "<<counter1<<endl
            <<"tip2 : "<<counter2<<endl
            <<"tip3 : "<<counter3
            <<endl;
    }
    else if(counter2>counter1 && counter2>counter3)
    {
        cout<<"\nEn cok tercih edilen salon 2"<<endl;
        cout<<"tip1 : "<<counter1<<endl
            <<"tip2 : "<<counter2<<endl
            <<"tip3 : "<<counter3
            <<endl;
    }
    else if(counter3>counter1 && counter3>counter2)
    {
        cout<<"\nEn cok tercih edilen salon 3"<<endl;
        cout<<"tip1 : "<<counter1<<endl
            <<"tip2 : "<<counter2<<endl
            <<"tip3 : "<<counter3
            <<endl;
    }

    file.close();

}

//void musterianaliz::salontipi()

void musterianaliz::maxyasgrubu()
{

    fstream file;
    int counter1=0,counter2=0,counter3=0,counter4=0;
    musterianaliz m;

    file.open("analiz.dat",ios::in | ios::out);

    while(file>>m.salontercihi)
    {
        file>>m.salontipi;
        file>>m.cinsiyet;
        file>>m.yasgrubu;
        file>>m.imax;
        file>>m.td;

        if(m.yasgrubu.compare("0-7")==0){counter1++;}
        else if(m.yasgrubu.compare("7-13")==0){counter2++;}
        else if(m.yasgrubu.compare("13-17")==0){counter3++;}
        else if(m.yasgrubu.compare("18+")==0){counter4++;}


    }
    file.close();
    double total;
    total=counter1+counter2+counter3+counter4;
    double oran;

    if(counter1>=counter2 && counter1>=counter3 && counter1>=counter4)
    {
        cout<<"m2: "<<counter2<<endl;
        oran=(counter1/total)*100;
        cout<<"\nAgirlikli yas grubu: 0-7 || "<<"digerlerine gore agirlik orani: "<<oran<<endl;
    }
    else if(counter2>=counter1 && counter2>=counter3 && counter2>=counter4)
    {
        oran=(counter2/total)*100;
        cout<<"\nAgirlikli yas grubu: 7-13 || "<<"digerlerine gore agirlik orani: "<<oran<<endl;
    }
    else if(counter3>=counter1 && counter3>=counter2 && counter3>=counter4)
    {
        oran=(counter3/total)*100;
        cout<<"\nAgirlikli yas grubu: 13-17 || "<<"digerlerine gore agirlik orani: "<<oran<<endl;
    }
    else if(counter4>=counter1 && counter4>=counter2 && counter4>=counter3)
    {
        oran=(counter4/total)*100;
        cout<<"\nAgirlikli yas grubu: 18+ || "<<"digerlerine gore agirlik orani: %"<<oran<<endl;
    }
}

musterianaliz::musterianaliz()
{
    salontipi="none";
    salontercihi=0;
    cinsiyet='0';
    yasgrubu="none";
}

void musterianaliz::analiz_goster()
{
    fstream file;
    musterianaliz m;
    file.open("analiz.dat",ios::out | ios::in);

    while(file>>salontercihi)
    {
        file>>salontipi;
        file>>cinsiyet;
        file>>yasgrubu;
        file>>imax;
        file>>td;

        cout<<"\n  |salon tipi: "<<salontipi<<"|"
            <<"  |salon tercihi: "<<salontercihi<<"|"
            <<"  |cinsiyet: "<<cinsiyet<<"|"
            <<"  |yas grubu: "<<yasgrubu<<"|"
            <<endl;
       }

    //m.maxsalontipi();
    maxsalon();
    maxcinsiyet();
    maxyasgrubu();
    imax_analiz();
    td_analiz();

}

void musteri::set_saat(double saat)
{
    this->saat=saat;
}

void musterianaliz::set_filmadi(string f)
{
    this->filmadi=f;
}

void musteri::fatura_yaz(musterianaliz m)
{
    system("color 4");

    cout<<"isim: "<<isim<<endl
        <<"soyisim: "<<soyisim<<endl
        <<"film ismi: "<<m.filmadi<<endl
        <<"salon: "<<m.salontercihi<<endl
        <<"salon tipi: "<<m.salontipi<<endl
        <<"seans saat: "<<saat
        <<endl;

        if(m.imax==1)
        {
            cout<<"imax secildi"<<endl;
        }

        if(m.td==1)
        {
            cout<<"3D secildi"<<endl;
        }

        cout<<"tutar: "<<verilenucret<<endl;

        fstream file;

        file.open("faturalar.dat",ios::in | ios::out | ios::app);

        file.setf(ios::left);
        file<<setw(20)<<isim
            <<setw(20)<<soyisim
            <<setw(20)<<m.filmadi
            <<setw(20)<<m.salontercihi
            <<setw(20)<<m.salontipi
            <<setw(20)<<saat
            <<setw(20)<<m.imax
            <<setw(20)<<m.td
            <<setw(20)<<verilenucret
            <<endl;
        cout<<"Devam etmek icin bir tusa basiniz..."<<endl;
        getch();
    file.close();

}

void musteri::set_salontercih(int salon_tercih)
{
    this->salontercih=salon_tercih;
}

void musteri::set_koltuktercih(int koltuk_tercih)
{
    this->koltuktercihsayi=koltuk_tercih;
}

void musteri::set_verilenucret(double ucret)
{
    this->verilenucret=ucret;
}

void musteri::set_salontipi(string s_tipi)
{
    this->salontipi=s_tipi;
}

 void musterianaliz::set_imax(bool i)
 {
     this->imax=i;
 }

void musterianaliz::set_trd(bool i)
{
    this->td=i;
}

void musterianaliz::imax_analiz()
{
    double oran;
    if(toplam!=0){
    oran=(imaxnum/toplam)*100;
    cout<<"\n imax tercih eden kisi sayisi: "<<imaxnum<<" & toplam kisi sayisi: "<<toplam<<endl;
    cout<<"\n |Imax tercih eden orani: %"<<oran<<"|"<<endl;
    }
    else
    {
        cout<<"\nIMAX tercih edenlerin orani icin bilet girisi olmasi gerekir\n"<<endl;
    }

}


void musterianaliz::td_analiz()
{
    double oran;
    if(toplam!=0){
    oran=(tdnum/toplam)*100;
    cout<<"\n 3D tercih eden kisi sayisi: "<<imaxnum<<" & toplam kisi sayisi: "<<toplam<<endl;
    cout<<"\n |3D tercih eden orani: %"<<oran<<"|"<<endl;
    }
    else{
        cout<<"\n3D tercih edenlerin orani icin bilet girisi olmasi gerekir\n"<<endl;
    }
}
