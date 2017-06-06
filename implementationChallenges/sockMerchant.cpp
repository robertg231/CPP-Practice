#include <iostream>

using namespace std;

int main()
{
    int socks[100] = {};

    int numSocks;
    cin >> numSocks;

    int sockVal;
    for(int i = 0; i < numSocks; i++)
    {
        cin >> sockVal;
        socks[sockVal - 1]++;
    }

    sockVal = 0;
    for(int i = 0; i < 100; i++)
    {
        sockVal += socks[i] / 2;
    }

    cout << sockVal;
}
