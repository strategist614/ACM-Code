/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 5e4 + 5;
int phi[N];
ll sum[N];
void phi_table()
{
	for (int i = 2; i <= N; i++) phi[i] = 0;
	phi[1] = 1;
	for (int i = 2; i <= N; i++) if (!phi[i])
			for (int j = i; j <= N; j += i)
			{
				if (!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
	for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + phi[i];
}
int main ()
{
	int n;
	phi_table();
	while (scanf("%d", &n) != EOF && n)
	{
		printf("%lld\n", 2 * sum[n] - 1);
	}
	return 0 ;
}