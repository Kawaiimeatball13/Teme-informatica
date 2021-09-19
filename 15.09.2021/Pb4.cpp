#include <iostream>

using namespace std;

int cmin(int x)
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

int primcif(int x)
{
    while(x > 9)
        x /= 10;
    return x;
}

int verif(int x)
{
    if(primcif(x) == cmin(x))
        return 1;
    return 0;
}

int main()
{
    int x;
    cin >> x;
    if(verif(x))
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
