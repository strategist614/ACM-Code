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

const int N = 3005;
const int INF = 0x7fffffff;
int bmap[N][N];//每次记得清空
//对于两边各50000个点，200000条边的二分图最大匹配可以在1s内出解，效果很好：）
struct HK { //用HK算法求解二分最大匹配问题(时间复杂度为sqrt(v)*e)
    int nx, ny, dis;
    int cx[N];//cx[i]表示左集合i顶点所匹配的右集合的顶点序号
    int cy[N]; //cy[i]表示右集合i顶点所匹配的左集合的顶点序号
    int dx[N];
    int dy[N];
    int Q[N];
    bool bmask[N];
    bool searchpath() { //极大最短增广路集
        int front, rear;
        front = rear = 0; //初始化队列
        dis = INF;
        memset(dx, -1, sizeof(dx));
        memset(dy, -1, sizeof(dy));
        for (int i = 1; i <= nx; i++) {
            if (cx[i] == -1) //左边未匹配
            {
                Q[rear++] = i; //将左边节点放入队列
                dx[i] = 0; //分层 所有潜在起点构成0层
            }
        }

        while (front < rear) {
            int u = Q[front++]; //u都是未匹配的
            if (dx[u] > dis)break;
            for (int v = 1; v <= ny; v++) {
                if (bmap[u][v] && dy[v] == -1) { //相邻未分层构成i+1层。
                    dy[v] = dx[u] + 1; //v对应的距离 为u对应距离加1
                    if (cy[v] == -1)dis = dy[v]; //右侧未匹配，更新最短距离
                    else {
                        dx[cy[v]] = dy[v] + 1; //右侧已经匹配，根据已匹配边回溯。分层
                        Q[rear++] = cy[v]; //左侧已匹配点入队。
                    }
                }
            }
        }
        return dis != INF;
    }
    int findpath(int u) { //只搜索极大最短增广路集中的边
        for (int v = 1; v <= ny; v++) {
            if (!bmask[v] && bmap[u][v] && dy[v] == dx[u] + 1) { //反向搜索的过程
                bmask[v] = 1;
                if (cy[v] != -1 && dy[v] == dis)continue;
                if (cy[v] == -1 || findpath(cy[v])) {
                    cy[v] = u;
                    cx[u] = v;
                    return 1;
                }
            }
        }
        return 0;
    }
    int Max_match() {
        int res = 0;
        memset(cx, -1, sizeof(cx));
        memset(cy, -1, sizeof(cy));
        while (searchpath()) {
            memset(bmask, 0, sizeof(bmask));
            for (int i = 1; i <= nx; i++) {
                if (cx[i] == -1) {
                    res += findpath(i);
                }
            }
        }
        return res;
    }
};
HK hk;
int head[N], ver[N], Next[N];
int tot = 0;
int match[N], v[N];
struct node
{
    int x;
    int y;
    int sp;
} a[N], b[N];
double dis(node a, node b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main ()
{
    int t;
    read(t);
    int flag = 0;
    while (t--) {
        tot = 0;
        //memset(head, 0, sizeof(head));
        //memset(match, 0, sizeof(match));
        memset(bmap, 0, sizeof(bmap));
        int ti;
        read(ti);
        int n, m;
        read(m);
        for (int i = 1; i <= m; i++) {
            read(a[i].x);
            read(a[i].y);
            read(a[i].sp);
        }
        read(n);
        for (int i = 1; i <= n; i++) {
            read(b[i].x);
            read(b[i].y);
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                double _ = dis(a[i], b[j]);
                double _t = _ / (double)a[i].sp;
                if (_t <= ti) bmap[i][j] = 1;
            }
        }
        hk.nx = m;
        hk.ny = n;
        printf("Scenario #%d:\n", ++flag);
        printf("%d\n\n", hk.Max_match());
    }
    return 0 ;
}
/*
#include<bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const int maxn = 3000 + 5;
const int maxm = 3e6 + 10;
vector<vector<int> >G(maxm);
int um[maxn],vm[maxn];
int dx[maxn],dy[maxn];
int dis;
bool vis[maxn];//建立匹配关系
//bfs寻找增广路径
bool SearchP(int n){
    queue<int>q;
    dis = INF;
    memset(dx,-1,sizeof(dx));
    memset(dy,-1,sizeof(dy));
    for(int i=1;i<=n;++i){
        //u中未匹配
        if(um[i]==-1){
            q.push(i);
            dx[i] = 0;
        }
    }
    while(!q.empty()){
        int u = q.front();q.pop();
        if(dx[u]>dis) break; //说明该增广路径长度大于dis还没有结束，等待下一次BFS在扩充
        for(int i=0;i<(int)G[u].size();++i){
            int v = G[u][i];
            if(dy[v]==-1){ //v中尚未匹配的点
                dy[v] = dx[u] + 1;
                //对点进行分层（不标记是匹配点和未匹配点）
                if(vm[v]==-1){
                    //得到本次BFS的最大遍历层次
                    dis = dy[v];
                }
                else{
                    dx[vm[v]] = dy[v] + 1;//v是匹配点，继续延伸
                    q.push(vm[v]);
                }
            }
        }
    }
    return (dis!=INF);
}

bool dfs(int u){
    for(int i=0;i<(int)G[u].size();++i){
        int v = G[u][i];
        if(!vis[v]&&dy[v]==dx[u]+1){
            vis[v] = 1;
            if(vm[v]!=-1&&dy[v]==dis) continue;
            //层次（也就是增广路径的长度）大于本次查找的dis，是searchP被break的情况，
            //也就是还不确定是否是增广路径，只有等再次调用searchP()在判断。
            if(vm[v]==-1||dfs(vm[v])){
                vm[v] = u;
                um[u] = v;
                return true;
            }
        }
    }
    return false;
}

int maxmatch(int n){
    int res = 0;
    memset(um,-1,sizeof(um));
    memset(vm,-1,sizeof(vm));
    while(SearchP(n)){
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;++i){
            //查找到一个增广路径，匹配数++
            if(um[i]==-1&&dfs(i)){
                ++res;
            }
        }
    }
    return res;
}

struct node1{
    int x,y,s;
}pe[maxn];

struct node2{
    int x,y;
}umb[maxn];

inline int getdis(const node1 &a, const node2 &b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main(){
    int T,kase = 0,n,m,t;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&t,&m);
        for(int i = 1; i <= m; ++i){
            scanf("%d%d%d",&pe[i].x,&pe[i].y,&pe[i].s);
            pe[i].s *= t;
            pe[i].s *= pe[i].s;
        }
        scanf("%d",&n);
        for(int i = 1; i <= n; ++i){
            scanf("%d%d",&umb[i].x,&umb[i].y);
        }
        for(int i = 0; i <= m; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(getdis(pe[i],umb[j]) <= pe[i].s){
                    G[i].push_back(j);
                }
            }
        }
        printf("Scenario #%d:\n%d\n\n",++kase,maxmatch(m));
    }
    return 0;
}

*/