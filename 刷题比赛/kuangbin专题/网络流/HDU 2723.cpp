#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(4)
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+50;
const int M = 2e5+50;
#define inf 0x3f3f3f3f
int n,m;
int head[N], deep[N], cur[N];
int w[M], to[M], nx[M];
int tot;
inline void add(int u, int v, int val)
{
    w[tot]  = val;
    to[tot] = v;
    nx[tot] = head[u];
    head[u] = tot++;
}
int bfs(int s, int t)
{
    queue<int> q;
    memset(deep, 0, sizeof(deep));
    q.push(s);
    deep[s] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = head[u]; ~i; i = nx[i])
        {
            if(w[i] > 0 && deep[to[i]] == 0)
            {
                deep[to[i]] = deep[u] + 1;
                q.push(to[i]);
            }
        }
    }
    return deep[t] > 0;
}
int Dfs(int u, int t, int flow)
{
    if(u == t) return flow;
    for(int &i = cur[u]; ~i; i = nx[i])
    {
        if(deep[u]+1 == deep[to[i]] && w[i] > 0)
        {
            int di = Dfs(to[i], t, min(w[i], flow));
            if(di > 0)
            {
                w[i] -= di, w[i^1] += di;
                return di;
            }
        }
    }
    return 0;
}
int Dinic(int s, int t)
{
    int ans = 0, tmp;
    while(bfs(s, t))
    {
        for(int i = 1; i <= n; i++) cur[i] = head[i];
        while(tmp = Dfs(s, t, inf)) ans += tmp;
    }
    return ans;
}
void init()
{
    memset(head, -1, sizeof(head));
    tot = 0;
}
 
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        int Max=0,Min=inf,s,t;
        init();
        for(int i=0; i<n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(Max<x) Max=x,t=i+1;
            if(Min>x) Min=x,s=i+1;
        }
        //cout<<s<<" "<<t<<endl;
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        printf("%d\n",Dinic(s,t));
    }
}