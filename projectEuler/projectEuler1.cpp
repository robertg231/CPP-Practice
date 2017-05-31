//find the sum of all the multiples of 3 or 5 below N

#include<iostream>
using namespace std;

int main()
{
    //input format: first line contains int X representing # of cases
    //                 then followed by X lines each containing an int N
    long long num;
    cin >> num;

    long long* cases = new long long[num];

    for(long long i = 0; i < num; i++)
    {
        cin >> cases[i];
    }

    long long sum;
    for(long long i = 0; i < num; i++)
    {
        sum = 0;
        long long div3 = (cases[i] - 1)/ 3;
        long long div5 = (cases[i] -1 )/ 5;
        long long div15 = (cases[i] -1 )/ 15; //to remove duplicates

        //Using SUM(k) = (1/2 n)(n+1) = (n2 + n) / 2
        sum = 3  * ( (div3 * div3 + div3) / 2);
        sum += 5 * ( (div5 * div5 + div5) / 2);
        sum -= 15 * ( (div15 * div15 + div15) / 2);

        cout << sum << endl;
    }

    // this method is too ineficient.
    //so i gotta do it the mathy way
    // int sum;
    //
    // for(int i = 0; i < num; i++)
    // {
    //     sum = 0;
    //
    //     for(int j = 1; j < cases[i]; j++)
    //     {
    //         if(j % 3 == 0 || j % 5 == 0)
    //         {
    //             sum += j;
    //         }
    //     }
    //     cout << sum << endl;
    // }

    return 0;
}
