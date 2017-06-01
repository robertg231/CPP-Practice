#include<iostream>
using namespace std;

long long fib(long long num);

int main()
{
    //find sum of even valued fibonacci terms not exceeding N
    long long num;
    cin >> num;

    long long* cases = new long long[num];

    for(long long i = 0; i < num; i++)
    {
        cin >> cases[i];
    }

    for(long long i = 0; i < num; i++)
    {
        long long curCase = cases[i];
        long long fibNum = 0;
        long long num1 = 0;
        long long num2 = 1;
        long long sum = 0;

        //finding the fib iteratively
        for(long long j = 0; fibNum < curCase; j++)
        {
            if(fibNum % 2 == 0)
            {
                sum += fibNum;
            }
            fibNum = num1 + num2;
            num1 = num2;
            num2 = fibNum;
        }
        cout << sum << endl;

    }


    //not fast enough :(
    // for(long long i = 0; i < num; i++)
    // {
    //     long long j = 0;
    //     sum = 0;
    //     while(fib(j) < cases[i])
    //     {
    //         if(fib(j) % 2 == 0)
    //         {
    //             sum += fib(j);
    //         }
    //         j++;
    //     }
    //     cout << sum << endl;
    // }
    return 0;
}

long long fib(long long num)
{
    if(num == 0)
    {
        return 0;
    }
    else if(num == 1)
    {
        return 1;
    }

    return fib(num-1) + fib(num-2);

}
