/*
独立思考
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

inline ll read(ll m){
    register ll x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)){
        x=x*10+ch-'0';
        if(x>=m) f=1;
        x%=m;ch=getchar();
    }
    return x+(f==1?m:0);
}

ll phi(ll n) {
	ll ans = n;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			ans = ans / i * (i - 1);
			while (n % i == 0) n /= i;
		}
	if (n > 1) ans = ans / n * (n - 1);
	return ans;
}

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
	return ans;
}

int main ()
{
    ll a,m;
    cin>>a>>m;
    ll p = phi(m);
    cout<<ksm(a,read(p),m)<<endl;
	return 0 ;
}	