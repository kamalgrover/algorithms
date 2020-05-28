//LongestCommonSubsequence

#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;
typedef map<pair<long,long>,long> LookupTable;
int LCS(string x, int sizex, string y, int sizey, LookupTable& lookup)
{
	pair<long,long> p(sizex,sizey);
	LookupTable::iterator itr = lookup.find(p);
	if (itr != lookup.end())
		return itr->second;

	int result = 0;
	if (sizex == 0)
		return 0;
	if (sizey == 0)
		return 0;

	if (x[sizex-1] == y[sizey-1])
	{
		result = 1+LCS(x,sizex-1,y,sizey-1,lookup);
	}
	else
	{
		result = std::max(LCS(x,sizex-1,y,sizey,lookup),LCS(x,sizex,y,sizey-1,lookup));
		
	}
	
	lookup[p]=result;

	return result;
}


int main()
{
	string X,Y;
	cin>>X>>Y;
	LookupTable lookup;
	int length = LCS(X,X.length(),Y,Y.length(),lookup);
	cout << length << endl;
}