#include <iostream>
#include <string>

using namespace std;

int main()
{
    string camelWords;
    cin >> camelWords;

    int numWords = 1;

    for(int i = 0; i < camelWords.size(); i++)
    {
        if(isupper(camelWords[i]))
        {
            numWords++;
        }
    }

    cout << numWords;


    return 0;
}
