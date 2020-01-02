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
int solve(vector<int> &V, vector<int> &W, int C, vector<vector<int>> &DP)
{
    const int size = W.size();
    for (int i = 1; i <= size; i++)
    {
        for (int c = C; c > 0; c--)
        {
            DP[i][c] = std::max(DP[i - 1][c + W[i]] + V[i - 1], DP[i - 1][c]);
            cout << i << "," << c << "=" << DP[i][c] << " ";
        }
        cout << endl;
    }
    return DP[size][C];
}

int main()
{

    int T, N, W;
    vector<int> weights;
    vector<int> values;
    cin >> T;
    int temp;
    while (T--)
    {
        cin >> N;
        cin >> W;
        for (int i = 0; i < N; i++)
        {
            cin >> temp;
            values.push_back(temp);
        }
        for (int i = 0; i < N; i++)
        {
            cin >> temp;
            weights.push_back(temp);
        }
        vector<vector<int>> DP(N + 1, vector<int>(W + 1, 0));
        // printVec(weights);
        // printVec(values);
        // cout << W << endl;
        cout << solve(values, weights, W, DP) << endl;
        weights.clear();
        values.clear();
    }

    //code
    return 0;
}