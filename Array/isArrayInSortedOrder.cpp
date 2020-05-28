//IsArrayInSortedOrder

#include <iostream>
#include <vector>
using namespace std;

bool isArrayInSortedOrder(std::vector<int> &a)
{
	//This is a change 

	if (a.size() <= 1)
		return true;
	std::vector<int> b(a.begin()+1,a.end());
	return a[0] <= b[0] and isArrayInSortedOrder(b);
}
int main ()
{
	std::vector< std::vector<int> > a(0,std::vector<int>(0,0));
	
	a.push_back({});
	a.push_back({1});
	
	a.push_back({0,0});
	
	a.push_back({1,2});
	a.push_back({2,1});
	
	a.push_back({1,2,3});
	a.push_back({3,2,1});
	a.push_back({1,3,2});
	
	
	for (int i = 0 ; i < a.size() ; i++)
	{
		cout << isArrayInSortedOrder(a[i]) << " "; 
	}
	cout << endl;
}