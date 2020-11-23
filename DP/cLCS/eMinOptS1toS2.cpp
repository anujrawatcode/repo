#include <bits/stdc++.h>
using namespace std;

int SCSS(string s1, string s2, int n1, int n2)
{
    int dp[n1 + 1][n2 + 1];
    for (int i = 0; i <= n1; i++)
        for (int j = 0; j <= n2; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    int lcs = dp[n1][n2];
    int add = n1 - lcs;
    int sub = n2 - lcs;

    return add + sub;
}
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << SCSS(s1, s1, s1.length(), s2.length()) << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    for (int z = 1; z <= t; z++)
    {
        solve();
    }
    return 0;
}