#include <iostream>
#include <fstream>

using namespace std;

void rezolvare(int &lmax, int &nr)
{
    ifstream fin("sir.in");

    int x, y;
    int lc = 1;
    lmax = 0, nr = 0;

    fin >> x;
    while(fin >> y)
    {
        if(y > x)
            lc++;
        else
        {
            if(lc % 2 == 0)
                nr++;
            else if(lc > lmax)
                lmax = lc;
            lc = 1;
        }
        x = y;
    }
    if(lc % 2 == 0)
        nr++;
    else if(lc > lmax)
        lmax = lc;
}

int main()
{
    int lmax, nr;
    rezolvare(lmax, nr);
    cout << nr << ' ' << lmax;
    return 0;
}
