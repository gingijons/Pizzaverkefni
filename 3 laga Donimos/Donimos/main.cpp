#include <iostream>
#include "MainUI.h"
#include "Donimos.h"
#include "Repo.h"
#include "Domain.h"

using namespace std;



int main()
{
    char login;
    char cont;

    MainUI menu;
    Domain domain;
    menu.printlogo();
    do
    {
        login = menu.getlogin();
        domain.login(&login);
        do
        {
            cout << "Logout or Quit? (L/Q): ";
            cin >> cont;
            cout << endl;
        }while(cont != 'l' && cont != 'L' && cont != 'q' && cont != 'Q');

        cout << "-----------------------------------------------------" << endl;
        cout << endl;
    }while(cont == 'l' || cont == 'L');


    return 0;
}
