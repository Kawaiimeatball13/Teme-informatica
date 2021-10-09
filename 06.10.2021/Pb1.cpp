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

int div_primi(int x)
{
    int p, d;
    int nr = 0;
    for(p = 0; x % 2 == 0; ++p, x /= 2);
    if(p)
        nr++;
    for(d = 3; d * d <= x; d += 2)
    {
        for(p = 0; x % d == 0; ++p, x /= d);
        if(p)
            nr++;
    }

    if(x != 1)
        nr++;

    return nr;
}

int suma(int n, int a[101][101])
{
    int s = 0;

    for(int i = 0; i < n - 1; ++i)
        for(int j = i + 1; j < n; ++j)
            if(div_primi(a[i][j]) % 2 == 0 && div_primi(a[i][j]))
                s += a[i][j];

    return s;
}

void afisare(int n, int a[101][101])
{
    ofstream fout("matrice.out");

    fout << suma(n, a);
}

int main()
{
    int n, a[101][101];
    citire(n, a);
    afisare(n, a);
    return 0;
}
