#include <iostream>
class Complex
{
    double x;
    double y;
public:
    Complex(double a = 0, double b = 0)
        : x(a), y(b) {}
    Complex operator+(const Complex & c) const;
    Complex operator-(const Complex & c) const;
    Complex operator*(const Complex & c) const;
    Complex operator*(const double n) const;
    Complex operator~() const;
    friend Complex operator*(const double n, const Complex c);
    friend std::ostream & operator<<(std::ostream & os, const Complex & c);
    friend std::istream & operator>>(std::istream & is, Complex & c);
};