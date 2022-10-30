#ifndef SINEMA_H_INCLUDED
#define SINEMA_H_INCLUDED
#include "salon.h"
#include "film.h"
#include "musteri.h"
class Sinema{//gunluk menu
private:
    int salonsayisi;
    int gun,ay,yil;
    int arsivdekifilmsayisi;
    Salon salonlar[10];
    musterianaliz ma;
public:
    Sinema();
    void Ana_menu();
    void admin_menu();
    void stuff_menu();
    void istatistik_menu();
    void film_menu();
    void salonmenusu();

    void salonekle(int salonsayisi);
    void salondatagoster(int salonsayisi);
    void seansfilminibelirle();
    void seansfilminigoster();
    //void resizesalon();


    void ekranlarigoster();
    void salonugoster();

    void biletkes();

    int get_gun();
    int get_ay();
    int get_yil();

    void predefination();


};


#endif // SINEMA_H_INCLUDED
