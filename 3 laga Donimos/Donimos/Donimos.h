#ifndef DONIMOS_H
#define DONIMOS_H
#include <string>
#include "Repo.h"
#include "Domain.h"
#include "MainUI.h"
#include <vector>

using namespace std;

class Donimos
{
    public:
        Donimos();
        virtual ~Donimos();

        int s;
        int a;
        string str[1000];

        void order();
        void printorders();
        void y_printorders(int a, string str[]);
        void neworder(int a);
        string getpizzasize();
        string getcrust();
        void gettoppings(vector<string>* top, int* j);
        string sorttoppings(vector<string> *top);




        friend ostream& operator<< (ostream& out, const Donimos& donimos);

    protected:


    private:
        Repo repo;
        MainUI main;


};

#endif // DONIMOS_H
