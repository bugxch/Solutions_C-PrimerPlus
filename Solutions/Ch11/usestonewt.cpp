#include <iostream>
#include "stonewt.h"

int main()
{
    using namespace std;
    Stonewt wt1, wt2(5, 345, Stonewt::POUND);
    cout << "wt1: " << wt1 << endl;
    cout << "wt2: " << wt2 << endl;

    cout << "wt2 + wt1: " << wt1 + wt2 << endl;
    cout << "wt2 - wt1: " << wt1 - wt2 << endl;
    cout << "wt2 * 3.3: " << 3.3 * wt2 << endl;
    return 0;
}