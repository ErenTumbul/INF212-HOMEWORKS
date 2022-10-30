#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED
#include <string.h>
using namespace std;

class Film
{

private:
    int film_kodu;
    string film_adi;
    string genre;
    int yas_siniri;
    bool TD;
    double salon_ucreti;
    double gozluk_ucreti;
    double imax_ucreti;
    int vizyon_gun;
    int vizyon_ay;
    int vizyon_yil;
    int haftalik_vizyon_suresi;
    int gun,ay,yil;

public:
    Film();
    Film(int fk,string fa,string g, int ys,bool TD, double su,double gu,double iu, int vg, int va,int vy,int hvs);
    Film(const Film& obj);
    Film& operator=(const Film& obj);
    Film& operator+(const Film& obj);
    friend ostream &operator <<(ostream &output, Film& f);
    friend istream &operator >>(istream &input, Film& f);

    void set_film_kodu(int film_kodu);
    void set_film_adi(string film_adi);
    void set_genre(string genre);
    void set_yas_siniri(int yas_siniri);
    void set_TD(bool TD);
    void set_salon_ucreti(double salon_ucreti);
    void set_gozluk_ucreti(double gozluk_ucreti);
    void set_imax_ucreti(double imax_ucreti);
    void set_vizyon_gun(int vizyon_gun);
    void set_vizyon_ay(int vizyon_ay);
    void set_vizyon_yil(int vizyon_yil);
    void set_haftalik_vizyon(int haftalik_vizyon_suresi);
    void tarih();

    int get_film_kodu();
    string get_film_adi();
    string get_genre();
    int get_yas_siniri();
    bool get_TD();
    double get_salon_ucreti();
    double get_gozluk_ucreti();
    double get_imax_ucreti();
    int get_vizyon_gun();
    int get_vizyon_ay();
    int get_vizyon_yil();
    int get_haftalik_vizyon();

    void vizyon_durumu();
    void threeD();
    void film_arsivi_olustur();
    void film_arsivini_goster();
    void film_arsivi_duzenle();
    void vizyondaki_filmler();
    void vizyon_sifirla();
    void vizyondakileri_goster();

};

ostream &operator <<(ostream &output, Film& f);
istream &operator >>(istream &input, Film& f);

#endif // FILM_H_INCLUDED
