/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
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
ll exgcd(ll a,ll b,ll &x,ll &y)
{
   if(!b){x = 1,y = 0;return a;}
   ll d = exgcd(b,a%b,x,y);
   ll z = x;x = y;y = z-y*(a/b);
   return d;
}
ll ans1,ans2;
int main ()
{ 
    ll x,y,m,n,l;
    cin>>x>>y>>m>>n>>l;
    ll b = n - m;
    ll a = x - y;
    if(b < 0)
    {
       b = -b;
       a = -a;
    }
    ll tmp = exgcd(b,l,ans1,ans2);    
    if(a % tmp != 0) 
    {
    	cout<<"Impossible"<<endl;
    	return 0;
    } 
    cout<<(ans1*(a/tmp)%(l/tmp)+l/tmp)%(l/tmp)<<endl;
	return 0 ;
}