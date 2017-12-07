#ifndef DONIMOS_H
#define DONIMOS_H
#include <string>
#include "Repo.h"

using namespace std;

class Donimos
{
    public:
        Donimos();
        virtual ~Donimos();

        int s;
        int a;
        string* str[1000];

        void order();

        friend ostream& operator<< (ostream& out, const Donimos& donimos);

    protected:

    private:
        Repo repo;
};

#endif // DONIMOS_H
