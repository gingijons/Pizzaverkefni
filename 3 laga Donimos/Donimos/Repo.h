#ifndef REPO_H
#define REPO_H
#include <string>
#include <vector>


using namespace std;


class Repo
{
    public:
        Repo();
        virtual ~Repo();


        void readorders(int& a, string str[1000]);
        string getstore(string store);
        void write_order(string size, string crust, vector<string> top, int price, char paid, string store, string p_or_d, int a);
        friend ostream& operator<< (ostream& out, const Repo& repo);

    protected:

    private:

};

#endif // REPO_H
