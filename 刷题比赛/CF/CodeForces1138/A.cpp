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
int a[100005];
int main ()
{
    int n;
    cin>>n;
    for(int i= 1;i<=n;i++)
    	cin>>a[i];
    int ans = 0;
    for(int i= 1;i<=n;)
    {
    	if(a[i] == 1)
    	{
    		pos++;
    		//i++;
    		while(a[i]==1)
    		{
               i++;
               pos++;
    		}

    	}
    }
	return 0 ;
}