#include<iostream>
using namespace std;

int main()
{
    int games;
    cin >> games;

    int* scores = new int[games];

    for(int i = 0; i < games; i++)
    {
        cin >> scores[i];
    }

    //find number of times highest and lowest scores are broken(aka changed)
    int timesHighestBroken = 0;
    int timesLowestBroken = 0;

    int highest = scores[0];
    int lowest = scores[0];

    for(int i = 1; i < games; i++)
    {
        if(scores[i] > highest)
        {
            highest = scores[i];
            timesHighestBroken++;
        }
        else if(scores[i] < lowest)
        {
            lowest = scores[i];
            timesLowestBroken++;
        }
    }

    cout << timesHighestBroken << ' ' << timesLowestBroken;
    return 0;
}
