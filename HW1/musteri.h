#ifndef MUSTERI_H_INCLUDED
#define MUSTERI_H_INCLUDED

#include <iostream>
#include "salon.h"
#include "film.h"
#include "sinema.h"

using namespace std;
class musterianaliz;

class musteri
{

    //friend class sinema;
    //friend class film;
    //friend class salon;

private:
    string isim;
    string soyisim;
    int yas;
    char cinsiyet;
    int kimlikno;
    int salontercih;
    int koltuktercihsayi;
    //koltuktercihhafýza??
    string salontipi;
    double verilenucret;
    double saat;


public:

    musteri();
    musteri(string isim,string soyisim,char cinsiyet,int kimlikno,int yas);

    void set_salontercih(int salon_tercih);
    void set_koltuktercih(int koltuk_tercih);
    void set_verilenucret(double ucret);
    void set_salontipi(string s_tipi);
    void set_saat(double saat);
    //void Koltuksec();
    //void Salonveseanssec();
    //void Biletolustur();

    void fatura_yaz(musterianaliz a);

    string get_isim(){return isim;}
    string get_soyisim(){return soyisim;}
    int get_yas(){return yas;}
    char get_cinsiyet(){return cinsiyet;}
    int get_kimlikno(){return kimlikno;}
    int get_salontercih(){return salontercih;}
    int get_koltuktercihsayi(){return koltuktercihsayi;}
    double get_verilenucret(){return verilenucret;}
    string get_salontipi(){return salontipi;}


};

class musterianaliz
{
    friend class musteri;

private:
    string yasgrubu;
    int salontercihi;
    char cinsiyet;
    string salontipi;
    bool imax;
    bool td;
    string filmadi;
public:


    static int imaxnum;
    static int tdnum;
    static int toplam;

    musterianaliz();
    void set_musterianaliz(musteri);
    void maxsalon();
    void maxyasgrubu();
    void maxcinsiyet();
    void maxsalontipi();
    void imax_analiz();
    void td_analiz();
    void set_filmadi(string f);
    void set_imax(bool i);
    void analizyaz();
    void analiz_goster();

    void set_trd(bool i);

};


#endif // MUSTERI_H_INCLUDED
