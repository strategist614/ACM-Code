#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
const int N = 1e5+5;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
map<int,int> mp;
int sum[N];
int a[N];
int main ()
{
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    int flag = 0;
    for(int i = 1;i<=n;i++)
    {
    	sum[i] = sum[i-1] + a[i];
    	mp[sum[i]] = ++flag;
    }
    int m;
    cin>>m;
    while(m--)
    {
       int q;
       cin>>q;
       int tmp = *lower_bound(sum+1,sum+n+1,q);
       cout<<mp[tmp]<<endl;
    }
	return 0 ;
}