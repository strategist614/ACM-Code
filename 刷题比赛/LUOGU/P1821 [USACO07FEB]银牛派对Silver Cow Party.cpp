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
const int N = 10010, M = 100010;
int head[N], ver[M], edge[M], Next[M], d[N];
bool v[N];
int n, m, tot; 
pair<int,int> ans[N];
priority_queue< pair<int, int> > q;

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

void dijkstra(int st) {
	memset(d, 0x3f, sizeof(d)); 
	memset(v, 0, sizeof(v)); 
	d[st] = 0;
	q.push(make_pair(0, st));
	while (q.size()) {
		int x = q.top().second; q.pop();
		if (v[x]) continue;
		v[x] = 1;
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i], z = edge[i];
			if (d[y] > d[x] + z) {
				d[y] = d[x] + z;
				q.push(make_pair(-d[y], y));
			}
		}
	}
}

int main ()
{   
    int n,m,x;
    cin>>n>>m>>x;
    for(int i= 1;i<=m;i++)
    {
    	int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    dijkstra(x);
    for(int i = 1;i<=n;i++) 
    {
    	ans[i].second = d[i];
    }
    for(int i= 1;i<=n;i++)
    {
    	dijkstra(i);
    	ans[i].first = d[x];
    }
    int _ = 0;
    for(int i =1;i<=n;i++)
        _ = max(_,ans[i].first+ans[i].second);
    cout<<_<<endl;
	return 0 ;
}