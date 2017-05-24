/*
Given five positive integers, find the minimum and maximum values that can be calculated by 
summing exactly four of the five integers. Then print the respective minimum and maximum values 
as a single line of two space-separated long integers.
*/
// nCr(5,4) = 5
//so i only gotta do 5 calculations

//so i started doing it this way(doing the calculations). then i thought i was doing it wrong
//so i stopped and then realized i could just sort it. then i saw some comment with a similar
//solution and i was like THATS WHAT I WAS TRYING TO DO!!!! so i came back and redid it
#include<iostream>
using namespace std;

int main()
{
    long long nums[5];
    
    for(int i = 0; i < 5; i++)
    {
        cin >> nums[i];
    }
    
    long long sums[5];
    
    sums[0] = nums[0] + nums[1] + nums[2] + nums[3];
    sums[1] = nums[0] + nums[1] + nums[2] + nums[4];
    sums[2] = nums[0] + nums[1] + nums[3] + nums[4];
    sums[3] = nums[0] + nums[2] + nums[3] + nums[4];
    sums[4] = nums[1] + nums[2] + nums[3] + nums[4];
    
    long long max = 0;
    long long min = 9223372036854775807;        //max long long value
    for(int i = 0; i < 5; i++)
    {
        if(sums[i] > max)
        {
            max = sums[i];
        }
        if(sums[i] < min)
        {
            min = sums[i];
        }
    }
    
    cout << min << ' ' << max;
    return 0;
}


// solution 2
/*
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long long nums[5];
    
    for(int i = 0; i < 5; i++)
    {
        cin >> nums[i];
    }
    
    int size = sizeof(nums) / sizeof(nums[1]);
    
    sort(nums, nums + size);
    
    long long max = 0;
    long long min = 0;
    
    for(int i = 0; i < 5; i++)
    {
        max += nums[i];
        min += nums[i];
    }
    
    //sort then subtract smallest
    max -= nums[0];
    
    //sort then subtract largest
    min -= nums[4];
    
    cout << min << ' ' << max;
    return 0;
}

*/