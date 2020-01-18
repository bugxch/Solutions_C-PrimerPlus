#include <iostream>
#include <cstring>

using namespace std;

template<typename T>
T maxn(T* arr, int len);
template<typename T>
void show(T* arr, int len);

template <>
char* maxn<char *>(char **, int len);
template<>
void show<char*>(char **, int len);

int main()
{
    int arr_int[6] = {1, 2, 3, 4, 5, 6};
    double arr_flt[4] = {10.0, 11.0, 12.0, 13.0};
    char* arr_ch[4] = {
        "shao",
        "zhengjiang",
        "haha",
        "yesyesyesgood",
    };

    cout << maxn(arr_int, 6) << endl;
    show(arr_int, 6);
    cout << maxn(arr_flt, 4) << endl;
    show(arr_flt, 4);
    cout << maxn(arr_ch, 4) << endl;
    show(arr_ch, 4);


    return 0;
}

template<typename T>
T maxn(T* arr, int len)
{
    T maxval = arr[0];
    for (int i = 1; i < len; ++i) {
        if (arr[i] > maxval)
        {
            maxval = arr[i];
        }
    }
    return maxval;
}

template<typename T>
void show(T* arr, int len)
{
    for(int i = 0; i < len; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <>
char* maxn<char *>(char** arr, int len)
{
    int maxlen = strlen(arr[0]);
    int maxid = 0;
    int templen = 0;
    for (int i = 1; i < len;i++)
    {
        templen = strlen(arr[i]);
        if (templen > maxlen)
        {
            maxlen = templen;
            maxid = i;
        }
    }
    return arr[maxid];
}

template<>
void show<char*>(char **arr, int len)
{
    int i = 0;
    while (i++ < len)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}