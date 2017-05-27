#include<iostream>
#include<climits>

using namespace std;

int main()
{
	//given location 1 and velocity 1
	//then
	//given location 2 and velocity 2
	//find when(if at all) two kangaroos land on same spot
	//they start from 0 to inf

	long long k1, v1, k2, v2;

	cin >> k1 >> v1 >> k2 >> v2;

	bool same = false;

	//constraints
	//0 <= k1 < k2 <= 10000
	//1 <= v1 <= 10000
	//1 <= v2 <= 10000

	//using pure brute force :)
	for(int i = 0; i < INT_MAX; i++)
	{
		k1 += v1;
		k2 += v2;
		if(k1 == k2)
		{
			//kangaroos are in same spot
			same = true;
			break;
		}
	}	

	if(same)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}