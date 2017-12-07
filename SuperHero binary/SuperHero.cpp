#include "SuperHero.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

SuperHero::SuperHero()
{
    this->name[0] = '\0';
    this->age = age ;
    this->superpower = 'n';
}

void SuperHero::get_info()
{
    cin >> name >> age >> superpower;
}
string SuperHero::changeInfo()
{
    string real_power = "Weakling";

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

    return real_power;
}

istream& operator >> (istream& in, SuperHero& hero)
{

    cout << "Enter name ";
    in >> hero.name;
    cout << "Enter age ";
    in >> hero.age;
    cout << "Enter superpower ";
    in >> hero.superpower;
    cout << endl;
    return in;
}
ostream& operator << (ostream& out, SuperHero& hero)
{
    out << "Name: ";
    out << hero.name << endl;
    out << "Age:  ";
    out << hero.age << endl;
    out << "Superpower: ";
    out << hero.changeInfo() << endl; //muna að breyta í real_power

    return out;
}
