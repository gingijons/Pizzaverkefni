#include <iostream>
#include "MainUI.h"
#include "Donimos.h"
#include "Repo.h"
#include "Domain.h"

using namespace std;



int main()
{
    char login;

    MainUI menu;
    Domain domain;
    menu.printlogo();
    login = menu.getlogin();
    cout << login;
    domain.login(&login);
    return 0;
}
