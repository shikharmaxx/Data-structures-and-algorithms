#include <bits/stdc++.h>
using namespace std;
// command to run is
// g++ helloo.cpp -o prog(to compile)
// prog (to run)
typedef long long int ll;
#define F(i, a, b) for (int i = (int)(a); i < (int)(b); i++)  //for loop [0 to n]
#define RF(i, a, b) for (int i = (int)(a); i > (int)(b); i--) //reverse for loop [n to 0]
//#define MOD 1000000007  // to declare some constants

int func(string s, string t)
{
    int i = 0, j = 0, count = 0;
    for (i = 0; i < t.length(); i++)
    {
        if (s[j] == t[i])
        {
            ++count;
            j++;
            cout << "char4 marthced \n";
            if (count == s.length())
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    string s, t;
    cin >> s;
    cin >> t;

    int ans = func(s, t);
    cout << ans;
    return 0;
}