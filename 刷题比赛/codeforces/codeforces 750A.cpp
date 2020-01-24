/*
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
int main ()
{
	int n,k;
	cin>>n>>k;
	int min = 4*60;
	min -= k;
	int ans = 0 ;
	for(int i = 1;i<=n;i++)
	{
		min -= 5*i;
		if(min < 0) break; 
		ans ++;
    }
    cout<<ans<<endl;
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
int n,k,minn;
int check(int x)
{
	int tmp = 5*(1+x)*x/2;
	if(tmp <= minn) return 1;
	else return 0;
}
int main ()
{
    cin>>n>>k;
    minn = 4*60;
    minn -= k;
    int l = 0;
    int r = n;
    while(l < r)
    {
    	int mid = (l+r+1)>>1;
    	if(check(mid)) l = mid;
    	else r = mid-1;
    }
    cout<<l<<endl;
	return 0 ;
}