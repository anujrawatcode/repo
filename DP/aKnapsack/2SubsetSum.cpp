#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 10000000007
#define push_back pb

bool SubsetSumRcv(int arr[], int n, int sum)
{
	if (sum == 0 && n == 0)  //If we have No sum and No element
		return true;    
	if (sum == 0)    //If size is something and sum is zero
		return true;
	if (n == 0)      //If size is 0 and sum is something
		return false;
	if (arr[n - 1] > sum)  
		return SubsetSumRcv(arr, n - 1, sum);
	else
		return SubsetSumRcv(arr, n - 1, sum) || SubsetSumRcv(arr, n - 1, sum - arr[n - 1]);
}

bool SubsetSumDP(int arr[], int n, int sum)
{
	bool dp[n + 1][sum + 1];

	for (int i = 0; i < n+1; i++)   //Initilization
	{
		for (int j = 0; j < sum+1; j++)
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
	int sum;
	cin >> n >> sum;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << SubsetSumDP(arr, n, sum) << endl;
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