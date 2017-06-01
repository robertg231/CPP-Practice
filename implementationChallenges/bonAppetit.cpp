#include<iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;

    int k;
    cin >> k;

    int* prices = new int[size];
    int total = 0;

    for(int i = 0; i < size; i++)
    {
        cin >> prices[i];
        total += prices[i];
    }

    int charged;
    cin >> charged;

    //constraints
    //2 <= n <= 10^5
    //0 <= k < n
    //0 <= prices[i] <= 10^4
    //0 <= b <= SUM (prices[i])

    //removing kth item not eaten by anna
    total -= prices[k];

    //finding fair shair
    total /= 2;

    if(total == charged)
    {
        cout << "Bon Appetit";
    }
    else
    {
        cout << charged - total;
    }

    return 0;
}
