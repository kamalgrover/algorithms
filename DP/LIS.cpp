//https://www.techiedelight.com/longest-increasing-subsequence-using-dynamic-programming/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using namespace std;
template <class T>
void printA(const T &v)
{
    for (auto const &e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}
template <class T>
void printAA(const vector<vector<T>> &v)
{
    for (auto const &e : v)
    {
        printA(e);
    }
}

int lisLength(vector<int> &x, vector<int> &L)
{
    const int N = x.size();
    //int dp[i] be the length of the longest increasing subsequence ending at index i.
    //base case
    L[0] = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (x[i] > x[j])
            {
                L[i] = max(L[i], L[j]);
            }
        }
        L[i]++;
    }
    printA(L);
    return *max_element(L.begin(), L.end());
}
vector<int> getAsolution(vector<int> &x)
{
    vector<vector<int>> L(x.size(), vector<int>(0));
    //base case LIS of a single number sequence is itself;
    L[0].push_back(x[0]);
    for (int i = 1; i < x.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            
            
        }
    }
}
int main()
{
    /**
     * 16
     * 0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
     */
    int lenx;
    cin >> lenx;
    vector<int> x(lenx, '0');
    for (int i = 0; i < lenx; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < lenx; i++)
        cout << i << " ";
    cout << endl;
    vector<int> dp(lenx, 0);
    printA(getAsolution(x));
    return 0;
}