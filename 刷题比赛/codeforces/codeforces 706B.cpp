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
const int N = 1e5+5;
int a[N];
int main()
{
	//memset(t,0,sizeof(t));
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {cin>>a[i];}
	sort(a+1,a+n+1);
	int q;
    cin>>q;
    while(q--)
    {
    	int m;
    	cin>>m;
    	int y = upper_bound(a+1,a+n+1,m)-a;
    	cout<<y-1<<endl;
    }
 	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int b[N];
int c[N];
int n,m;
struct node
{
    int dat;
    int pos;	
}a[N];
bool cmp(node &a,node &b)
{
	return a.dat < b.dat;
}
void add(int x,int y)
{
	for(;x <= N; x += x&-x) c[x] += y;
}
int ask(int x)
{
	int ans = 0;
	for(;x; x-= x&-x) ans += c[x];
	return ans; 
}
int main ()
{
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) {cin>>a[i].dat;a[i].pos = i;}
    sort(a+1,a+n+1,cmp);
    for(int i = 1;i<=n;i++) b[a[i].pos] = i;
    for(int i = 1;i<=n;i++) c[i] = 0;
    for(int i = 1;i<=n;i++)
    {
    	
    }
	return 0 ;
}