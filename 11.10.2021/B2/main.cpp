#include <iostream>
#include <fstream>

using namespace std;

int lmax[10];

int nrcif(int x)
{
    int nr = 0;
    do
    {
        nr++;
        x /= 10;
    }
    while(x);

    return nr;
}

void rezolvare(int x)
{
    ifstream fin("sir.in");

    int lc = 0;
    int nrc = -1;
    while(fin >> x)
    {
        int nr = nrcif(x);
        if(nrc == -1)
            nrc = nr;
        if(nr == nrc)
            lc++;
        else
        {
            if(lc > lmax[nrc])
                lmax[nrc] = lc;
            nrc = nr;
            lc = 1;
        }
    }
    if(lc > lmax[nrc])
        lmax[nrc] = lc;
}

void afisare()
{
    for(int i = 9; i > 0; --i)
        if(lmax[i])
            cout << i << ' ' << lmax[i] << '\n';
}

int main()
{
    int x;
    rezolvare(x);
    afisare();
    return 0;
}
