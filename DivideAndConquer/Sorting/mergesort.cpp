//sMergeSort

#include <iostream>
using namespace std;

void print(int * arr, int start, int end)
{
	for (int i = start ; i <= end - start ; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;
}
// inplace merge . time complexity n squared.
// better solution is to copy the the parts 
//into auxilary array and merge back into the original array . 
//This way the aux space complexity will be O(n)
// If in place sorting is required the quicksort gives O(nlg(n) in average case
void merge (int *a, int i, int j , int end)
{

//cout << "merge" << i <<" "<<j<<" "<<end<<endl;
	while (i < j and j <= end )
	{

		if( a[i] <= a[j])
		{
			i++;
		}
		else
		{
			// insert a[j] at a[i] 
			int temp = a[j];
			int t = j ; 
			while (t > i )
			{
				a[t] = a[t-1];
				t--;
			}
			a[t] = temp;
			//increment both i and j
			i++;
			j++;

		}
	}

}
void mergesort(int *arr , int start, int end )
{
//	cout << start<< " "<<end<<" MergeSort ";print(arr,start, end);
	if (start >= end)
		return;
	
	int mid = start + (end - start)/2;

	mergesort(arr,start,mid);
	mergesort(arr,mid+1,end);	
	merge(arr,start, mid+1, end);


}


int main ()
{
	//int arr[] = {1};
	//int arr [] = {4,3,2,1} ;
	//int arr [] = {1,2,3,4,5,6};
	//int arr [] = {5,6,4,3,2,1} ;
	int arr [] = {11,9,23,0,3,2,4,3,2,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	mergesort(arr,0,size -1 );
	cout << "Final Result ";print (arr, 0, size - 1);
}