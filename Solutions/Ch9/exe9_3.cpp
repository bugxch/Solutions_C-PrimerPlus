#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

const int N = 2;
const int BUFF = 80;

struct chaff
{
    char dross[20];
    int slag;
};


char buff[BUFF];

int main()
{
    // method 1
    char* name1[N] = {"Charles", "Liming"};
    char* name2[N] = {"Feg", "Hello"};
    chaff * pd1 = new (buff) chaff[N];
    chaff* pd2 = new chaff[N];

    for(int i = 0; i < N;i++) {
        strcpy(pd1[i].dross, name1[i]);
        strcpy(pd2[i].dross, name2[i]);

        pd1[i].slag = 1000 * i + 1;
        pd2[i].slag = 1000 * i + 2;
    }

    // show content
    for(int i = 0; i < N;i++) {
        cout << "pd1[" << i << "] dross is " << pd1[i].dross << endl;
        cout << "pd1[" << i << "] slags is " << pd1[i].slag << endl;

        cout << "pd2[" << i << "] dross is " << pd2[i].dross << endl;
        cout << "pd2[" << i << "] slags is " << pd2[i].slag << endl;
    }


    delete [] pd2;
    return 0;
}

