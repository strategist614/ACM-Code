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
const int N = 1e5+5;
int p[N],c[N],m;
ll gcd(ll a,ll b)
{
	return b ? gcd(b,a%b):a;
}
void divid(ll n)
{
   m = 0;
   for(int i= 2;i<=sqrt(n);i++)
   {
      if(n % i == 0) 
      {
         p[++m] = i,c[m] = 0;
         while(n % i == 0) n/=i,c[m]++;
      } 
   }
   if(n > 1) 
      p[++m] = n,c[m] = 1;
}

int main ()
{
    ll n ;
    while(scanf("%lld",&n)!=EOF && n)
    {
    	if(n < 0) 
    	{
    		n = 0 - n;
            divid(n);
            int ans =  0;
            for(int i= 1;i<=m;i++)
             ans = gcd(ans,c[i]);
            while(ans % 2 == 0) ans >>= 1;
            cout<<ans<<endl; 
    	} 
    	else 
    	{
    		divid(n);
    		int ans = 0 ;
            for(int i= 1;i<=m;i++)
            {
            	ans = gcd(ans,c[i]);
            }
            cout<<ans<<endl;
    	}
    }	
	return 0 ;
}