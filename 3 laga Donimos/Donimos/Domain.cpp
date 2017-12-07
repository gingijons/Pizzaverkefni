#include "Domain.h"
#include "MainUI.h"
#include "Donimos.h"
#include "Repo.h"


Domain::Domain()
{
    Donimos donimos;
    //ctor
}

void Domain::login(char* login)
{
    Donimos donimos;

    if(*login == 'A' || *login == 'a')
    {

    }
    if(*login == 'M' || *login == 'm')
    {

    }
    if(*login == 'O' || *login == 'o')
    {
        donimos.order();
    }
    if(*login == 'C' || *login == 'c')
    {

    }

}

void Domain::printorders(int a, string str[])
{
    Donimos donimos;

    cout << "Would you like to print orders? (y/n): " << input;
    cin >> input;
    if(input == 'y'|| input == 'Y')
    {
        donimos.y_printorders(a, str);
    }
}

void Domain::add_order(int a)
{
    Donimos donimos;

    cout << "would you like to add a new order? (y/n): ";
    cin >> input;
    if(input == 'y'|| input == 'Y')
    {
        donimos.neworder(a);
    }
}

ostream& operator<< (ostream& out, const Domain& domain)
{
    out << domain;
    return out;
}

Domain::~Domain()
{
    //dtor
}
