//Diff Utility
//https://www.techiedelight.com/implement-diff-utility/

#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <class T>
void printA(vector<T> &a)
{
    const int size = a.size();
    for (int i = 1; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
template <class K>
void printAA(vector<vector<K>> &a)
{
    const int m = a.size();
    for (int i = 1; i < m; i++)
    {
        printA(a[i]);
    }
}

//we need to define notation in path array.
// path[i][j = 'L' means coming from left
// path[i][j = 'U' means coming from left
// path[i][j = 'D' means coming from left

int solve(string &x, string &y, vector<vector<int>> &dp, vector<vector<char>> &path)
{
    const int lx = x.size();
    const int ly = y.size();
    //base case dp[i][0] = 0 and dp[0][j] = 0 taken care by way of init

    for (int i = 1; i <= lx; i++) // caution : dp and paths is indexed with 1
    {
        for (int j = 1; j <= ly; j++) // caution : dp and paths is indexed with 1
        {

            if (x[i - 1] == y[j - 1]) // caution : dp and paths is indexed with 1
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                path[i][j] = 'D';
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                    path[i][j] = 'U';
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    path[i][j] = 'L';
                }
            }
        }
    }
    return dp[lx][ly];
}
string diff(string &x, string &y, string &lcs)
{
    const int lx = x.length();
    const int ly = y.length();
    int k = 0;
    int j = 0;
    string s;
    int i = 0;
    while (i < lx and j < ly and k < lcs.length())
    {
        if (x[i] == y[j])
        {
            if (x[i] == lcs[k])
            {
                s = s + x[i];
                i++;
                j++;
                k++;
            }
        }
        else
        {
            if (x[i] == lcs[k])
            {
                s = s + '+' + y[j];
                j++;
            }
            else if (y[j] == lcs[k])
            {
                s = s + '-' + x[i];
                i++;
            }
            else
            {
                s = s + '+' + y[j];
                j++;
                s = s + '-' + x[i];
                i++;
            }
        }
    }
    return s;
}
string getSolutionPath(string &x, string &y, vector<vector<char>> &path)
{
    const int lx = path.size();
    const int ly = path[0].size();
    string s;
    int i = lx - 1;
    int j = ly - 1;
    while (path[i][j] != '0')
    {
        switch (path[i][j])
        {

        case 'D':
            s = x[i - 1] + s;
            i--;
            j--;
            break;
        case 'U':
            i--;
            break;
        case 'L':
            j--;
            break;
        default:
            //error
            s.erase();
        }
    }
    return s;
}
int main(int argc, char const *argv[])
{
    /*
    10 14
    A B C D F G H J Q Z
    A B C D E F G I J K R X Y Z
    */
    int lenX, lenY;
    cin >> lenX;
    cin >> lenY;
    string X;
    string Y;
    char temp;
    for (int i = 0; i < lenX; i++)
    {
        cin >> temp;
        X = X + temp;
    }
    for (int i = 0; i < lenY; i++)
    {
        cin >> temp;
        Y = Y + temp;
    }
    vector<vector<int>> DP(lenX + 1, vector<int>(lenY + 1, 0));
    vector<vector<char>> path(lenX + 1, vector<char>(lenY + 1, '0'));
    solve(X, Y, DP, path);
    string s = getSolutionPath(X, Y, path);
    cout << diff(X, Y, s) << endl;
    return 0;
}
