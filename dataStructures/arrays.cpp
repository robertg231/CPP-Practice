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
    
    for(int i = (size - 1); i >= 0; i--)
    {
        cout << nums[i] << ' ';
    }
    return 0;
}