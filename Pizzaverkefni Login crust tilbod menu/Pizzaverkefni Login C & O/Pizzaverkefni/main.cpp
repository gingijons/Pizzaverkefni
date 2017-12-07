#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getpriceforsize(string size)
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
    else
    {
        price = 2999;
    }
    return price;
}

string getpizzasize()
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

string getcrust()
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


void gettoppings(vector<string> *top, int *j)
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

string sorttoppings(vector<string> *top)
{
    string sorted;

    sort(top->begin(), top->end());

    for(unsigned int i = 0; i < top->size(); i++)
    {
        sorted += (*top)[i];
    }

    return sorted;
}

int main()
{
    ifstream fin;
    ifstream bin;
    ofstream fout;
    int a = 0;
    int s = 0;
    int *j = &s;
    int price = 0;
    string b;
    string str[1000];
    char login;

    bin.open("pantanir.txt");

    while(getline(bin, b))
    {
        a++;
    }

    fin.open("pantanir.txt");


    for(int i = 0; i < a; i++)
    {
        getline(fin, str[i]);
        //cout << str[i] << endl;
        //cout << str[i].find("greidd");

    }
    bin.close();
    fin.close();

    fout.open("pantanir.txt");

    for(int i = 0; i < a; i++)
    {
        fout << str[i] << endl;
    }
    fout.close();

    cout << "`````````                                   .+oo-                                  :oo+." << endl;
    cout << "/hhhhhhhhhhyo:`                              shhhh`                                .hhhhs          " << endl;
    cout << "/hhhhhhhhhhhhhy:                             `/++-                                  .+hy-          " << endl;
    cout << "/hhhh/   `:yhhhh:  -oyhhhhy+.  +hhhy+yhhhho. +hhho :hhhh+yhhhhs:ohhhhh+   .+yhhhhy+. -- :oyhhhhys+`" << endl;
    cout << "/hhhh/     -hhhhs +hhhhyyhhhh/ +hhhhysyhhhhs ohhhs :hhhhyoshhhhhsoyhhhh. /hhhhyyhhhh+  -hhhh+//oy: " << endl;
    cout << "/hhhh/     +hhhho-hhhy`  .hhhh`+hhhy   ohhhy ohhhs :hhhh`  shhho  -hhhh..hhhh.  .yhhh. `shhhhhyso/`" << endl;
    cout << "/hhhho:::/shhhhy..hhhh/..+hhhy`+hhhy   +hhhy ohhhs :hhhh`  shhho  .hhhh.`hhhh/../hhhh.  `/:/++shhho" << endl;
    cout << "/hhhhhhhhhhhhy+`  :yhhhhhhhhy- +hhhy   +hhhy ohhhs :hhhh`  shhho  .hhhh. -yhhhhhhhhy:  .yhhysoshhh/" << endl;
    cout << "-ooooooooo+/-      `:+syys+-   :ooo+   :ooo+ /ooo/ .o+++`  /+++:  `++++`   :+syys+:`   `:+osyyso/. " << endl;
    cout << endl;
    cout << "(o = order, c = cashier)" << endl;
    cout << "login: ";
    cin >> login;


    if(login == 'o' || login == 'O')
    {


        string size;
        string sorted;
        vector<string> top;
        char cont;
        string crust;

        fout.open("pantanir.txt");
        for(int i = 0; i < a; i++)
        {
            fout << str[i] << endl;
        }

        do
        {
        size = getpizzasize();

        crust = getcrust();

        gettoppings(&top, j);

        sorted = sorttoppings(&top);

        //cout << sorted;

        if(sorted == "anaski")
        {
            top.clear();
            top.push_back("Hawaiian");
        }

        if(sorted == "anabeiski")
        {
            top.clear();
            top.push_back("Bahamas");
        }

        if(sorted == "pppsve")
        {
            top.clear();
            top.push_back("PS2");
        }



        price = getpriceforsize(size);

        price += (*j*150);

        if(size == "sto" && *j == 2)
        {
            price = 1690;
        }

        cout << "<" << a+1 << "> <" << size << "> <" << crust << "> <";

        for(unsigned int i = 0; i < top.size(); i++)
        {
            if(!top[i].empty())
            {
                if(i==top.size()-1)
                {
                    cout << top[i];
                }
                else
                {
                    cout << top[i] << " ";
                }

            }
            if(top[i].empty()==true)
            {
                break;
            }
        }

        cout << "> <" << price << ">" << endl;

        fout << "<" << a+1 << "> <" << size << "> <" << crust << "> <";

            for(unsigned int i = 0; i < top.size(); i++)
        {
            if(!top[i].empty())
            {
                if(i==top.size()-1)
                {
                    fout << top[i];
                }
                else
                {
                    fout << top[i] << " ";
                }

            }
            if(top[i].empty()==true)
            {
                break;
            }
        }

        fout << "> <" << price << ">" << endl;
        a++;

        cout << "another order? (y/n): ";
        cin >> cont;

        } while(cont == 'y' || cont == 'Y');


        fout.close();
    }

    if(login == 'c' || login == 'C')
    {
        int order_num;
        char paid;
        char cont;
        do
        {
            cout << "would you like a list of the most recent orders? (y/n): ";
            cin >> cont;
            if(cont == 'y' || cont == 'Y')
            {
                for(int i = a-10; i < a; i++)
                {
                    cout << str[i] << endl;
                }
            }
            do
            {
                cout << "Enter order number: ";
                cin >> order_num;
                cout << endl;
                order_num -= 1;
                if(order_num > a)
                {
                    cout << "There are only " << a << " orders" << endl;
                }
                else{break;}
            }while(true);

            cout << str[order_num];
            cout << endl;
            cout << endl;
            cout << "mark paid? (y/n): ";
            cin >> paid;
            cout << endl;



            if(paid == 'y' || paid == 'Y')
            {
                if(str[order_num].find("greidd") != string::npos)
                {
                    cout << "Already payed" << endl;
                }
                else
                {
                    fout.open("pantanir.txt");
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
                    }
                    cout << str[order_num] << " <greidd>" << endl;
                }

            fout.close();

            }
            cout << "pay for another order (y/n): ";
            cin >> cont;

        }while(cont == 'y' || cont == 'Y');

    }


    return 0;
}
