#include<iostream>
using namespace std;

int main()
{
    int a = 5;
    int& b = a;

    cout << a << endl;
    cout << b << endl;

    cout << &a << endl;
    cout << &b << endl;

    int* c = &a;

    cout << c << endl;
    return 0;
}
