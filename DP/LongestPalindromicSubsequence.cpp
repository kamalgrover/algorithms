//LongestPalindromicSubsequence
#include <string>
#include <iostream>
#include <map>
#include <utility>
using namespace std;


typedef map<pair<long,long>,long> LookupTable;

int LPS(const char* x, int sizex, LookupTable& lookup)
{
	pair<long,long> p((long)x,sizex) ;
	LookupTable::iterator itr = lookup.find(p);
	if (itr != lookup.end())
		return itr->second;

	
	int result;
	if (sizex <= 1)
		return sizex;

	if(x[0] == x[sizex-1])
	{
		result = 2 + LPS(x+1,sizex-2,lookup);
	}
	else
	{
		result = std::max(LPS(x,sizex-1,lookup),LPS(x+1,sizex-1,lookup));
	}
	lookup[p] = result;
	return result;
}
int main ()
{
	string s1;
	cin>>s1;
	
	LookupTable lookup;
	int length = LPS(s1.c_str(),s1.length(), lookup);
	cout << length << endl;
}