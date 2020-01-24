// Tarjan算法求有向图强连通分量并缩点
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int N = 100010, M = 1000010;
int ver[M], Next[M], head[N], dfn[N], low[N];
int stack[N], ins[N], c[N];
int vc[M], nc[M], hc[N], tc;
vector<int> scc[N];
int n, m, tot, num, top, cnt;

void add(int x, int y) {
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void add_c(int x, int y) {
	vc[++tc] = y, nc[tc] = hc[x], hc[x] = tc;
}

void tarjan(int x) {
	dfn[x] = low[x] = ++num;
	stack[++top] = x, ins[x] = 1;
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
			y = stack[top--], ins[y] = 0;
			c[y] = cnt, scc[cnt].push_back(y);
		} while (x != y);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	//cout<<n<<" "<<m<<endl;
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i);
	for(int i = 1; i<= cnt;i++){
		for(int j = 0;j < scc[i].size();j++)
			cout<<scc[i][j]<<" ";
		cout<<endl;
	}
	for (int x = 1; x <= n; x++)
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i];
			if (c[x] == c[y]) continue;
			add_c(c[x], c[y]);
			printf("%d - %d\n",c[x],c[y]);
		}
	
    return 0; 
}
/*
9 13
1 2
1 5
1 6
2 3
3 4
4 5
5 2
6 8
8 9
9 6
6 7
8 7
7 4
*/