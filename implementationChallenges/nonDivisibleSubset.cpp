//given a set S of N distinct ints. print the size of a maximal subset S'
//where the sum of any 2 numbers in S' is NOT EVENLY divisible by K

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int size, k;
    cin >> size >> k;

    int* nums = new int[size];
    int* remainders = new int[k]{0};

    for(int i = 0; i < size; i++)
    {
        cin >> nums[i];
        remainders[nums[i] % k]++;
    }

    //constraints
    //1 <= n <= 10^5
    //1 <= k <= 100
    //1 <= nums[i] <= 10^9

    int setSize = 0;

    //we can only have 1 or 0 numbers that evenly divides into k
    setSize = min(remainders[0], 1);

    //according to math if
    //(a + b) % k == 0 then a mod k + b mod k == 0
    //so we check the pairs that do evenly divide into k
    //and then choose one. we want the largest subset so
    //we choose the one with the higher frequency
    for( int i = 1; i < k/2 + 1; i++)
    {
        //we are checking the remainders that add to k
        //ex: k=7, 1and6, 2and5,3and4...
        //so when they are moded they have a remainder 0
        //we can only have 1 not both
        if( i != k-i)
        {
            setSize += max(remainders[i], remainders[k - i]);
        }
    }

    //if k is even we can only have 1 or 0
    //values that have a remainder equal to half of k
    //cause 2 would give us remainder 0 aka evenly divisible
    if(k % 2 == 0)
    {
        setSize++;
    }

    cout << setSize;

    return 0;
}
