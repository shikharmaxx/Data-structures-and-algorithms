#include <bits/stdc++.h>
using namespace std;
// command to run is
// g++ helloo.cpp -o prog(to compile)
// prog (to run)
typedef long long int ll;
#define F(i, a, b) for (int i = (int)(a); i < (int)(b); i++)  //for loop [0 to n]
#define RF(i, a, b) for (int i = (int)(a); i > (int)(b); i--) //reverse for loop [n to 0]
//#define MOD 1000000007  // to declare some constants
int func(string s1, string s2)
{
    int ans;
    int m = s1.size();
    int n = s2.size();

    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    F(i, 0, m + 1)
    {
        dp[i][0] = i;
    }
    F(i, 0, n + 1)
    {
        dp[0][i] = i;
    }

    F(i, 1, m + 1)
    {
        F(j, 1, n + 1)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }

    ans = dp[m][n];
    F(i, 0, m + 1)
    {
        F(j, 0, n + 1)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return ans;
}
int main()
{
    string a, b;
    cout << "\nenter the original string : ";
    cin >> a;
    cout << "\nenter the future string :";
    cin >> b;

    int answer = func(a, b);
    cout << "\nminimum edit distance is :" << answer;

    return 0;
}