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
const int mod = 1e9+7;
int a[55];
int main ()
{
	int n;
	cin>>n;
	for(int i= 1;i<=n;i++)
	{
		cin>>a[i];
	}
	ll ans = 1 ;
	sort(a+1,a+n+1);
	for(int i= 1;i<=n;i++)
	{
		ans *= a[i]-i+1;
		ans %= mod;
	}
	cout<<ans<<endl;
	return 0 ;
}