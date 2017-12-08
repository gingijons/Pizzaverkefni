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
        getprice(string size, int j);



    protected:

    private:

        friend ostream& operator<< (ostream& out, const Domain& domain);

};

#endif // DOMAIN_H
