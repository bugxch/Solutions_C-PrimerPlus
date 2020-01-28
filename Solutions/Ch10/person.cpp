#include "person.h"
#include <iostream>
#include <cstring>

Person::Person(const std::string ln, const char* fn)
{
    lname = ln;
    strncpy(fname, fn, LIMIT);
}
void Person::show() const
{
    std::cout << fname << ".";
    std::cout << lname << std::endl;
}
void Person::FormalShow()const
{
    std::cout << lname << ".";
    std::cout << fname << std::endl;
}