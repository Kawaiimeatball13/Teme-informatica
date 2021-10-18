#include <iostream>
#include <fstream>

using namespace std;

void citire(int &n, int a[101])
{
    ifstream fin("sir.in");

    fin >> n;
    for(int i = 0; i < n; ++i)
        fin >> a[i];
}

int scif(int x)
{
    int s = 0;
    while(x)
    {
        s += x % 10;
        x /= 10;
    }

    return s;
}

int lung_max(int n, int a[101])
{
    int lmax = 0;
    int lc = 0;
    for(int i = 0; i < n; ++i)
        if(scif(a[i]) < 10)
            lc++;
        else
        {
            if(lc > lmax)
                lmax = lc;
            lc = 0;
        }
    if(lc > lmax)
        lmax = lc;

    return lmax;
}

void val_min(int n, int a[101])
{
    int lmax = lung_max(n, a);
    int lc = 0;
    int vmin = 2000000000;
    for(int i = 0; i < n; ++i)
        if(scif(a[i]) < 10)
        {
            lc++;
            if(a[i] < vmin)
                vmin = a[i];
        }
        else
        {
            if(lc == lmax)
                cout << vmin << ' ';
            lc = 0;
            vmin = 2000000000;
        }
    if(lc == lmax)
        cout << vmin << ' ';
}

int main()
{
    int n, a[101];
    citire(n, a);
    val_min(n, a);
    return 0;
}
