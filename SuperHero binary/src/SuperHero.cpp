#include "SuperHero.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


SuperHero::SuperHero()
{
    this->name = name;
    this->age = age;
    this->superpower = superpower;
    this->real_power = real_power;

}

void SuperHero::get_info()
{
    cin >> name >> age >> superpower;

}

string SuperHero::changeInfo()
{
    string real_power;

    if (superpower == 'f' || superpower == 'F')
    {
        real_power = "Flying";
    }
    if (superpower == 'g' || superpower == 'G')
    {
        real_power = "Giant";
    }
    if (superpower == 'h' || superpower == 'H')
    {
        real_power = "Hacker";
    }
    if (superpower == 'n' || superpower == 'N')
    {
        real_power = "None";
    }
    else
    {
        real_power = "Weakling"
    }

    return real_power;
}

ostream& operator << (ostream& out, SuperHero& hero)
{
    out << "Hero name: " << hero.name << endl;
    out << "Hero age: " << hero.age << endl;
    out << "Powers: " << hero.changeInfo() << endl;
    return out;
}

istream& operator >> (istream& in, SuperHero& hero)
{
    in >> hero.name;
    in >> hero.age;
    in >> hero.superpower;
    return in;
}
