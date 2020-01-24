#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[50005];
int main ()
{
    ll n,m;
    cin>>n>>m;
    if(m == 0)
    {
    	for(int i= 1;i<=n;i++)
    		cout<<i<<" ";
    	return 0;
    }
    for(ll i= 2;i <= n;i++)
    {
       if(i*(i-1)/2 >= m && (i-1)*(i-2)/2 < m)
       {
           int _ = i;
           int __ = i*(i-1)/2-m;
           for(int i =1;i<=n - _;i++)
           	cout<<i<<" ";
           cout<<n-__<<" ";
           for(int i= n;i>=(n-_+1);i--)
           {
           	if(i != n-__)
           		cout<<i<<" ";
           }  
           return 0;  
       }
    }
	return 0 ;
}