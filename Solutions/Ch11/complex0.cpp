#include "complex0.h"

Complex Complex::operator+(const Complex & c) const
{
    Complex cn;
    cn.x = x + c.x;
    cn.y = y + c.y;
    return cn;
}
Complex Complex::operator-(const Complex & c) const
{
    Complex cn;
    cn.x = x - c.x;
    cn.y = y - c.y;
    return cn;
}

Complex Complex::operator*(const Complex & c) const
{
    Complex cn;
    cn.x = x * c.x - y * c.y;
    cn.y = x * c.y + y * c.x;
    return cn;
}
Complex Complex::operator*(const double n) const
{
    Complex cn;
    cn.x = x * n;
    cn.y = y * n;
    return cn;
}
//Complex operator~(const Complex & c);
Complex operator*(const double n, const Complex c)
{
    return c * n;
}

Complex Complex::operator~() const
{
    Complex cn;
    cn.x = 0 - x;
    cn.y = 0 - y;
    return cn;
}

std::ostream & operator<<(std::ostream & os, const Complex & c)
{
    os << "real part: " << c.x << ", imag part: " << c.y << std::endl;
    return os;
}

std::istream & operator>>(std::istream & is, Complex & c)
{
    std::cout << "real is ";
    is >> c.x;
    std::cout << "imag is ";
    is >> c.y;
    return is;
}