#include <iostream>
#include <string>

using namespace std;
void PrintString(const string str, int i = 3);

int main()
{
    PrintString("hello world");
    PrintString("houqi", 5);
    return 0;
}

void PrintString(const string str, int times)
{
    static int printTimes = 1;
    for (int i = 0; times != 0 && i < printTimes; i++) {
        cout << str << endl;
        printTimes++;
    }
}
