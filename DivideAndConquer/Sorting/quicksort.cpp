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
void swap (int & a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(int *a, int l , int r)
{
//	cout <<"partition "<<l<<" "<<r<<endl ;
	int pivot = a[r];
	int i = l ; int j = r;
	while(i < j )
	{
		if (a[i] < pivot)
		{
			i++;
		}
		else
		{
			swap(a[i],a[j-1]);
//			print(a,l,r);
			j--;
		}

	}
//	cout << "before";print(a,l,r);
	swap ( a[j], a[r]);
//	print(a,l,r);
	return j;
}

void quicksort ( int *a, int l, int r)
{
//	cout <<l<<" "<<r<<endl ;
	if (r > l)
	{
		int p = partition(a,l,r);
		quicksort(a,l,p-1);
		quicksort(a,p+1,r);
	}
}

int main ()
{
	//int arr[] = {1};
	//int arr [] = {1,2,3,4,5,6};
	//int arr [] = {4,3,2,1} ;
	//int arr [] = {5,6,4,3,2,1} ;
	int arr [] = {11,9,23,0,3,2,4,3,2,5};
	int size = sizeof(arr)/sizeof(arr[0]);

	quicksort(arr,0, size-1 );
	
	cout << "Final Result ";print (arr, 0, size - 1);

}