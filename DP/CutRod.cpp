//Rod Cutting

#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int CutRod(std::vector<int>& v, int N, vector<int>& lookup)
{
	int maxrevenue = INT_MIN;
	
	if (lookup[N] != 0) return lookup[N];

	if ( N == 0 )
		maxrevenue = 0;
	else
	{
		for (int i = 1 ; i <= N ; i++)
		{
			maxrevenue = std::max(maxrevenue,v[i-1]+CutRod(v,N-i,lookup));
		}
	}

	lookup[N] = maxrevenue;
	return maxrevenue;
}

int main()
{
	int N;
	cin>>N;
	int number ;
	std::vector<int> price;
	for (int i=0;i<N;i++)
	{
		int number ;
		cin >> number ;
		price.push_back(number);
	}
	vector<int> lookup(N+1,0) ;

	int maxrevenue = CutRod(price,N,lookup);
	
	cout << maxrevenue << endl;

	for(int i = 0 ; i < lookup.size();i++)
	{
		cout << lookup[i] << " ";
	}
	cout << endl;
}