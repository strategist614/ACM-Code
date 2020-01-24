#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll powmod(ll a,ll b) {ll res=1;a; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
int main ()
{
	 int b,k;
	 cin>>b>>k；
	 ll ans = 0;
	 for(int i= 1;i<=k;i++)
	 { 
	 	int x;
	 	cin>>x;
        ans += x * powmod(b,k-i); 
	 }
	 if(ans % 2) cout<<"odd"<<endl;
	 else cout<<"even"<<endl; 
	return 0 ;
}