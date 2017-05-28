#include<iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;

    int* nums = new int[size];

    int k;
    cin >> k;

    for(int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }

    //constraints
    //2 <= n <= 100
    //1 <= k <= 100
    //1 <= nums[i] <<= 100

    //find number of i,j pairs (where i < j)
    //find (nums[i] + nums[j]) % k == 0

    int pairsDivisible = 0;

    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if((nums[i] + nums[j]) % k == 0)
            {
                pairsDivisible++;
            }
        }
    }

    cout << pairsDivisible;

    return 0;
}
