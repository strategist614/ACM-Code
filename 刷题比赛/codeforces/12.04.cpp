/*
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
typedef long long ll;
const int S = 8;
ll mult_mod(ll a,ll b,ll c)
{
	a %= c;
	b %= c;
	ll ret = 0;
	ll tmp = a;
	while(b)
	{
		if(b & 1)
		{
			ret += tmp;
			if(ret > c) ret -= c;
		}
		tmp <<= 1;
		if(tmp > c) tmp -= c;
		b >>= 1;
	}
	return ret;
}
ll pow_mod(ll a,ll n,ll mod)
{
   ll ret = 1;
   ll temp = a % mod;
   while(n)
   {
   	if(n&1) ret = mult_mod(ret,temp,mod);
   	temp = mult_mod(temp,temp,mod);
   	n>>=1;
   } 
  return ret; 
}
bool check(ll a,ll n, ll x ,ll t)
{
	ll ret = pow_mod(a,x,n);
	ll last = ret;
	for(int i  =1;i<=t;i++)
	{
		ret = mult_mod(ret,ret,n);
		if(ret == 1 && last != 1&&last != n-1) return true;
		last = ret;
	}
	if(ret != 1) return true;
	else return false;
}
bool miller_rabin(ll n)
{
	if(n <2) return false;
	if(n == 2) return true;
	if((n&1) == 0) return false;
	ll x = n-1;
	ll t = 0 ;
	while((x&1) == 0){x >>= 1;t++;}
	srand(time(NULL));
	for(int i = 0;i<S;i++)
	{
		ll a = rand()%(n - 1)+1;
		if(check(a,n,x,t))
			return 	false;
	}
	return true;
}
int main ()
{
	int n;
	cin>>n;
	if(n == 1) {cout<<-1<<endl;return 0;}
    else cout<<n<<" "<<n<<endl;
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+5;
long long a[N];
std::vector<long long> v;
int main ()
{
	long long n,k;
	cin>>n>>k;
	for(int i= 1;i<=n;i++) {cin>>a[i];v.push_back(a[i]);}
    v.push_back(0);
    sort(v.begin(),v.end());
    unique(v.begin(),v.end());
    for(int i= 0;i<v.size() -1 && k;i++)
    {
       k--;
       long long ans = v[i+1]-v[i];
       cout<<ans<<endl;
    }
    while(k--) cout<<0<<endl;
	return 0;  
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 2500;
int a[N];
int main ()
{
	int n;
	cin>>n;
	for(int i =1;i<=n;i++) cin>>a[i];
	cout<<n+1<<endl;
	cout<<1<<" "<<n<<" "<<900000<<endl;
	for(int i =1;i<=n;i++) a[i] += 900000;
	for(int i =1;i<=n;i++) cout<<2<<" "<<i<<" "<<a[i]-i<<endl;
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
multiset<ll> s;
multiset<ll>::iterator it;
ll a[100005];
int main ()
{
    int n,k;
    cin>>n>>k;
    for(int i =1;i<=n;i++)  {cin>>a[i];s.insert(a[i]);}
    int last = 0;
    while(!s.empty() && k)
    {
    	auto si = *(s.begin());
    	//cout<<si<<endl;
    	if(si - last == 0) {s.erase(s.begin());}
        else 
        {
        	//cout<<si-last<<endl;
        	last += si-last;
        	k--;
        	s.erase(s.begin());
        	//cout<<s.size()<<endl;
        }
    }
    //while(k--) cout<<0<<endl;
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+5;
int a[N];
int b[N];
std::vector<long long> v;
int main ()
{
	int n,k;
	cin>>n>>k;
	for(int i= 1;i<=n;i++) {cin>>a[i];v.push_back(a[i]);}
    sort(a+1,a+n+1);
    int tot = 0;
    for(int i =1;i<=n;i++)
        if(i == 1 || a[i] != a[i-1]) b[++tot] = a[i]; 
    b[0] = 0;
    for(int i = 1;i<=tot&& k;i++)
    {
       k--;
       long long ans = b[i]-b[i-1];
       if(ans <= 0) cout<<0<<endl;
       else cout<<ans<<endl;
    }
    while(k--) cout<<0<<endl;
	return 0;  
}