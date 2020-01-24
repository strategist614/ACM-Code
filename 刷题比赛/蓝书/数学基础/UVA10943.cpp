#include<bits/stdc++.h>
#define mod 1000000
using namespace std;
typedef long long LL;
const int maxn = 1000 + 10;
LL comb[maxn][maxn];
void solve() {
	for (int i = 0; i <= 200; i++) comb[i][0] = comb[i][i] = 1;
	for (int i = 1; i <= 200; i++) {
		for (int j = 1; j <= 200; j++) {
			comb[i][j] = ((comb[i - 1][j - 1] % mod) + (comb[i - 1][j] % mod)) % mod;
		}
	}
}
int main()
{
	solve();
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF) {
		if(n == 0 && k == 0) break;
		printf("%lld\n", comb[n+k-1][k-1]);
	}
	return 0;
}