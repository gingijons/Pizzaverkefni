#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class SuperHero
{
    private:
    string name;
    int age;
    char superpower;
    string real_power;

    public:
    SuperHero();
    SuperHero(string name, int age, char superpower);
    friend ostream& operator << (ostream& out, SuperHero& hero);
    friend istream& operator >> (istream& in, SuperHero& hero);
    void get_info();
    string changeInfo();
};

#endif // SUPERHERO_H
