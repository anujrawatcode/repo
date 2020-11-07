#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 10000000007
#define push_back pb

int knapsackRecursive(int val[], int wt[], int size, int cap)
{

    if (cap == 0 || size == 0) // base condition
        return 0;
    if (cap < wt[size - 1]) // if the item is not selected
        return knapsack(val, wt, size - 1, cap);
    else
        return max(val[size - 1] + knapsack(val, wt, size, cap - wt[size - 1]),
                   0 + knapsack(val, wt, size - 1, cap));
    //if wt <= cap, return max ( either include / not include it )
}

int dp[1001][1001];
int knapsackMemoization(int val[], int wt[], int size, int cap)
{
    if (dp[size][cap] != -1)
        return dp[size][cap]; // check if answer exists already exits or not

    if (cap == 0 || size == 0) // base condition
        return 0;
    if (cap < wt[size - 1]) // if the item is not selected
        return dp[size][cap] = knapsack(val, wt, size - 1, cap);
    else
        return dp[size][cap] = max(val[size - 1] + knapsack(val, wt, size, cap - wt[size - 1]),
                                   0 + knapsack(val, wt, size - 1, cap));
}

int knapsack(int val[], int wt[], int size, int cap)
{
    int dp[size + 1][cap + 1];
    for (int i = 0; i < size + 1; i++)
        for (int j = 0; j < cap + 1; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0; //initiliation part

    for (int i = 1; i < size + 1; i++)
        for (int j = 1; j < cap + 1; j++)
            if (j < wt[i - 1]) // if the item is not selected
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);

    return dp[size][cap];
}

void solve()
{

    int n;
    int cap;
    cin >> n >> cap;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    cout << knapsack(val, wt, n, cap) << endl;
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