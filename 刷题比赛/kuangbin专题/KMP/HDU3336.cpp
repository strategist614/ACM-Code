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
	while(c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=sgn;
}
template <typename T>
void out(T x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>=10)out(x/10);
	putchar(x%10+'0');
}
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
const int N = 2e5+5;
const int mod = 10007;
char s[N];
int Next[N];
int dp[N];

void count_string()
{
	int n;
	read(n);
	scanf("%s",s+1);
	Next[1] = 0;
	memset(Next,0,sizeof(Next));
	memset(dp,0,sizeof(dp));
	for(int i = 2,j = 0;i <= n;i++)
	{
		while(j > 0 && s[i] != s[j+1]) j = Next[j];
		if(s[i] == s[j+1]) j ++;
		Next[i] = j;
	}
	ll ans = 0;
	for(int i = 1;i<=n;i++)
	{
		dp[i] = dp[Next[i]] + 1;
		ans = ans + dp[i] % mod;
		ans %= mod;
	}
	cout<<ans<<endl;
}
int main ()
{
    int t;
    read(t);
    while(t--)
    {
    	count_string();
    }	
	return 0 ;
}