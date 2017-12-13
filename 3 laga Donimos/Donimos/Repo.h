#ifndef REPO_H
#define REPO_H
#include <string>
#include <vector>
//#include "Domain.h"


using namespace std;


class Repo
{
    public:
        Repo();
        virtual ~Repo();


        void readorders(int& a, string str[1000]);
        string getstore(string store);
        void write_order(string size, string crust, vector<string> top, int price, char paid, string store, string p_or_d, int a, string soda, bool breadsticks, string comment);
        string readsoda();
        void admin_ui();
        void change_stores();
        void change_toppings();
        void change_price();
        void change_soda();
        void change_menu();
        void change_crust();
        void ready(int x, int z, int a, int order_num, string str[1000]);
        void inprogress(int a, int order_num, string str[1000]);
        void markpaid(int a, int order_num, string str[1000]);
        string readtoppings();
        string getcrust(string crust);

        friend ostream& operator<< (ostream& out, const Repo& repo);

        //Domain domain;

    protected:

    private:


};

#endif // REPO_H
