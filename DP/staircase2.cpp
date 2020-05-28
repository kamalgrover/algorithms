//Problem:  you are climbing a stair case. It takes N steps to reach to the top.
//          Each time you take either one step or two steps. In how many distinct
//          ways can you climb to the top. At most k jumps

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
int solveStairCase(int N, int K, vector<vector<int>> &DP)
{
    //DP[i][k] : no of ways to reach the level i in k steps.
    // no of ways to reach the zeroth level in 1 or more steps is 0;
    for (int k = 1; k <= K; k++)
    {
        DP[0][k] = 0;
    }
    // no of ways to reach any level in 0 steps is 0 for all levels except 0(where it is 1)
    for (int i = 1; i <= N; i++)
    {
        DP[i][0] = 0;
    }
    //no of ways to the zeroth level in zero steps is  1
    DP[0][0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int k = 1; k <= K; k++)
        {
            DP[i][k] = ((i - 1 >= 0) ? DP[i - 1][k - 1] : 0) + ((i - 2 >= 0) ? DP[i - 2][k - 1] : 0);
        }
    }
    int ans = 0;
    for (int k = 0; k <= K; k++)
    {
        ans = ans + DP[N][k];
    }
    return ans;
}
int main()
{
    int N, K;
    cin >> N >> K;
    vector<vector<int>> DP(N + 1, vector<int>(K + 1, 0));
    cout << solveStairCase(N, K, DP) << endl;
    return 0;
}