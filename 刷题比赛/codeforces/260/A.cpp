#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll KGCD(ll a,ll b)
{
	if(a == 0)	return b;
	if(b == 0)	return a;
	if(~a & 1)
	{
		if(b & 1)	return KGCD(a>>1, b);
		else	return KGCD(a>>1, b>>1) << 1;
	}
	if(~b & 1)	return KGCD(a, b>>1);
	if(a > b)	return KGCD((a-b)>>1, b);
	return	KGCD((b-a)>>1, a);
}
int main ()
{
    ll a,b,n;
    cin>>a>>b>>n;
    ll tmp = a*10;
    ll cnt = tmp % b;
    if(cnt == 0)
    {
    	cout<<a;
    	for(int i = 1;i<=n;i++)
    		cout<<0;
        return 0;
    }
    if(b == 1)
    {
    	cout<<a;
    	for(int i = 1;i<=n;i++)
    		cout<<0;
        return 0 ;
    }
    if(abs(cnt-b) > 9) cout<<-1<<endl;
    else 
    {
    	cout<<a;
    	cout<<abs(cnt-b);
    	for(int i = 1;i <= n-1;i++) cout<<0;
    }
	return 0 ;
}

