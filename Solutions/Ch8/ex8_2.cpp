#include <iostream>
#include <cstring>

using namespace std;

struct CandyBar {
    char Name[30];
    double candyWeight;
    int candyHot;
};

void SetCandy(CandyBar & candy, const char* name = "Mille", const double w = 2.85, const int clory = 350);
void DispCandy(const CandyBar candy);

int main()
{
    CandyBar myCandy;
    SetCandy(myCandy);
    DispCandy(myCandy);

    char name[30];
    cin.getline(name, 30);
    double weight;
    int calori;
    cin >> weight >> calori;

    SetCandy(myCandy, name, weight, calori);
    DispCandy(myCandy);

    return 0;
}

void SetCandy(CandyBar & candy, const char* name, const double w, const int clory)
{
    strcpy(candy.Name, name);
    candy.candyWeight = w;
    candy.candyHot = clory;
    return;
}

void DispCandy(const CandyBar candy)
{
    cout << "Candy name is " << candy.Name << ", weight is " << candy.candyWeight
        << ", hot is " << candy.candyHot << endl;
    return;
}