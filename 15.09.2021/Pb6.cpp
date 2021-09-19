#include <iostream>

using namespace std;

int distincte(int x)
{
    int fr[10];
    for(int i = 0; i < 10; ++i)
        fr[i] = 0;
    do
    {
        fr[x % 10]++;
        if(fr[x % 10] > 1)
            return 0;
        x /= 10;
    }while(x);

    return 1;
}

int main()
{
    int x;
    cin >> x;
    if(distincte(x))
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
