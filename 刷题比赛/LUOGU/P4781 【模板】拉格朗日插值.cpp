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
const int mod = 998244353;
ll ksm(ll a,ll b)
{
	ll ans = 1;
	while(b > 0){
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans % mod;
}
const int N = 2005;
int x[N],y[N];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
    int n,k;
    read(n);
    read(k);
    for(int i =1;i <= n;i++) 
    {
    	read(x[i]);
    	read(y[i]);
    } 
    ll ans = 0;
    for(int i =1;i <= n;i++){
    	ll _ = 1;
    	for(int j =1;j <= n;j++){
    		if(i != j)
    		{
    			_ = _ * (x[i] + mod - x[j]) % mod;
    		}
    	}
    	_ = ksm(_,mod - 2);
    	for(int j =1;j <= n;j++)
    		if(i != j)
    			_ = _ * (k + mod - x[j]) % mod;
        _ = _ * y[i] % mod;
        ans = (ans + _ ) % mod;
    }
    printf("%lld\n",ans);
	return 0 ;
}