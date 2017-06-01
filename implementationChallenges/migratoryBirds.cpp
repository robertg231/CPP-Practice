#include<iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;

    int birds[5] = {};
    int birdType;

    while(cin >> birdType)
    {
        birds[birdType - 1]++;
    }

    int max = 0;
    for(int i = 1; i < 5; i++)
    {
        if(birds[i] > birds[max])
        {
            max = i;
        }
    }

    cout << max + 1;
    return 0;
}
