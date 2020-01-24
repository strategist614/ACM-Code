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
const int N = 40005;
int head[N], ver[N * 2], Next[N * 2];
int tot = 0;
int v[N * 2], match[N * 2];
int n, m;
int used[N * 2],color[N * 2];

void add(int x, int y) {
	ver[++tot] = y;
	Next[tot] = head[x];
	head[x] = tot;
}

int Color(int x){
	memset(used,0,sizeof(used));
	memset(color,0,sizeof(color));
    queue <int> Q;
    Q.push(x);
    used[x]=1;
    color[x]=1;
    while(!Q.empty()){
        int v_cur=Q.front();
        Q.pop();
        for(int i = head[v_cur];i;i = Next[i]){
            int v_to=ver[i];
            if(used[v_to]==0){
                color[v_to]=1-color[v_cur];
                used[v_to]=1;
                Q.push(v_to);
            }
            else if(used[v_to]==1){
                if(color[v_to]==color[v_cur]){
                    return 1;
                }
            }
        }
    }
    return 0;
}

bool dfs(int x) {
	for (int i = head[x], y; i; i = Next[i])
		if (!v[y = ver[i]]) {
			v[y] = 1;
			if (!match[y] || dfs(match[y])) {
				match[y] = x;
				return true;
			}
		}
	return false;
}

int main ()
{
	while (~scanf("%d%d", &n, &m)) {
		tot = 0;
		memset(head,0,sizeof(head));
		memset(ver,0,sizeof(ver));
		memset(Next,0,sizeof(Next));
		memset(v,0,sizeof(v));
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			read(a);
			read(b);
			add(b, a);
			add(a, b);
		}
		if (Color(1) || n == 1) {
			printf("No\n");
			continue;
		}
		int ans = 0 ;
		memset(match,0,sizeof(match));
		for (int i = 1; i <= n; i++) {
			memset(v, 0, sizeof(v));
			if (dfs(i)) ans++;
		}
		printf("%d\n", ans / 2);
	}
	return 0 ;
}