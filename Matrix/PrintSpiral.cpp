//Spiral 

#include <iostream>
#include <vector>

using namespace std;
void printSprial(vector<vector<int>> &a)
{
	int left, right , top , bottom ;
	left = top = 0;
	right  = a[0].size() - 1;
//cout << right << endl;
	bottom = a.size() - 1;
//cout << bottom << endl;
	while (left <= right and top <= bottom)
	{
		for (int j = left ; j <= right ; j++)
		{
			cout << a[top][j] << " ";
		}
		top++;
		for (int i = top ; i <= bottom ; i++)
		{
			cout << a[i][right]<<" ";
		}
		right--;
		for (int j = right ; j >= left ; j--)
		{
			cout << a[bottom][j]<<" ";
		}
		bottom--;
		for (int i = bottom ; i>= top ; i--)
		{
			cout << a[i][left] <<" ";
		}
		left++;
	}
	cout << endl ;
}
int main ()
{
	vector<vector<int>> a (0,vector<int>(0,0));
	a.push_back({1,2,3});
	a.push_back({4,5,6});
	a.push_back({7,8,9});
for ( int i = 0 ; i < a.size() ;i++)
{
	for (int j = 0 ; j < a[0].size() ;j++)
		cout << a[i][j] << " ";
	cout << endl;
}
cout << endl;

	printSprial(a);

}