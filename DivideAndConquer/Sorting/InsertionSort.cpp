// Insertion Sort By Recursion 
// Divide and Conquer 

#include <iostream>
using namespace std;

void printArray(int* A, int size)
{
	for (int i = 0 ; i < size ; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

int binarySearch (int* A, int left , int right, int num)
{
	while ( left <= right )
	{
		if (num < A[left])
			return left;
		if (num >= A[right])
			return right + 1;
		
		int mid = left + ( right - left )/2;
		
		if ( A[mid] < num and A[mid+1] >= num )
		{
			return mid+1;
		} 
		else if (A [mid] < num )
		{
			left = mid + 1;
		}
		else if ( A[mid] > num )
		{
			right = mid - 1;
		}
	}
	return -1;
}

void insertionSort(int* A, int left, int right)
{
	int size = right - left + 1;
	
	if (left == right)
		return;

	insertionSort( A, left, right - 1 );
	
	//printArray (A,size);

	int lastnum = A[right];

	//use binary search to find the position if the last element
	int index = binarySearch(A,left,right - 1 , lastnum );
	
	//cout << "insert at "<<index <<endl;
	
	//insert the element
	for ( int i = right ; i > index ; i-- )
	{
		A[i] = A[i-1];
	}
	A[index] = lastnum;

}

int main ()
{
	int A [] = {4,55,5,1};
	//int A[] = {3};
	int size = sizeof(A)/sizeof(A[0]);
	//cout  << binarySearch(A,0,size -1,4) << endl;return 0;
	insertionSort(A,0,size-1);
	printArray (A,size);
	return 0;
}