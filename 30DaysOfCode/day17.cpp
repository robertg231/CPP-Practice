#include <iostream>
#include <cmath>
#include <exception>
#include <stdio.h>

using namespace std;

class Calculator
{
public:
    int power(int base, int power);

};

class calcError: public exception
{
    const char* what() const throw()
    {
        return "n and p should be non-negative";
    }
};


int Calculator::power(int base, int power)
{
    if(base < 0 || power < 0)
    {
        throw calcError();
    }
    return pow(base, power);
}


//main provided by challenge
int main()
{
    Calculator myCalculator = Calculator();

    int T;
    int n;
    int p;

    cin >> T;

    while(T-- > 0)
    {
        if(scanf("%d %d", &n, &p) == 2)
        {
            try
            {
                int ans = myCalculator.power(n, p);
                cout << ans << endl;
            }
            catch(exception& e)
            {
                cout << e.what() << endl;
            }
        }
    }
    return 0;
}
