#include "golf.h"

#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

void setgolf(golf &g, const char * name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}
int setgolf(golf &g)
{
    cout << "Please enter name: ";
    cin.getline(g.fullname, Len);
    if (strlen(g.fullname) == 0) {
        return 0;
    } else {
        cout << "Enter handicap:";
        cin >> g.handicap;
        cin.get();
        return 1;
    }
}
void handicap(golf & g, int hc)
{
    g.handicap = hc;
}
void showgolf(const golf &g)
{
    cout << "Name: " << g.fullname << ", handicap is " << g.handicap << endl;
}