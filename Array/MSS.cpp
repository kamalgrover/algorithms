// Compute the maximum sum subarray

#include <iostream>
#include <algorithm>

using namespace std;

int MSS(int* a, int size)
{
	bool isAlLNegative = true;
	int maximum= a[0];
	for (int i = 0 ; i < size ; i++)
	{
		if(a[i] >= 0)
			isAlLNegative=false;
		
		if (a[i] > maximum)
			maximum = a[i];
	}

	if (isAlLNegative)
		return maximum;


	int glob_max = a[0];
	int cur_max = 0;

	for (int i = 0 ; i < size ; i++)
	{
		if (cur_max + a[i] > 0 )
			cur_max += a[i];
		else
			cur_max = 0 ;
		glob_max = max(cur_max,glob_max);
	}
	return glob_max;
}

int main ()
{
	int N;
	cout << "Enter N ";
	cin >> N ;
	for (int i = 0 ; i < N ; i++)
	{
		int size ;
		cin >> size;
		int a[size];
		for (int j = 0 ; j < size ; j++)
		{
			cin >> a[j];
		}

		cout << MSS(a,size) << endl;
	}
	return 0;
}