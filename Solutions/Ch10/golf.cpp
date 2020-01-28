#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;

class Golf
{
private:
    static const int LEN = 40;
    char fullname[LEN];
    int handicap;
public:
    Golf();
    Golf(const char * name, int hc = 34);
    void Show() const;
    void Sethand(int hc);
    void SetGolf(const char* name, int hc);
};

Golf::Golf(const char * name, int hc)
{
    strncpy(fullname, name, LEN);
    handicap = hc;
}
Golf::Golf()
{
    cout << "Please enter name: ";
    cin.getline(fullname, LEN);
    if (strlen(fullname) == 0) {
        return;
    } else {
        cout << "Enter handicap:";
        cin >> handicap;
        cin.get();
    }
}
void Golf::Sethand(int hc)
{
    handicap = hc;
}
void Golf::Show() const
{
    cout << "Name: " << fullname << ", handicap is " << handicap << endl;
}
void Golf::SetGolf(const char* name, int hc)
{
    Golf golf(name, hc);
    strncpy(this->fullname, name, LEN);
    this->handicap = hc;
}

int main()
{
    Golf mygolf, golf;
    mygolf.Show();
    golf.Show();
    cout << "Set houqi handicap";
    mygolf.Sethand(34);
    mygolf.Show();
    golf = Golf("faster", 45);
    golf.Show();
    return 0;
}