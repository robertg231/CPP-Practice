#include <iostream>
#include <string>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    //so after i cin >> cases there is a \n in cin
    cin.ignore(10000, '\n');

    string* words = new string[cases];

    for(int i = 0; i < cases; i++)
    {
        //according to cpp reference getline() consumes the \n
        //but cin >> doesn't so i have to "reset" the value in cin
        getline(cin, words[i]);
    }

    for(int i = 0; i < cases; i++)
    {
        string even = "";
        string odd = "";

        for(int j = 0; j < words[i].length(); j++)
        {
            if(j % 2 == 0)
            {
                even.push_back(words[i][j]);
            }
            else
            {
                odd.push_back(words[i][j]);
            }
            //will i have to worry about spaces???
        }
        cout << even << ' ' << odd << endl;
    }

    return 0;
}
