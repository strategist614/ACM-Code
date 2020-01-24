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
const int N = 1e6 + 6;
int vis[N];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	register int n;
	read(n);
	for (register int i = 1; i <= n; i++)
	{
		for (register int j = i; j <= n; j += i) vis[j]++;
	}
	register int ans = 0;
	for (register int i = 1; i <= n; i++)
		ans += vis[i];
	out(ans);
	puts("");
	return 0 ;
}
/*
#include<cstdio>
int n,ans;
int main(){
    scanf("%d",&n);
    for(int i=1,j;i<=n;i=j+1){
        j=n/(n/i);
        ans+=(n/i)*(j-i+1);
    }
    printf("%d",ans);
return 0;
}
*/