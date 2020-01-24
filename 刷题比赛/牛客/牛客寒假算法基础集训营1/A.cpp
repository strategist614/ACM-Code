/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long long ll;
int a[N];
int vis[4];
std::vector<int> v4;
std::vector<int> v2;
std::vector<int> v0;
std::vector<int> v;
int main ()
{
    int n;
    cin>>n;
    for(int i= 1;i<=n;i++) cin>>a[i];
    int cnt2 = 0,cnt0 = 0,cnt4 = 0;
    for(int i =1;i<=n;i++)
    {
    	if(a[i] == 4) 
        {
    	   v4.push_back(a[i]);      
        }
        if(a[i] == 0)
        {
        	v0.push_back(a[i]);
        }
        if(a[i] == 2)
        {
        	v2.push_back(a[i]);
        }
    }
    v.push_back(0);
    while(v4.size() && v0.size())
    {
    	v.push_back(4);
    	v.push_back(0);
    	v4.pop_back();
    	v0.pop_back();
    }
    if(v4.size())
    { 
       while(v4.size() && v2.size())
       {
       	   v.push_back(4);
       	   v.push_back(2);
       	   v4.pop_back();
       	   v2.pop_back();
       }
       if(v2.size()) v.push_back(2);
       else v.push_back(4);
    }
    else 
    {
       while(v2.size() && v0.size())
       {
       	  v.push_back(2);
       	  v.push_back(0);
       	  v2.pop_back();
       	  v0.pop_back();
       }
       if(v2.size()) v.push_back(2);
       else v.push_back(0);
    }
    ll ans = 0;
    for(int i= 0;i<v.size()-1;i++)
    {
       ans += (v[i+1]-v[i])*(v[i+1]-v[i]);
    }
    cout<<ans<<endl;
    return 0 ;
}
*/
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
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res%mod;}
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
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
ll phi(ll n)
{
	ll ans = n;
	for(int i = 2;i<=sqrt(n);i++)
	{
		if(n % i == 0)
		{
			ans = ans/i*(i-1);
			while(n % i == 0) n /= i;
		}
	}
	if(n > 1) ans = ans / n * (n-1);
	return ans ;
}
int main ()
{
    ll n,k,a,b;
    cin>>n>>k>>a>>b;
    ll tmp = phi(mod);
    ll di = phi(n)/2*n;
    ll ans = powmod(k%mod,di%tmp+tmp);
    ans = (ll)(ans%mod)*(ll)((a+b)%mod);
    cout<<ans%mod<<endl;
	return 0 ; 
}