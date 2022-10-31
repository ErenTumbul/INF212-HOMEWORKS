#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <iostream>

class User;

using namespace std;

class User
{
    friend class Basketball;
    friend class Tennis;
    friend class Football;
    friend class Swimming;

    friend class Breakfast;
    friend class Lunch;
    friend class Dinner;

    friend void create_user(User u[7]);
    friend void show_user();
    friend void eat(int,User u[7]);
    friend void user_2(User u[7]);
    friend void do_sport(int,User u[7]);
    friend void weekly_report(int,User);
    friend void user_menu(User u[7]);
    friend ostream& operator<<(ostream& o,User& u);
    friend void developer_mode();
    friend void show_sportdone(User u);



private:
    string name;
    int id;
    int age;
    double weight;


public:

    int daily_takencal[7][3];
    int daily_burned[7];
    int daily_sports[7];

    string Name(){return name;}
    int Id(){return id;}
    int Age(){return age;}
    double Weight(){return weight;}

    User();
    User(const User& u);
    User& operator=(const User& u);
    User& operator+(const User& u);

    void set_person(string name,int id,int age,double weight);



    double calorie_taken();
    double calorie_burned();
    //double daily_taken();
    //double daily_given();


};


ostream& operator<<(ostream& o,User& u);
void show_sportdone(User u);



void create_user(User u[7]);
void show_user();
void eat(int,User u[7]);
void user_2(User u[7]);
void do_sport(int,User u[7]);
void weekly_report(int,User u[7]);
void user_menu(User u[7]);
void developer_mode();

#endif // USER_H_INCLUDED
