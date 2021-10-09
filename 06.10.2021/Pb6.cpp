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

int nrcif(int x)
{
    int nr = 0;
    do
    {
        nr++;
        x /= 10;
    }while(x);

    return nr;
}

int verificare(int n, int a[101][101], int lin)
{
    for(int j = n - lin; j < n; ++j)
        if(nrcif(a[lin][j]) % 2)
            return 0;

    return 1;
}

void indici(int n, int a[101][101])
{
    ofstream fout("matrice.out");

    for(int i = 1; i < n; ++i)
        if(verificare(n, a, i))
            fout << i << ' ';

}

int main()
{
    int n, a[101][101];
    citire(n, a);
    indici(n, a);
    return 0;
}
