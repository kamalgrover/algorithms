#include<iostream>
#include<vector>
using namespace std;

bool binarySearch(vector<int>& input, int val, int begin, int end)
{
	cout << begin<< " "<<end<< endl;
	int mid = begin + (end - begin)/2 ;

	if(begin > end ) return false;
	if(val == input[mid] ) return true;
	if(val > input[mid] ) 
		return binarySearch(input , val, mid+1, end);
	return binarySearch(input, val, begin, mid - 1 );
}

int binarySearch(vector<int>& input , int val )
{
	int begin = 0 ; 
	int end = input.size()-1;
	int mid = -1 ;

	while ( begin <= end)
	{
		cout << begin << " "<< end<<endl;
		mid = begin + ( end - begin ) / 2;
		if ( input[mid] == val )
		{
			break;
		}
		else if (input[mid] > val)
		{
			end = mid - 1;			
		}
		else
		{
			begin = mid + 1;
		}
		mid = -1 ;
	}
	return mid;
}
int findLeftmost(int target)
{

}
int findRightmost(int target)
{

}
vector<int> findTargetRange(vector<int>& input , int target)
{

}
int main()
{
	int a[] = {0,0,0,1,2,3,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,7,8,100} ;
	vector<int>inArr ( a, a + sizeof( a ) / sizeof( a[0] ) );
	int val = 8 ;

	cout<<binarySearch(inArr,val,0,inArr.size()-1)<<endl;
	cout<<"Iter : "<<binarySearch(inArr,val)<<endl;
			
}