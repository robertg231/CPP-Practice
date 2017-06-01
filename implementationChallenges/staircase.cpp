#include<iostream>
using namespace std;

int main()
{
    int size;
    
    cin >> size;
    
    for(int i = 0; i < size; i++)
    {
      
        //spaces = size - (i + 1)
        for(int k = 0; k < (size - (i + 1)); k++)
        {
            cout << ' ';
        }
            
        // # = i + 1
        for(int k = 0; k < (i + 1); k++)
        {
            cout << '#';
        }
        
        cout << endl;
    }
    
    
    return 0;
}