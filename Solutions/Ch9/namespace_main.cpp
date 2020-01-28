#include "namespace.h"

int main()
{
    using namespace SALES;
    double arr[6] = {0.232, -233234.0, -32.213, 34.12, 9.87,23345};
    Sales s;
    setSales(s, arr, 6);
    showSales(s);

    setSales(s);
    showSales(s);
    return 0;
}