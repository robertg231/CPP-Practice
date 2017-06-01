//maximizing xor
//getting 2 inputs L and R
//find max value of A XOR B where L <= A <= B <= R
//constraints 1 <= L <= R <= 1000

#include<iostream>
using namespace std;

int main()
{
    
    int L;
    int R;
    int max = 0;
    
    cin >> L;
    cin >> R;
    
    for(int i = L; i <= R; i++)
    {
        for(int j = L; j <= R; j++)
        {
            if(max < (i ^ j))
            {
                max = (i ^ j);
            }
        }
    }
    
    cout << max;
    
    
    return 0;
}