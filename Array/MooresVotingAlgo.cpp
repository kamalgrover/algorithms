//Mooore's Voting Algorithm

#include <iostream>

int majorityElement(int*a, int size)
{
	int count = 1;
	int imajor = 0;
	//Find the majority element
	for (int i = 0 ; i < size ; i++)
	{	
		if (a[imajor] == a[i])
		{
			count++;
		}
		else
		{
			count--;
		}
		if (count <= 0)
		{
			imajor = i;
			count = 1 ;
		}

	}
	std::cout << "Candidate" << a[imajor] <<  std::endl;
	//check if it is valid 
	int majorityCount = 0 ;
	for ( int i = 0 ; i < size ; i++)
	{
		if(a[i] == a[imajor])
		{
			majorityCount++;
		}
	}

	if(majorityCount > size/2 )
	{
		std::cout << imajor <<std::endl;
		return imajor;
	}
	else
		return -1;
}

int main()
{
	//int a[] = {0};
	//int a[] = {0,1,1};
	//int a[] = {0,1,0};
	//int a[] = {0,0,0};
	//int a [] = {2,3,4,2,4,2,5,6,4,4,4,8,4,4,5,4,5,1,2,3,4};	
	//int a [] = {4,2,4,2,5,6,4,4,4,8,4,4,5,4};	
	//int a[] = {3 ,3, 4, 2, 4, 4, 2, 4, 4};
	//int a[] = {3 ,3, 4, 2, 4, 4, 2, 4};
	//int a[] = {1, 1, 1, 1, 1, 2, 3, 4};
	
	int a[] = { 2, 2, 3, 5, 2, 2, 6};

	//int a [] = {1, 3, 3, 1, 2};
	int out = 0 ;
	if ( (out = majorityElement(a, sizeof(a)/sizeof(a[0])) )!= -1)
		std::cout << a[out] << std::endl;
	else
	{
		std::cout << "Not found;" << std::endl;
	}
	return 0;
}