#include "Repo.h"
#include "Domain.h"
#include "MainUI.h"
#include "Donimos.h"
#include <fstream>

Repo::Repo()
{
    //ctor
}

void Repo::readorders(int& a, string str[1000])
{
    ifstream fin;
    ifstream bin;
    ofstream fout;
    string b;

    //cout << a;

    bin.open("orders.txt");

    while(getline(bin, b))
    {
        a++;
    }

    //cout << a;

    fin.open("orders.txt");


    for(int i = 0; i < a; i++)
    {
        getline(fin, str[i]);
        //cout << str[i] << endl;
        //cout << str[i].find("greidd")
    }
    bin.close();
    fin.close();

    fout.open("orders.txt");

    for(int i = 0; i < a; i++)
    {
        fout << str[i] << endl;
    }
    fout.close();

    //cout << a;
}

string Repo::getstore(string store)
{
    ifstream bin;
    string storelist[50];
    ifstream st;
    string b;
    int a = 0;
    bin.open("stores.txt");
    while(getline(bin, b))
    {
        a++;
    }
    cout << a;
    st.open("stores.txt");
    for(int i = 0; i < a; i++)
    {
        getline(st, storelist[i]);
    }
    do
    {
        cout << "Store (";
        for(int i = 0; i < a; i++)
        {
            cout << storelist[i] << " ";
        }
        cout << "): ";
        cin >> store;
        for(int i = 0; i < a; i++)
        {
            if(storelist[i] == store)
            {
                return store;
                break;

            }
        }
    cout << "invalid store input" << endl;

    }while(true);
}

void Repo::write_order(string size, string crust, vector<string> top, int price, char paid, string store, string p_or_d, int a, string soda, bool breadsticks)
{
    ofstream fout;
    fout.open("orders.txt", ios::app);

    cout << "<" << a+1 << "> <" << size << "> <" << crust << "> <";
    fout << "<" << a+1 << "> <" << size << "> <" << crust << "> <";
    for(unsigned int i = 0; i < top.size(); i++)
    {
        if(!top[i].empty())
        {
            if(i==top.size()-1)
            {
                cout << top[i];
                fout << top[i];
            }
            else
            {
                cout << top[i] << " ";
                fout << top[i] << " ";
            }

        }
        if(top[i].empty()==true)
        {
            break;
        }
    }

    if(breadsticks == true)
    {
        fout << "> <BS";
        cout << "> <BS";
    }

    if(!soda.empty())
    {
        fout << "> <" << soda;
        cout << "> <" << soda;
    }

    cout << "> <" << price << ">";
    fout << "> <" << price << ">";

    if(paid == 'y' || paid == 'Y')
    {
        fout << " <greidd>";
        cout << " <greidd>";
    }

    if(p_or_d == "d" || p_or_d == "D")
    {
        fout << " <Delivery>";
        cout << " <Delivery>";
    }

    else if(p_or_d == "p" || p_or_d == "P")
    {
        fout << " <Pickup>";
        cout << " <Pickup>";
    }

    cout << " <" << store << ">" << endl;
    fout << " <" << store << ">" << endl;

    fout.close();
    a++;
}

string Repo::readsoda()
{
    ifstream bin;
    string sodalist[50];
    ifstream sod;
    string soda;
    string b;
    int a = 0;

    bin.open("sodas.txt");
    while(getline(bin, b))
    {
        a++;
    }
    cout << a;
    sod.open("sodas.txt");
    for(int i = 0; i < a; i++)
    {
        getline(sod, sodalist[i]);
    }
    do
    {
        cout << "Sodas (";
        for(int i = 0; i < a; i++)
        {
            cout << sodalist[i] << " ";
        }
        cout << "): ";
        cin >> soda;
        for(int i = 0; i < a; i++)
        {
            if(sodalist[i] == soda)
            {
                return soda;
                break;

            }
        }
        cout << "invalid input" << endl;

    }while(true);

    return soda;
}


ostream& operator<< (ostream& out, const Repo& repo)
{
    out << repo;
    return out;
}

Repo::~Repo()
{
    //dtor
}
