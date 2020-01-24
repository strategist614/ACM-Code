#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1e6+5;
int c[N];
void add(int x,int y)
{
	for(;x <=N;x+=x&-x) c[x] += y;
}
int ask(int x)
{
	int ans = 0;
	for(;x;x -= x&-x) ans += c[x];
    return ans;
}
struct node
{
	int x;
	int y;
}a[N];
bool cmp(node &a,node &b)
{
	if(a.x == b.x)
	   return a.y < b.y;
	return a.x < b.x;
}
int main ()
{
	int t;
	scanf("%d",&t);
	int flag = 0;
	while(t--)
	{
		memset(c,0,sizeof(c));
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
        for(int i = 1;i <= k;i++) scanf("%d %d",&a[i].x,&a[i].y);
        sort(a+1,a+k+1,cmp);
        long long ans = 0;
        for(int i = k;i;i--)
        {
             ans += (long long)(ask(a[i].y-1));
             add(a[i].y,1);
        }
        printf("Test case %d: ",++flag);
        printf("%lld\n",ans);
	}
	return 0 ;
}