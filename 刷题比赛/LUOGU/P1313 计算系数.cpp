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
const int mod = 10007;

ll ksc(ll a, ll b, ll c) {
    ll ans = 0;
    while (b) {
        if (b & 1) ans = (ans + a) % c;
        a = a * 2 % c;
        b >>= 1;
    }
    return ans;
}

ll ksm(ll a, ll b, ll c) {
    ll ans = 1 % c;
    a %= c;
    while (b) {
        if (b & 1) ans = ksc(ans, a, c);
        a = ksc(a, a, c);
        b >>= 1;
    }
    return ans%c;
}

ll pow_m(ll a,ll k,ll p)
{
    ll ans=1;
    ll tmp=a%p;
    while(k)
    {
        if(k&1)ans=ans*tmp%p;
        tmp=tmp*tmp%p;
        k>>=1;
    }
    return ans;
}
ll C(ll n,ll m,ll p)
{
    if(m>n)return 0;
    ll a=1,b=1;
    for(int i=1;i<=m;i++)
    {
        a=a*(n+i-m)%p;
        b=b*i%p;
    }
    return a*pow_m(b,p-2,p)%p;
}
ll Lucas(ll n,ll m,ll p)
{
    ll ans=1;
    while(n&&m)
    {
        ans=ans*C(n%p,m%p,p)%p;
        n/=p;
        m/=p;
    }
    return ans%p;
}

int main ()
{
    int a,b,k,n,m;
    cin>>a>>b>>k>>n>>m;
    a %= mod;
    b %= mod;
    ll ans = 0;
    ans = Lucas(k,n,mod)*ksm(a,n,mod)*ksm(b,m,mod);
    cout<<ans%mod<<endl;
 	return 0 ;
}