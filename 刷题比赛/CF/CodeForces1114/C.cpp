#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1600;
ll a,b;
ll c[N],m = 0,p[N];
void fj()
{
	for(int i= 2;i<=sqrt(b);i++)
	{
		if(b % i== 0)
		{
           p[++m] = i,c[m] = 0;
           while(b %i == 0) b/=i,c[m]++;
		} 
	}
	if(b > 1) 
		p[++m] = b,c[m] = 1;
}
ll cal(ll x,ll y)
{
	if(x < y) return 0;
	else return x/y+cal(x/y,y);
} 
void solve()
{
	ll minn=0x7fffffffffffffff;
	fj();
	for(int i= 1;i<=m;i++)
	{
		minn = min(minn,cal(a,p[i])/c[i]);
	}
	cout<<minn<<endl;
}
int main ()
{
    cin>>a>>b;
    solve();
	return 0 ;
}