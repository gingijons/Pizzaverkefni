ks #include <iostream>
#include "MainUI.h"
#include "Domain.h"


using namespace std;

int main()
{
    char login;
    MainUI mainmenu;
    Domain domain;
    mainmenu.printlogo();
    login = mainmenu.getlogin();
    domain.sendlogin(login);
    return 0;
}
