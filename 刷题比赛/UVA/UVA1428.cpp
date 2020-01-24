//看题解的 重要
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int a[20005];
int c[N];
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
struct node
{
	int lmin,lmax;
	int rmin,rmax;
}b[N];
int main ()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
        for(int i =1;i<=n;i++) scanf("%d",&a[i]);
        memset(c,0,sizeof(c));
        ll ans = 0;
        for(int i= 1;i<=n;i++)
        {
        	int num = ask(a[i]);
        	b[i].lmax = num;
        	b[i].lmin = i-1-num;
        	add(a[i],1);
        }
        memset(c,0,sizeof(c));
        for(int i = n;i>=1;i--)
        {
        	int num = ask(a[i]);
        	b[i].rmax = num;
        	b[i].rmin = n-i-num;
        	add(a[i],1);
        }
        for(int i = 1;i<=n;i++) 
        	ans += (ll)b[i].lmax*b[i].rmin+(ll)b[i].lmin*b[i].rmax;
        printf("%lld\n",ans);
	}
	return 0 ;
}