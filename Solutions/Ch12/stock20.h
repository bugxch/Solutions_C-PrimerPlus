// stock20.h -- augmented version
#ifndef STOCK20_H_
#define STOCK20_H_
#include <string>
#include <iostream>

class Stock
{
private:
    char * company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
    Stock();        // default constructor
    Stock(const std::string & co, long n = 0, double pr = 0.0);
    Stock(const Stock & st);
    Stock & operator=(const Stock & st);
    ~Stock();       // do-nothing destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    //void show()const;
    friend std::ostream & operator<<(std::ostream & os, const Stock & st);
    friend std::ostream & operator<<(std::ostream & os, const Stock * st);
    const Stock & topval(const Stock & s) const;
};
#endif
