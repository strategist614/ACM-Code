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
const int N = 100010, M = 1000010;
int ver[M], Next[M], head[N], dfn[N], low[N];
int Stack[N], ins[N], c[N];
int vc[M], nc[M], hc[N], tc;
vector<int> scc[N];
int s;
int n, m, tot, num, top, cnt;
int in[N];
void add(int x, int y) {
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void add_c(int x, int y) {
	vc[++tc] = y, nc[tc] = hc[x], hc[x] = tc;
}

void tarjan(int x) {
	dfn[x] = low[x] = ++num;
	Stack[++top] = x, ins[x] = 1;
	for (int i = head[x]; i; i = Next[i])
		if (!dfn[ver[i]]) {
			tarjan(ver[i]);
			low[x] = min(low[x], low[ver[i]]);
		}
		else if (ins[ver[i]])
			low[x] = min(low[x], dfn[ver[i]]);
	if (dfn[x] == low[x]) {
		cnt++; int y;
		do {
			y = Stack[top--], ins[y] = 0;
			c[y] = cnt, scc[cnt].push_back(y);
		} while (x != y);
	}
}

int main() {
	read(n);
	read(m);
	read(s);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i);
	int _ = 0;
    for(int i = 1;i <= cnt;i++){
    	for(int j =0;j < scc[i].size();j++)
    		if(scc[i][j] == s)
    		{
               _ = i;
               break;
    		}
    	if(_) break;
    }
	for (int x = 1; x <= n; x++)
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i];
			if (c[x] == c[y]) continue;
			add_c(c[x], c[y]);
	        in[c[y]]++;  
	}
	int ans = 0;
    for(int i =1;i <= cnt;i++){
         if(i == _) continue;
         if(!in[i]) ans ++; 
    }
    cout << ans << endl;
	return 0;
}

