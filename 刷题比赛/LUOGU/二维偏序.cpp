/*
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
const int N = 1e6+5;
int c[N];
int f[N];
struct node
{
	int x;
	int y;
}a[N];
bool cmp(node a,node b)
{
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x ;
}
void add(int x,int y)
{
	for(;x<=N;x += x&-x) c[x] += y; 
}
int ask(int x)
{
	int ans = 0;
	for(;x;x-=x&-x) ans += c[x];
	return ans;
}
int main ()
{
	int n,k;
	read(n);
	read(k);
	for(int i= 1;i<=n;i++)  {read(a[i].x);read(a[i].y);}
	sort(a+1,a+n+1,cmp); 
    memset(c,0,sizeof(c));
    for(int i = 1;i<=n;i++)
    {
       int ans = ask(a[i].y);
       add(a[i].y,1);
       f[ans]++;
    }
    for(int i= 0;i < k;i++)
   	 	{out(f[i]);puts("");}
	return 0 ;
}
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
const int N = 1e6+5;
struct node 
{
	int x;
	int y;
	int ans;
}a[N],b[N];
int f[N];
bool cmp(node a,node b)
{
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
void CDQ(int l,int r)
{
	if(l == r) return ;
	int mid = (l+r)>>1;
	CDQ(l,mid);
	CDQ(mid+1,r);
	int i = l;
	int j = mid+1;
	for(int k= l;k<=r;k++)
	{
		if(j > r||(a[i].y <= a[j].y&&i <= mid)) b[k] = a[i++],
	}
}
int main()
{
	int n,k;
	read(n);
	read(k);
	for(int i= 1;i<=n;i++)
	{ 
        read(a[i].x);
        read(a[i].y);
	    a[i].ans = 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int )
	return 0 ;
}