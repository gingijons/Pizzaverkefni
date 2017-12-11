#ifndef DOMAIN_H
#define DOMAIN_H
#include <iostream>
#include "Donimos.h"
#include <vector>



using namespace std;

class Domain
{
    public:
        Domain();
        virtual ~Domain();

        void login(char* login);
        void printorders(int a, string str[]);
        void add_order(int a);
        char input;
        void on_menu(vector<string> *top, string sorted);
        int getprice(string size, int j);
        string markpaid(string& paid);
        char pickup_or_delivery();
        bool getbreadsticks();
        string getsoda();




    protected:

    private:

        friend ostream& operator<< (ostream& out, const Domain& domain);

};

#endif // DOMAIN_H
