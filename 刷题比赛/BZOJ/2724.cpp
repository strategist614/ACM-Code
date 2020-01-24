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
const int N = 4e4+5;
int c[40][40][N],f[40][40],d[40][40],a[N],b[N],fa[N],fb[N],st[40],ed[40];
int n,m,t,l,tot,L,R,cnt,num,ans;
void prework()
{
   t = (int)pow(n*1.0,1.0/3);
   if(t) l = n/t;
   for(int i= 1;i<=t;i++) 
   	{
   		st[i] = (i-1)*l+1;
        ed[i] = i*l;
    }
   if(ed[t] < n) st[t+1] = ed[t]+1,ed[++t] = n;
   memcpy(fa,a,sizeof(a));
   sort(fa+1,fa+n+1);
   for(int i= 1;i<=n;i++)
     if(i == 1 || fa[i] != fa[i-1]) fb[++tot] = fa[i];
   for(int i= 1;i<=n;i++)
     b[i] = lower_bound(fb+1,fb+tot+1,a[i])-fb; 
   for(int i= 1;i<=t;i++)
     for(int j = i;j<=t;j++)
     {
     	for(int k = st[i];k <= ed[j];k++) c[i][j][b[k]]++;
     	for(int k = 1;k <= tot;k++)
     	{
     		if(c[i][j][k] > f[i][j] || (c[i][j][k] == f[i][j] && k < d[i][j]))
     			f[i][j] = c[i][j][k],d[i][j] = k;
     	}
     } 
}
inline void update(int i)
{
   c[L][R][b[i]]++;
   if(c[L][R][b[i]] > cnt|| (c[L][R][b[i]] == cnt && b[i] < num))
   {
   	 cnt = c[L][R][b[i]];
   	 num = b[i];
   }
}
inline int solve(int x,int y)
{
	int i,l,r;
	if(x>y) swap(x,y);
	for(i=1;i<=t;i++) if(x<=ed[i]) {l=i; break;}
	for(i=t;i;i--) if(y>=st[i]) {r=i; break;}
	if(l+1<=r-1) L=l+1,R=r-1; else L=R=0;
	cnt=f[L][R],num=d[L][R];
	if(l==r)
	{
		for(i=x;i<=y;i++) update(i);
		for(i=x;i<=y;i++) c[L][R][b[i]]--;
	}
	else{
		for(i=x;i<=ed[l];i++) update(i);
		for(i=st[r];i<=y;i++) update(i);
		for(i=x;i<=ed[l];i++) c[L][R][b[i]]--;
		for(i=st[r];i<=y;i++) c[L][R][b[i]]--;
	}
	return fb[num];
}   
int main ()
{
    read(n);
    read(m);
    for(int i= 1;i<=n;i++) read(a[i]);
    prework();
    while(m--)
    {
    	int l,r;
    	read(l);
    	read(r);
        ans=solve((l+ans-1)%n+1,(r+ans-1)%n+1);
        out(ans);
        puts("");
    }
	return 0 ;
}