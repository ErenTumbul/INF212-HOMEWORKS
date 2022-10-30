#ifndef SALON_H_INCLUDED
#define SALON_H_INCLUDED
#include "film.h"
#include <string>
using namespace std;
class Salon;
class Seans;

class Salon{
    friend class Seans;
private:
    int numara;
    string tip;
    int x;
    int y;
    int kapasite;
    int** koltuknumaralari;
    Seans *seanslar;
public:
    Salon();
    Salon(int numara,string tip,int x, int y);
    Salon& operator =(const Salon &obj);
    friend ostream &operator <<(ostream &output,Salon &s);
    friend bool operator ==(const Salon &obj1, const Salon &obj2);
    void setnumara(int numara);
    void settip(string tip);
    void setxy(int x, int y);
    void setalldata(int numara,string tip,int x,int y);
    int getnumara();
    string gettip();
    int getkapasite();
    int getx();
    int gety();

    void koltukduzeninigoster();
    void seansolustur();
    //void seanskopyala(seansseti);//assignment operator yuzunden yazdigimiz fonk
    void boskoltuklarigoster(int seans);
    int koltuklariyonet(int seans, int mode);//Mode1 doldur mode2 bosalt
    void salonozelliklerinigoster();//<<operator kullanacagim yinede yazdim
    void seansafilmekle();
    void seansfilmigoster();
    void tumseanslardakifilmigoster();
    Film& getfilmverileri(int seans);
    double getseanssaati(int seans);
};
    ostream &operator << (ostream &output,Salon &s);
    bool operator== (const Salon &obj1, const Salon &obj2);

class Seans{
    friend class Salon;
private:
    double saat;
    bool durum;
    int *dolukoltuklar;//1 2 3 4
    Film seansfilmi;
public:
    Seans();
    Seans(double saat, bool durum, int kapasite);

    void setsaat(double saat);
    void setdurum(bool durum);
    void setdolukoltuklarlistesi(int kapasite);
    double getsaat();
    bool getdurum();
    void getdolukoltuklar(int kapasite);

    void koltukdoldur(int numara);
    void koltukbosalt(int numara);

    void filmekle();
    void filmgoster();

};

#endif // SALON_H_INCLUDED
