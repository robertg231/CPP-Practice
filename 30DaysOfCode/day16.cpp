#include<iostream>
#include <string>

using namespace std;

int main()
{
    string number;
    cin >> number;

    try
    {
        cout << stoi(number);
    }
    catch(invalid_argument& E)
    {
        cout << "Bad String";
    }
    return 0;
}
