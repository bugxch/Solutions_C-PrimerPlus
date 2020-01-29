// stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout;
#include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, Mode m)
{
    stone = int (lbs) / Lbs_per_stn;    // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    mode = m;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, Mode m)
{
    stone = stn;
    pds_left = lbs;
    pounds =  stn * Lbs_per_stn +lbs;
    mode = m;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
    mode = POUND;
}

Stonewt::~Stonewt()         // destructor
{
}

std::ostream & operator<<(std::ostream & os, const Stonewt wt)
{
    cout << "The mode of Stonewt is " << wt.mode << std::endl;
    if (wt.mode == Stonewt::POUND)
    {
        os << wt.pounds << " pounds\n";
    } else {
        os << wt.stone << " stone, " << wt.pds_left << " pounds\n";
    }
    return os;
}

Stonewt Stonewt::operator+(const Stonewt & wt) const
{
    Stonewt st;
    st.pounds = wt.pounds + pounds;

    st.stone = int (st.pounds) / Lbs_per_stn;    // integer division
    st.pds_left = int (st.pounds) % Lbs_per_stn + st.pounds - int(st.stone);

    st.mode = POUND;
    return st;
}

Stonewt Stonewt::operator-(const Stonewt & wt) const
{
    Stonewt st;
    st.pounds = pounds - wt.pounds;

    st.stone = int (st.pounds) / Lbs_per_stn;    // integer division
    st.pds_left = int (st.pounds) % Lbs_per_stn + st.pounds - int(st.stone);

    st.mode = POUND;
    return st;
}

Stonewt Stonewt::operator*(const double n) const
{
    Stonewt st;
    st.pounds = pounds * n;

    st.stone = int (st.pounds) / Lbs_per_stn;    // integer division
    st.pds_left = int (st.pounds) % Lbs_per_stn + st.pounds - int(st.stone);

    st.mode = POUND;
    return st;
}

Stonewt operator*(const double n, Stonewt const & wt)
{
    return wt * n;
}