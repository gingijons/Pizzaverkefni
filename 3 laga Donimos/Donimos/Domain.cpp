#include "Domain.h"
#include "MainUI.h"
#include "Donimos.h"
#include "Repo.h"
#include <string>


Domain::Domain()
{
    Donimos donimos;
    //ctor
}

void Domain::login(char* login)
{
    Donimos donimos;
    Repo repo;

    if(*login == 'A' || *login == 'a')
    {
        repo.admin_ui();
    }
    if(*login == 'M' || *login == 'm')
    {
        donimos.makeline();
    }
    if(*login == 'O' || *login == 'o')
    {
        donimos.order();
    }
    if(*login == 'C' || *login == 'c')
    {
        donimos.cashier();
    }

}

void Domain::change(int num)
{
    Repo repo;

    if(num == 1)
    {
        repo.change_stores();
    }

    if(num == 2)
    {
        repo.change_toppings();
    }

    if(num == 3)
    {
        repo.change_price();
    }

    if(num == 4)
    {
        repo.change_soda();
    }

    if(num == 5)
    {
        repo.change_menu();
    }

    if(num == 6)
    {
        repo.change_crust();
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

void Domain::listOrder(int a, string str[])
{
    Donimos donimos;
    cout << "would you like a list of the most recent orders? (y/n): ";
    cin >> input;
    if(input == 'y'|| input == 'Y')
    {
        donimos.list_orders(a, str);
    }
}

/*void Domain::listOfTen(int a, string str[])
{
    Donimos donimos;
    cout << "Printing out the last ten orders: " << endl;

    donimos.list_of_ten(a, str);

}*/

void Domain::markPaid(int a, string str[])
{
    Donimos donimos;
    Repo repo;
    //ofstream fout;
    int order_num;
    char cont;
    char paid;
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
        else
        {
            break;
        }
    }
    while(true);

    cout << str[order_num];
    cout << endl;
    cout << endl;
    cout << "Mark paid? (y/n): ";
    cin >> paid;
    cout << endl;

    if(paid == 'y' || paid == 'Y')
    {

        if(str[order_num].find("greidd") != string::npos)
        {
            cout << "Already paid" << endl;
        }
        else
        {
            repo.markpaid(a, order_num, str);
            /*fout.open("orders.txt");
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
            }*/
            cout << str[order_num] << " <greidd>" << endl;
        }
    }
    cout << "pay for another order (y/n): ";
    cin >> cont;
    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;

    if(cont == 'y' || cont == 'Y')
    {
        donimos.list_orders(a, str);
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

void Domain::makeline_list(int a, string str[]){

    Repo repo;
    Domain domain;

    //ifstream fin;
    char login;
    char cont;
    int order_num;
    //ofstream fout;
    char status;

    //cout << a;

    do
    {
        repo.readorders(a, str);
        domain.printorders(a, str);
        /*fin.open("orders.txt");
        for(int i = 0; i < a; i++)
        {
            getline(fin, str[i]);
        }*/

        /*cout << "Would you like a list of the 10 most recent orders? (y/n): ";
        cin >> cont;
        if(cont == 'y' || cont == 'Y')
        {

            for(int i = a-10; i < a; i++)
            {
                cout << str[i] << endl;
            }
            //fin.close();
        }*/

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
        cout << "Mark status (I = In progress, R = Ready): ";
        cin >> status;
        cout << endl;

        if(status == 'i' || status == 'I')
        {
            if(str[order_num].find("In progress") != string::npos)
            {
                cout << "Already in progress" << endl;
            }
            else if(str[order_num].find("Ready") != string::npos)
            {
                cout << "Cannot mark 'In progress', order is ready" << endl;
            }
            else
            {
                repo.inprogress(a, order_num, str);
                /*fout.open("orders.txt");
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
                }*/

                cout << "Order marked 'In progress' " << endl;
            }
            //fout.close();
        }

        int x = str[order_num].find("<I");
        int z = str[order_num].find("ss>");
        cout << x << " " << z;

        if(status == 'r' || status == 'R')
        {
            if(str[order_num].find("Ready") != string::npos)
            {
                cout << "Already marked ready" << endl;
            }
            else
            {
                repo.ready(x, z, a, order_num, str);
                /*fout.open("orders.txt");
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
                }*/
                cout << "Order marked 'ready' " << endl;
            }
        }
        cout << "update another order (y/n): ";
        cin >> cont;

    }while(cont == 'y' || cont == 'Y');
}

string Domain::comment()
{
    string comment;
    char comm;

    cout << "Would you like to add a comment? (y/n) ";

    cin >> comm;
    if (comm == 'y' || comm == 'Y')
    {
        cin.ignore();
        cout << "Add comment: ";
        getline(cin, comment);
    }
    return comment;
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
