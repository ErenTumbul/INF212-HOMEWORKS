#include <iostream>
#include "sinema.cpp"
#include "salon.cpp"
#include "film.cpp"
#include "musteri.cpp"
#include <stdlib.h>

using namespace std;

int main()
{
    Sinema pazartesi;
    baslangic:
    //pazartesi.predefination();
    pazartesi.Ana_menu();
    goto baslangic;
    //Salon test(1,"standart",5,4);
    //test.seansolustur();
    //test.salonozelliklerinigoster();
    //for(int i=0;i<10;i++){
    //test.koltuklariyonet(0,1);}
    //test.boskoltuklarigoster(0);
    //for(int i=0;i<2;i++){test.koltuklariyonet(0,2);}
    //test.boskoltuklarigoster(0);

       //test.boskoltuklarigoster(1);
    //test.koltukduzeninigoster();

    //test.koltuklariyonet(1,1);
    //test.boskoltuklarigoster(1);

    //Seans s(2100,true,30);
    //s.koltukdoldur(4);
    //s.getdolukoltuklar(30);

    return 0;
}
