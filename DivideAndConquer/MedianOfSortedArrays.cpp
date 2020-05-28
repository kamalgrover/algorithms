//Median of 2 Sorted Arrays

#include <iostream>
#include <vector>

using namespace std;

int medianOfSorted(int* left, int* right, int size)
{
	int m1 = size / 2, m2 = size / 2;
	cout << size << " " << m1 << endl;
	if ( size == 1 )
		return ( left[0] + right[0] ) / 2 ;
	if ( size == 2 )
	{
		return ( max(left[0],right[0]) + min(left[1], right[1]) ) / 2 ;
	}
	if (left[m1] == right[m2])
	{
		return left[m1];
	}

	if ( left[m1] < right [m2] )
	{
		//median lies in the arrays 
		//left [m1 ... end] and right [0...m2]

		medianOfSorted(left+m1, right , size/2 + 1);

	}
	else if ( left[m1] > right[m2] )
	{
		// median lies in the arrays
		//left [0...m1] and right [m2...end]
		
		medianOfSorted(left, right+m2 , size/2 + 1);
	}

}

int main ()
{
	int a[] = {1,5,7,20,21};
	int b[] = {3,4,29,30,31};
	
	// int a[] = {1};
	// int b[] = {2};
 
	// int a[] = {1,3};
	// int b[] = {2,4};

	// int a[] = {1,3,5};
	// int b[] = {2,4,6};
	

	// vector<int> left (a, sizeof(a)/sizeof(a[0]));
	// vector<int> right (b, sizeof(b)/sizeof(b[0]));
	
	int size = sizeof(a) /sizeof(a[0]);
	cout << medianOfSorted(a,b,size);
	
	return 0;
}