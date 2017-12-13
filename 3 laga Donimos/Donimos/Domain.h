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
        void markPaid(int a, string str[]);
        void listOrder(int a, string str[]);
        void listOfTen(int a, string str[]);
        char input;
        void on_menu(vector<string> *top, string sorted);
        int getprice(string size, int j, bool breadsticks, string soda);
        string markpaid(string& paid);
        char pickup_or_delivery();
        bool getbreadsticks();
        string getsoda();
        void change(int num);
        void makeline_list(int a, string str[]);
        string comment();




    protected:

    private:

        friend ostream& operator<< (ostream& out, const Domain& domain);

};

#endif // DOMAIN_H
