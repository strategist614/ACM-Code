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
int a[105][105];
int main ()
{
	int t;
	read(t);
	while(t--)
	{
       int n,m;
       cin>>n>>m;
       memset(a,0x3f,sizeof(a));
       for(int i= 1;i<=m;i++)
       {
       	int x,y,z;
       	cin>>x>>y>>z;
       	a[x][y] = z;
       }
       for(int i =1;i<=n;i++) a[i][i] = 0;
       for(int k= 1;k<=n;k++)
       	for(int i= 1;i<=n;i++)
       		for(int j =1;j<=n;j++)
       			a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
       int ans = 0;
       for(int i= 1;i<=n;i++) ans += a[1][i];
       for(int i= 1;i<=n;i++) ans += a[i][1];
       cout<<ans<<endl;
	}
	return 0 ;
}
*/
/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
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
const int N = 1e6 + 5, M = 1e6 + 5;
const int INF=0x3f3f3f3f;
int head[N], ver[M], edge[M], Next[M], d[N];
int n, m, tot;
queue<int> q;
bool v[N];
struct node
{
	int x;
	int y;
	int z;
} e[N];

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}
void init()
{
	memset(ver, 0, sizeof(ver));
	memset(edge, 0, sizeof(edge));
	memset(Next, 0, sizeof(Next));
	memset(head, 0, sizeof(head));
	memset(v, 0, sizeof(v));
	memset(d, INF, sizeof(d));
	while (q.size()) q.pop();

}
void spfa() {
	d[1] = 0; v[1] = 1;
	q.push(1);
	while (q.size()) {
		int x = q.front(); q.pop();
		v[x] = 0;
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i], z = edge[i];
			if (d[y] > d[x] + z) {
				d[y] = d[x] + z;
				if (!v[y]) q.push(y), v[y] = 1;
			}
		}
	}
}

int main() {
	int t;
	read(t);
	while (t--)
	{
		tot = 0;
	    init();
		read(n);
		read(m);
		for (int i = 1; i <= m; i++) {
			read(e[i].x);
			read(e[i].y);
			read(e[i].z);
			add(e[i].x, e[i].y, e[i].z);
		}
		spfa();
		ll ans = 0;
		for (int i = 1; i <= n; i++) ans += d[i];
		init();
		for (int i = 1; i <= m; i++) add(e[i].y, e[i].x, e[i].z);
		spfa();
		for (int i = 1; i <= n; i++) ans += d[i];
		out(ans);
		puts("");
	}
	return 0;
}
