#include <iostream>

using namespace std;

int div_pari(int x)
{
    int nr = 0;
    int d;
    for(d = 1; d * d < x; d++)
    {
        if(x % d == 0)
        {
            if(d % 2 == 0)
                nr++;
            if(x /d % 2 == 0)
                nr++;
        }
    }

    if(d * d == x && d % 2 == 0)
        nr++;

    return nr;
}

int main()
{
    int x;
    cin >> x;
    cout <<div_pari(x);
    return 0;
}
