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
const int N = 2e4+5;
const int M = 1e5+5;
int v[M];
int head[M],ver[M * 2],Next[M * 2];
int tot = 0;
int n,m;
int flag = 0;
void add(int x,int y){
	ver[++tot] = y;
	Next[tot] = head[x];
	head[x] = tot;
}
struct node
{
	int a;
	int b;
	int p;
}a[M];
void dfs(int x,int color){
	v[x] = color;
	for(int i = head[x];i;i = Next[i]){
		int y = ver[i];
		if(!v[y])
			dfs(y,3-color);
		else if(v[y] == color) 
		{
			flag = 1;
			return ;
		}
	}
}

int solve(int mid){
	memset(head,0,sizeof(head));
	memset(v,0,sizeof(v));
	tot = 0;
	flag = 0;
	for(int i =1;i <= m;i++){
		if(a[i].p > mid) 
		{
			add(a[i].a,a[i].b);
			add(a[i].b,a[i].a);
		}
	}
    for(int i = 1;i <= n;i++)
    	if(!v[i]) dfs(i,1);
    if(!flag) return 1;
    else return 0;
}

int main ()
{
	read(n);
	read(m);
	int l = 0;
	int r = 0;
	for(int i = 1;i <= m;i++){
        read(a[i].a);
        read(a[i].b);
        read(a[i].p);
	    r = max(r,a[i].p);
	}
	while(l < r){
		int mid = (l + r)>>1;
		if(solve(mid)) r = mid;
		else l = mid + 1;
	}
    cout<<l<<endl;
	return 0 ;
}