#include<iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;

    int* nums = new int[size];

    for(int i = 0; i < size; i++)
    {
        cin >> nums[i];
    }

    int d;
    int m;

    cin >> d >> m;

    //constraints
    //1 <= n <= 100
    // 1 <= nums[i] <= 5 where (0 <= i < size)
    //1 <= d <= 31
    //1 <= m <= 12

    int numPieces = 0;
    int sum;

    for(int i = 0; i < size; i++)
    {
        sum = 0;

        for(int j = 0; j < m; j++)
        {
            sum += nums[i + j];
        }
        if( sum == d)
        {
            numPieces++;
        }
    }

    cout << numPieces;

    return 0;
}
