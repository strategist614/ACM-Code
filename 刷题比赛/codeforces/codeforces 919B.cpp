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
int solve(int x)
{
   int sum = 0;
   while(x)
   {
   	  sum += x % 10;
   	  x /= 10;
   }
   if(sum == 10) return 1;
   else return 0;
}
std::vector<int> v;
int main()
{
	v.push_back(0);
    for(int i = 19;i<=11000000;i++)
    	if(solve(i)) v.push_back(i);
    int k;
    cin>>k;
    cout<<v[k]<<endl;
	return 0 ;
}