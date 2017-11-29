#include <iostream>
#include "SuperHero.h"

using namespace std;

int main()
{
    char input = 0;
    int num;
    string heros;

    ofstream fout;
    ifstream fin;
    fout.open("Hero.txt", ios::app);

    cout << "Hvad viltu skra margar hetjur? ";
    cin >> num;
    SuperHero Hero;

    for(int i = 0; i < num; i++)
    {
        cin >> Hero;
        if(fout.is_open())
        {
            fout << Hero;

        }
    }
 fout.close();
    cout << "Do you want a list of all superhero's?! ";
    cin >> input;

    if(input == 'y' || input == 'Y')
    {
        fin.open("Hero.txt");
        if(fin.is_open())
        {
            while(!fin.eof())
            {
                getline(fin, heros);
                cout << heros << endl;
            }
        }
        fin.close();
    }
    else
    return 0;
}
