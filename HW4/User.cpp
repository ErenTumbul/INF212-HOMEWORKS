#include <iostream>
#include <string>
#include "User.h"
#include <windows.h>
#include <conio.h>
#include "meals.h"
#include "sports.h"
#include <cstdlib>

using namespace std;

User::User()
{
    name=" ";
    id=0;
    weight=0;
    age=0;

    int i;
    int a;

    for(i=0;i<7;++i)
    {
        daily_burned[i]=0;
    }

    for(i=0;i<7;++i)
    {
        daily_sports[i]=0;
    }

    for(i=0;i<7;++i)
    {
        for(a=0;a<3;++a)
        {
            daily_takencal[i][a]=0;
        }
    }

}
void User::set_person(string n,int i,int a,double w)
{
    this->name=n;
    this->id=i;
    this->age=a;
    this->weight=w;



}

void developer_mode()
{
    User u;


    string name;
    int id;
    int age;
    double weight;

    Basketball bs;
    Football fb;
    Tennis tn;
    Swimming sw;

    Breakfast bf;
    Lunch ln;
    Dinner dn;

    cout<<"\t\t\n User class test:"<<endl;

    cout<<"\n name: ";
    cin>>name;
    cout<<"\n id: ";
    cin>>id;
    cout<<"\n age: ";
    cin>>age;
    cout<<"\n weight: ";
    cin>>weight;

    u.set_person(name,id,age,weight);

    cout<<"\n User created"<<endl;

    User u2(u);
    cout<<"\n user2 constructed"<<endl;
    cout<<"\n user2 copied"<<endl;
    cout<<u2;

    cout<<"********************************************************"<<endl;

    User u3;
    u3=u2;
    cout<<u3;
    cout<<"= operator used."<<endl;
    cout<<"********************************************************"<<endl;
    u3=u2+u;

    cout<<u3;

    cout<<"\n\n + operator is used;"<<endl;
    cout<<"********************************************************"<<endl;

    cout<<"\n\nUser is done\n"<<endl;
    cout<<"\n\nSports class test\n"<<endl;

    double bs_cal=bs.burned();
    cout<<"\n\n basketball played "<<bs_cal<<" cal burned\n"<<endl;
    double fb_cal=fb.burned();
    cout<<"\n\n football played "<<fb_cal<<" cal burned\n"<<endl;
    double tn_cal=tn.burned();
    cout<<"\n\n tennis played "<<tn_cal<<" cal burned\n"<<endl;
    double sw_cal=sw.burned();
    cout<<"\n\n swimming done "<<sw_cal<<" cal burned\n"<<endl;

    int toplam;
    toplam=bs.B()+fb.F()+tn.T()+sw.S();
    cout<<"\n\n birim kolari toplam: "<<toplam<<endl;

    cout<<"\n\n sport class done\n"<<endl;

    cout<<"\n\n Meal class\n"<<endl;

    bf.info();
    ln.info();
    dn.info();

    int t1,t2,t3;

    t1=bf.s()+bf.m()+bf.l();
    t2=ln.s()+ln.m()+ln.l();
    t3=dn.s()+dn.m()+dn.m();

    cout<<"\n\n breakfast birim kalori toplam: "<<t1<<" cal"<<endl;
    cout<<"\n\n lunch birim kalori toplam: "<<t2<<" cal"<<endl;
    cout<<"\n\n dinner birim kalori toplam: "<<t3<<" cal"<<endl;

    cout<<"\n\n developer mode ended\n"<<endl;


}


void create_user(User u[])
{
    system("cls");
    system("color 4");

    int i=0;
    bool b=false;

    while(b==false)
    {
        if(u[i+1].id==0)
        {
            b=true;
        }
        else
        {
            i++;
        }


    }

    string name;
    int id;
    int age;
    double weight;

    cout<<"name: ";
    cin>>name;
    cout<<"id: ";
    cin>>id;
    cout<<"age :";
    cin>>age;
    cout<<"weight: ";
    cin>>weight;

   u[i].set_person(name,id,age,weight);

    cout<<"SAVED..."<<endl;

    user_menu(u);
}




void user_menu(User u[7])
{

    system("cls");
    system("color 4");

    k:

    User x;
    cout<<"\n\n\t 1.Sign in"<<endl;
    cout<<"\n\n\t 2.Log in"<<endl;

    int ch;
    cout<<"\n\n chose"<<endl;
    cin>>ch;

    if(ch==1)
    {
        create_user(u);
    }
    else if(ch==2)
    {
        user_2(u);
    }
    else
    {
        cout<<"\n TRY AGAIN!!"<<endl;
        goto k;
    }


}

void user_2(User u[7])
{

    system("cls");
    system("color 4");

    k:

    cout<<"\n\n\t Enter name:";
    string name;
    cin>>name;

    string username;

    bool r=false;
    int i;

    while(r==false)
    {
        username=u[i].Name();
        if(strcmp(name.c_str(),username.c_str())==0)
        {

            r=true;
            cout<<"++++"<<endl;

        }
        else
        {
             i++;
        }
    }

    //system("cls");

    cout<<"1.eat"<<endl
        <<"2.do sports"<<endl
        <<"3. week report"<<endl
        <<"4. return user menu"<<endl;


        cout<<"\n\n\t choose:"<<endl;

        int ch;
        cin>>ch;

        if(ch==1)
        {
            eat(i,u);
        }
        else if(ch==2)
        {
            do_sport(i,u);
        }
        else if(ch==3)
        {
            weekly_report(i,u);
        }
        else if(ch==4)
        {
           user_menu(u);
        }
        else
        {
            goto k;
        }


}




void eat(int i,User u[7])
{


  system("cls");
  system("color 4");

  Breakfast bf;
  Lunch ln;
  Dinner dn;

  k:

  int day,ch;
  cout<<"\n\n\t enter day:"<<endl;
  cin>>day;

  cout<<"\n\t Choose meal: "<<endl;

  cout<<"\n\n 1.Breakfast"<<endl
      <<"2.Lunch"<<endl
      <<"3.Dinner"
      <<endl;


      cin>>ch;
  int ch2;



  if(ch==1)
  {
        bf.info();

        cout<<"\n\n choose: ";
        cin>>ch2;

        if(ch2==1)
        {
            u[i].daily_takencal[day-1][ch-1]=bf.s();
        }
        else if(ch2==2)
        {
            u[i].daily_takencal[day-1][ch-1]=bf.m();
        }
        else if(ch2==3)
        {
            u[i].daily_takencal[day-1][ch-1]=bf.l();
        }
  }
  else if(ch==2)
  {

        ln.info();

        cout<<"\n\n choose: ";
        cin>>ch2;

        if(ch2==1)
        {
            u[i].daily_takencal[day-1][ch-1]=ln.s();
        }
        else if(ch2==2)
        {
            u[i].daily_takencal[day-1][ch-1]= ln.m();
        }
        else if(ch==2)
        {
            u[i].daily_takencal[day-1][ch-1]= ln.l();
        }
  }
  else if(ch==3)
  {

         dn.info();

        cout<<"\n\n choose: ";
        cin>>ch2;

        if(ch2==1)
        {
            u[i].daily_takencal[day-1][ch-1]=dn.s();
        }
        else if(ch2==2)
        {
            u[i].daily_takencal[day-1][ch-1]= dn.m();
        }
        else if(ch==2)
        {
            u[i].daily_takencal[day-1][ch-1]= dn.l();
        }
  }

  int ch3;

  cout<<"\n\n1.eat another round"<<endl
      <<"2.User Menu"
      <<endl;

      cin>>ch3;

      if(ch3==1)
      {
          goto k;
      }
      else if(ch3==2)
      {
          user_2(u);
      }


}

void do_sport(int i,User u[7])
{
    system("cls");
    system("color 4");


    Basketball bb;
    Football fb;
    Tennis tn;
    Swimming sw;

    k:

    int ch,day;

    cout<<"\n\n\tChoose day: ";
    cin>>day;

    cout<<"\n\n\t1.Basketball"
        <<"2.Football"
        <<"3.Tennis"
        <<"4.Swimming"
        <<endl;

    cout<<"\n\n\tChoose sport: ";
    cin>>ch;


    if(ch==1)
    {
        if(u[i].daily_sports[day-1]==0)
        {
            u[i].daily_sports[day-1]=ch;
            u[i].daily_burned[day-1]=bb.burned();
        }
        else
        {
            cout<<"\n\n You have done sports this day"<<endl;
            goto k;
        }
    }
    else if(ch==2)
    {
         if(u[i].daily_sports[day-1]==0)
        {
            u[i].daily_sports[day-1]=ch;
            u[i].daily_burned[day-1]=fb.burned();
        }
        else
        {
            cout<<"\n\n You have done sports this day"<<endl;
            goto k;
        }
    }

    else if(ch==3)
    {
         if(u[i].daily_sports[day-1]==0)
        {
            u[i].daily_sports[day-1]=ch;
            u[i].daily_burned[day-1]=tn.burned();
        }
        else
        {
            cout<<"\n\n You have done sports this day"<<endl;
            goto k;
        }
    }

    else if(ch==4)
    {
         if(u[i].daily_sports[day-1]==0)
        {
            u[i].daily_sports[day-1]=ch;
            u[i].daily_burned[day-1]=sw.burned();
        }
        else
        {
            cout<<"\n\n You have done sports this day"<<endl;
            goto k;
        }
    }

    int ch3;


    cout<<"\n\n\t1.do another day"
        <<"2.return User Menu"
        <<endl;

    cout<<"Choose: ";
    cin>>ch3;

    if(ch3==1)
    {
        goto k;
    }
    else if(ch3==2)
    {
        user_2(u);
    }
}


void show_sportdone(User u)
{

    cout<<"\n\n\t Sports done in week:"<<endl;

    int i;

    for(i=0;i<7;++i)
    {

        if(u.daily_sports[i]==1)
        {
            cout<<"\t day"<<i+1<<"  Basketball "<<u.daily_burned[i]<<" cal"<<endl;
        }
        else if(u.daily_sports[i]==2)
        {
            cout<<"\t day"<<i+1<<"  Football "<<u.daily_burned[i]<<" cal"<<endl;
        }
        else if(u.daily_sports[i]==3)
        {
             cout<<"\t day"<<i+1<<"  Tennis "<<u.daily_burned[i]<<" cal"<<endl;
        }
        else if(u.daily_sports[i]==4)
        {
             cout<<"\t day"<<i+1<<"  Swimming "<<u.daily_burned[i]<<" cal"<<endl;
        }
        else if(u.daily_sports[i]==0)
        {
            cout<<"\t sport has not done"<<endl;
        }

    }


}

void show_calorieweekly(User u)
{
    int i,b;

    int c1=0,c2=0,c3=0;

    for(i=0;i<7;++i)
    {

        cout<<"\n\n day "<<i+1;


        for(b=0;b<3;++b)
        {
            if(b==0)
            {
                if(u.daily_takencal[i][b]==0)
                {
                    cout<<"\tbreakfast not eaten  ";

                }
                else if(u.daily_takencal[i][b]==200)
                {
                    cout<<"\tbreakfast small ";

                }
                else if(u.daily_takencal[i][b]==400)
                {
                    cout<<"\tbreakfast medium  ";

                }
                else if(u.daily_takencal[i][b]==600)
                {
                    cout<<"\tbreakfast large  ";

                }
            }
            else if(b==1)
            {
                if(u.daily_takencal[i][b]==0)
                {

                    cout<<"\tlunch not eaten   ";

                }
                else if(u.daily_takencal[i][b]==400)
                {
                    cout<<"\tlunch small   ";

                }
                else if(u.daily_takencal[i][b]==600)
                {
                    cout<<"\tlunch medium   ";

                }
                else if(u.daily_takencal[i][b]==800)
                {
                    cout<<"\tlunch large   ";

                }

            }
            else if(b==2)
            {

                if(u.daily_takencal[i][b]==0)
                {
                    cout<<"\tdinner not eaten   ";
                }
                else if(u.daily_takencal[i][b]==400)
                {
                    cout<<"\tdinner small   ";
                }
                else if(u.daily_takencal[i][b]==600)
                {
                    cout<<"\tdinner medium   ";
                }
                else if(u.daily_takencal[i][b]==800)
                {
                    cout<<"\tdinner large   ";
                }
            }

        }
    }
}
ostream& operator<<(ostream& o,User& u)
{

    o<<"\n\n\t User Info"<<endl;

    o<<u.name<<endl
        <<u.id<<endl
        <<u.age<<endl
        <<u.weight<<endl;

        return o;
}

double User::calorie_taken()
{
    double toplam;

    int i,b;

    for(i=0;i<7;++i)
    {
        for(b=0;b<3;++b)
        {
            toplam=toplam+daily_takencal[i][b];
        }
    }

    return toplam;


}

double User::calorie_burned()
{

    int i;
    double toplam;
    for(i=0;i<7;++i)
    {
    toplam=toplam+daily_burned[i];
    }

    return toplam;

}




void weekly_report(int i,User u[])
{

    system("cls");
    system("color 4");

    cout<<"\n\n\t\t Week Report of You"<<endl;

    cout<<"\t\n\n Your Personal Ýnfo"<<endl;
    cout<<u[i];

    cout<<"\n\t Taken calorie"<<endl;
    show_calorieweekly(u[i]);


    show_sportdone(u[i]);

    cout<<"\n\n\t total calorie taken: "<<u[i].calorie_taken()<<" cal"<<endl;

    cout<<"\n\n\t total calorie burned: "<<u[i].calorie_burned()<<" cal"<<endl;

    int ch1;

    cout<<"\n\n\n\t1.exit"<<endl
        <<"2.User menu"<<endl;

    cout<<"\n choose : ";
    cin>>ch1;

    if(ch1==1)
    {
        exit(0);
    }
    else if(ch1==2)
    {
        user_2(u);
    }
}

User::User(const User& u)
{
    this->name=u.name;
    this->id=u.id;
    this->age=u.age;
    this->weight=u.weight;

    int i=0,b=0;

    for(i=0;i<7;++i)
    {
        daily_sports[i]=u.daily_sports[i];
    }

    for(i=0;i<7;++i)
    {
        daily_burned[i]=u.daily_burned[i];
    }

    for(i=0;i<7;++i)
    {
        for(b=0;b<3;++b)
        {
            daily_takencal[i][b]=u.daily_takencal[i][b];
        }
    }



}

User& User::operator=(const User& u)
{

    this->name=u.name;
    this->id=u.id;
    this->age=u.age;
    this->weight=u.weight;

    int i=0,b=0;

    for(i=0;i<7;++i)
    {
        this->daily_sports[i]=u.daily_sports[i];
    }

    for(i=0;i<7;++i)
    {
        this->daily_burned[i]=u.daily_burned[i];
    }

    for(i=0;i<7;++i)
    {
        for(b=0;b<3;++b)
        {
            this->daily_takencal[i][b]=u.daily_takencal[i][b];
        }
    }




    return (*this);

}

User& User::operator+(const User& u)
{


    this->name=u.name+this->name;

    this->id=u.id+this->id;

    this->age=u.age+this->age;

    this->weight=u.weight+this->weight;

    return (*this);
}
