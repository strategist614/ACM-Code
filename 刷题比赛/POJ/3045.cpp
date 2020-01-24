//看题解的
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N = 5e4+5;
const int inf = 0x3f3f3f3f;
struct node
{
	int s;
	int w;
}a[N];
bool cmp(node a,node b)
{
	return a.s + a.w < b.s + b.w;
}
ll d[N];
int main ()
{
	int n;
	cin>>n;
	for(int i= 1;i<=n;i++) scanf("%d %d",&a[i].w,&a[i].s);
    sort(a+1,a+n+1,cmp);
	ll p = 0;
    ll ans = -inf;
	for(int i = 1;i<=n;i++)
	{
		d[i] = p - a[i].s;
		p += a[i].w;
		ans = max(ans,d[i]);
	}
	printf("%lld\n",ans);
	return 0 ;
}