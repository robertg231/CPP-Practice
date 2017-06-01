#include<iostream>
using namespace std;


int main()
{
    
    int A[3];
    cin >> A[0] >> A[1] >> A[2];
    
    int B[3];
    cin >> B[0] >> B[1] >> B[2];
    
    
    //add check for 1 <= a[i] <= 100
    //and           1 <= b[i] <= 100
    
    int score1 = 0;
    int score2 = 0;
    
    for(int i = 0; i < 3; i++)
    {
        if(A[i] > B[i])
        {
            score1++;
        }
        else if(B[i] > A[i])
        {
            score2++;
        }
        
    }
    
    cout << score1 << ' ' << score2;
    
    return 0;
}