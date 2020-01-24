/*
独立思考
*/
#include<iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int N = 2005;
int a[N];
int dp[N][N];
int main ()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = n; j >= 1; j--)
		{
			int x = n - (j - i + 1);
			dp[i][j] = max(dp[i - 1][j] + a[i - 1] * x, dp[i][j + 1] + a[j + 1] * x);
		}
	}
	int ans = 0 ;
	for (int i = 1; i <= n; i++)
		ans = max(dp[i][i] + a[i] * n, ans);
	cout << ans << endl;
	return 0 ;
}