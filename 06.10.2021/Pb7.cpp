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

int prim(int x)
{
    if(x < 2 || x > 2 && x % 2 == 0)
        return 0;
    for(int d = 3; d * d <= x; d += 2)
        if(x % d == 0)
            return 0;

    return 1;
}

void sortare(int n, int a[101][101])
{
    for(int i1 = 0; i1 < n - 1; ++i1)
        if(prim(a[i1][i1]))
            for(int i2 = i1 + 1; i2 < n; ++i2)
                if(prim(a[i2][i2]) && a[i2][i2] < a[i1][i1])
                {
                    int aux = a[i1][i1];
                    a[i1][i1] = a[i2][i2];
                    a[i2][i2] = aux;
                }

}

void afisare(int n, int a[101][101])
{
    ofstream fout("matrice.out");

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            fout << a[i][j] << ' ';
        fout << '\n';
    }
}

int main()
{
    int n, a[101][101];
    citire(n, a);
    sortare(n, a);
    afisare(n, a);
    return 0;
}
