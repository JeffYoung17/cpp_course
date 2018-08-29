#include <iostream>

using namespace std;
  
class Yuebao
{
private:
    static double profitRate;
    double mon_now;
    double mon_add;

public:
    Yuebao(double money_init);
    Yuebao();
    static void setProfitRate(double rate);
    void addProfit();
    void deposit(double money_in);
    void withdraw(double money_out);
    double getBalance();
};

double Yuebao::profitRate = 0.0;

int main(void)
{
    int n;
    cin >> n;

    double Rate;
    cin >> Rate;

    Yuebao::setProfitRate(Rate);//设定鱼额宝的利率

    Yuebao y(0); //新建鱼额宝账户，余额初始化为0

    int operation;//接受输入判断是存还是取
    double amount;//接受输入存取金额

    for (int i = 0; i < n; ++i)
    {
        y.addProfit(); //加入前一天余额产生的利息
        cin >> operation >> amount;
        if (operation == 0)
            y.deposit(amount); //存入金额
        else
            y.withdraw(amount); //取出金额
    }

    y.getBalance(); //输出最终账户余额

    return 0;
}

Yuebao::Yuebao(double money_init):mon_now(money_init)
{}

Yuebao::Yuebao():Yuebao::Yuebao(0)
{}

void Yuebao::setProfitRate(double rate)
{
    profitRate = rate;
}

void Yuebao::addProfit()
{
    mon_add = mon_now * profitRate;
    mon_now += mon_add;
}

void Yuebao::deposit(double money_in)
{
    mon_now += money_in;
}

void Yuebao::withdraw(double money_out)
{
    mon_now -= money_out;
}

double Yuebao::getBalance()
{
    cout << mon_now << endl;
}


