#include "Donimos.h"

#include "Domain.h"
#include "MainUI.h"

Donimos::Donimos()
{
    a = 0;
    //ctor
}

void Donimos::order()
{
    cout << a;
    *str[1000] = repo.readorders(a);

    for(int i = 0; i < a; i++)
    {
        cout << str[i] << endl;
    }
}

ostream& operator<< (ostream& out, const Donimos& donimos)
{
    out << donimos;
    return out;
}

Donimos::~Donimos()
{
    //dtor
}
