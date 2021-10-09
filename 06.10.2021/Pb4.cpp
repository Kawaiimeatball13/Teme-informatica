#include <iostream>
#include <fstream>

using namespace std;

void citire(int &n, int a[101][101])
{
    ifstream fin("matrice.in");

    fin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            fin >> a[i][j];
}

int sdiv(int x)
{
    int s = 0, d;
    for(d = 1; d * d < x; d++)
        if(x % d == 0)
        {
            s += d;
            s += x / d;
        }
    if(d * d == x)
        s += d;

    return s;
}

int val_max(int n, int a[101][101])
{
    int vmax = -1000000000;
    for(int i = 1; i < n; ++i)
        for(int j = n - i; j < n; ++j)
            if(sdiv(a[i][j]) % 2 == 0)
                if(a[i][j] > vmax)
                    vmax = a[i][j];

    return vmax;
}

int main()
{
    ofstream fout("matrice.out");

    int n, a[101][101];
    citire(n, a);
    fout << val_max(n, a);
    return 0;
}
