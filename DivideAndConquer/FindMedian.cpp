//Find Median in linear Time .

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int FindRank(int r, int* A, int N);

int median(int x)
{
    return ceil((float)x / 2) - 1;
}

//Copy array A into B
void copyArray(int *A, int N, int* B)
{
    for (int i = 0; i < N; i++)
        B[i] = A[i];
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* a, int size, int pivot)
{
    int* left = a;
    int* right = a + size - 1; 
    int* ipivot = left;
    
    for (; ipivot <= right; ipivot++)
    {
        if (*ipivot == pivot)
        {
            break;
        }
    }

    swap(ipivot, right);
    int* i = left;
    int* j = right;

    while (i < j)
    {
        if (*i < pivot)
        {
            i++;
        }
        else
        {
            swap(i, j- 1);
            j--;
        }
    }

    swap(j, right);

    return j-a;

}

// Calculate approx Median , say x
// if x == r - 1  return x;
// if x > r - 1 Recursively Find the element of rank r in arr begin to x
// if x < r - 1 Recursivel find the element of new rank in right part  

int FindApproxMedian(int* A, int N)
{
    int* ACopy = (int *)malloc(N * sizeof(int));

    copyArray(A, N, ACopy);

    int numGroups = ceil((float)N / 5);

    int* Medians = (int *)malloc(numGroups * sizeof(int));

    int numFullGroups = N / 5;
    int numEltInLastGroup = N % 5;

    for (int i = 0; i < numFullGroups; i++)
    {
        int* start = ACopy + (5 * i);
        sort(start, start + 5);
        Medians[i] = *(start + median(5));
    }

    if (numEltInLastGroup != 0)
    {
        int* start = ACopy + (numFullGroups * 5);
        sort(start, start + numEltInLastGroup);
        Medians[N / 5] = *(start + median(numEltInLastGroup));
    }

    delete ACopy;

    int medOfMeds = FindRank(median(numGroups), Medians, numGroups);
    if (medOfMeds != -1)
    {
        int num = Medians[medOfMeds];
        delete Medians;
        return num;
    }

    return -1;

}

// divide in groups of 5 and calculate median of each group using any sorting algorithm and put it in array B of size n/5
// Recursively find the exact median of B of size size n/5, This is the approx median
// Find it's position in original array. That is the location of approx median , i.e x
int FindRank(int r, int* A, int N)
{
    //Error Case
    if (r >= N) return -1;

    // base Conditions
    if (N == 1) return r;

    //Calculate approx Median , say x
    int num = FindApproxMedian(A, N);
    if (num == -1) return -1;

    int ipivot = partition(A, N, num);

    if (ipivot == r) return ipivot;
    if (ipivot > r)
        return FindRank(r, A, ipivot);
    if (ipivot < r)
        return FindRank(r - ipivot, A + (ipivot + 1), N - (ipivot + 1));

}

int FindMedian(int* A, int N)
{
    return FindRank(median(N), A, N);
}

int main()
{

    //int a[] = { 3, 2, 1, 4, 5 };
    int a[] = {11,9,23,0,3,2,4,5};
    int size = sizeof(a) / sizeof(a[0]);
    int imedian = FindMedian(a, size);
    if (imedian != -1)
        cout << "Median Element : a[" << imedian << "] = " << a[imedian] << endl;
    else
        cout << "error!!" << endl;

    return 0;
}