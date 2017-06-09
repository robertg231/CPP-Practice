#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Difference
{
private:
    vector<int> elements;

public:
    int maximumDifference;

    Difference(vector<int> newElements): elements(newElements)
    {}

    void computeDifference();

};

void Difference::computeDifference()
{
    sort(elements.begin(), elements.end());

    maximumDifference = elements.at(elements.size() - 1) - elements.at(0);
}

int main()
{
    int N;
    cin >> N;

    vector<int> a;

    for(int i = 0; i < N; i++)
    {
      int e;
      cin >> e;
      a.push_back(e);
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0;
}
