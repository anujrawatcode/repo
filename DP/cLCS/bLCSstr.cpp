#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 10000000007
#define push_back pb

int LcsDp(string X, string Y, int m, int n)
{
    int LCSuff[m+1][n+1]; 
    int result = 0; 
    for (int i=0; i<=m; i++) 
    { 
        for (int j=0; j<=n; j++) 
        { 
            if (i == 0 || j == 0) 
                LCSuff[i][j] = 0; 
  
            else if (X[i-1] == Y[j-1]) 
            { 
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1; 
                result = max(result, LCSuff[i][j]); 
            } 
            else LCSuff[i][j] = 0; 
        } 
    } 
    return result; 
}
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << LcsDp(s1, s1, s1.length(), s2.length()) << endl;
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