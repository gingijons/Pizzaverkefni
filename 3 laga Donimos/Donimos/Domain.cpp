#include "Domain.h"
#include "MainUI.h"
#include "Donimos.h"
#include "Repo.h"


Domain::Domain()
{
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

ostream& operator<< (ostream& out, const Domain& domain)
{
    out << domain;
    return out;
}

Domain::~Domain()
{
    //dtor
}
