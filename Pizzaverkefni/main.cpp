#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

int main()
{
    ifstream fin;
    ifstream bin;
    ofstream fout;
    int j = 0;
    int a = 0;
    int price;
    string b;
    string str[1000];

    bin.open("pantanir.txt");

    while(getline(bin, b))
    {
        a++;
    }
    cout << a;

    fin.open("pantanir.txt");


    for(int i = 0; i < a; i++)
    {
        getline(fin, str[i]);
        cout << str[i] << endl;
    }
    bin.close();
    fin.close();

    fout.open("pantanir.txt");

    for(int i = 0; i < a; i++)
    {
        fout << str[i] << endl;
    }

    string size;
    vector<string> top;
    string topping;

    cout << "Size (lit mid sto)";
    cin >> size;
    cout << "topping: (ppp, bei, rjo, sve)";
    do
    {
        cin >> topping;
        top.push_back(topping);
        j+=1;
    }while(topping == "ppp" || topping == "rjo" || topping == "sve" || topping == "bei");

    for(int i = 0; i < 50; i++)
    {
        cout << top[i] << " ";
    }
    price = getpriceforsize(size);

    price += (j*150);

    cout << price;




    return 0;
}
