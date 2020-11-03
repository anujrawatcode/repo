#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 10000000007
#define push_back pb

bool EqualSumDP(int arr[], int n) //
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + arr[i];
    if (sum % 2 != 0)   //if sum if arr is odd cannot be divided into two halfs
        return 0;
    sum = sum / 2;

    //same as subset sum just sum is equal to half of sum of array
    bool dp[n + 1][sum + 1];

    for (int i = 0; i < n; i++) //Initilization
    {
        for (int j = 0; j < sum; j++)
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
    return dp[n][sum];
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << EqualSumDP(arr, n) << endl;
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