#include <iostream>
using namespace std;

int factorial(int n);

int main()
{
    int num;
    cin >> num;

    cout << factorial(num);

    return 0;
}

int factorial(int n)
{
    if(n <2)
    {
        return 1;
    }

    return n * factorial(n - 1);
}
