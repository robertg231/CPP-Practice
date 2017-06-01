//simple array sum

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int num1;
    cin >> num1;
    int* nums = new int[num1];
    
    int i = 0;
    int sum = 0;
    
    while(i < num1)
    {
        cin >> nums[i];
        sum +=  nums[i];
        i++;
    }

    cout << sum << endl;
    return 0;
}
