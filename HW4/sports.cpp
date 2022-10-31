#include <iostream>
#include "sports.h"
#include "User.h"

using namespace std;

double Basketball::burned()
{
    int time;
    double toplam;

    cout<<"\t\n\n Enter time in minutes: ";
    cin>>time;

    toplam=time*cal;

    return toplam;

}

double Football::burned()
{

    int time;
    double toplam;

    cout<<"\t\n\n Enter time in minutes: ";
    cin>>time;

    toplam=time*cal;

    return toplam;


}

double Tennis::burned()
{
    int time;
    double toplam;

    cout<<"\t\n\n Enter time in minutes: ";
    cin>>time;

    toplam=time*cal;

    return toplam;
}

double Swimming::burned()
{
    int time;
    double toplam;

    cout<<"\t\n\n Enter time in minutes: ";
    cin>>time;

    toplam=time*cal;

    return toplam;
}
