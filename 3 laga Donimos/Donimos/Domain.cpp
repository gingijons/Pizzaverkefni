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

    cout << "Would you like to print orders? (y/n): ";
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

void Domain::on_menu(vector<string> *top, string sorted)
{
    if(sorted == "anaski")
    {
        top->clear();
        top->push_back("Hawaiian");
    }

    if(sorted == "anabeiski")
    {
        top->clear();
        top->push_back("Bahamas");
    }

    if(sorted == "pppsve")
    {
        top->clear();
        top->push_back("PS2");
    }
}

int Domain::getprice(string size, int j, bool breadsticks, string soda)
{
    int price;

    if(size == "lit")
    {
        price = 1499;
    }
    else if(size == "mid")
    {
        price = 1999;
    }
    else if(size == "sto")
    {
        price = 2999;
    }

    price += (j*150);

    if(size == "sto" && j == 2)
    {
        price = 1690;
    }

    if(!soda.empty())
    {
        price += 390;
    }

    if(breadsticks == true)
    {
        price += 590;
    }

    return price;
}

string Domain::markpaid(string& paid)
{
    if(paid == "y" || paid == "Y")
    {
        paid = "Greidd";
    }

    return paid;
}

char Domain::pickup_or_delivery()
{
    char p_or_d;

    do
    {
        cout << "Pickup or delivery (P = pickup, D = delivery): ";
        cin >> p_or_d;
        if(p_or_d == 'd' || p_or_d == 'D' || p_or_d == 'p' || p_or_d == 'P')
        {
            break;
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }while(true);

    return p_or_d;
}

bool Domain::getbreadsticks()
{
    char add;
    do
    {
        cout << "breadsticks (y/n): ";
        cin >> add;
    }while(add != 'y' && add != 'Y' && add != 'n' && add != 'N');

    if(add == 'y' || add == 'Y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

string Domain::getsoda()
{
    Repo repo;
    char add;
    string type;
    do
    {
        cout << "Add a soda? (y/n): ";
        cin >> add;
    }while(add != 'y' && add != 'Y' && add != 'n' && add != 'N');

    if(add == 'y' || add == 'Y' )
    {
        type = repo.readsoda();
    }
    return type;
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
