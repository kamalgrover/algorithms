//Longest common subsequence
//iterative solution

#include <iostream>
#include <vector>
#include <string>
using namespace std;
void printA(vector<int> &a)
{
    const int N = a.size();
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}
void printAA(vector<vector<int>> &A)
{
    int R = A.size();
    for (int i = 0; i < R; i++)
    {
        printA(A[i]);
    }
    cout << endl;
}
int lcs(vector<int> &X, vector<int> &Y, vector<vector<int>> &DP)
{
    const int R = X.size();
    const int C = Y.size();

    // DP[i][j] : value of the longest common subsequence for X[1..i] Y[1..j]
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (X[i-1] == Y[j-1]) // because X and Y are 0 indexed and DP is 1 indexed
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else
            {
                DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
            }
        }
    }
    return DP[R][C];
}
int main()
{
    /* input
        7 6
        1 2 3 2 4 1 2
        2 4 3 1 2 1

        X M J Y A U Z
        M Z J A W X U
        7 7
        120 109 106 121 97 117 122
        109 122 106 97 119 120 117
    */

    int lenX, lenY;
    cin >> lenX;
    cin >> lenY;
    vector<int> X(lenX);
    vector<int> Y(lenY);
    int temp;
    for (int i = 0; i < lenX; i++)
    {
        cin >> temp;
        X[i] = temp;
    }
    for (int i = 0; i < lenY; i++)
    {
        cin >> temp;
        Y[i] = temp;
    }
    vector<vector<int>> DP(lenX + 1, vector<int>(lenY + 1, 0));
    cout << lcs(X, Y, DP) << endl;
    printAA(DP);
    return 0;
}