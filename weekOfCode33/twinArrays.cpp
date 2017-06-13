#include <bits/stdc++.h>
#include <climits>
using namespace std;

//find the minimum sum of 2 values(1 from A, 1 from B)
//A and B cannot have same index
int twinArrays(vector <int> A, vector <int> B)
{
    int minA = 0;
    int minB = 0;

    int minA2 = 1;
    int minB2 = 1;


    for(int i = 1; i < A.size(); i++)
    {
        if(A[i] < A[minA])
        {
            minA2 = minA;
            minA = i;
        }
        else if(A[i] < A[minA2] && A[i] >= A[minA])
        {
            minA2 = i;
        }
        if(B[i] < B[minB])
        {
            minB2 = minB;
            minB = i;
        }
        else if(B[i] < B[minB2] && B[i] >= B[minB])
        {
            minB2 = i;
        }
    }

    if(minA == minB)
    {
        if(A[minA] + B[minB2] < A[minA2] + B[minB])
        {
            minB = minB2;
        }
        else
        {
            minA = minA2;
        }
    }

    return A[minA] + B[minB];
}

// int findMin(vector<int> nums, int start)
// {
//     int min = start;
//     for(int i = start + 1; i < nums.size(); i++)
//     {
//         if(nums[i] < nums[min])
//         {
//             min = i;
//         }
//     }
//     return min;
// }

//main provided by challenge
int main() {
    int n;
    cin >> n;
    vector<int> ar1(n);
    for(int ar1_i = 0; ar1_i < n; ar1_i++){
       cin >> ar1[ar1_i];
    }
    vector<int> ar2(n);
    for(int ar2_i = 0; ar2_i < n; ar2_i++){
       cin >> ar2[ar2_i];
    }
    int result = twinArrays(ar1, ar2);
    cout << result << endl;
    return 0;
}
