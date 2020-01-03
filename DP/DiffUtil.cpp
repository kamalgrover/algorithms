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
// path[i][j = '*' means coming from left

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
                path[i][j] = '*';
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

        case '*':
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
    /* INPUT
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
    printAA(DP);
    printAA(path);
    string s = getSolutionPath(X, Y, path);
    cout << diff(X, Y, s) << endl;

    /**
     * DP ARRAY : I = 0 AND J = 0 NOT SHOWN FOR CLARITY
                    A B C D E F G I J K R X Y Z
                A   1 1 1 1 1 1 1 1 1 1 1 1 1 1 
                B   1 2 2 2 2 2 2 2 2 2 2 2 2 2 
                C   1 2 3 3 3 3 3 3 3 3 3 3 3 3 
                D   1 2 3 4 4 4 4 4 4 4 4 4 4 4 
                F   1 2 3 4 4 5 5 5 5 5 5 5 5 5 
                G   1 2 3 4 4 5 6 6 6 6 6 6 6 6 
                H   1 2 3 4 4 5 6 6 6 6 6 6 6 6 
                J   1 2 3 4 4 5 6 6 7 7 7 7 7 7 
                Q   1 2 3 4 4 5 6 6 7 7 7 7 7 7 
                Z   1 2 3 4 4 5 6 6 7 7 7 7 7 8 

    PATH ARRAY : I = 0 AND J = 0 NOT SHOWN FOR CLARITY
                    A B C D E F G I J K R X Y Z
                A   * L L L L L L L L L L L L L 
                B   U * L L L L L L L L L L L L 
                C   U U * L L L L L L L L L L L 
                D   U U U * L L L L L L L L L L 
                F   U U U U L * L L L L L L L L 
                G   U U U U L U * L L L L L L L 
                H   U U U U L U U L L L L L L L 
                J   U U U U L U U L * L L L L L 
                Q   U U U U L U U L U L L L L L 
                Z   U U U U L U U L U L L L L * 
    
    
    DIFF RESULT  : ABCD+EFG+I-HJ+K-Q+R+X+YZ
    */
    return 0;
}
