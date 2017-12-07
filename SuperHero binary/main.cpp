#include <iostream>
#include "SuperHero.h"

using namespace std;

int main()
{

    SuperHero hero;
    char printHeroes;
    int size;
    cout << "Hvad viltu skra margar hetjur? ";
    cin >> size;
    cout << endl;

    for(int i = 0; i < size; i++)
    {
        cin >> hero;
        ofstream fout;
        fout.open("binary_file_SuperHero.dat", ios::binary | ios::app);
        fout.write((char*)(&hero), sizeof(SuperHero));
        fout.close();
    }
    cout << "Do you want to print out all heroes? (y/n) ";
    cin >> printHeroes;
    cout << endl;

    if(printHeroes == 'y' || printHeroes == 'Y')
    {
        ifstream fin;
        fin.open("binary_file_SuperHero.dat", ios::binary);
        if(fin.is_open())
        {
            fin.seekg(0, fin.end);
            int Counter = fin.tellg() / sizeof(SuperHero);
            fin.seekg(0, fin.beg);
            for(int i = 0; i < Counter; i++)
            {
                fin.read((char*)(&hero), sizeof(SuperHero));
                cout << hero << endl;
            }
        }
        else
        {
            cout << "Could not open file"<< endl;
        }
        fin.close();
    }
    return 0;
}
