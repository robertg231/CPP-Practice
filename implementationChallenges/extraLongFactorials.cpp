#include<iostream>
#include<climits>

using namespace std;

void multiply(int* number, int& numberSize, int number2);

int main()
{
    int num;
    cin >> num;

    const int maxDigits = INT_MAX;

    int* answer = new int[maxDigits]{0};

    int numDigits = 1;

    //we are setting answer to zero
    //but we are storing the numbers in reverse
    // 592 == array{2,9,5}
    answer[0] = 1;

    //multiplying factorial. 2 * 3 *....* num
    for(int i = 2; i <= num; i++)
    {
        multiply(answer, numDigits, i);
    }

    //cout << "digits: " << numDigits << endl;

    for(int i = numDigits - 1; i > -1; i--)
    {
        cout << answer[i];
    }



    return 0;
}

void multiply(int* number, int& numberSize, int number2)
{
    int carry = 0;
    int product;

    //iterate through each number to multiply
    for(int i = 0; i < numberSize; i++)
    {
        product = (number[i] * number2) + carry;
        number[i] = product % 10;
        carry = product / 10;
    }

    while(carry)
    {
        number[numberSize] = carry % 10;
        carry /= 10;
        numberSize++;
    }
}
