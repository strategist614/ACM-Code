#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
    	ll L,v,l,r;
    	cin>>L>>v>>l>>r;
    	ll ans = 0;
    	ll tmp1 = r/v;
    	ll tmp2 = (l-1)/v;
    	ll tmp3 = L/v;
    	cout<<(tmp3)-(tmp1-tmp2)<<endl;
    }
	return 0 ;
}