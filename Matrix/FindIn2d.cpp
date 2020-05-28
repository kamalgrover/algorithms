// sum of two in matrix 

#include <iostream>
#include <vector>

using namespace std;

vector<int> FindIn2D(vector<vector<int>>& a, int n)
{
	int left , right , top , bottom ;
	left = top = 0 ; 
	right = a[0].size()-1;
	bottom = a.size()-1;

//cout << top << " " << left << " " << bottom << " " << right << endl;

	int i = top ;
	int j = right;

	vector<int> res (0,0);

	while ((i >= top and i <= bottom) and (j >= left and j <= right))
	{
		if (a[i][j] < n)
		{
			i++;
		}	
		else if (a[i][j] > n)
			j--;
		else
		{
			res.push_back(i);
			res.push_back(j);
			break;
		}
//cout << i << " " << j <<endl;
	}
	return res;
}

int main()
{
	vector<vector<int>> a (0, vector<int>(0,0));

	a.push_back({1,2,3});
	a.push_back({4,5,6});
	a.push_back({7,8,9});

	int NUM = 0 ;

// for ( int i = 0 ; i < a.size(); i++)
// {
// 	for ( int j = 0 ; j < a[0].size() ; j++)
// 	{
// 		cout << a[i][j] << " ";
// 	}
// 	cout << endl;
// }
// cout << endl;
	vector <int> res = FindIn2D(a,NUM);
	
	if (res.size()!=0)
	{
		cout << "arr["<< res[0] << "][" << res[1] << "]=" << a[res[0]][res[1]] << endl;	
	}
	else
	{
		cout << "Not Found\n";
	}
	
	return 1;
}