#include "stack.h"

int main()
{
    using std::cout;
    Stack st1(5);
    st1.push(23);
    st1.push(34);
    Stack st2;
    st2.push(3444);
    st2.push(3);
    st2.push(123);
    cout << "st1: " << st1;
    cout << "st2: " << st2;
    Stack st3 = st1;
    cout << "st3: " << st3;
    st2 = st3;
    cout << "st2: " << st2;
    return 0;
}