#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string nextPerm(string word);

int main()
{
    int num;
    cin >> num;

    string* words = new string[num];

    for(int i = 0; i < num; i++)
    {
        cin >> words[i];
    }

    for(int i = 0; i < num; i++)
    {
        cout << nextPerm(words[i]) << endl;
    }

    return 0;
}

string nextPerm(string word)
{
    int i = word.size() - 1;
    int j = word.size() - 1;

    while( word[i] <= word[i - 1] && i > 0)
    {
        i--;
    }

    if(i == 0)
    {
        return "no answer";
    }

    while(word[j] <= word[i - 1])
    {
        j--;
    }

    swap(word[j], word[i - 1]);

    reverse(word.begin() + i, word.end());

    return word;
}
