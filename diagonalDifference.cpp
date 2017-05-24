#include<iostream>
#include<cmath>
using namespace std;


int main()
{
    int N;
    
    cin >> N;
    
    //gotta allocate 2d array all weirdly
    //cause a 2d array is an array of arrays
    int** nums = new int*[N];
    for(int i = 0; i < N; i++)
    {
        nums[i] = new int[N];
    }
    
    //filling up matrix with input
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> nums[i][j];
        }
    }
    
    int diagSum1 = 0;
    int diagSum2 = 0;
    
    for(int i = 0; i < N; i++)
    {
            diagSum1 += nums[i][i];
    }
    
    for(int i = (N-1), j = 0; i >= 0 && j < N; i--, j++)
    {
            diagSum2 += nums[i][j];
    }
    
    cout << abs(diagSum1 - diagSum2);
    
    return 0;
}