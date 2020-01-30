#include "complex0.h"
#include <iostream>

int main()
{
    using namespace std;
    Complex a(3.0, 4.0);
    Complex c;
    cout << "Eneter a complex number(q to quit):\n";
    while(cin >> c)
    {
        cout << "c is " << c << "\n";
        cout << "complex conjugate is " << ~c << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << 2 * c << '\n';
        cout << "Eneter a complex number(q to quit):\n";
     }
     cout << "Done!\n";
     return 0;
}