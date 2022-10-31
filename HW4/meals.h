#ifndef meals_h
#define meals_h
#include <iostream>
#include "User.h"

using namespace std;

class Breakfast
{
    friend class User;

private:
    int small=200;
    int medium=400;
    int large=600;

public:

    int s(){return small;}
    int m(){return medium;}
    int l(){return large;}

    void info();




};

class Lunch
{
    friend class User;

private:
    int small=400;
    int medium=600;
    int large=800;

public:

    int s(){return small;}
    int m(){return medium;}
    int l(){return large;}

    void info();





};

class Dinner
{
    friend class User;

private:
    int small=400;
    int medium=600;
    int large=800;

public:

    int s(){return small;}
    int m(){return medium;}
    int l(){return large;}

    void info();


};


#endif // meals_h
