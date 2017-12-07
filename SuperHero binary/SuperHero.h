#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class SuperHero
{
    private:
    char name[50];
    int age;
    char superpower;

    public:
    SuperHero();
    SuperHero(char name, int age, char superpower);
    friend ostream& operator << (ostream& out, SuperHero& hero);
    friend istream& operator >> (istream& in, SuperHero& hero);
    void get_info();
    string changeInfo();
};

#endif // SUPERHERO_H
