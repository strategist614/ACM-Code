/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
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
const int N = 8e4 + 5;
int f[N][20], Next[N * 2], ver[N * 2], head[N], d[N];
int n, a[N], qx, t, vis[N],tot;
int fa[N];
queue<int> q;
std::vector<int> v;
bool cmp(int a,int b){
	return a > b;
}
void add(int x, int y) {
	ver[++tot] = y;
	Next[tot] = head[x];
	head[x] = tot;
}

void bfs() {
	q.push(1); d[1] = 1;
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i];
			if (d[y]) continue;
			fa[y] = x; 
			d[y] = d[x] + 1;
			f[y][0] = x;
			for (int j = 1; j <= t; j++)
				f[y][j] = f[f[y][j - 1]][j - 1];
			q.push(y);
		}
	}
}

int lca(int x, int y) {
	if (d[x] > d[y]) swap(x, y);
	for (int i = t; i >= 0; i--)
		if (d[f[y][i]] >= d[x]) {y =  f[y][i];}
	if (x == y) return x;
	for (int i = t; i >= 0; i--)
		if (f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	return f[x][0];
}

void path(int st,int ed)
{
	while(st != ed){
		v.push_back(a[st]);
		st = fa[st];
	}
}

int main ()
{
	read(n);
	read(qx);
	t = (int)(log(n)/log(2))+1;
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n - 1; i++) {
		int x, y;
		read(x);
		read(y);
		add(x,y);
		add(y,x);
	}
	bfs();
	while (qx--) {
		int w, x, y;
		read(w);
		read(x);
		read(y);
		if (w == 0) {
			a[x] = y;
		}
		else
		{
			int _ = lca(x,y);
			v.clear();
			v.push_back(0);
            path(y,_);
            path(x,_);
            v.push_back(a[_]);
            if(w > v.size() - 1) {
            	printf("invalid request!\n");
            }
            else 
            {
            	sort(v.begin(),v.end(),cmp);
            	printf("%d\n",v[w - 1]);
            }
		} 
	}
	return 0 ;
}
