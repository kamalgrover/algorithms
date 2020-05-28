#include <iostream>
using namespace std;

int modifiedBinarySearch(int e, int* a, int left, int right)
{
	if (left <= right)
	{
		int mid = left + (right - left) / 2;
		if ( e == a[mid])
		{

			if (mid == left or a[mid-1] != e)
				return mid;
			
			return modifiedBinarySearch(e,a,left,mid-1);
		}
		if ( e < a[mid] )
			return modifiedBinarySearch(e, a , left, mid -1);
		
		return modifiedBinarySearch(e,a, mid + 1, right);
	}
	return -1;
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
	int pos =	modifiedBinarySearch(e,a,0,size-1 );
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