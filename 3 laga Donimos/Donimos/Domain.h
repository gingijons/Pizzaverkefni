#ifndef DOMAIN_H
#define DOMAIN_H
#include <iostream>
#include "Donimos.h"
#include "Domain.h"

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



    protected:

    private:

        friend ostream& operator<< (ostream& out, const Domain& domain);

};

#endif // DOMAIN_H
