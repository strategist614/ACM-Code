/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/

/*
#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while (c < '0' || c > '9') {if (c == '-')sgn = -1; c = getchar();}
	while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	x *= sgn;
}
template <typename T>
void out(T x)
{
	if (x < 0) {putchar('-'); x = -x;}
	if (x >= 10)out(x / 10);
	putchar(x % 10 + '0');
}
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 1e6;
int is_prime[N], prime[N];
int tot = 0 ;
int t;
void sieve()
{
	for (int i = 0; i <= N; i++) is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		if (is_prime[i])
		{
			prime[++tot] = i;
			for (int j = i * 2; j <= N; j += i) is_prime[j] = 0;
		}
	}
}
struct T
{
	int x;
	int y;
};
pair<int,int> a[N];
T solve(int n)
{
	T ans;
	for (int i = 1; i <= tot && prime[i] <= n / 2; i++)
	{
         if(is_prime[n-prime[i]])
         {
         	ans.x = prime[i];
         	ans.y = n-prime[i];
         	break;
         }
	}
	return ans;
}
int main ()
{
    sieve();
    for(int i= 4;i<=N;i+=2)
    {
    	T ans;
    	ans = solve(i);
       a[i].first = ans.x;
       a[i].second = ans.y;
    }
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	cout<<a[n].first<<" "<<a[n].second<<endl;
    }
	return 0 ;
}
*/
/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
/*
#include<bits/stdc++.h>
using namespace std;
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
int main ()
{
	ll l,r,d;
	cin>>l>>r>>d;
    ll _ = r/d;
    ll __ = l/d;
    ll ans = 0;
    if(l % d == 0)
    {
       ans = _ - __+1;
    }
    else ans = _ - __;
    cout<<ans<<endl;
	return 0 ;
}
*/
/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
/*
#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while (c < '0' || c > '9') {if (c == '-')sgn = -1; c = getchar();}
	while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	x *= sgn;
}
template <typename T>
void out(T x)
{
	if (x < 0) {putchar('-'); x = -x;}
	if (x >= 10)out(x / 10);
	putchar(x % 10 + '0');
}
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
struct rec { int x, y, z; } edge[500010];
int fa[100010], n, m, ans, c;
bool operator <(rec a, rec b) {
	return a.z < b.z;
}
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
int main() {
	int t;
	cin >> t;
	while (t--)
	{
		cin >> c >> n >> m;
		ans = 0 ;
		for (int i = 1; i <= m; i++)
			scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].z);
		sort(edge + 1, edge + m + 1);
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (int i = 1; i <= m; i++) {
			int x = get(edge[i].x);
			int y = get(edge[i].y);
			if (x == y) continue;
			fa[x] = y;
			ans += edge[i].z;
		}
		if(ans <= c)
		{
			puts("Yes");
		}
		else puts("No");
	}
	return 0;
}
2
20 5 10
1 2 6
1 3 3
1 4 4
1 5 5
2 3 7
2 4 7
2 5 8
3 4 6
3 5 9
4 5 2

10 2 2
1 2 5
1 2 15
*/
/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
/*
#include<bits/stdc++.h>
using namespace std;
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
string s;
int main ()
{
	getline(cin,s);
//	cout<<s<<endl;
	int flag = 0;
	int len = s.size();
	for(int i= 0;i<len;i++)
	{
		if(s[i] == ' ')
		{
			//cout<<1;
			flag = 1;
			break;
		}
	}
	//cout<<!flag<<endl;
	//cout<<s[0]<<" "<<s[len-1]<<endl;
	if((!flag) || s[0] == ' ' || s[len-1] == ' ')
	{
		//cout<<1;
		cout<<0<<endl;
		return 0;
	}
	int pos = 0;
	for(int i =0;i < len;i++)
	{
       if(s[i] == ' ') pos = i;
	}
	pos += 1;
	//cout<<pos<<endl;
    cout<<len-pos<<endl;
	return 0 ;
}
*/
/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
/*
#include<bits/stdc++.h>
using namespace std;
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
const int N = 1e5+5;
int fa[N],sz[N];
void init(int n)
{
   for(int i =1;i<=n;i++) {fa[i] = i;sz[i] = 1;}
}
int find(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x,int y)
{
	int a = find(x);
	int b = find(y);
	if(a != b)
	{
		sz[a] += sz[b];
		fa[b] = a;
	}
}
int main ()
{
	int n;
	cin>>n;
	init(n);
	for(int i= 1;i<=n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		merge(a,b);
	}
	int ans = 0;
	for(int i= 1;i<=n;i++)
	{
       ans = max(ans,sz[i]);
	}
	cout<<ans<<endl;
	return 0 ;
}
*/
/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
/*
#include<bits/stdc++.h>
using namespace std;
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
const int N = 1e5+5;
int a[N];
int main ()
{
	int n;
	cin>>n;
	for(int i= 1;i<=n;i++) cin>>a[i];

	return 0 ;
}

*/
/*
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
char p[maxn], s[maxn];
int n, k, Next[maxn], plen;

void getNext()
{
	int j=0, k=-1;
	Next[0]=-1;
	while(j<plen)
	{
		if(k==-1 || p[j]==p[k])
			Next[++j] = ++k;
		else
			k = Next[k];
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    cin >> p;
    plen = strlen(p);
    getNext();
    int num = Next[plen];
    int tot = 1;
   	for(int i=0; i<plen; i++)
   		s[i] = p[i];
   	int res = plen;
   	while(tot<k)
   	{
   		for(int j=num; j<plen; j++)
   		{
   			s[res++] = p[j];
   		}
   		tot++;
   	}
   	for(int i=0; s[i]; i++)
   		cout << s[i];
   	cout << endl;
    return 0;
}
*/
/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
/*
#include<bits/stdc++.h>
using namespace std;
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
const int N = 55;
char s[N],p[N];
int Next[N];
int len;
void getNext()
{
	int j=0, k=-1;
	Next[0]=-1;
	while(j<len)
	{
		if(k==-1 || p[j]==p[k])
			Next[++j] = ++k;
		else
			k = Next[k];
	}
}

int main ()
{
	int n,k;
	cin>>n>>k;
	cin>>p;
	len = strlen(p);
	getNext();
	int num = Next[len];
	int tot = 1;
	for(int i= 0;i<len;i++)
		s[i] = p[i];
	int pos = len;
	while(tot < k)
	{
		for(int i = num;i<len;i++)
		{
           s[pos++] = p[i];
		}
		tot++;
	}
	for(int i= 0;i<pos;i++)
		cout<<s[i];
	return 0 ;
}
*/
/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
/*
#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while (c < '0' || c > '9') {if (c == '-')sgn = -1; c = getchar();}
	while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	x *= sgn;
}
template <typename T>
void out(T x)
{
	if (x < 0) {putchar('-'); x = -x;}
	if (x >= 10)out(x / 10);
	putchar(x % 10 + '0');
}
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 1e5 + 5;
int a[N];
int dp[N];
int vis[N];
int ans[N];
set<int> s;
int main ()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int tot = 0;
	ans[++tot] = a[n];
	vis[a[n]] = 1;
	for (int i = n - 1; i >= 1; i--)
	{
		dp[i] = tot;
		if (!vis[a[i]])
		{
			vis[a[i]] = 1;
			ans[++tot] = a[i];
		}
	}
	ll ansx = 0;
	memset(vis,0,sizeof(vis));
	for (int i = 1; i <= n - 1; i++)
	{
         if(!vis[a[i]])
         {
         	ansx += dp[i];
         	vis[a[i]] = 1;
         }
	}
	cout << ansx << endl;
	return 0 ;
}
*/