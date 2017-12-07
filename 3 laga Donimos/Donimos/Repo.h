#ifndef REPO_H
#define REPO_H
#include <string>

using namespace std;


class Repo
{
    public:
        Repo();
        virtual ~Repo();


        void readorders(int& a, string str[1000]);

    protected:

    private:

};

#endif // REPO_H
