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
int main ()
{
    int q;
    cin>>q;
    while(q--)
    {
    	ll n,a,b;
    	cin>>n>>a>>b;
        if(a * 2 < b)
        {
        	cout<<n * a<<endl;
        }
        else 
        {
        	if(n % 2)
        	{
        		ll num = n / 2 ;
                ll ans = num * b + a;
                cout<<ans<<endl;
        	}
        	else 
        	{
        		cout<<n/2*b<<endl;
        	}
        }
    }
	return 0 ;
}
