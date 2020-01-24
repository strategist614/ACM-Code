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
const int N = 105;
int n,m;
std::vector<int> g[N];
int in[N];
int cnt;
int a[N];
void init()
{
	cnt = 0;
	for(int i =1;i <= n;i++) g[i].clear();
	memset(in,0,sizeof(in));
}
void add(int x,int y){
	g[x].push_back(y);
    in[y]++;
}

void bfs()
{
   queue<int> q;
   for(int i= 1;i <= n;i++)
   	if(!in[i]) q.push(i);
   while(q.size()){
   	int x = q.front();
   	q.pop();
   	a[++cnt] = x;
   	for(int i = 0;i < g[x].size();i++){
   		int y = g[x][i];
   		if(--in[y] == 0) q.push(y); 
   	}
   } 
} 

int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
    while(~scanf("%d %d",&n,&m))
    {
    	if(n == 0 && m == 0) break; 
        init();
        for(int i =1;i <= m;i++){
        	int u,v;
        	read(u);
        	read(v);
        	add(u,v);
        }   
        bfs();
        for(int i =1;i <= cnt;i++)
        {
        	if(i != cnt) printf("%d ",a[i]);
        	else printf("%d\n",a[i]);
        }
    }
	return 0 ;
}