#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
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
int a[20];
int cab[20];
int ans = 0;
int n,w;
void dfs(int now,int cnt)
{
   if(cnt >= ans) return;
   if(now == n+1)
   {
   	 ans = min(ans,cnt);
   	 return ;
   }
   for(int i = 1;i <= cnt;i++)
   {
   	   if(cab[i] + a[now] <= w)
   	   {
   	   	  cab[i] += a[now];
   	   	  dfs(now+1,cnt);
   	   	  cab[i] -= a[now];
   	   }
   }
   cab[cnt+1] = a[now];
   dfs(now+1,cnt+1);
   cab[cnt+1] = 0;
}
int main ()
{
	//int n,w;
	read(n);
	read(w);
	for(int i = 1;i<=n;i++) read(a[i]);
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    ans = n;
	dfs(1,0);
	cout<<ans<<endl;
	return 0 ;
}