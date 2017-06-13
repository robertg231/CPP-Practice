#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class AdvancedArithmetic
{
public:
    virtual int divisorSum(int n)=0;
};

class Calculator: public AdvancedArithmetic
{
public:
    int divisorSum(int n);
};

int Calculator::divisorSum(int n)
{
    vector<int> divisors;

    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            divisors.push_back(i);

            //dont need to push square roots twice
            //ex: n = 25 and i = 5. don't need 2 fives just one
            if(n / i == i)
            {
                continue;
            }
            divisors.push_back(n / i);
        }
    }

    //reusing n
    n = 0;
    for(int i = 0; i < divisors.size(); i++)
    {
        n += divisors[i];
    }
    return n;
}


//main provided by challenge
int main()
{
    int n;
    cin  >> n;
    AdvancedArithmetic* myCalculator = new Calculator();
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n" << sum;

    return 0;
}
