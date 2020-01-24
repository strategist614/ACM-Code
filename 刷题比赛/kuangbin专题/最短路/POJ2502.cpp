/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>

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
const int INF = 0x3f3f3f3f;
int tot = 2;
struct node 
{
	int x;
	int y;
}sub[50005];
double d[50005];
double a[511][511];
double dis1(node a,node b)
{
	double d = sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	double t = d * 3.0 / 2000;
	return t;
}
double dis2(node a,node b)
{
	double d = sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	double t = d * 3.0 / 500;
	return t;
}

bool v[5010];

void dijkstra() {
	for(int i= 1;i<=50005;i++) d[i] = INF;
	memset(v, 0, sizeof(v)); 
	d[1] = 0;
	for (int i = 1; i < tot; i++) { 
		int x = 0;
		for (int j = 1; j <= tot; j++)
			if (!v[j] && (x == 0 || d[j] < d[x])) x = j;
		v[x] = 1;
		for (int y = 1; y <= tot; y++)
		{
           if(!v[y] && d[y] > d[x]+a[x][y]) 
           	d[y] = d[x] + a[x][y];
		} 
	}
}

int main ()
{
	for(int i= 1;i<=511;i++)
		for(int j =1;j<=511;j++) 
			a[i][j] = INF;
	int sx,sy,ex,ey;
	cin>>sx>>sy>>ex>>ey;
	int x,y;
	while(scanf("%d %d",&x,&y) != EOF)
	{ 
       sub[tot].x = x;
       sub[tot++].y = y;
       while(scanf("%d %d",&x,&y) == 2)
       {
       	  if(x == -1 && y == -1) break;
       	  sub[tot].x = x;
       	  sub[tot].y = y;
          a[tot][tot-1] = dis1(sub[tot],sub[tot-1]);
          a[tot-1][tot] = a[tot][tot-1];
          tot++;
       }
	}
	sub[1].x = sx;
    sub[1].y = sy;
    sub[tot].x = ex;
    sub[tot].y = ey;
    for(int i= 1;i<=tot;i++)
    	for(int j= 1;j<=tot;j++)
    	{
    		a[i][j] = min(a[i][j],dis2(sub[i],sub[j]));
    		a[j][i] = a[i][j];
    	}  
    dijkstra();
    printf("%d\n",(int)(d[tot]+0.5));
	return 0 ;
}