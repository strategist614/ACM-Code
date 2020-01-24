#include <iostream>
#include <cstring>
#include <assert.h>
#include <vector>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> pii;
const ll mod=9901;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll m,a,b;

vector<pair<int, int> > vpi;
bool notprime[10003];
int prime[10003], cnt;
inline void getPrime() {
    prime[1] = 2; cnt = 1;
    for(int i = 3; i <= 10003; i += 2) {
        if(notprime[i]) continue;
        prime[++cnt] = i;
        for(int j = 2; i * j < 10003; ++j)
            notprime[i * j] = 1;
    }
}
inline void fj(ll x) {
    int qwq = 0;
    for(int i = 1; i <= cnt; ++i) {
        qwq = 0;
        while(x % prime[i] == 0)
            x /= prime[i], ++qwq;
        if(qwq) vpi.push_back(mp(prime[i], qwq));
    }
    if(x != 1) vpi.push_back(mp(x, 1));
}

long long sum(int p,int c)
{
   if(p == 0) return 0; 
   if(c == 0) return 1;
   if(c % 2 == 0) return ((1+powmod(p,c/2))*sum(p,c/2-1)%mod+powmod(p,c))%mod;
   else return (1+powmod(p,(c+1)/2))*sum(p,(c-1)/2)%mod;
}
int main ()
{
	cin>>a>>b;
    getPrime();
    fj(a);
    ll ans = 1;
    for(int i = 0;i<vpi.size();i++)
    {
        ans = ans * (sum(vpi[i].first,b*vpi[i].second))%mod;
    }
    cout<<ans<<endl;
	return 0 ;
}