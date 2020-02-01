#include <iostream>
#include <cstring>

using namespace std;
class Port
{
private:
    char * brand;
    char style[20]; // i.e., tawny, ruby, vintage
    int bottles;
public:
    Port(const char * br = "none", const char * st = "none", int b = 0);
    // copy constructor
    Port(const Port & p);
    virtual ~Port() { delete [] brand; }
    Port & operator=(const Port & p);
    Port & operator+=(int b);
    // adds b to bottles
    Port & operator-=(int b);
    // subtracts b from bottles, if available
    int BottleCount() const { return bottles; }
    virtual void Show() const;
    friend ostream & operator<<(ostream & os, const Port & p);
};


class VintagePort : public Port // style necessarily = "vintage"
{
private:
    char * nickname;
    // i.e., "The Noble" or "Old Velvet", etc.
    int year;
    // vintage year
public:
    VintagePort();
    VintagePort(const char * br, int b, const char * nn, int y);
    VintagePort(const VintagePort & vp);
    ~VintagePort() { delete [] nickname; }
    VintagePort & operator=(const VintagePort & vp);
    void Show() const;
    friend ostream & operator<<(ostream & os, const VintagePort & v);
};

Port::Port(const char * br, const char * st, int b)
{
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strncpy(style, st, 20);
    bottles = b;
}
// copy constructor
Port::Port(const Port & p)
{
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strncpy(style, p.style, 20);
    bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
    if (this == &p)
        return *this;
    delete [] brand;

    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strncpy(style, p.style, 20);
    bottles = p.bottles;
}
Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}
// adds b to bottles
Port & Port::operator-=(int b)
{
    if (b <= 0) {
        cout << "Negative number and quit\n";
    } else if (bottles - b < 0) {
        cout << "Too many bottles to minus\n";
    } else {
        bottles -= b;
    }
    return *this;
}

void Port::Show() const
{
    cout << "Brand :" << brand << endl;
    cout << "Style: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles << endl;
    return os;
}

VintagePort::VintagePort()
    : Port()
{
    nickname = nullptr;
    year = 0;
}

VintagePort::VintagePort(const VintagePort & v)
    : Port(v)
{
    nickname = new char[strlen(v.nickname) + 1];
    strcpy(nickname, v.nickname);
    year =  v.year;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y)
    : Port(br, "", b)
{
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort & VintagePort::operator=(const VintagePort & v)
{
    if (this ==  &v)
    {
        return *this;
    }

    Port::operator=(v);
    delete [] nickname;
    nickname = new char[strlen(v.nickname) + 1];
    strcpy(nickname, v.nickname);
    year = v.year;

    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    cout << "nickname: " << nickname << endl;
    cout << "year: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & v)
{
    os << (Port &) v;
    os << ", " << v.nickname << ", " << v.year;
    return os;
}