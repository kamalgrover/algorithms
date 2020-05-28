// minimum and Second minimum 

#include <iostream> 
using namespace std;

// Divide the Array in 2 equal parts . 
// Calculate the Min and SMin from both the parts 
// Compare the Results to combine the solution 

typedef struct 
{
	int first;
	int second;
} Mins;

void MinSecMin(int* a, int left, int right, Mins& res)
{
	//cout << "Left : "<<left << ", Right : " << right << endl;
	int mid = left + (right - left) / 2;
	// Base Conditon
	if (left == right)
	{
		res.first = res.second = a[left];
		//cout << "size 1~ "<<res.first << " " << res.second << endl;
		return;
	}

	if (right - left == 1 )
	{
		if (a[left] < a[right])
		{
			res.first = a[left];
			res.second = a[right];
		}
		else
		{
			res.first = a[right];
			res.second = a[left];
		}

		//cout << "size 2~ "<<res.first << " " << res.second << endl;
		return;
	}

	//Divide // Recurse 
	Mins ResLeft;
	MinSecMin(a,left, mid, ResLeft);
	Mins ResRight;
	MinSecMin(a, mid + 1 , right, ResRight);

	int candidate1;
	int candidate2;
	// Conquer // Combine
	if (ResLeft.first < ResRight.first)
	{
		res.first = ResLeft.first;
		candidate1 = ResLeft.second;
		candidate2 = ResRight.first;
	}
	else
	{
		res.first = ResRight.first;
		candidate1 = ResRight.second;
		candidate2 = ResLeft.first;
	}

	(candidate1 < candidate2) ? 
		res.second = candidate1 : res.second = candidate2;

	//cout << "after Combine~ "<<res.first << " " << res.second << endl;
	return;

}
int main ()
{
	int a [] = {1,2,3,4,5,6};
	int size = sizeof (a)/sizeof(a[0]);
	Mins res ;
	MinSecMin (a,0, size - 1, res);
	cout << "Min "<< res.first << " SMin " << res.second << endl; 
	return 0;
}