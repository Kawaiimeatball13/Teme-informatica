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

void c_min_max(int x, int &cmin, int &cmax)
{
    cmin = 9;
    cmax = 0;
    do
    {
        int c = x % 10;
        if(c < cmin)
            cmin = c;
        if(c > cmax)
            cmax = c;
        x /= 10;
    }
    while(x);
}

int prima(int x)
{
    while(x > 9)
        x /= 10;

    return x;
}

int verif(int x)
{
    int cmin, cmax;
    int prim_cif = prima(x);
    c_min_max(x, cmin, cmax);
    if(x % 10 == cmin && prim_cif == cmin)
        return 1;
    if(x % 10 == cmax && prim_cif == cmax)
        return 1;

    return 0;
}

void secventa(int n, int a[101], int &lmax, int &poz)
{
    int lc = 0;
    lmax = 0;
    for(int i = 0; i < n; ++i)
    {
        if(verif(a[i]))
            lc++;
        else
        {
            if(lc > lmax)
            {
                lmax = lc;
                poz = i - 1;
            }
            lc = 0;
        }
    }
    if(lc > lmax)
    {
        lmax = lc;
        poz = n - 1;
    }
}

void afisare(int n, int a[101])
{
    int lmax, poz;
    secventa(n, a, lmax, poz);
     if(lmax == 0)
    {
        cout << "NU EXISTA SECVENTE";
        return;
    }
    for(int i = poz - lmax + 1; i <= poz; ++i)
        cout << a[i] << ' ';
}

int main()
{
    int n, a[101];
    citire(n, a);
    afisare(n, a);
    return 0;
}
