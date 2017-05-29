#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if( (n % 2) == 1)
    {
        cout << "Weird";
    }
    else if(n <= 5)
    {
        cout << "Not Weird";
    }
    else if(n <= 20)
    {
        cout << "Weird";
    }
    else
    {
        cout << "Not Weird";
    }
    return 0;
}
