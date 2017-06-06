// I DID IT ALL WRONGGGGGG
// ;_;
//(ノಠ益ಠ)ノ彡┻━┻
//ಠ╭╮ಠ
//┻━┻ ︵ヽ(`Д´)ﾉ︵ ┻━┻
// ᕙ(⇀‸↼‶)ᕗ
// ༼ つ ಥ_ಥ ༽つ
// （╯°□°）╯︵( .o.)

#include <iostream>
#include <string>

using namespace std;

string gridSearch();

int main()
{
    int testCases;
    cin >> testCases;

    string* answers = new string[testCases];

    for(int i = 0; i < testCases; i++)
    {
        answers->append(gridSearch());
    }

    for(int i = 0; i < testCases; i++)
    {
        cout << answers[i] << endl;
    }

    return 0;
}

string gridSearch()
{
    int rows;
    int columns;
    cin >> rows >> columns;

    char someChar;
    string theGrid;
    string thePattern;

    //build the grid
    for(int j = 0; j < rows; j++)
    {
        for(int k = 0; k < columns; k++)
        {
            cin >> someChar;
            theGrid.push_back(someChar);
        }
    }

    cin >> rows >> columns;
    //build the pattern
    for(int j = 0; j < rows; j++)
    {
        for(int k = 0; k <columns; k++)
        {
            cin >> someChar;
            thePattern.push_back(someChar);
        }
    }

    if(theGrid.find(thePattern) != string::npos)
    {
        return "YES";
    }

    return "NO";

}
