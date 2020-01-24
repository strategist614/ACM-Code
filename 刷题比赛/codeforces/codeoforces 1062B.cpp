#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
int p[1000];
int c[1000];
int m = 0;
std::vector<ll> v;
void divide(int n)
{
    for(int i = 2;i<=sqrt(n);i++) 
    {
       if(n % i == 0)
       {
       	 p[++m] = i;
       	 c[m] = 0;
       	 while(n % i == 0) n /= i,c[m]++;
       } 
    }
    if(n > 1)
     p[++m] = n,c[m] = 1;
    ll cur = 1;
    for(int i = 0;cur <= N;i++) v.push_back(cur),cur *= 2;
}
ll ans1 = 1;
int ans2 = 0;
int main ()
{   
	int n;
	cin>>n;
	divide(n);
    for(int i =1;i<=m;i++)
    	ans1 = (ll)ans1 * (ll)p[i];
    int ans = 0;
    int mx = 0;
    for(int i= 1;i<=m;i++) mx = max(mx,c[i]);
    int pos = lower_bound(v.begin(),v.end(),mx) - v.begin();
    int flag = 0;
    for(int i = 1;i<=m;i++)
    {
    	if(c[i] < v[pos] && !flag)
    	 {
    	 	flag = 1;
    	 	pos++;
    	 }
    }
    cout<<ans1<<" "<<pos<<endl;
	return 0 ;
}

