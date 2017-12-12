#include "Repo.h"
#include "Domain.h"
#include "MainUI.h"
#include "Donimos.h"
#include <fstream>
#include "Domain.h"

Repo::Repo()
{
    //ctor
}

void Repo::admin_ui()
{
    Domain domain;

    int num;
    cout << "What would you like to change?" << endl;
    cout << "1 = Stores, 2 = Toppings, 3 = Price, 4 = Soda, 5 = Menu: ";
    cin >> num;
    domain.change(num);
}

void Repo::change_stores()
{
    ifstream st;
    ifstream bin;
    ofstream fout;
    string b;
    int a = 0;
    int num = 0;

    bin.open("stores.txt", ios::app);

    while(getline(bin, b))
    {
        a++;
    }
    bin.close();

    string storelist[50];

    st.open("stores.txt");

    if(st.is_open())
    {
        cout << "heyy";
    }
    for(int i = 0; i < a; i++)
    {
        getline(st, storelist[i]);
        //fout << storelist[i];
    }
    st.close();

    cout << endl;

    cout << endl;
    cout << "1 = Add store, 2 = remove store: ";
    cin >> num;

    if(num == 1)
    {
        string newstore;
        cout << "Enter name (all lowercase): ";
        cin >> newstore;
        cout << newstore;
        fout.open("stores.txt");
        for(int i = 0; i < a; i++)
        {
            fout << storelist[i] << endl;
        }
        fout << newstore;
        fout.close();
    }
    if(num == 2)
    {
        int store;
        st.open("stores.txt");
        for(int i = 0; i < a; i++)
        {
            getline(st, storelist[i]);
            cout << i + 1 << " = " << storelist[i] << endl;
        }
        cout << "What store to remove: ";
        cin >> store;
        store -= 1;
        fout.open("stores.txt");
        for(int i = 0; i < a; i++)
        {
            if(i != store)
            {
                fout << storelist[i] << endl;
            }
        }
        cout << endl;

        if(store >= a)
        {
            cout << "nothing was removed";
        }
        else
        {
            cout << storelist[store] << " has been removed" << endl;
        }
    }

}

void Repo::change_toppings()
{

}

void Repo::change_price()
{

}

void Repo::change_soda()
{

}

void Repo::change_menu()
{

}

void Repo::inprogress(int a, int order_num, string str[1000])
{
    ofstream fout;
    fout.open("orders.txt");
    for(int i = 0; i < a; i++)
    {
        if(i==order_num)
        {
            fout << str[order_num] << " <In progress>" << endl;
        }
        else
        {
            fout << str[i] << endl;
        }
    }
    fout.close();
}

void Repo::readorders(int& a, string str[1000])
{
    ifstream fin;
    ifstream bin;
    ofstream fout;
    string b;

    //cout << a << " ";

    bin.open("orders.txt", ios::app);

    while(getline(bin, b))
    {
        a++;
    }

    //cout << a << " ";

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

    //cout << a << " ";
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

void Repo::ready(int x, int z, int a, int order_num, string str[1000])
{
    ofstream fout;
    fout.open("orders.txt");
    for(int i = 0; i < a; i++)
    {
        if(i==order_num)
        {
            if(str[order_num].find("progress") != string::npos)
            {
                str[order_num].replace(x, 13, "<Ready>");
                fout << str[order_num] << endl;
            }
            else
            {
                fout << str[order_num] << " <Ready>" << endl;
            }

        }
        else
        {
            fout << str[i] << endl;
        }
    fout.close();
    }
}

void Repo::markpaid(int a, int order_num, string str[1000])
{
    ofstream fout;
    fout.open("orders.txt");
    for(int i = 0; i < a; i++)
    {
        if(i==order_num)
        {
            fout << str[order_num] << " <greidd>" << endl;
        }
        else
        {
            fout << str[i] << endl;
        }
        fout.close();
    }
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
