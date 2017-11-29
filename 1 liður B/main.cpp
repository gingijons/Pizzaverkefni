#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    ifstream bin;
    ofstream fout;
    int j = 0;
    int a = 0;
    string b;
    string str[1000];

    bin.open("output.txt");

    while(getline(bin, b))
    {
        a++;
    }

    fin.open("output.txt");


    for(int i = 0; i < a; i++)
    {
        getline(fin, str[i]);
        cout << str[i] << endl;
    }
    bin.close();
    fin.close();

    fout.open("output.txt");

    for(int i = 0; i < a; i++)
    {
        fout << str[i] << endl;
    }

    if(fout.is_open())
    {
        //cout << "plz write" << endl;
        j += a;


            for(int i = j; i < 500; i++)
            {
                getline(cin, str[i]);

                if(str[i].find('\\'))
                {
                    fout << str[i];
                }
                else
                {
                    break;
                }
                fout << endl;
                j++;
            }
    }

    return 0;
}
