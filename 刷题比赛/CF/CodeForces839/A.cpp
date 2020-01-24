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
int a[105];
int main ()
{
	int n,k;	
	cin>>n>>k;
	for(int i= 1;i <= n;i++)
		cin>>a[i];
	int last = 0;
	if(a[1] >= 8) k -= 8,last = a[1] - 8;
	else k -= a[1];
	if(k <= 0) {cout<<1<<endl;return 0;}
	for(int i= 2;i <= n;i++)
	{
		if(last + a[i] >= 8) k -= 8,last = last + a[i] - 8;
		else k -= last + a[i],last = 0;
	    if(k <= 0) {cout<<i<<endl;return 0;}
	}
    cout<<-1<<endl;
	return 0 ;
}