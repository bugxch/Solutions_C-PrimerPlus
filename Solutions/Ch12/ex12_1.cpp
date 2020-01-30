#include <iostream>
#include <cstring>

class Cow
{
    char name[20];
    char * hobby;
    double weight;
public:
    Cow();
    Cow(const char *nm, const char * ho, double wt);
    Cow(const Cow & c);
    ~Cow();
    Cow & operator=(const Cow & c);
    void ShowCow() const;
};

Cow::Cow()
{
    std::cout << "Default constructor\n";
    name[0] = '\0';
    hobby = new char[5];
    strcpy(hobby, "basketball");
    weight = 0;
}

Cow::Cow(const char *nm, const char * ho, double wt)
{
    std::cout << "new constructor\n";
    strncpy(name, nm, strlen(nm) + 1);
    int len = strlen(ho);
    hobby = new char[len + 1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow & c)
{
    std::cout << "copy constructor\n";
    strcpy(name, c.name);
    int len = strlen(c.hobby);
    delete [] hobby;
    hobby = new char[len + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow & Cow::operator=(const Cow & c)
{
    std::cout << "fuzhi constructor\n";
    if (this == &c)
        return *this;
    strcpy(name, c.name);
    int len = strlen(c.hobby);
    delete [] hobby;
    hobby = new char[len + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}

Cow::~Cow()
{
    name[0] = '\0';
    delete [] hobby;
    weight = 0;
}

void Cow::ShowCow() const
{
    std::cout << "name is " << name << ", and hobby is " << hobby;
    std::cout << ", and weight is " << weight << '\n';
}

int main()
{
    Cow cow1;
    cow1.ShowCow();
    Cow cow2("fengzhi", "pingpang", 44);
    cow2.ShowCow();
    Cow cow3 = Cow("huang", "yumaoqiu", 33);
    cow3.ShowCow();
    cow1 = cow3;
    cow1.ShowCow();
    Cow cow4 = cow2;
    cow4.ShowCow();

    return 0;
}