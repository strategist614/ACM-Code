/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while (c < '0' || c > '9') {if (c == '-')sgn = -1; c = getchar();}
	while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	x *= sgn;
}
template <typename T>
void out(T x)
{
	if (x < 0) {putchar('-'); x = -x;}
	if (x >= 10)out(x / 10);
	putchar(x % 10 + '0');
}
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 1005;
int n;
int a[N];
unordered_map<ll, pair<int, int>> mp;
//unordered_map<ll, pair<int, int>> ma;
int main ()
{
	while (~scanf("%d", &n) && n)
	{
		mp.clear();
		for (int i = 1; i <= n; i++) read(a[i]);
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++) {
				mp[a[i] + a[j]] = make_pair(i, j);
			}
		}
		int f = 0;
		for (int d = n; d >= 1; d--) {
			for (int c = 1; c <= n; c++) {
				if (d == c) continue;
				int tmp = a[d] - a[c];
                if(mp[tmp].first && mp[tmp].second){
                	 int ax = mp[tmp].first;
                	 int b = mp[tmp].second;
                     if(ax != c && ax != d && b != c && b != d)
                     {
                     	printf("%d\n",a[d]);
                     	f = 1;
                     }
                } 
                if(f) break;
			}
			if(f) break;
		}
		if(!f) printf("no solution\n");
	}
	return 0 ;
}