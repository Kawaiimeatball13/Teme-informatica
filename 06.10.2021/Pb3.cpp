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

int pali(int x)
{
    int inv = 0, aux = x;
    while(x)
    {
        inv = inv * 10 + x % 10;
        x /= 10;
    }

    if(inv == aux)
        return 1;
    return 0;
}

int verificare(int n, int a[101][101])
{
    for(int i = 0; i < n - 1; ++i)
        for(int j = 0; j < n - i - 1; ++j)
            if(pali(a[i][j]))
                return 1;

    return 0;
}

void afisare(int n, int a[101][101])
{
    ofstream fout("matrice.out");

    fout << verificare(n, a);
}

int main()
{
    int n, a[101][101];
    citire(n, a);
    afisare(n, a);
    return 0;
}
