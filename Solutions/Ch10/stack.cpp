// stack.cpp -- Stack member functions
#include "stack.h"
#include <cstring>
#include <iostream>
Stack::Stack()    // create an empty stack
{
    top = 0;
    total = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item & item)
{
    if (top < MAX)
    {
        strncpy(items[top].fullname, item.fullname, 35);
        items[top].payment = item.payment;
        top++;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        top--;
        item.payment = items[top].payment;
        strncpy(item.fullname, items[top].fullname, 35);
        total += item.payment;
        std::cout << "Now the total payment is " << total << std::endl;
        return true;
    }
    else
        return false;
}