#include <iostream>

using namespace std;

int putere(int a ,int p)
{
    int rez = 1;
    while(p)
    {
        rez *= a;
        --p;
    }

    return rez;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << putere(a, b);
    return 0;
}
