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
const int N = 1e6+5;
bool Prime[N];
void IsPrime()
{
    memset(Prime,true,sizeof(Prime));
    Prime[1]=Prime[0]=false;
    int n=N,m=sqrt(N);
    for(int i=2; i<=m; i++)
        if(Prime[i])
            for(int j=i*i; j<=n; j+=i)
                Prime[j]=false;
}
int main ()
{
	int n;
	read(n);
	IsPrime();
	while(n--)
	{
		ll x;
		read(x);
		ll tmp = 0 ;
		ll _cnt = (int)sqrt(x);
		if(Prime[_cnt] && (ll)_cnt * (ll)_cnt == x) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0 ;
}