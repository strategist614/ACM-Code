#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int vis[N];
int a[N];
vector<int> g[N];
int P[N];
int pre[N];

inline int read()
{
    int x = 0, k = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-')k = -1; c = getchar(); }
    while (c >= '0' && c <= '9')x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * k;
}


void dfs(int x,int fa)
{
    pre[x]=fa;//求x的父结点
    for(int i=0;i<g[x].size();i++){
        if(g[x][i]==fa)continue;
        dfs(g[x][i],x);
    }
}
int n;
inline void add(int x,int y)
{
  g[x].push_back(y);
  g[y].push_back(x);
}
int main ()
{
  n = read();
  int i,j;
  for( i = 0;i<n - 1;i++)
  {
    int u,v;
    u = read();
    v = read();
    add(u,v);
  }
  pre[1] = 0;vis[0] = 1;dfs(1,0);
  for(i = 1;i<=n;i++) a[i] = read();
  if(a[1] != 1)
  {
    cout<<"No"<<endl;
    return 0;
  }
  vis[1] = 1;P[1] =1;
  for( i=2;i<=n;i++){
      if(!vis[pre[a[i]]]){
        cout<<"NO"<<endl;
        return 0;//a[i]的父结点在前面没有出现，就是NO。
      }//查询当前的a[i]的父结点是否在前面出现过，这是要求保证当前节点的父结点要在当前节点的前面
      vis[a[i]]=1;//标记当前节点出现过，当前节点又作为父结点要求出现在子节点的前面
      P[a[i]]=i;//记录a[i]的下标
      if(P[pre[a[i]]]>=P[pre[a[i-1]]])
      //维护父亲节点在前面遍历到，子节点也在前面。BFS性质
      continue;//记录a[i]的父结点的下标要在a[i-1]的父结点前面
      else {
          cout<<"NO"<<endl;return 0;
      }
  }
  cout<<"Yes"<<endl;
  return 0;
}
/*
#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
#define met(s) memset(s, 0, sizeof(s))
#define rep(i, a, b) for(int i = a; i < b; ++i)
template <class T> inline void scan_d(T &ret) {
char c; ret = 0;
while ((c = getchar()) < '0' || c > '9');
while (c >= '0' && c <= '9') {
ret = ret * 10 + (c - '0'), c = getchar();}}
typedef long long LL;
#define asdf(a)  ((int)a.size())
const int     MOD  = (int)1e9 + 7;
const int MAXN = (int)2e5 + 5;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
int vis[MAXN];
vector<int> V[MAXN];
set<int> s[MAXN];

void dfs(int v, int fa) {
    for(int i = 0; i < V[v].size(); ++i) {
        int u = V[v][i];
        if(u != fa) {
            s[v].insert(u);
            dfs(u, v);
        }
    }
}

int main() {
    int n, x, y;
    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        scanf("%d%d", &x, &y);
        V[x].push_back(y);
        V[y].push_back(x);
    }
    dfs(1, 0);
    scanf("%d", &x);
    if(x != 1) {
        puts("No");
        return 0;
    }
    queue<int> que;
    que.push(x);
    bool flag = true;
    while(!que.empty()) {
        int cnt = que.front();
        que.pop();
        for(int i = 0; i < s[cnt].size(); ++i) {
            scanf("%d", &x);
            if(s[cnt].find(x) == s[cnt].end() || vis[x]) flag = false;
            if(!flag) break;
            vis[x] = 1;
            que.push(x);
        }
        if(!flag) break;
    }
    if(flag) puts("Yes");
    else puts("No");
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int vis[N];
int a[N];
vector<int> g[N];
map<int,int> mp;
int pre[N];

inline int read()
{
    int x = 0, k = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-')k = -1; c = getchar(); }
    while (c >= '0' && c <= '9')x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * k;
}


void dfs(int x,int fa)
{
    pre[x]=fa;//求x的父结点
    for(int i=0;i<g[x].size();i++){
        if(g[x][i]==fa)continue;
        dfs(g[x][i],x);
    }
}
int n;
inline void add(int x,int y)
{
  g[x].push_back(y);
  g[y].push_back(x);
}
int main ()
{
  n = read();
  int i,j;
  for( i = 0;i<n - 1;i++)
  {
    int u,v;
    u = read();
    v = read();
    add(u,v);
  }
  pre[1] = 0;vis[0] = 1;dfs(1,0);
  for(i = 1;i<=n;i++) a[i] = read();
  if(a[1] != 1)
  {
    cout<<"No"<<endl;
    return 0;
  }
  vis[1] = 1;mp[1] =1;
  for( i=2;i<=n;i++){
      if(!vis[pre[a[i]]]){
        cout<<"NO"<<endl;
        return 0;
      }
      vis[a[i]]=1;
      mp[a[i]]=i;
      if(mp[pre[a[i]]]>=mp[pre[a[i-1]]])
      continue;
      else {
          cout<<"NO"<<endl;return 0;
      }
  }
  cout<<"Yes"<<endl;
  return 0;
}
*/
