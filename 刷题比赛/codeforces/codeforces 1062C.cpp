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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll mypow(ll x,ll n)
{
	ll res = 1;
	while(n > 0)
	{
		if(n & 1) res = ((res%mod)*(x%mod))%mod;
		x = ((x%mod) * (x%mod) )%mod;
		n >>= 1;
	}
	return res;
}
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
const int N = 1e5+5;
ll a[N];
ll b[N];
int main ()
{
	int n,q;
	cin>>n>>q;
    string s;
    cin>>s;
    a[0] = 0;
    b[0] = 0;
    for(int i= 1;i<=n;i++)
    {
    	a[i] = a[i-1];
    	b[i] = b[i-1];
    	if(s[i-1] == '1') b[i]++;
    	else a[i]++;
    }
    while(q--)
    {
    	int l,r;
    	read(l);
    	read(r);
    	int len = r - l+1;
    	int cnt = a[r] - a[l-1];
    	ll ans = (mypow(2,len)-mypow(2,cnt)+mod)%mod;
        ll _ = ans % mod;
        out(_);
        puts("");
    }
	return 0 ;
}