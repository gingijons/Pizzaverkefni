#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    ifstream bin;
    int j = 0;
    char cont;
    int a = 0;
    string b;

    bin.open("states.txt");

    while(getline(bin, b))
    {
        a++;
    }

    fin.open("states.txt");

    string list[a];

    if(fin.is_open())
    {
        for(int i = 0; i < a; i++)
        {
            getline(fin, list[i]);
        }
    }

    do
    {
        if (j >= a-10)
        {
            for(int i = j; i < a; i++)
            {
                cout << list[i] << endl;
            }
        }

        if(j < a-10)
        {
            for(int i = j; i < (j+10); i++)
            {
                cout << list[i] << endl;
            }
            j+=10;
        }
        else
        {
            break;
        }

        cout << "Would you like the next ten lines? (y/n) ";
        cin >> cont;

    }
    while(cont == 'y' || cont == 'Y');

    return 0;
}
