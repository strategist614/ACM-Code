#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
int main ()
{
	    int a,b;
	    ll ans = a * b;
    	ll maxn = 0;
    	for(ll i =1;i<=sqrt(ans);i++)
    	{
    		if(ans % i == 0)
    		{
               ll _ = ans / i;
               if(gcd(_,i) == a && (ll)_ * i/gcd(_,i) == b)
               maxn = max(maxn,i);
    		}
    	}  
    	cout<<maxn<<" "<<ans/maxn<<endl;
	return 0 ;
}

/*
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	return 0 ;
}
*/