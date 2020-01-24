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
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while(c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=sgn;
}
template <typename T>
void out(T x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>=10)out(x/10);
	putchar(x%10+'0');
}
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int x,y,z;
    	cin>>x>>y>>z;
    	ll ans = 0;
    	if(z % 2 == 0)
    	{
           ans += (x - y)  * (ll)(z / 2);
    	}
    	else 
    	{
    		ans += (x - y) *(ll) (z / 2);
    		ans += x;
    	}
    	cout<<ans<<endl;
    }
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int tmp;
int vis[105];
int a[105];
int n;
std::vector<int> v;
int main ()
{
	cin>>n;
	int ans = 0;
	int last = 0 ;
	for(int i =1;i<=n;i++) cin>>a[i];
	for(int i =1;i<=n-2;i++)
	{
       if(a[i] == 1 && a[i+1] == 0 && a[i+2] == 1)
             {
             	a[i+2] = 0;
             	ans++;
             }   		
    }
    cout<<ans<<endl;
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
struct node
{
	int x;
	int pos;
}a[N];
bool cmp(node a,node b)
{
	return a.x < b.x;
}
ll sum[N];
std::vector<int> v;
int main ()
{
    int n;
    cin>>n;
    for(int i= 1;i<=n;i++) 
    {
    	cin>>a[i].x;
    	a[i].pos = i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i =1;i<=n;i++) sum[i] = sum[i-1]+a[i].x;
    for(int i =1;i<=n;i++)
    {
    	if(i == n)
    	{
    		if(sum[n-2] == a[n-1].x) v.push_back(n);
    		break;
    	}
    	if((sum[i-1]+sum[n-1]-sum[i]) == a[n].x) v.push_back(i);
    }
    if(v.size() == 0)
    {
    	cout<<0<<endl;
    	cout<<endl;
    	return 0 ;
    }
    cout<<v.size()<<endl;
    for(int i= 0;i<v.size();i++)
    	cout<<a[v[i]].pos<<" ";
	return 0 ;
}
*/