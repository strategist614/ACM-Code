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
ll n,x,y;
int a;
int _lcm;
int main ()
{	
	  cin>>n>>x>>y;
    for(int i= 1;i<=n;i++)
    {
      cin>>a;
      ll l = min(x,y);
      ll r = 1e15;
 	  while(l < r)
	  {
	  	   ll mid = (l+r)>>1;
         if(mid/x+mid/y >= a) r = mid;
         else l = mid+1;
 	  }
 	  cout<<l<<endl;
      if(l % x != 0) cout<<"Vanya"<<endl;
      else if(l % y != 0) cout<<"Vova"<<endl;
      else cout<<"Both"<<endl;
	}
	return 0 ;
}
/*
1
2
2
3
3
4
4
6
5
6
6
8
7
9
8
10
9
12
10
12
11
14
12
15
*/
