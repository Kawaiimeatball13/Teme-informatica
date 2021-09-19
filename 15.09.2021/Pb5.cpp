#include <iostream>

using namespace std;
/*
int cmin1(int x)
{
    int cifmin = 9;
    do
    {
        if(x % 10 < cifmin)
            cifmin = x % 10;
        x /= 10;
    }
    while(x);

    return cifmin;
}

int cmin2(int x)
{
    int cif = cmin1(x);
    int cifmin = 10;
    do
    {
        if(x % 10 < cifmin && x % 10 > cif)
            cifmin = x % 10;
        x /= 10;
    }
    while(x);

    return cifmin;
}
*/

int cmin(int x)
{
    int cifmin1 = 10;
    int cifmin2  = 10;
    do
    {
        if(x % 10 < cifmin1)
        {
            cifmin2 = cifmin1;
            cifmin1 = x % 10;
        }
        else if(x % 10 < cifmin2 && x % 10 != cifmin1)
            cifmin2 = x % 10;
        x /= 10;
    }
    while(x);

    if(cifmin2 == 10)
        return -1;
    else
        return cifmin1 * 10 + cifmin2;
}

int main()
{
    int x;
    cin >> x;
    int c = cmin(x);
    if(c == -1)
        cout << "NU EXISTA 2 CIFRE DISTINCTE IN NUMAR";
    else
        cout << c / 10 << ' ' << c % 10;
//    if(cmin2(x) == 10)
//        cout << "NU EXISTA 2 CIFRE DISTINCTE IN NUMAR";
//    else
//        cout << cmin1(x) << ' ' << cmin2(x);
    return 0;
}
