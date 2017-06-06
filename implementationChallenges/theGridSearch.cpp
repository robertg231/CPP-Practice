//I DID ITTTTT

#include <iostream>
#include <string>

using namespace std;

string gridSearch();
void printGrid(string* someGrid, int rows);

int main()
{
    int testCases;
    cin >> testCases;

    string* answers = new string[testCases];

    for(int i = 0; i < testCases; i++)
    {
        answers[i] = gridSearch();
    }

    for(int i = 0; i < testCases; i++)
    {
        cout << answers[i] << endl;
    }

    return 0;
}

string gridSearch()
{
    int rowsG;
    int columnsG;
    cin >> rowsG >> columnsG;

    string* theGrid = new string[rowsG];

    for(int i = 0; i < rowsG; i++)
    {
        cin >> theGrid[i];
    }

    int rowsP;
    int columnsP;

    cin >> rowsP >> columnsP;

    string* thePattern = new string[rowsP];

    for(int i = 0; i < rowsP; i++)
    {
        cin >> thePattern[i];
    }

    //AFTER HERE SOMETHING GOES WRONG
    bool inGrid;

    int rowMatch;
    int columnMatch;


    int reCheckIndex = 0;

    for(int i = 0; i < rowsG; i++)
    {
        inGrid = false;
        columnMatch = theGrid[i].find(thePattern[0], reCheckIndex);


        if( columnMatch != string::npos)
        {
            rowMatch = i;
            inGrid = true;
            for(int j = 1; j < rowsP; j++)
            {
                int pColumnMatch = theGrid[rowMatch + j].find(thePattern[j], columnMatch);
                if(pColumnMatch == string::npos || columnMatch != pColumnMatch)
                {
                    inGrid = false;
                    break;
                }
            }

        if(!inGrid && columnMatch < theGrid[0].size())
        {
            i--;
            reCheckIndex = ++columnMatch;
            continue;
        }

        }

        if(inGrid)
        {
            return "YES";
        }

        reCheckIndex = 0;
    }

    return "NO";

}


void printGrid(string* someGrid, int rows)
{
    for(int i = 0; i < 5; i++)
    {
        cout << "////////////////////////////////" << endl << "test start" << endl;
    }
    for(int i = 0; i < rows; i++)
    {
        cout << someGrid[i] << endl;
    }

    for(int i = 0; i < 5; i++)
    {
        cout << "////////////////////////////////" << endl << "test end" << endl;
    }
}
