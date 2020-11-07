#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 10000000007

int CountSubGivenDiff(int arr[], int n, int diff) //
{

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + arr[i];

    sum = (sum + diff) / 2 ;

    int dp[n + 1][sum + 1];  //same as count subset sum problem

    for (int i = 0; i < n; i++) //Initilization
    {
        for (int j = 0; j < sum; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]);
        }
    }
    return dp[n][sum];
}

void solve()
{
    int n, diff;
    cin >> n >> diff;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << CountSubGivenDiff(arr, n, diff) << endl;
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