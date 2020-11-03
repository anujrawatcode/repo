#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 10000000007
#define push_back pb

int CountSubsetSumRCV(int arr[], int n, int sum)
{
    if (sum == 0 && n == 0)
        return 1;
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    if (arr[n - 1] > sum)
        CountSubsetSumRCV(arr, n - 1, sum);
    else
        CountSubsetSumRCV(arr, n - 1, sum) + CountSubsetSumRCV(arr, n - 1, sum - arr[n - 1]);
}

int CountSubsetSumDP(int arr[], int n, int sum) //
{

    //same as subset sum just sum is equal to half of sum of array
    int  dp[n + 1][sum + 1];

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
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << CountSubsetSumDP(arr, n, sum) << endl;
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