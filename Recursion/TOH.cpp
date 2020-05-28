#include <iostream>
#include <stdlib.h>
using namespace std;
int count = 0;
void TOH(int n, char src , char aux, char dest)
{
	if (n==1)
	{
		++count;
		std::cout << src << "->" << dest << std::endl;
		return;
	}	
	TOH(n-1,src,dest,aux);
	TOH(1,src,aux,dest);
	TOH(n-1,aux,src,dest);
}

int main (int argc , char* argv[])
{
	char doContinue = 'y' ;
	while (doContinue == 'y')
	{
		count = 0 ;
		system("clear");
		int n ;
		cin >> n ; 
		TOH(n,'a','b','c');
		std::cout<<"No. of moves "<<count<< std::endl;
		std::cout << "Wanna try again, y or n?"<<std::endl;
		cin >> doContinue ;
	}
	
}