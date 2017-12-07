#ifndef MAINUI_H
#define MAINUI_H
#include <iostream>

using namespace std;


class MainUI
{
    public:
        MainUI();
        virtual ~MainUI();
        void printlogo();
        char getlogin();

        char login;

        friend ostream& operator<< (ostream& out, MainUI& main);
        friend istream& operator>> (istream& in, MainUI& main);

    protected:

    private:
};

#endif // MAINUI_H
