// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>

class Stonewt
{
public:
    enum Mode {STONE, POUND};
    Stonewt(double lbs, Mode m = POUND);          // constructor for double pounds
    Stonewt(int stn, double lbs, Mode m = POUND); // constructor for stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    Stonewt operator+(const Stonewt & wt) const;
    Stonewt operator-(const Stonewt & wt) const;
    Stonewt operator*(const double n) const;
    friend std::ostream & operator<<(std::ostream & os, const Stonewt wt);
    friend Stonewt operator*(const double n, Stonewt const & wt);
private:
    enum {Lbs_per_stn = 14};      // pounds per stone
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds
    Mode mode;
};
#endif