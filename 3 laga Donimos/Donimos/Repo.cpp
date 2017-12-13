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
    cout << "1 = Stores, 2 = Toppings, 3 = Price, 4 = Soda, 5 = Menu, 6 = crust: ";
    cin >> num;
    domain.change(num);
}

void Repo::change_crust()
{
    ifstream st;
    ifstream bin;
    ofstream fout;
    string b;
    int a = 0;
    int num = 0;

    bin.open("crusts.txt", ios::app);

    while(getline(bin, b))
    {
        a++;
    }
    bin.close();

    string crustlist[50];

    st.open("crusts.txt");

    if(st.is_open())
    {

    }
    for(int i = 0; i < a; i++)
    {
        getline(st, crustlist[i]);
        //cout << crustlist[i];
    }
    st.close();

    cout << endl;

    cout << endl;
    cout << "1 = Add crust, 2 = remove crust: ";
    cin >> num;

    if(num == 1)
    {
        string newcrust;
        cout << "Enter name (all lowercase): ";
        cin.ignore();
        getline(cin, newcrust);
        cout << newcrust;
        fout.open("crusts.txt");
        for(int i = 0; i < a; i++)
        {
            fout << crustlist[i] << endl;
        }
        fout << newcrust;
        fout.close();
    }
    if(num == 2)
    {
        int num;
        st.open("crusts.txt");
        for(int i = 0; i < a; i++)
        {
            getline(st, crustlist[i]);
            cout << i + 1 << " = " << crustlist[i] << endl;
        }
        cout << "What crust to remove: ";
        cin >> num;
        num -= 1;
        fout.open("crusts.txt");
        for(int i = 0; i < a; i++)
        {
            if(i != num)
            {
                fout << crustlist[i] << endl;
            }
        }
        cout << endl;

        if(num >= a)
        {
            cout << "nothing was removed";
        }
        else
        {
            cout << crustlist[num] << " has been removed" << endl;
        }
    }

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

/*void Repo::readcrust(int a)
{
    ifstream fin;
    ifstream bin;
    ofstream fout;
    string b;

    //cout << a << " ";

    bin.open("crusts.txt", ios::app);

    while(getline(bin, b))
    {
        a++;
    }

    //cout << a << " ";

    fin.open("crusts.txt");


    for(int i = 0; i < a; i++)
    {
        getline(fin, str[i]);
        //cout << str[i] << endl;
        //cout << str[i].find("greidd")
    }
    bin.close();
    fin.close();

    fout.open("crusts.txt");

    for(int i = 0; i < a; i++)
    {
        fout << str[i] << endl;
    }
    fout.close();

    //cout << a << " ";
}*/

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
        cout << " Stores (";
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

string Repo::getcrust(string crust)
{
    ifstream bin;
    string crustlist[50];
    ifstream st;
    string b;
    int a = 0;
    bin.open("crusts.txt");
    while(getline(bin, b))
    {
        a++;
    }
    cout << a;
    st.open("crusts.txt");
    for(int i = 0; i < a; i++)
    {
        getline(st, crustlist[i]);
    }
    do
    {
        cout << " Crusts: ";
        for(int i = 0; i < a; i++)
        {
            cout << crustlist[i] << " | ";
        }
        cout << ": ";
        cin.ignore();
        getline(cin, crust);
        for(int i = 0; i < a; i++)
        {
            if(crustlist[i] == crust)
            {
                return crust;
                break;

            }
        }
    cout << "invalid crust input" << endl;

    }while(true);
}

void Repo::write_order(string size, string crust, vector<string> top, int price, char paid, string store, string p_or_d, int a, string soda, bool breadsticks, string comment)
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

    cout << " <" << store << ">";
    fout << " <" << store << ">";

    if(!comment.empty())
    {
        cout << " <" << comment << ">" << endl;
        fout << " <" << comment << ">" << endl;
    }

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

string Repo::readtoppings()
{
    ifstream bin;
    string toppings_list[50];
    ifstream top;
    string toppings;
    string t;
    int a = 0;

    bin.open("toppings.txt");
    while(getline(bin, t))
    {
        a++;
    }
    bin.close();

    cout << a;
    top.open("toppings.txt");
    for(int i = 0; i < a; i++)
    {
        getline(top, toppings_list[i]);
    }
    do
    {
        cout << "Toppings (";
        for(int i = 0; i < a; i++)
        {
            cout << toppings_list[i] << " ";
        }
        cout << "): ";
        cin >> toppings;
        for(int i = 0; i < a; i++)
        {
            if(toppings_list[i] == toppings)
            {
                return toppings;
                break;

            }
        }
        cout << "invalid input" << endl;

    }while(true);

    return toppings;

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
