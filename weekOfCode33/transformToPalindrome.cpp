#include <bits/stdc++.h>
#include <vector>
#include <map>

using namespace std;


bool isPalindrome(vector<int>& letters);


class Node
{
private:
    Node* parent;
    int data;
    int rank;

public:
    Node(int newData = 0): parent(NULL), data(newData), rank(0)
    {}

    Node* getParent(){return parent;}
    int getData(){return data;}
    int getRank(){return rank;}

    void setParent(Node* newParent){parent = newParent;}
    void setData(int newData){data = newData;}
    void setRank(int newRank){rank = newRank;}

    void print();
};

void Node::print()
{
    cout << "parent: " << parent << endl;
    cout << "data: " << data << endl;
    cout << "rank: " << rank << endl;
}

class UF
{
private:
    map<int, Node> sets;

public:
    UF(int size = 0);

    void makeSet(int newData);
    void Union(int a, int b);
    Node* find(int a);
    void print();
};

UF::UF(int size)
{
    for(int i = 1; i <= size; i++)
    {
        makeSet(i);
    }
}

void UF::print()
{
    for(int i = 1; i < sets.size() + 1; i++)
    {
        cout << "my address: " << &(sets[i]) << endl;
        cout << "Key: " << i << endl;
        cout << "Value: ";
        sets[i].print();
        cout << endl;
    }
}

void UF::makeSet(int newData)
{
    //Node* newNode = new Node(newData);
    Node newNode(newData);

    sets.emplace(newData, newNode);

    sets[newData].setParent(&(sets[newData]));
    //rank is defaulted to zero
}

void UF::Union(int a, int b)
{
    Node* parentA = find(a);
    Node* parentB = find(b);

    //if in same set do nothing
    if(parentA == parentB)
    {
        return;
    }

    if(parentA->getRank() >= parentB->getRank())
    {
        //if rank is equal we pick A to be "higher rank"
        if(parentA->getRank() == parentB->getRank())
        {
            parentA->setRank(parentA->getRank() + 1);
        }

        parentB->setParent(parentA);
    }
    //B has higher rank
    else
    {
        parentA->setParent(parentB);
    }

}

Node* UF::find(int a)
{
    Node* parent = sets[a].getParent();
    if(parent == &(sets[a]))
    {
        return parent;
    }

    sets[a].setParent(find(parent->getData()));

    return sets[a].getParent();
}



int main() {
    int n;
    int k;
    int m;
    //n = # of letters from 1 to n
    //k = # of transformations
    //m = # of elements in string
    cin >> n >> k >> m;

    UF transforms(n);

    //transforms.print();

    //following k lines denote transformations x->y
    for(int i = 0; i < k; i++)
    {
        int x;
        int y;
        cin >> x >> y;
        transforms.Union(x, y);
    }

    vector<int> letters(m);

    //following m lines are the string we will apply transformations to
    for(int i = 0; i < m; i++)
    {
       cin >> letters[i];
    }

    // cout << "it is " << isPalindrome(letters);

    // for(int i = 1; i < n; i++)
    // {
    //     transforms.find(i)->print();
    // }

    for(int i = 0; i < m; i++)
    {
        letters[i] = (transforms.find(letters[i]))->getData();
    }

    // cout << "PRINTING TRANSFORMED VALUES" << endl;
    // for(int r = 0; r < letters.size(); r++)
    // {
    //     cout << letters[r] << ' ';
    // }
    // cout << endl << endl << endl << endl;

    int lo = 0;
    int hi = letters.size() - 1;
    int i;
    int j;

    for(; lo < hi; lo++,hi--)
    {
        for(i = hi; i > lo; i--)
        {
            if(letters[lo] == letters[i])
            {
                break;
            }
        }

        for(j = lo; j < hi; j++)
        {
            if(letters[hi] == letters[j])
            {
                break;
            }
        }

        if(lo == i)
        {
            //erase?
            letters.erase(letters.begin() + i);
            lo--;
            continue;
        }
        else if(hi == j)
        {
            //erase?
            letters.erase(letters.begin() + j);
            lo--;
            continue;
        }

        int loDiff = hi - i;
        int hiDiff = j - lo;

        if(loDiff == hiDiff)
        {
            //found pair
            continue;
        }
        else if(loDiff < hiDiff)
        {
            letters.erase(letters.begin() + hi);
            lo--;
        }
        else
        {
            letters.erase(letters.begin() + lo);
            lo--;
        }

    }


    //cout << "Max palindrome size is " << letters.size() << endl;

    cout << letters.size() << endl;


    // cout << "PRINTING MODIFIED LETTERS" << endl;
    // cout << "m = " << m << endl;
    // for(int i = 0; i < m; i++)
    // {
    //     cout << letters.at(i) << ' ';
    // }

    return 0;
}

bool isPalindrome(vector<int>& letters)
{
    int i = 0;
    int j = letters.size() - 1;

    while(i < j)
    {
        if(letters[i++] != letters[j--])
        {
            return false;
        }
    }
    return true;
}
