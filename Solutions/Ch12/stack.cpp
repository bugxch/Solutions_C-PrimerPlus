#include "stack.h"
#include <iostream>

Stack::Stack(int n)
{
    pitems = new Item[n];
    top = 0;
    size = n;
}
// creates stack with n elements
Stack::Stack(const Stack & st)
{
    pitems = new Item[st.size];
    for(int i = 0;i < st.top; ++i)
    {
        pitems[i] = st.pitems[i];
    }

    top = st.top;
    size = st.size;
}

Stack::~Stack()
{
    delete []  pitems;
    top = 0;
    size = 0;
}

bool Stack::isempty() const
{
    return (top == 0);
}
bool Stack::isfull() const
{
    return (top == size);
}
// push() returns false if stack already is full, true otherwise
bool Stack::push(const Item & item)
{
    if (isfull())
    {
        std::cout << "Stack is full";
        return false;
    } else {
        pitems[top++] = item;
        return true;
    }
} // add item to stack
// pop() returns false if stack already is empty, true otherwise
bool Stack::pop(Item & item)
{
    if (isempty()) {
        std::cout << "Stack is empty";
        return false;
    } else {
        top--;
        return false;
    }
} // pop top into item
Stack & Stack::operator=(const Stack & st)
{
    if (&st == this) {
        return *this;
    }

    delete [] pitems;
    pitems = new Item[st.size];
    for(int i = 0;i < st.top; ++i)
    {
        pitems[i] = st.pitems[i];
    }

    top = st.top;
    size = st.size;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const Stack & st)
{
    os << "stack size is " << st.size << ", and now it has " << st.top << " items\n";
    os << "stack items list as below\n";
    for(int i = 0 ; i < st.top; ++i)
    {
        os << i + 1 << ": " << st.pitems[i] << "\n";
    }
    os << "\n";
    return os;
}