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
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
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
const int N = 2e5+5;
int a[N];
int vis[N];
std::vector<int> v;
int main ()
{
	int n;
	cin>>n;
	for(int i = 1;i<=n-1;i++) {cin>>a[i];vis[a[i]]++;}
	for(int i = 1;i<=n;i++)
	{
		if(!vis[i]) v.push_back(i);
	}
	cout<<v[0]<<endl;
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct node
{
	int x;
	int y;
}a[N];
bool cmp(node a,node b)
{
	return a.x*b.y < a.y * b.x;
}
long long sum[N];
int main ()
{
	int n;
	cin>>n;
    for(int i =1;i<=n;i++) cin>>a[i].x>>a[i].y;
    sort(a+1,a+n+1,cmp);
    for(int i= 1;i<=n;i++)
     sum[i] = sum[i-1]+a[i].y;
    long long ans = 0;
    for(int i =1;i<=n;i++)
    {
        ans += (long long)a[i].x*(long long)(sum[n]-sum[i]);
    }
    cout<<ans<<endl;
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		if(m % 2 == 0)
		{
           int ans = n * (m-2)+n-1;
           cout<<ans<<endl;
		}
		else 
		{
           int ans = (m-2)*n+(n-1)*2;
           cout<<ans<<endl;
		}
	}
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	
	return 0;
}