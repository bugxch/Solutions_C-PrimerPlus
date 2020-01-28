#include <iostream>
#include <cstring>

class BankAccount
{
    enum {
        NAMELEN = 40,
        ACCLEN = 50
        };
private:
    char name_[NAMELEN];
    char account_[ACCLEN];
    double deposit_;
public:
    BankAccount(const char * name = "Charles", const char * account = "China", double de = 500.0);
    void Show() const;
    void AddDeposit(double de);
    void MinusDeposit(double de);
};

BankAccount::BankAccount(const char * name, const char * account, double de)
{
    strncpy(name_, name, NAMELEN);
    strncpy(account_, account, ACCLEN);
    deposit_ = de;
}
void BankAccount::Show() const
{
    std::cout << "Name: " << name_ << ", Account: " << account_ <<", and desposit is " <<
    deposit_ << std::endl;
}
void BankAccount::AddDeposit(double de)
{
    if (de < 0 ) {
        std::cout << "Wrong number to add, it must be a positive" << std::endl;
        return;
    }
    deposit_ += de;
}
void BankAccount::MinusDeposit(double de)
{
    if (de < 0 ) {
        std::cout << "Wrong number to add, it must be a positive" << std::endl;
        return;
    }
    deposit_ -= de;
}


int main()
{
    BankAccount acc1;
    acc1.Show();
    BankAccount acc2("Hou yi", "USA", 345.0);
    acc2.Show();
    acc1.AddDeposit(3434);
    acc2.MinusDeposit(3434);
    acc1.Show();
    acc2.Show();

    return 0;
}