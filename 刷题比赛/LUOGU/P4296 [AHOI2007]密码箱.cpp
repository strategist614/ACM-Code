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
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
set<ll> s;
int main ()
{
	ll n;
	cin>>n;
	if(n == 1)
	{
		cout<<"None"<<endl;
		return 0;
	}
	int p = (int)sqrt(n);
    for(register int i =1;i <= p;i++)
    {
    	if(n % i == 0)
    	{
    		ll a = i;
    		ll b = n / i;
    		for(register ll x = 1;x <= n;x += b)
    			if((x+1) % a == 0) s.insert(x);
    		for(register ll x = b- 1;x <= n; x += b)
    			if((x-1) % a == 0) s.insert(x);
    	}
    }
    for(set<ll>::iterator it = s.begin();it != s.end();it++)
    	{
    		out(*it);
    		puts("");
    	}
	return 0 ;
}