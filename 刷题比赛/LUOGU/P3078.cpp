/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
ll a[N];
int main ()
{
	ll n;
	cin>>n;
	for(int i= 1;i<=n;i++) cin>>a[i];
	stack<int> s;
    ll ans = 0;
    ll cnt = 0;
	for(int i= 1;i<=n;i++)
	{
       if(s.empty() || s.top() > a[i]) s.push(a[i]);
       else
       {
       	  ans += a[i]-s.top();
       	  while(s.size() && s.top() < a[i]) s.pop();
       	  s.push(a[i]);
       } 
	}
	cout<<ans+a[1]<<endl;
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	
	return 0;
}