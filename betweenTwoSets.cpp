#include <iostream>
using namespace std;

int main()
{
  int sizeA;
  int sizeB;

  cin >> sizeA >> sizeB;

  int *A = new int[sizeA];
  int *B = new int[sizeB];

  for (int i = 0; i < sizeA; i++)
  {
    cin >> A[i];
  }

  for (int i = 0; i < sizeB; i++)
  {
    cin >> B[i];
  }

  // constraints
  // 1 <= n,m <= 10
  // 1 <= A[i] <= 100
  // 1 <= B[i] <= 100

  int factors = 0;
  bool isFactor;

  for (int i = 1; i < 101; i++)
  {
    isFactor = true;

    for (int j = 0; j < sizeA; j++)
    {
      if (i % A[j] != 0)
      {
        isFactor = false;
        break;
      }
    }

    if (!isFactor)
    {
      continue;
    }

    for (int k = 0; k < sizeB; k++)
    {
      if (B[k] % i != 0)
      {
        isFactor = false;
        break;
      }
    }

    if (isFactor)
    {
      factors++;
    }
  }

  cout << factors;

  return 0;
}
