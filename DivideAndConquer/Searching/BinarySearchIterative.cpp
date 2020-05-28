#include <iostream>
using namespace std;

int BinarySearchIterative(int e, int* a, int left, int right)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2 ;
		if (a[mid] == e )
		{
			return mid;
		}
		else if (e < a[mid])
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
}

int main()
{
	// int a [] = {1,2,2,4,5};
	// int e = 1;
	
	// int a [] = {1,2,2,4,5};
	// int e = 2;
	
	// int a [] = {1,2,2,4,5};
	// int e = 5;
	
	// int a [] = {1,2,2,4,5};
	// int e = 0;

	// int a [] = {3,4};
	// int e = 3;
	
	// int a [] = {3,4};
	// int e = 5;

	// int a [] = {3,3,4};
	// int e = 3;
	
	// int a [] = {3,4,4};
	// int e = 4;

	// int a [] = {1,1,2,2,3,4};
	// int e = 2;
	
	// int a [] = {1,1,2,2,2,2,2,2,2,3,4};
	// int e = 2;
	
	// int a [] = {1,1,2,2,3,4};
	// int e = 5;
	
	int a [] = {0,0,0,0};
	int e = 0;
	
	int size = sizeof (a) /sizeof(a[0]);
	int pos =	BinarySearchIterative(e,a,0,size-1 );
	if (pos != -1 )
	{
		cout <<"Found at first index" << pos << endl;
	}
	else
	{
		cout <<"Not Found";
	}
	return 0;
}