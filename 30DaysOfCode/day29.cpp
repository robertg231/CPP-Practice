#include <iostream>

using namespace std;

int maxAnd(int n, int k);


int main()
{
    int testCases;
    cin >>testCases;

    int* nums = new int[testCases];

    int n;
    int k;

    for(int i = 0; i < testCases; i++)
    {
        cin >> n >> k;
        cout << maxAnd(n, k) << endl;
    }

    return 0;
}

int maxAnd(int n, int k)
{
    int max = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            int num = i & j;
            if(num > max && num < k)
            {
                max = i & j;
            }
        }
    }

    return max;
}
