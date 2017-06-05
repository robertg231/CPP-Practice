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


//given a string find the next lexicographical permutation
//so we want to increase the sequence as little as possible
string nextPerm(string word)
{
    int i = word.size() - 1;

    //first find longest increasing sequence starting from the right. travel left
    //so find smallest(aka leftmost) index where
    //valBefore >= someVal starting at the right end and travel to the left
    while( word[i - 1] >= word[i] && i > 0)
    {
        i--;
    }
    //the sequence from i - end is considered the suffix
    //it is decreasing(from left to right) ex: 544321, 886421, etc

    //if we reach the start of the string then the whole
    //string is non increasing. so there is no next larger value
    if(i == 0)
    {
        return "no answer";
    }

    //we choose a pivot that will be swapped. the pivot is at i-1(to the left of i)
    //we also need to find the rightmost value that is larger than the pivot
    int j = word.size() - 1;
    //so we loop starting from the right side and stop when our value at j is larger than pivot
    while(word[j] <= word[i - 1])
    {
        j--;
    }

    //this swap will increase the prefix
    //cause we are swapping the pivot with a larger value
    swap(word[j], word[i - 1]);

    //we reverse the suffix(aka i - end) to make it as low as we can
    //because we increased the prefix
    //originally the suffix was non increasing(aka as large as it could get)
    //so by reversing it we make it as small as it can get
    reverse(word.begin() + i, word.end());

    return word;
}
