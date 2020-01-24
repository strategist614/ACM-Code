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
ll mypow(ll x,ll n)
{
	ll res = 1;
	while(n > 0)
	{
		if(n & 1) res = res*x;
		x = x * x ;
		n >>= 1;
	}
	return res;	
}
int main ()
{
	int x,n;
	cin>>x>>n;
	ll ans = 1;
	for(int i= 1;i<=n;i++)
	{
	    ans += ans * x ;
	}
	cout<<ans<<endl;
	return 0 ;
}