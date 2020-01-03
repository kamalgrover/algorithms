#include <iostream>
#include <limits>
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
int solver(vector<int> &W, vector<int> &V, int C, vector<vector<int>> &DP)
{
    // DP[i][c] : maximum value of the items picked so far till i and with remaining capacity c
    const int size = W.size();
    for (int i = 1; i <= size; i++)
    {
        for (int c = C; c > 0; c--)
        {
            DP[i][c] =  std::max(DP[i-1][c+W[i]] + V[i-1], DP[i-1][c]);
            cout << i << "," << c << "=" << DP[i][c] << " ";
        }
        cout << endl;
    }
    return DP[size][C];
}
int main()
{
    vector<int> W;
    vector<int> V;
    int C, N, temp;
    cin >> N >> C;
    int size = N;
    while (size--)
    {
        cin >> temp;
        V.push_back(temp);
    }
    size = N;
    while (size--)
    {
        cin >> temp;
        W.push_back(temp);
    }
    vector<vector<int>> DP(N + 1, vector<int>(C + 1, 0));
    cout << solver(W, V, C, DP) << endl;
    return 0;
}