#include "person.h"

int main()
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    one.show();
    two.FormalShow();
    three.FormalShow();
    return 0;
}