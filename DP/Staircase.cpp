//Problem:  you are climbing a stair case. It takes N steps to reach to the top.
//          Each time you take either one step or two steps. In how many distinct
//          ways can you climb to the top.

#include <array>
#include <iostream>
#include <vector>
using namespace std;
void printVec(vector<int> &a)
{
    const int size = a.size();
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int solveStairCase(int N, vector<int> &DP)
{
    //DP[i] : Is the number of ways of climbing i stairs
    DP[0] = 1;
    DP[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        DP[i] = (DP[i - 1] + DP[i - 2]);
    }
    printVec(DP);
    return DP[N];
}
int main()
{
    int N;
    cin >> N;
    const int size = N;
    vector<int> DP(N + 1, 0);
    cout << solveStairCase(N, DP) << endl;
    return 0;
}