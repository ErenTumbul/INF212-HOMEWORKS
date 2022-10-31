#include <iostream>
#include "User.h"
#include "sports.h"
#include "meals.h"

using namespace std;

int main()
{
    User u[7];
    double pass;//1901022030

    cout<<"\n\n\t\t Welcome\n"<<endl;

    cout<<"1.User mode"<<endl
        <<"2.developer mode"<<endl;

    int ch;
    cin>>ch;
    if(ch==1)
    {
        user_menu(u);
    }
    else
    {
        cout<<"password: "<<endl;
        cin>>pass;
        if(pass==1901022030)
        {
            developer_mode();
        }
        else
        {
            exit(0);
        }
    }
}
