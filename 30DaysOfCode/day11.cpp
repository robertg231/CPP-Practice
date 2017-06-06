#include <iostream>

using namespace std;

int main()
{
    int array[6][6];

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            cin >> array[i][j];
        }
    }

    int maxHourglassSum = -63;
    int hourglassSum;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            //this one is the center
            hourglassSum = array[i + 1][j + 1];

            for(int k = 0; k < 3; k++)
            {
                hourglassSum += array[i][k + j];
                hourglassSum += array[i + 2][k + j];
            }

            if(hourglassSum > maxHourglassSum)
            {
                maxHourglassSum = hourglassSum;
            }
        }
    }

    cout << maxHourglassSum;

    return 0;
}
