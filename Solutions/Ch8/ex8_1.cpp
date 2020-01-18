#include <iostream>
#include <string>


using namespace std;
void PrintString(const string str, int i = 0);

int main()
{
    int a = 0;
    PrintString("hello world");
    PrintString("hello again", 5);
    PrintString("hello only once");
    PrintString("hello 4 times",5);
    return 0;
}

void PrintString(const string str, int times)
{
    static int printTimes = 1;
    if (times == 0) {
        cout << str << endl;
    } else {
        for (int i = 0; i < printTimes; i++) {
            cout << str << endl;
        }
    }
    // the call time plus one
    printTimes++;
    return;
}