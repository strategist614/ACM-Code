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
const int N = 1e4+5;
int d[N];
void solve()
{
	for(int i= 1;i<=N;i++) d[i] = i;
	for(int i= 1;i<=N;i++)
	{
		for(int j = i;j<=N;j += i) d[j]--;
	}
}
int a[N];
int main ()
{
    solve();
    int tot = 0;
    for(int i =1;i<=N;i++)
    {
    	if(i - d[i] >= 10) a[++tot] = i;
    }
    for(int i= 1;i<=2000;i++) cout<<a[i]<<endl;
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long long ll;
struct node
{
	int x;
	int y;
}a[N];
bool cmp(node a,node b)
{
   return a.y < b.y;
}
int sum[N];
int main ()
{
	int n;
	cin>>n;
	for(int i=  1;i<=n;i++) cin>>a[i].x;
	for(int i= 1;i <= n;i++) cin>>a[i].y;
	sort(a+1,a+n+1,cmp);
    for(int i= 1;i<=n;i++) 
    {
    	if(i == 1)
    	{
    		sum[i] = a[i].y;
    	}
    	else 
    	{
    		if(a[i].y-a[i-1].y-2<=0) sum[i] = 0;
    		else sum[i] = a[i].y-a[i-1].y-2;
    	}
    } 
    int t = 0;
    int last = 0;
    for(int i= 1;i<=n;i++)
    {
       sum[i] += last;
       if(sum[i] - a[i].x < 0) 
       {
       	 puts("NO");
       	 return 0; 
       }
       else 
       {
       	  sum[i] -= a[i].x;
       	  a[i].x = 0;
       	  last = sum[i];
       }
    }
    for(int i= 1;i<=n;i++) 
    {
    	if(a[i].x) 
    	{
    		puts("NO");
    		return 0;
    	}
    }
    puts("YES");
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int vis1[27];
int vis2[27];
int main ()
{
	string s1,s2;
	cin>>s1>>s2;
	for(int i = 0;i<s1.size();i++)
         vis1[s1[i]-'a']++;
    for(int i =0;i<s2.size();i++)
    	vis1[s2[i]-'a']++;
    int n = s1.size();
    int ans1 = 0;
    for(int i= 0;i<26;i++) if(vis1[i] == 2) ans1++;
    if(ans1 >= n - 1 && s1.size() == s2.size()) puts("YES");
    else if(ans1 >= n - 2 && s2.size() == s1.size() - 1) puts("YES");
    else if(ans1 >= n - 1 && s2.size() == s1.size() + 1) puts("YES");
    else if(ans1 == n && s2.size() == s1.size() + 2) puts("YES");
    else if(ans1 == n - 2 && s2.size() == s1.size() - 2) puts("YES");
    else if(ans1 >= n - 2 && s1.size() == s2.size()) puts("YES");
    else puts("NO");  
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
ll prime[maxn];
bool is_prime[maxn];
int p= 0,tot= 0 ;
ll a[2005];
void sieve(int n)
{
	 p = 0;
	for(ll i= 0;i<= n;i++) is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;
    for(ll i = 2;i<= n;i++)
    {
    	if(is_prime[i])
    	{
    		prime[++p] = i;
    		for(ll j = 2*i;j <= n;j+=i) is_prime[j] = false;
    	}
    }
    //return p;
}
int main()
{
	sieve(1e5);
	for(int i = 1;i<=2000;i++)
	{
		cout<<prime[i]*prime[4000-i]<<endl;
	}
	return 0 ;
}