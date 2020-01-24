#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int a[N];
int b[N];
int n,m;
int solve(int x,int r)
{
	int l = 0;
	while(l < r)
	{
		int mid = (l+r+1)>>1;
		if(b[mid] < x) l = mid ;
		else r = mid - 1;
	}
	return l;
}
int main ()
{
	cin>>n;
	for(int i= 0;i < n;i++) cin>>a[i];
    cin>>m;
    for(int i= 1;i<=m;i++) cin>>b[i];
    sort(a,a+n);
    sort(b+1,b+m+1);
    ll ansa = n*2;
    ll ansb = m*2;
    ll _ = ansa-ansb;
    for(int i = 0;i < n;i++)
    {
    	ll t = solve(a[i],m);
        ll tmp1 = 2*i+3*(n-i);
        ll tmp2 = 2*t+3*(m-t);
        ll tmp = tmp1 - tmp2;
        if(tmp > _) {
        	_ = tmp;
        	ansa = tmp1;
        	ansb = tmp2;
        }
        else if(tmp == _ && tmp1 > ansa)
        {
        	ansa = tmp1;
        	ansb = tmp2;
        }
    }
    cout<<ansa<<":"<<ansb<<endl;
	return 0 ;
}
