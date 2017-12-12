#include "Donimos.h"
#include "Domain.h"
#include "MainUI.h"
#include <vector>
#include <iostream>
#include <algorithm>

Donimos::Donimos()
{
    a = 0;
    //ctor
}

void Donimos::order()
{
    Domain domain;

    repo.readorders(a, str);
    domain.printorders(a, str);
    domain.add_order(a);

}

void Donimos::neworder(int a)
{
    Donimos donimos;
    Domain domain;

    int j = 0;
    int price = 0;
    char cont;
    //int order_num;
    char paid;
    string store;
    string size;
    string p_or_d;
    string sorted;
    vector<string> top;
    string crust;
    string soda;
    bool breadsticks;

    do
    {
        size = donimos.getpizzasize();
        crust = donimos.getcrust();
        donimos.gettoppings(&top, &j);
        sorted = donimos.sorttoppings(&top);
        domain.on_menu(&top, sorted);
        soda = domain.getsoda();
        breadsticks = domain.getbreadsticks();
        price = domain.getprice(size, j, breadsticks, soda);
        paid = donimos.paid();
        store = repo.getstore(store);
        p_or_d = domain.pickup_or_delivery();
        repo.write_order(size, crust, top, price, paid, store, p_or_d, a, soda, breadsticks);
        a++;

        do
        {
            cout << "another order? (y/n): ";
            cin >> cont;
            cout << endl;
        }while(cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N');

        cout << "-----------------------------------------------------" << endl;
        cout << endl;
    }while(cont == 'y' || cont == 'Y');


}

string Donimos::getpizzasize()
{
    string size;
    do
    {
        cout << "Size (lit mid sto): ";
        cin >> size;
        if(size == "sto" || size == "lit" || size == "mid")
        {
            break;
        }
        else
        {
            cout << "invalid size" << endl;
        }
    }
    while(true);

    return size;

}

string Donimos::getcrust()
{
    string crust;

    do
    {
        cout << "crust (italy light org): ";
        cin >> crust;
        if(crust == "italy" || crust == "light" || crust == "org")
        {
            break;
        }
        else
        {
            cout << "invalid crust" << endl;
        }
    }
    while(true);

    return crust;
}

void Donimos::gettoppings(vector<string>* top, int* j)
{
    cout << "topping: (ppp, bei, rjo, sve, ana, ski) n = exit " << endl;
    int i = 0;
    *j = i;
    top->clear();

    do
    {
        string topping;
        cin >> topping;
        //topping == "ppp" || topping == "rjo" || topping == "sve" || topping == "bei"

        //str[i].find('\\')
        if(topping == "ppp" || topping == "rjo" || topping == "sve" || topping == "bei" || topping == "ana" || topping == "ski")
        {
            top->push_back(topping);
            *j+=1;
        }
        else
        {
            break;
        }

    }while(true);
}

void Donimos::y_printorders(int a, string str[])
{
    for(int i = 0; i < a; i++)
    {
        cout << str[i] << endl;
    }
}

string Donimos::sorttoppings(vector<string> *top)
{
    string sorted;

    sort(top->begin(), top->end());

    for(unsigned int i = 0; i < top->size(); i++)
    {
        sorted += (*top)[i];
    }

    return sorted;
}

char Donimos::paid()
{
    char paid;
    cout << "Mark paid? (y/n): ";
    cin >> paid;
    return paid;
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
