#include <iostream>
#include <vector>
using namespace std;

vector<int> FindMinMax(vector<int>& v, int left, int right )
{
	vector<int> result (2,0) ;

	int mid = left + (right - left) / 2; //(left + right) /2  
	
	// Error Case ?? Wrong Input
	if (left == right) //v.size() == 1
	{
		result[0] = v[left];
		result[1] = v[right];
		cout << "~Left "<<left << " Right " << right << " "<<  result[0] << " " << result[1] <<endl;
		return result;
	}

	//Base Condition
	if ( right - left == 1) // v.size() == 2
	{
		if (v[left] < v[right])
		{
			result[0] = v[left];
			result[1] = v[right];
		}
		else
		{	
			result[0] = v[right];
			result[1] = v[left];
		}
		cout << "Left "<<left << " Right " << right << " "<<  result[0] << " " << result[1] <<endl;
		return result;
	}

	//recursive Step
	vector<int> resLeft = FindMinMax(v, 0,mid);
	vector<int> resRight = FindMinMax(v, mid+1 , right);

	//Combine step to get Solution
	int minimum = min (resLeft[0],resRight[0]);
	int maximum = max(resLeft[1],resRight[1]);
	
	result[0] = minimum;
	result[1] = maximum;

	cout << result[0] << " " << result[1] <<endl;
	
	return result;
}
int main()
{
	//int a [] = {1,2,3,4,5};
	// int a [] = {5,4,3,2,1};
	//int a [] = {1,1,1,1,1};
	// int a [] = {1};
	// int a [] = {2,1};
	int a [] = {2,4,1,45,3,1};

	int size = sizeof(a) / sizeof(a[0]) ;
	vector<int>v(a, a+size);
	vector<int>res;
	res = FindMinMax(v,0, size-1);
	cout << res[0] << " " << res[1] <<endl;
	return 0;
}