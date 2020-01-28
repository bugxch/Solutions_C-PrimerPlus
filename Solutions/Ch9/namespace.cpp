#include "namespace.h"
#include <iostream>

namespace SALES
{
    using std::cout;
    using std::cin;
    using std::endl;

    void setSales(Sales & s, const double ar[], int n)
    {
        double sum = 0;
        for (int i = 0; i < QUARTERS; i++)
        {
            s.sales[i] = 0;
            if (i < std::min(QUARTERS, n))
            {
                s.sales[i] = ar[i];
                sum += s.sales[i];
            }
        }

        s.min = s.max = s.sales[0];
        for (int i = 0; i < QUARTERS; i++)
        {
            s.min = std::min(s.min, s.sales[i]);
            s.max = std::max(s.max, s.sales[i]);
        }

        s.average = sum / QUARTERS;
    }

    void setSales(Sales & s)
    {
        cout << "Enter the len of arr: ";
        int n;
        cin >> n;
        double * pd = new double[n];
        cout << "Now enter the arr: ";
        for (int i = 0; i < n;i++)
        {
            cin >> pd[i];
        }
        setSales(s, pd, n);
        delete [] pd;
    }
    void showSales(const Sales &s)
    {
        cout << "Sales list as below" << endl;
        for (int i = 0; i < QUARTERS;i++)
        {
            cout << s.sales[i] << " ";
        }
        cout << endl;
        cout << "average: " << s.average << ", min: "<< s.min << ", max: " << s.max << endl;
    }
}