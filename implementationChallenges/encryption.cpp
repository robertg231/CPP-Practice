//given a line of text encrypt it.
//encryption scheme:
//1. remove spaces
//2. L = length of text(after spaces removed)
//3. characters are written into a grid
//4. grid = floor(sqrt(L)) <= row <= col <= ceil(sqrt(L))
//5. ensure that row * col >= L
//6. if multiple grids can be made, choose the one with minimum area
//7. encoded message is printed by printing the chars in a column
//      then inserting a space then printing next column and so on
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    //we will be given a message with no spaces between words.
    //max length of message is 81 chars

    string message;

    cin >> message;

    int length = message.size();

    int row = floor(sqrt(length));
    int col = ceil(sqrt(length));

    if(!(row * col > length))
    {
        row++;
    }

    char** messageGrid = new char*[row];
    for(int i = 0; i < row; i++)
    {
        messageGrid[i] = new char[col];
    }

    int k = 0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col && k < length; j++)
        {
            messageGrid[i][j] = message[k++];
        }
    }


    for(int i = 0; i < col; i ++)
    {
        for(int j = 0; j < row; j++)
        {
            if(messageGrid[j][i] == '\0')
            {
                continue;
            }
            cout << messageGrid[j][i];
        }
        cout << ' ';
    }

    return 0;
}
