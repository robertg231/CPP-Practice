#include<iostream>
using namespace std;

int main()
{
    
    long long size;
    
    cin >> size;
    
    long long* nums = new long long[size];
    long long sum = 0;
    
    for(int i = 0; i < size; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    
    cout << sum;
    return 0;
}