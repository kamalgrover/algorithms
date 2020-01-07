//https://www.techiedelight.com/shortest-common-supersequence-finding-scs/

#include <iostream>
#include <vector>
#include <string>
#include <set>
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
int scsLength(string &x, string &y, vector<vector<int>> &dp)
{
    const int lenx = x.length();
    const int leny = y.length();

    // int dp[i][j] : min size of the supersequence for x[1..i] and y[1..j]
    //Base case
    for (int i = 1; i <= lenx; i++)
        dp[i][0] = i;
    for (int j = 1; j <= leny; j++)
        dp[0][j] = j;

    for (int i = 1; i <= lenx; i++)
    {
        for (int j = 1; j <= leny; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    return dp[lenx][leny];
}
string findSingleSCS(string &x, string &y, vector<vector<int>> &dp, int m, int n)
{
    //Base Cases
    if (m <= 0)
    {
        return y.substr(0, n);
    }
    if (n <= 0)
    {
        return x.substr(0, m);
    }

    if (x[m - 1] == y[n - 1])
    {
        return findSingleSCS(x, y, dp, m - 1, n - 1) + x[m - 1];
    }
    else
    {
        if (dp[m - 1][n] <= dp[m][n - 1])
        {
            return findSingleSCS(x, y, dp, m - 1, n) + x[m - 1];
        }
        else
        {
            return findSingleSCS(x, y, dp, m, n - 1) + y[n - 1];
        }
    }
}
vector<string> findAllSCS(string &x, string &y, vector<vector<int>> &dp, int m, int n)
{
    if (m == 0)
    {
        vector<string> v;
        v.push_back(y.substr(0, n));
        return v;
    }
    if (n == 0)
    {
        vector<string> v;
        v.push_back(x.substr(0, m));
        return v;
    }
    if (x[m - 1] == y[n - 1])
    {
        vector<string> v = findAllSCS(x, y, dp, m - 1, n - 1);
        for (auto &s : v)
        {
            s += x[m - 1];
        }
        return v;
    }
    if (dp[m - 1][n] < dp[m][n - 1])
    {
        vector<string> v = findAllSCS(x, y, dp, m - 1, n);
        for (auto &s : v)
        {
            s += x[m - 1];
        }
        return v;
    }
    if (dp[m - 1][n] > dp[m][n - 1])
    {
        vector<string> v = findAllSCS(x, y, dp, m, n - 1);
        for (auto &s : v)
        {
            s += y[n - 1];
        }
        return v;
    }

    //chose left path
    vector<string> top = findAllSCS(x, y, dp, m - 1, n);
    for (auto &s : top)
    {
        s += x[m - 1];
    }
    //chose top path
    vector<string> left = findAllSCS(x, y, dp, m, n - 1);
    for (auto &s : left)
    {
        s += y[n - 1];
    }
    //merge solutions from both the paths and return
    copy(left.begin(), left.end(), back_inserter(top));
    return top;
}
set<string>SCS(string &x, string&y)
{
    const int lenx = x.length();
    const int leny = y.length();
    vector<vector<int>> dp(lenx + 1, vector<int>(leny + 1, 0));
    scsLength(x, y, dp);
    vector<string> s = findAllSCS(x, y, dp, lenx + 1, leny + 1);
    set<string> result(s.begin(), s.end());
    return result;
}
int main()
{

    /**
     * 
     *  7
        6
        A B C B D A B
        B D C A B A

     */
    int lenx, leny;
    cin >> lenx;
    cin >> leny;
    string x(lenx, '0');
    string y(leny, '0');
    for (int i = 0; i < lenx; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < leny; i++)
    {
        cin >> y[i];
    }
    set<string> scs = SCS(x, y);
    for (auto &s : scs)
        cout << s << endl;
    return 0;
}