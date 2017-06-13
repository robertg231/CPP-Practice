#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class Solution
{
private:
    stack<char> myStack;
    queue<char> myQueue;

public:
    void pushCharacter(char ch);
    void enqueueCharacter(char ch);

    char popCharacter();
    char dequeueCharacter();
};

void Solution::pushCharacter(char ch)
{
    myStack.push(ch);
}

void Solution::enqueueCharacter(char ch)
{
    myQueue.push(ch);
}

char Solution::popCharacter()
{
    char ch = myStack.top();
    myStack.pop();
    return ch;
}

char Solution::dequeueCharacter()
{
    char ch = myQueue.front();
    myQueue.pop();
    return ch;
}

int main()
{
    string s;
    getline(cin,s);
     Solution obj;

     for(int i = 0; i < s.length(); i++)
     {
         obj.pushCharacter(s[i]);
         obj.enqueueCharacter(s[i]);
     }

     bool isPalindrome = true;

     for(int i = 0; i < s.length() / 2; i++)
     {
         if(obj.popCharacter() != obj.dequeueCharacter())
         {
             isPalindrome = false;
             break;
         }
     }

     if(isPalindrome)
     {
         cout << "The word, " << s << ", is a palidnrome.";
     }
     else
     {
         cout << "The word, " << s << ", is not a palindrome.";
     }

    return 0;
}
