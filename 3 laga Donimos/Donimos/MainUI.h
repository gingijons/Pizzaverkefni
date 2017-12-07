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


    protected:

        friend ostream& operator<< (ostream& out, const MainUI& menu);


    private:
};

#endif // MAINUI_H
