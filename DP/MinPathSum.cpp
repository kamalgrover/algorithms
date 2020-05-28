// Problem:    Given a matirx, find a path from the top left to the bottom right corner
//             That minimizes the sum of numbers along the path, you can only move right or down;

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void printMatrix(vector<vector<int>> &A)
{
    int R = A.size();
    int C = A[0].size();
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}
int findMinCostPath(vector<vector<int>> &A, vector<vector<int>> &dp)
{
    int R = dp.size();
    int C = dp[0].size();
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (i > 0 and j > 0)
                dp[i][j] = A[i][j] + min (dp[i-1][j],dp[i][j-1]);
            else if (i == 0)
                dp [i][j] = A[i][j] + dp [i][j-1];
            else 
                dp [i][j] = A[i][j] + dp [i-1][j];
                       
        }
    }
    cout << endl;
    printMatrix(dp);
    return dp[R - 1][C - 1];
}
int main(int argc, char const *argv[])
{
    int R, C;
    cin >> R >> C;
    vector<vector<int>> inp(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> inp[i][j];
        }
    }
    vector<vector<int>> dp(R, vector<int>(C, 0));
    cout << findMinCostPath(inp, dp) << endl;
    return 0;
}
