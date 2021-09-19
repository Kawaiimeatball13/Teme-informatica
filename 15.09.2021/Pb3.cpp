#include <iostream>

using namespace std;

int ordonate(int x)
{
    int ultima = -1;
    while(x > 9)
    {
        if(x % 2 == 0)
            if(ultima == -1)
                ultima = x % 10;
            else if(x % 10 > ultima)
                return 0;
        x /= 10;
    }
    if(ultima == -1)
        return - 1;

    return 1;
}

int main()
{
    int x;
    cin >> x;
    int ok = ordonate(x);
    if(ok == -1)
        cout << "NU EXISTA CIFRE PARE";
    else if(ok)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
