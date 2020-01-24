#include<iostream>
#include<cstdio>
#include<algorithm>
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
const int N = 1e5+5;
int c[N],ans[N];
struct node
{
   int l;
   int r;
   int pos;	
}a[N];
bool cmp(node a,node b)
{
	if(a.r == b.r) return a.l < b.l;
	return a.r > b.r;
}
void add(int x,int y)
{
	for(;x <= N;x += x&-x) c[x] += y;
}
int ask(int x)
{
	int ans = 0;
	for(;x;x -= x&-x) ans += c[x];
	return ans ; 
}
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		memset(ans,0,sizeof(ans));
		memset(c,0,sizeof(c));
		for(int i= 1;i<=n;i++)
        {
        	read(a[i].l);
        	read(a[i].r);
        	a[i].pos = i;
        } 
        sort(a+1,a+n+1,cmp);
        ans[a[1].pos] = 0;
        add(a[1].l+1,1); 
        for(int i = 2;i<=n;i++)
        {
           if(a[i].l == a[i-1].l && a[i].r == a[i-1].r) ans[a[i].pos] = ans[a[i-1].pos];
           else ans[a[i].pos] = ask(a[i].l+1);
           add(a[i].l+1,1);
        } 
        for(int i =1;i<=n;i++)
        {
        	if(i != 1) 
            printf(" ");
            printf("%d",ans[i]);
        }
        puts("");
	}
	return 0 ;
}