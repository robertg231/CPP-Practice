#include<iostream>
using namespace std;

int main()
{
    int size;
    
    cin >> size;
    
    int* candles = new int[size];
    
    int max = 0;
    for(int i = 0; i < size; i++)
    {
        cin >> candles[i];
        if( candles[i] > max)
        {
            max = candles[i];
        }
    }
    
    int blownCandles = 0;
    for(int i = 0; i < size; i++)
    {
        if(candles[i] == max)
        {
            blownCandles++;
        }
    }
    
    cout << blownCandles;
    
    
    return 0;
}