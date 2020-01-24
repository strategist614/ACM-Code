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
ll a,b,x,y;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
   if(!b){x = 1,y = 0;return a;}
   ll d = exgcd(b,a%b,x,y);
   ll z = x;x = y;y = z-y*(a/b);
   return d;
}
int main ()
{
    cin>>a>>b;
    exgcd(a,b,x,y);
    cout<<(x%b+b)%b<<endl;//求最小正整数解
	return 0 ;
}