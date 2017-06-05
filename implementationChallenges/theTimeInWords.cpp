//i'm gunna hate this code :(       --11:06PM
// done... i took too long to find my error.
// i missed a space in like two parts. smh...  -- 11:38

#include<iostream>
#include<string>

using namespace std;

void printTimeWords(int hh, int mm);
string getWord(int num);

int main()
{
    int hh;
    int mm;
    cin >> hh >> mm;

    printTimeWords(hh, mm);

    return 0;
}

void printTimeWords(int hh, int mm)
{
    if(mm == 0)
    {
        cout << getWord(hh) << " o' clock";
    }
    else if(mm == 1)
    {
        cout << getWord(mm) << " minute past " << getWord(hh);
    }
    else if(mm == 15)
    {
        cout << "quarter past " << getWord(hh);
    }
    else if(mm == 30)
    {
        cout << "half past " << getWord(hh);
    }
    else if(mm == 45)
    {
        cout << "quarter to " << getWord(hh + 1);
    }
    else if(mm == 59)
    {
        cout << getWord(60 - mm) << " minute to " << getWord(hh + 1);
    }
    else if(mm < 30)
    {
        cout << getWord(mm) << " minutes past " << getWord(hh);
    }
    else //(mm < 60)
    {
        cout << getWord(60 - mm) << " minutes to " << getWord(hh + 1);
    }
}

string getWord(int num)
{
    switch(num)
    {
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
        case 10: return "ten";
        case 11: return "eleven";
        case 12: return "twelve";
        case 13: return "thirteen";
        case 14: return "fourteen";
        case 15: return "fifteen";
        case 16: return "sixteen";
        case 17: return "seventeen";
        case 18: return "eighteen";
        case 19: return "nineteen";
        case 20: return "twenty";
        case 21: return "twenty one";
        case 22: return "twenty two";
        case 23: return "twenty three";
        case 24: return "twenty four";
        case 25: return "twenty five";
        case 26: return "twenty six";
        case 27: return "twenty seven";
        case 28: return "twenty eight";
        case 29: return "twenty nine";
        default: return "";
    }
}
