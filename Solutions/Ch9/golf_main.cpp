#include "golf.h"

int main()
{
    golf mygolf, arr[5];
    setgolf(mygolf, "Charles", 34);
    showgolf(mygolf);
    setgolf(mygolf);
    showgolf(mygolf);

    for (int i = 0; i < 5; i++) {
        if(!setgolf(arr[i])) {
            break;
        } else {
            showgolf(arr[i]);
        }
    }
    return 0;
}