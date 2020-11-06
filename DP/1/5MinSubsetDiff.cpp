#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 10000000007



bool MinSubsetDiff(int arr[], int n)
{
    int sum=0;
    for(int i=0; i<n; i++)
      sum = sum + arr[i];

    bool dp[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++) //Initilization
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - arr[i - 1]]);
        }
    }

    vector<int> vec;
    for (int i = 0; i <= (sum) / 2; i++)
        if (dp[n][i] == true)
            vec.push_back(i);

    int mn = INT_MAX;
    for (int i = 0; i < vec.size(); i++)
        mn = min(mn, sum - 2 * vec[i]);
    return mn;
}

void solve()
{
    int n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << MinSubsetDiff(arr, n) << endl;
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