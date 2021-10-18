#include <iostream>
#include <fstream>

using namespace std;

int rezolvare()
{
    ifstream fin("sir.in");

    int x, y;
    int lc = 1;
    int urca = 1;

    fin >> x;
    while(fin >> y)
    {
        if(y > x)
        {
            if(urca == 1)
                lc++;
            else
            {
                if(lc % 2)
                    return 0;
                else
                {
                    lc = 1;
                    urca = 1;
                }
            }
        }
        else
        {
            if(urca == 1)
            {
                urca = 0;
                lc++;
            }
            else
                lc++;
        }
        x = y;
    }
    if(lc % 2)
        return 0;

    return 1;
}

int main()
{
    cout << rezolvare();
    return 0;
}
