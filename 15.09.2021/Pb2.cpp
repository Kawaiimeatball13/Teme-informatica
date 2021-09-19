#include <iostream>

using namespace std;

int factori_primi(int x)
{
    int p, d;
    for(p = 0; x % 2 == 0 && x; ++p, x /= 2);
    if(p)
        cout << 2 << '^' << p << '\n';
    for(d = 3; d * d <= x; d += 2)
    {
        for(p = 0; x % d == 0 && x; ++p, x /= d);
        if(p)
            cout << d << '^' << p << '\n';
    }

    if(x != 1)
        cout << x << '^' << 1 << '\n';
    return 0;
}

int main()
{
    int x;
    cin >> x;
    factori_primi(x);
    return 0;
}
