#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include "film.h"
#include <stdlib.h>


Film::Film()
{
    film_kodu=0;
    film_adi="NULL";
    genre="NULL";
    yas_siniri=0;
    TD=false;
    salon_ucreti=0.0;
    gozluk_ucreti=0.0;
    imax_ucreti=0.0;
    vizyon_gun=1;
    vizyon_ay=1;
    vizyon_yil=2000;
    haftalik_vizyon_suresi=0;
}

Film::Film(int fk,string fa,string g, int ys,bool td, double su,double gu,double iu, int vg, int va,int vy,int hvs)
{
    film_kodu= fk;
    film_adi= fa;
    genre= g;
    yas_siniri= ys;
    TD= td;
    salon_ucreti= su;
    gozluk_ucreti=gu;
    imax_ucreti= iu;
    vizyon_gun= vg;
    vizyon_ay= va;
    vizyon_yil= vy;
    haftalik_vizyon_suresi= hvs;
}

Film::Film(const Film& obj)
{
    film_kodu=obj.film_kodu;
    film_adi=obj.film_adi;
    genre=obj.genre;
    yas_siniri=obj.yas_siniri;
    TD= obj.TD;
    salon_ucreti=obj.salon_ucreti;
    gozluk_ucreti=obj.gozluk_ucreti;
    imax_ucreti=obj.imax_ucreti;
    vizyon_gun=obj.vizyon_gun;
    vizyon_ay=obj.vizyon_ay;
    vizyon_yil=obj.vizyon_yil;
    haftalik_vizyon_suresi=obj.haftalik_vizyon_suresi;
}

Film& Film::operator=(const Film& obj)
{
    film_kodu=obj.film_kodu;
    film_adi=obj.film_adi;
    genre=obj.genre;
    yas_siniri=obj.yas_siniri;
    TD= obj.TD;
    salon_ucreti=obj.salon_ucreti;
    imax_ucreti=obj.imax_ucreti;
    vizyon_gun=obj.vizyon_gun;
    vizyon_ay=obj.vizyon_ay;
    vizyon_yil=obj.vizyon_yil;
    haftalik_vizyon_suresi=obj.haftalik_vizyon_suresi;
    return *this;
}

void Film::set_film_kodu(int film_kodu){ this->film_kodu=film_kodu;}
void Film::set_film_adi(string film_adi){ this->film_adi=film_adi;}
void Film::set_genre(string genre){ this->genre=genre;}
void Film::set_yas_siniri(int yas_siniri){ this->yas_siniri=yas_siniri;}
void Film::set_TD(bool TD){this->TD=TD;}
void Film::set_salon_ucreti(double salon_ucreti){this->salon_ucreti=salon_ucreti;}
void Film::set_gozluk_ucreti(double gozluk_ucreti){this->gozluk_ucreti=gozluk_ucreti;}
void Film::set_imax_ucreti(double imax_ucreti){this->imax_ucreti=imax_ucreti;}
void Film::set_vizyon_gun(int vizyon_gun){this->vizyon_gun=vizyon_gun;}
void Film::set_vizyon_ay(int vizyon_ay){this->vizyon_ay=vizyon_ay;}
void Film::set_vizyon_yil(int vizyon_yil){this->vizyon_yil=vizyon_yil;}
void Film::set_haftalik_vizyon(int haftalik_vizyon_suresi){this->haftalik_vizyon_suresi=haftalik_vizyon_suresi;}

int Film::get_film_kodu(){ return film_kodu;}
string Film::get_film_adi(){ return film_adi;}
string Film::get_genre(){ return genre;}
int Film::get_yas_siniri(){return yas_siniri;}
bool Film::get_TD(){return TD;}
double Film::get_salon_ucreti(){return salon_ucreti;}
double Film::get_gozluk_ucreti(){ return gozluk_ucreti;}
double Film::get_imax_ucreti(){return imax_ucreti;}
int Film::get_vizyon_gun(){return vizyon_gun;}
int Film::get_vizyon_ay(){return vizyon_ay;}
int Film::get_vizyon_yil(){return vizyon_yil;}
int Film::get_haftalik_vizyon(){return haftalik_vizyon_suresi;}

istream &operator >>(istream &input, Film& f)
{
    fstream file;
    file.open("film_arsivi.txt", ios::in);
    int array[50];
    int i=0;
    while(file>>f.film_kodu)
    {
        file>>f.film_adi;
        file>>f.genre;
        file>>f.yas_siniri;
        file>>f.TD;
        file>>f.salon_ucreti;
        file>>f.gozluk_ucreti;
        file>>f.imax_ucreti;
        file>>f.vizyon_gun;
        file>>f.vizyon_ay;
        file>>f.vizyon_yil;
        file>>f.haftalik_vizyon_suresi;

    array[i]=f.film_kodu;
    i++;
    }
    again:
    cout<<"Film Kodu: ";
    input>>f.film_kodu;
    for(int j=0; j<i; j++)
    {
        if(f.film_kodu==array[j])
        {
            cout<<"Bu kod kullaniliyor. Baska bir kod giriniz"<<endl;
            goto again;
        }
    }

    cout<<"Film Adi (Lutfen bosluk yerine \"-\" kullaniniz): ";
    input>>f.film_adi;
    cout<<"Film Turu (Lutfen bosluk yerine \"-\" kullaniniz): ";
    input>>f.genre;
    cout<<"Yas Siniri: ";
    input>>f.yas_siniri;
    cout<<"3D: ";
    input>>f.TD;
    cout<<"Salon Ucreti: ";
    input>>f.salon_ucreti;
    cout<<"Gozluk Ucreti: ";
    input>>f.gozluk_ucreti;
    cout<<"IMAX Ucreti: ";
    input>>f.imax_ucreti;

    flag:
    cout<<"Vizyon Tarihi (Gun/Ay/Yil): ";
    input>>f.vizyon_gun;


    try
    {
        if ( input.get() != '/' ) // make sure there is a slash between DD and MM
        {
          throw input.get();
        }
    }
   	catch(int gg)
   	{
      cout<<"\nGun ve ayin yanina \"/\" isareti gerekli\n";
      goto flag;
   	}
    input>>f.vizyon_ay;
   	try{
        if ( input.get() != '/' ) // make sure there is a slash between MM and YYYY
        {
          throw input.get();
        }
   	}
   	catch(int aa)
   	{
      cout<<"\nAy ve yilin yanina \"/\" isareti gerekli\n";
      goto flag;
   	}
   	input>>f.vizyon_yil;


    cout<<"Vizyon Suresi (Hafta): ";
    input>>f.haftalik_vizyon_suresi;

    return input;

}
ostream &operator <<(ostream &output, Film& f)
{

    output<<"==== Film Bilgileri ====\n"<<endl;

    output<<"Film Kodu: "<<f.film_kodu<<endl;
    output<<"Film Adi: "<<f.film_adi<<endl;
    output<<"Film Turu: "<<f.genre<<endl;
    output<<"Yas Siniri: "<<f.yas_siniri<<endl;
    output<<"3D: "<<f.TD<<endl;
    output<<"Salon Ucreti: "<<f.salon_ucreti<<endl;
    output<<"Gozluk Ucreti: "<<f.gozluk_ucreti<<endl;
    output<<"IMAX Ucreti: "<<f.imax_ucreti<<endl;;
    output<<"Vizyon Tarihi: "<<f.vizyon_gun<<"/"<<f.vizyon_ay<<"/"<<f.vizyon_yil<<endl;
    output<<"Haftalik Vizyon Suresi: "<<f.haftalik_vizyon_suresi<<endl;

    output<<"===========================================\n"<<endl;
    return output;
}

void Film::threeD()
{
    char ch='n';
    cout<<"Müsterinin gozlugu var mi?(Y/N): ";
    ch=getche();

    if(ch=='y' || ch=='Y')
        salon_ucreti+=gozluk_ucreti;
}



void Film::film_arsivi_olustur()
{
    system("cls");
    fstream file;
    file.open("film_arsivi.txt", ios::in| ios::out| ios::app);

    file.setf(ios::left);
    Film f;

    cin>>f;

    file<<setw(20)<<f.film_kodu
		<<setw(20)<<f.film_adi
        <<setw(20)<<f.genre
        <<setw(20)<<f.yas_siniri
        <<setw(20)<<f.TD
        <<setw(20)<<f.salon_ucreti
        <<setw(20)<<f.gozluk_ucreti
        <<setw(20)<<f.imax_ucreti
        <<setw(20)<<f.vizyon_gun
        <<setw(20)<<f.vizyon_ay
        <<setw(20)<<f.vizyon_yil
        <<setw(20)<<f.haftalik_vizyon_suresi
        <<endl;


    file.close();
}

void Film::film_arsivini_goster()
{
    system("cls");
    fstream file;
    file.open("film_arsivi.txt", ios::in);
    Film f;

    while(file>>f.film_kodu)
    {
		file>>f.film_adi;
        file>>f.genre;
        file>>f.yas_siniri;
        file>>f.TD;
        file>>f.salon_ucreti;
        file>>f.gozluk_ucreti;
        file>>f.imax_ucreti;
        file>>f.vizyon_gun;
        file>>f.vizyon_ay;
        file>>f.vizyon_yil;
        file>>f.haftalik_vizyon_suresi;

        cout<<f;
    }
    file.close();
}

void Film::film_arsivi_duzenle()
{
    fstream file;
    file.open("film_arsivi.txt", ios::in);

    int kod;
    Film f;

    cout<<"\nBilgilerimi degistirmek istediginiz filmin kodunu giriniz giriniz: ";
    cin>>kod;

    fstream file2;
    file2.open("temp.dat",ios::out | ios::in | ios::app);
    file2.setf(ios::left);
    while(file>>f.film_kodu)
    {
		file>>f.film_adi;
        file>>f.genre;
        file>>f.yas_siniri;
        file>>f.TD;
        file>>f.salon_ucreti;
        file>>f.gozluk_ucreti;
        file>>f.imax_ucreti;
        file>>f.vizyon_gun;
        file>>f.vizyon_ay;
        file>>f.vizyon_yil;
        file>>f.haftalik_vizyon_suresi;

        if(f.film_kodu!=kod)
        {
            file2<<setw(20)<<f.film_kodu
                 <<setw(20)<<f.film_adi
                 <<setw(20)<<f.genre
                 <<setw(20)<<f.yas_siniri
                 <<setw(20)<<f.TD
                 <<setw(20)<<f.salon_ucreti
                 <<setw(20)<<f.gozluk_ucreti
                 <<setw(20)<<f.imax_ucreti
                 <<setw(20)<<f.vizyon_gun
                 <<setw(20)<<f.vizyon_ay
                 <<setw(20)<<f.vizyon_yil
                 <<setw(20)<<f.haftalik_vizyon_suresi
                 <<endl;
        }
        else if(f.film_kodu==kod){
        cin>>f;

        file2<<setw(20)<<f.film_kodu
            <<setw(20)<<f.film_adi
            <<setw(20)<<f.genre
            <<setw(20)<<f.yas_siniri
            <<setw(20)<<f.TD
            <<setw(20)<<f.salon_ucreti
            <<setw(20)<<f.gozluk_ucreti
            <<setw(20)<<f.imax_ucreti
            <<setw(20)<<f.vizyon_gun
            <<setw(20)<<f.vizyon_ay
            <<setw(20)<<f.vizyon_yil
            <<setw(20)<<f.haftalik_vizyon_suresi
            <<endl;
            }

    }

        file.close();
        file2.close();
        remove("film_arsivi.txt");
        rename("temp.dat","film_arsivi.txt");
}

void Film::vizyon_durumu()
{
    int i=0;
    int song,sona,sony;
    fstream file;
    file.open("film_arsivi.txt", ios::in);
    Film f[20];

    while(file>>f[i].film_kodu)
    {
		file>>f[i].film_adi;
        file>>f[i].genre;
        file>>f[i].yas_siniri;
        file>>f[i].TD;
        file>>f[i].salon_ucreti;
        file>>f[i].gozluk_ucreti;
        file>>f[i].imax_ucreti;
        file>>f[i].vizyon_gun;
        file>>f[i].vizyon_ay;
        file>>f[i].vizyon_yil;
        file>>f[i].haftalik_vizyon_suresi;

        song=f[i].haftalik_vizyon_suresi*7;

        if((f[i].vizyon_gun+song)/30>0){

            sona=(f[i].vizyon_gun+song)/30;
            song=(f[i].vizyon_gun+song)%30;

            if((f[i].vizyon_ay+sona)/12>0){
                sony=(f[i].vizyon_ay+sona)/12;
                sony=f[i].vizyon_yil+sony;
            }
            else{
                sona+=f[i].vizyon_ay;
                sony=f[i].vizyon_yil;
            }
        }
        else{
            song+=f[i].vizyon_gun;
            sona=f[i].vizyon_ay;
            sony=f[i].vizyon_yil;
        }

        if(f[i].vizyon_yil<yil && yil<sony)
        {
            f[i].vizyondaki_filmler();
        }
        else if(f[i].vizyon_yil<=yil && yil<=sony)
        {
            if(yil==sony)
            {
                if(f[i].vizyon_ay<ay && ay<sona)
                {
                    f[i].vizyondaki_filmler();
                }

                else if(f[i].vizyon_ay<=ay && ay<=sona)
                {
                    if(ay==sona)
                    {
                        if(gun<=song)
                            f[i].vizyondaki_filmler();
                    }
                    else
                        f[i].vizyondaki_filmler();
                }
            }
             else
                f[i].vizyondaki_filmler();
        }

        i++;
    }

    file.close();
}

void Film::vizyondaki_filmler()
{
    fstream file;
    file.open("vizyondaki_filmler.txt", ios::out|ios::in|ios::app);
    file.setf(ios::left);

    file<<setw(20)<<film_kodu
		<<setw(20)<<film_adi
        <<setw(20)<<genre
        <<setw(20)<<yas_siniri
        <<setw(20)<<TD
        <<setw(20)<<salon_ucreti
        <<setw(20)<<gozluk_ucreti
        <<setw(20)<<imax_ucreti
        <<setw(20)<<vizyon_gun
        <<setw(20)<<vizyon_ay
        <<setw(20)<<vizyon_yil
        <<setw(20)<<haftalik_vizyon_suresi
        <<endl;

    file.close();

}

void Film::vizyondakileri_goster()
{
    fstream file;
    file.open("vizyondaki_filmler.txt", ios::in);

    while(file>>film_kodu)
    {
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

        cout<<"==== Vizyondaki Film Bilgileri ====\n"<<endl;

        cout<<"Film Kodu: "<<film_kodu<<endl;
        cout<<"Film Adi: "<<film_adi<<endl;
        cout<<"Film Turu: "<<genre<<endl;
        cout<<"Yas Siniri: "<<yas_siniri<<endl;
        cout<<"3D: "<<TD<<endl;
        cout<<"Salon Ucreti: "<<salon_ucreti<<endl;
        cout<<"Gozluk Ucreti: "<<gozluk_ucreti<<endl;
        cout<<"IMAX Ucreti: "<<imax_ucreti<<endl;;
        cout<<"Vizyon Tarihi: "<<vizyon_gun<<"/"<<vizyon_ay<<"/"<<vizyon_yil<<endl;
        cout<<"Haftalik Vizyon Suresi: "<<haftalik_vizyon_suresi<<endl;

        cout<<"===========================================\n"<<endl;
    }
    file.close();
}


void Film::vizyon_sifirla()
{
    remove("vizyondaki_filmler.txt");
}

void Film::tarih()
{
    flag:
    cout<<"\n\n\tLutfen tarih giriniz(gun/ay/yil): ";
    cin>>gun;

    try
    {
        if ( cin.get() != '/' ) // make sure there is a slash between DD and MM
        {
          throw cin.get();
        }
    }
   	catch(int gg)
   	{
      cout<<"\nGun ve ayin yanina \"/\" isareti gerekli\n";
      goto flag;
   	}
    cin>>ay;
   	try{
        if ( cin.get() != '/' ) // make sure there is a slash between MM and YYYY
        {
          throw cin.get();
        }
   	}
   	catch(int aa)
   	{
      cout<<"\nAy ve yilin yanina \"/\" isareti gerekli\n";
      goto flag;
   	}
   	cin>>yil;
}

