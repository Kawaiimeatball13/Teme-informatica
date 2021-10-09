#include <iostream>
#include <fstream>
using namespace std;

void citire(int &n, int a[101][101], int &k)
{
    ifstream fin("matrice.in");

    fin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            fin >> a[i][j];
    fin >> k;
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

int nr_val(int n, int a[101][101], int k)
{
    int nr = 0;

    for(int i = 1; i < n; ++i)
        for(int j = 0; j < i; ++j)
            if(nrcif(a[i][j]) == k)
                nr++;

    return nr;
}

void afisare(int n, int a[101][101], int k)
{
    ofstream fout("matrice.out");

    fout << nr_val(n, a, k);
}

int main()
{
    int n, a[101][101], k;
    citire(n, a, k);
    afisare(n, a, k);
    return 0;
}
