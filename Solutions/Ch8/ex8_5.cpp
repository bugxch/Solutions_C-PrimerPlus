#include <iostream>
using namespace std;

template<typename T>
T max5(T* arr, int len)
{
    T maxval = arr[0];
    for (int i = 1; i < len; ++i) {
        if (arr[i] > maxval)
        {
            maxval = arr[i];
        }
    }
    return maxval;
}


int main()
{
    int a[5] = {4, 5, 6, 7, -2};
    double b[5] = {-0.99, 7.77, 45.87, 89, 2.977};
    cout << "maxval of a is " << max5(a, 5) << endl;
    cout << "maxval of b is " << max5(b, 5) << endl;
    return 0;
}