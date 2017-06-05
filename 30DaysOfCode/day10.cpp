#include <iostream>
#include <string>
using namespace std;

string toBinary(int b10Num);

int main()
{
    int num;
    cin >> num;

    string binaryNum = toBinary(num);

    int ones = 0;
    int consecutiveOnes = 0;
    for(int i = 0; i < binaryNum.size(); i++)
    {
        if(binaryNum[i] == '1')
        {
            ones++;
        }
        else
        {
            ones = 0;
        }
        if(ones > consecutiveOnes)
        {
            consecutiveOnes = ones;
        }
    }

    cout << consecutiveOnes;
    return 0;
}


string toBinary(int b10Num)
{
    string binary;

    while(b10Num != 0)
    {
        binary.insert(0,to_string(b10Num % 2));
        b10Num /= 2;
    }

    return binary;
}
