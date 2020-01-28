#include <iostream>
#include <cstring>

class Plorg
{
private:
    char fullname[20];
    int ci;
public:
    Plorg(const char * name = "Plorga", int c = 50);
    void ReportName() const;
    void ModifyCI(int c);
};

Plorg::Plorg(const char *name, int c)
{
    strncpy(fullname, name, 19);
    ci = c;
}

void Plorg::ModifyCI(int c)
{
    ci = c;
}

void Plorg::ReportName() const
{
    std::cout << "Myname is " << fullname << std::endl;
}

int main()
{
    Plorg one;
    one.ReportName();
    Plorg two("Charles", 344);
    two.ReportName();
    return 0;
}