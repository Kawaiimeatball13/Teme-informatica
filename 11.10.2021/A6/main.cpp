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

int ord_cifre(int x)
{
    int uc = -1;
    do
    {
        if(x % 10 % 3 == 0)
        {
            if(uc == -1)
                uc = x % 10;
            else if(x % 10 > uc)
                return 0;
        }
        x /= 10;
    }
    while(x);

    return 1;
}

int lung_max(int n, int a[101])
{
    int lmax = 0;
    int lc = 0;
    for(int i = 0; i < n; ++i)
    {
        if(ord_cifre(a[i]))
            lc++;
        else
        {
            if(lc > lmax)
                lmax = lc;
            lc = 0;
        }
    }
    if(lc > lmax)
        lmax = lc;

    return lmax;
}

void primele(int n, int a[101], int valori[101], int &k)
{
    int lmax = lung_max(n, a);
    k = 0;
    int lc = 0;
    int pr;
    for(int i = 0; i < n; ++i)
    {
        if(ord_cifre(a[i]))
        {
            lc++;
            if(lc == 1)
                pr = a[i];
        }
        else
        {
            if(lc == lmax && lmax != 0)
                valori[k++] = pr;
            lc = 0;
        }
    }
    if(lc == lmax && lmax != 0)
        valori[k++] = pr;
}

void sortare(int n, int a[101])
{
    for(int i = 0; i < n - 1; ++i)
        for(int j = i + 1; j < n; ++j)
            if(a[i] > a[j])
            {
                int aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
}

void afisare(int n, int a[101])
{
    if(n == 0)
        cout << "NU EXISTA SECVENTE";
    for(int i = 0; i < n; ++i)
        cout << a[i] << ' ';
}

int n, a[101];
int valori[101], k;

int main()
{
    citire(n, a);
    primele(n, a, valori, k);
    sortare(k, valori);
    afisare(k, valori);
    return 0;
}
