#include <iostream>
#include <string>

using namespace std;

void ChangeToUppper(string& str);

int main()
{
    string inputstr;
    cout << "Input a string(q to quit):";
    getline(cin, inputstr);
    while (inputstr[0] != 'q' || inputstr[1] != '\0')
    {
        ChangeToUppper(inputstr);
        cout << "Next string(q to quit):";
        getline(cin, inputstr);
    }
    return 0;
}

void ChangeToUppper(string& str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        str[i] = toupper(str[i]);
    }
    cout << str << endl;
    return;
}