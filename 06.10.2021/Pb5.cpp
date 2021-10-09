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

int prima_cif(int x)
{
    while(x > 9)
        x /= 10;

    return x;
}

void minim(int n, int a[101][101])
{
    ofstream fout("matrice.out");

    int vmin[101];

    for(int i = 0; i < 101; ++i)
        vmin[i] = 1000000000;

    for(int i = 1; i < n; ++i)
        for(int j = 0; j < i; ++j)
        {
            if(prima_cif(a[i][j]) % 2 == 0)
                if(vmin[j] > a[i][j])
                    vmin[j] = a[i][j];
        }

    for(int i = 0; i < n - 1; ++i)
        cout << vmin[i] << ' ';
}

int main()
{
    int n, a[101][101];
    citire(n, a);
    minim(n, a);
    return 0;
}
