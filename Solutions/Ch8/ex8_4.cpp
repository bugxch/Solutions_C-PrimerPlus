#include <iostream>
#include <cstring>

struct stringy {
    char* str;
    int ct;
};

#include <string>
using namespace std;

void show(const stringy& stru, const int time = 1);
void set(stringy& stru, char* s);
void show(const char* stru, const int time = 1);

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done");
    return 0;
}

void show(const stringy& stru, const int time)
{
    for (int i = 0; i < time; i++)
    {
        cout << "str: " << stru.str << endl;
        cout << "ct: " << stru.ct << endl;
    }
    return;
}

void show(const char * stru, const int time)
{
    for (int i = 0; i < time; i++)
    {
        cout << stru << endl;
    }
    return;
}

void set(stringy& stru, char *s)
{
    int len = strlen(s);
    stru.str = new char[len + 1];
    strcpy(stru.str, s);

    stru.ct = len;
    return;
}