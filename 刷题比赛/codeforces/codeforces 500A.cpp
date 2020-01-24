/*#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod=1000000007;
//const inf = 0x3f3f3f3f;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
int vis[27];
int main ()
{
	int n;
    string s;
    cin>>n;
    cin>>s;
    for(int  i = 0;i<s.size();i++)
    {
    	if(i == s.size() - 1) break;
    	if(s[i] != s[i+1]) 
    	{
    		cout<<"YES"<<endl;
    		cout<<s[i]<<s[i+1]<<endl;
    		return 0 ;
    	}
    //	if(i == s.size() - 1) break;
    } 
    cout<<"NO"<<endl;
 	return 0 ;
}
*/
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
const int N = 2e5+5;
int pos[N];
int vis[N];
int a[N];
int b[N];
std::vector<int> ans;
int main ()
{
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) {cin>>a[i];pos[a[i]] = i;}
    for(int i = 1;i<=n;i++) cin>>b[i];
    int last = 0;
    for(int i= 1;i<=n;i++)
    {
       int tmp = pos[b[i]];
       if(tmp > last)
       {
           ans.push_back(tmp-last);
           last = tmp; 
       }
       else 
       {
           ans.push_back(0);
       }
    }
    for(int i = 0;i<ans.size();i++)
    	cout<<ans[i]<<" ";
	return 0 ;
}
*/

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
const int N = 2e5+5;
int a[N];
int main ()
{
    int n;
    cin>>n;
    ll t;
    cin>>t;
    for(int i = 1;i<=n;i++) cin>>a[i];
    
	return 0 ;
}

