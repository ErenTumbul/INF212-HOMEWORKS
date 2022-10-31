#ifndef sports_h
#define sports_h
#include "User.h"
#include <iostream>

using namespace std;

class Basketball
{

    friend class User;

private:
    int cal=6;

public:

    double B(){return cal;}

    double burned();


};

class Football
{

    friend class User;

private:
    int cal=5;

public:

    int F(){return cal;}

    double burned();



};

class Tennis
{
    friend class User;

private:
    int cal=6;

public:

    int T(){return cal;}

    double burned();


};

class Swimming
{
    friend class User;

private:
    int cal=7;

public:

    int S(){return cal;}

    double burned();





};

#endif // sports_h
