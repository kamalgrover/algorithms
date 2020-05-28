// int to hex

#include <iostream>
#include <sstream>
#include <string>

using namespace std;


int main()
{
	int in = 0;
	stringstream ss ;
	ss << std::hex << in ;
	std::string res (ss.str());

	cout << res;
	return 0;
}