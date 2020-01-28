#include <iostream>
#include <cstring>
#include <cmath>

namespace SALES
{
    using std::cout;
    using std::cin;
    using std::endl;

    class Sale
    {
    private:
        enum  { QUARTERS = 4 };
        double sales_[QUARTERS];
        double average_;
        double min_;
        double max_;
    public:
        Sale();
        Sale(const double ar[], int n);
        void ShowSale() const;
        void SetGolf(const char* name, int hc);
    };
};

namespace SALES
{
    Sale::Sale(const double ar[], int n)
    {
        double sum = 0;
        for (int i = 0; i < QUARTERS; i++)
        {
            sales_[i] = 0;
            if (i < std::min(4, n))
            {
                sales_[i] = ar[i];
                sum += sales_[i];
            }
        }

        min_ = max_ = sales_[0];
        for (int i = 0; i < QUARTERS; i++)
        {
            min_ = std::min(min_, sales_[i]);
            max_ = std::max(max_, sales_[i]);
        }
        average_ = sum / QUARTERS;
    }

    Sale::Sale()
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
        Sale(pd, n);
        delete [] pd;
    }
    void Sale::ShowSale() const
    {
        cout << "Sales list as below" << endl;
        for (int i = 0; i < QUARTERS;i++)
        {
            cout << sales_[i] << " ";
        }
        cout << endl;
        cout << "average: " << average_ << ", min: "<< min_ << ", max: " << max_ << endl;
    }
};
int main()
{
    using namespace SALES;
    double arr[6] = {0.232, -233234.0, -32.213, 34.12, 9.87,23345};
    Sale s;
    Sale s1(arr, 6);
    s.ShowSale();
    s1.ShowSale();

    return 0;
}