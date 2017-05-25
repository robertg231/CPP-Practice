#include<iostream>
using namespace std;

int main()
{
    int h1, h2;
    
    cin >> h1;
    cin >> h2;
    
    int appleTree, orangeTree;
    
    cin >> appleTree;
    cin >> orangeTree;
    
    int numApples, numOranges;
    
    cin >> numApples;
    cin >> numOranges;
    
    int* apples = new int[numApples];
    int* oranges = new int[numOranges];
    
    for(int i = 0; i < numApples; i++)
    {
        cin >> apples[i];
    }
    
    for(int i = 0; i < numOranges; i++)
    {
        cin >> oranges[i];
    }
    
    
    int applesOnHouse = 0;
    
    for(int i = 0; i < numApples; i++)
    {
        int dist;
        dist = appleTree + apples[i];
        
        if( dist >= h1 && dist <= h2)
        {
            applesOnHouse++;
        }
    }
    
    int orangesOnHouse = 0;
    
    for(int i = 0; i < numOranges; i++)
    {
        int dist;
        dist = orangeTree + oranges[i];
        
        if(dist >= h1 && dist <= h2)
        {
            orangesOnHouse++;
        }
    }
    
    cout << applesOnHouse << endl << orangesOnHouse;
    
    return 0;
}