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
std::vector<char> v;
int main ()
{
	int n;
	string s;
	cin>>n;
	cin>>s;
	int flag = 0;
	if(n == 1)
    {
    	cout<<s<<endl;
    	return 0;
    }
    int pos = -1;
    for(int i= 0;i<s.size();i++)
    {
    	if(i == n-1) break;
    	if(s[i] > s[i+1]) {pos = i;break;}
    }
    if(pos == -1)
    {
    	for(int i= 0;i<s.size()-1;i++)
    		cout<<s[i];
        return 0;
    }
    for(int i= 0;i<pos;i++) cout<<s[i];
    for(int i= pos+1;i<s.size();i++) cout<<s[i];

	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool notprime[100003];
ll prime[100003], cnt;
inline void getPrime() {
    prime[1] = 2; cnt = 1;
    for(int i = 3; i <= 1e6; i += 2) {
        if(notprime[i]) continue;
        prime[++cnt] = i;
        for(int j = 2; i * j < 1e6; ++j)
            notprime[i * j] = 1;
    }
}
inline ll fj(ll n)
{
	ll ans = 0;
	for(int i = 2;i <= cnt;i++)
	{
		if(n % prime[i] == 0) 
		{
			ans = prime[i];
			break;
		}
	}
	return ans;
}
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
    ll n;
    cin>>n;
    getPrime();
    int ans = 0;
    if(miller_rabin(n))
    {
    	cout<<1<<endl;
    	return 0;
    }
    if(n % 2 == 0)
    {
    	cout<<n/2<<endl;
    	return 0;
    }
    else 
    {
    	ll ans = fj(n);
    	ll tmp = 0;
    	tmp++;
    	n -= ans;
    	tmp += n/2;
    	cout<<tmp<<endl;
    }
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int n;

int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int ans = n * n - 4 * n;
		if(ans < 0) cout<<"N"<<endl;
		else
		{
	        double delta = (double)sqrt(ans);
	        double _ = ((double)n - delta)/2.0;
	        double __ = ((double)n + delta)/2.0;
	        printf("Y ");
	        printf("%.9f %.9f\n",_,__);
			}
		}
		return 0 ; 
	}
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double n;
	 	cin>>n;
        double l = 0.0;
        double r = n;
        if(n == 0) 
        {
        	cout<<"Y"<<endl;
        	printf("0.00000000000 0.0000000000\n");
        	continue;
        }
        if(n <= 3)
        {
        	cout<<"N"<<endl;
        	continue;
        }
        for(int i= 1;i<=60;i++)
        {
        	double mid = (l+r)/2.0;
        	if(mid + n / mid > n) r = mid;
        	else l = mid;
        }
        printf("Y ");
        printf("%.9f %.9f\n",l,n-l);
	} 
	return 0 ;
}