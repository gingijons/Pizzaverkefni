#include "Repo.h"
#include "Domain.h"
#include "MainUI.h"
#include "Donimos.h"
#include <fstream>

Repo::Repo()
{
    //ctor
}

string Repo::readorders(int& a)
{
    ifstream fin;
    ifstream bin;
    ofstream fout;
    string b;
    string str[1000];

    cout << a;

    bin.open("orders.txt");

    while(getline(bin, b))
    {
        a++;
    }

    cout << a;

    /*fin.open("orders.txt");


    for(int i = 0; i < a; i++)
    {
        getline(fin, str[i]);
        //cout << str[i] << endl;
        //cout << str[i].find("greidd")
    }
    bin.close();
    fin.close();

    fout.open("pantanir.txt");

    for(int i = 0; i < a; i++)
    {
        fout << str[i] << endl;
    }
    fout.close();

    cout << a;*/

    return str[1000];
}

Repo::~Repo()
{
    //dtor
}
