//CutRodIterative
//https://www.techiedelight.com/rot-cutting/
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
int solve(int C, vector<int> len, vector<int> price, vector<int> dp)
{
    cout << "Total length  =  " << C << endl;
    printVec(len);
    printVec(price);
    
    const int size = len.size();
    dp[0] = 0;
    for (int i = 1; i <= C; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], price[j-1] + dp[i - len[j-1]]);
        }
    }
    printVec(dp);
    return dp[C];
}
int main(int argc, char const *argv[])
{
    int N;
    int C;
    cin >> C;
    cin >> N;
    vector<int> len(N, 0);
    vector<int> price(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> len[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> price[i];
    }
    vector<int> dp(C + 1);
    cout << "\nMax Profit = " << solve(C, len, price, dp) << endl;
    return 0;
}
