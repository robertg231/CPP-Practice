//hello world

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string words;
    
    getline(cin, words);
    
    cout << "Hello, World." << endl;
    cout << words;
    
    return 0;
}