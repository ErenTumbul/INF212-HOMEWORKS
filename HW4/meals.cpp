#include <iostream>
#include "User.h"
#include "meals.h"

using namespace std;

void Breakfast::info()
{

    cout<<"\n\n\t1.small=200 cal"<<endl
        <<"2.medium=400 cal"<<endl
        <<"3.large=600 cal"<<endl;

}

void Lunch::info()
{

    cout<<"\n\n\t1.small=400 cal"<<endl
        <<"2.medium=600 cal"<<endl
        <<"3.large=800 cal"
        <<endl;

}

void Dinner::info()
{

     cout<<"\n\n\t1.small=400 cal"<<endl
        <<"2.medium=600 cal"<<endl
        <<"3.large=800 cal"
        <<endl;


}
