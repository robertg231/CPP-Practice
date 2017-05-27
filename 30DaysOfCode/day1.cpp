#include<iostream>
#include<string>
#include<iomanip>

using namespace std;


int main()
{
  int i = 4;
  double d = 4.0;
  string s = "HackerRank ";

  int j;
  cin >> j;
  j += i;


  double e;
  cin >> e;
  e += d;

  string t;
  cin.ignore();
  getline(cin, t);
  t = s + t;

  cout << j << endl;

  cout << fixed;
  cout << setprecision(1);
  cout << e << endl;

  cout << t << endl;

  return 0;
}
