/*
 * 公有继承的权限是怎么样的
 * 派生类的构造函数怎么写
**/
#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
        string userName;
public:
        Account();
        Account(string name);
        void PrintUserName();
};

class CreditAccount : public Account
{
public:
        CreditAccount( string name, int cred);
        void PrintInfo();
private:
        int credit;
};

int main(int argc, char** argv)
{
    CreditAccount a("I Love CPP", 10000);
    a.PrintInfo();

    return 0;
}

Account::Account(){}
Account::Account(string name)
{
    userName = name;
}
void Account::PrintUserName()
{
    cout << userName << endl;
}

CreditAccount::CreditAccount(string name, int cred):Account(name),credit(cred)
{}

void CreditAccount::PrintInfo()
{
        PrintUserName();
        cout << credit << endl;
}