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
    
    //find fraction(in decimal) of +nums in array compared to size
    //find fraction(in decimal) of -nums in array compared to size
    //find fraction(in decimal) of zeroes in array compared to size
    
    int pos = 0;
    int neg = 0;
    int zeros = 0;
    
    for(int i = 0; i < size; i++)
    {
        if(nums[i] > 0)
        {
            pos++;
        }
        else if(nums[i] < 0)
        {
            neg++;
        }
        else
        {
            zeros++;
        }
    }

    cout << double(pos)/size << endl << double(neg)/size << endl << double(zeros)/size;
   
   
    
    return 0;
}