// string1.cpp -- String class methods
#include <cstring>                 // string.h for some
#include "string2.h"               // includes <iostream>
#include <cctype>
using std::cin;
using std::cout;

// initializing static class member

int String::num_strings = 0;

// static method
int String::HowMany()
{
    return num_strings;
}

// class methods
String::String(const char * s)     // construct String from C string
{
    len = std::strlen(s);          // set size
    str = new char[len + 1];       // allot storage
    std::strcpy(str, s);           // initialize pointer
    num_strings++;                 // set object count
}

String::String()                   // default constructor
{
    len = 4;
    str = new char[1];
    str[0] = '\0';                 // default string
    num_strings++;
}

String::String(const String & st)
{
    num_strings++;             // handle static member update
    len = st.len;              // same length
    str = new char [len + 1];  // allot space
    std::strcpy(str, st.str);  // copy string to new location
}

String::~String()                     // necessary destructor
{
    --num_strings;                    // required
    delete [] str;                    // required
}

String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

    // assign a C string to a String
String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

    // read-write char access for non-const String
char & String::operator[](int i)
{
    return str[i];
}

    // read-only char access for const String
const char & String::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

String String::operator+(const String & str1) const {
    String newstr;
    newstr.str = new char[strlen(str) + strlen(str1.str) + 1];
    strcpy(newstr.str, str1.str);
    strcat(newstr.str, str);
    newstr.len = str1.len + len;
    num_strings++;
    return newstr;
}

String & String::stringlow()
{
    if (len == 0)
        return *this;
    for (int i = 0; i < len; ++i) {
        str[i] = towlower(str[i]);
    }
    return *this;
}

String & String::stringup()
{
    if (len == 0)
        return *this;
    for (int i = 0; i < len; ++i) {
        str[i] = towupper(str[i]);
    }
    return *this;
}

    // simple String output
ostream & operator<<(ostream & os, const String & st)
{
    os << "My name is " << st.str << ".\n";
    return os;
}

    // quick and dirty String input
istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

int String::has(char c) const
{
    int total = 0;
    for (int i  = 0; i < len; i++)
    {
        if (c == str[i])
        {
            total++;
        }
    }
    return total;
}

String operator+(const char * str0, const String & str1)
{
    String newstr;
    newstr.len = strlen(str0) + str1.len;
    newstr.str = new char[newstr.len + 1];
    strcat(strcpy(newstr.str, str0), str1.str);
    return newstr;
}