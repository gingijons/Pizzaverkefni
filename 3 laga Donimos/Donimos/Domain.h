#ifndef DOMAIN_H
#define DOMAIN_H
#include <iostream>

using namespace std;

class Domain
{
    public:
        Domain();
        virtual ~Domain();

        void login(char* login);

    protected:

    private:
        friend ostream& operator<< (ostream& out, const Domain& domain);
};

#endif // DOMAIN_H
