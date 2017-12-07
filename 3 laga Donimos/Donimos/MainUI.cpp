#include "MainUI.h"

MainUI::MainUI()
{
    //ctor
}

void MainUI::printlogo()
{
    cout << "`````````                                   .+oo-                                  :oo+." << endl;
    cout << "/hhhhhhhhhhyo:`                              shhhh`                                .hhhhs          " << endl;
    cout << "/hhhhhhhhhhhhhy:                             `/++-                                  .+hy-          " << endl;
    cout << "/hhhh/   `:yhhhh:  -oyhhhhy+.  +hhhy+yhhhho. +hhho :hhhh+yhhhhs:ohhhhh+   .+yhhhhy+. -- :oyhhhhys+`" << endl;
    cout << "/hhhh/     -hhhhs +hhhhyyhhhh/ +hhhhysyhhhhs ohhhs :hhhhyoshhhhhsoyhhhh. /hhhhyyhhhh+  -hhhh+//oy: " << endl;
    cout << "/hhhh/     +hhhho-hhhy`  .hhhh`+hhhy   ohhhy ohhhs :hhhh`  shhho  -hhhh..hhhh.  .yhhh. `shhhhhyso/`" << endl;
    cout << "/hhhho:::/shhhhy..hhhh/..+hhhy`+hhhy   +hhhy ohhhs :hhhh`  shhho  .hhhh.`hhhh/../hhhh.  `/:/++shhho" << endl;
    cout << "/hhhhhhhhhhhhy+`  :yhhhhhhhhy- +hhhy   +hhhy ohhhs :hhhh`  shhho  .hhhh. -yhhhhhhhhy:  .yhhysoshhh/" << endl;
    cout << "-ooooooooo+/-      `:+syys+-   :ooo+   :ooo+ /ooo/ .o+++`  /+++:  `++++`   :+syys+:`   `:+osyyso/. " << endl;
    cout << endl;
}

char MainUI::getlogin()
{
    char login;
    cout << "O = Order, C = Cashier, M = Makeline, A = Admin" << endl;
    cin >> login;
    return login;
}



ostream& operator<< (ostream& out, const MainUI& menu)
{
    out << menu;
    return out;
}

MainUI::~MainUI()
{
    //dtor
}
