#include<bits/stdc++.h>
using namespace std;
const int N = 5e6+5;
typedef long long ll;
int b[N];
int c[N];
int n,m;
struct node
{
    int dat;
    int pos;	
}a[N];
bool cmp(node &a,node &b)
{
	return a.dat < b.dat;
}
void add(int x,int y)
{
	for(;x<=n;x+=x&-x) c[x] += y;
}
int ask(int x)
{
	int ans = 0;
	for(;x;x-= x&-x) ans += c[x];
    return ans;
}
int main ()
{
	while(scanf("%d",&n)!=EOF && n)
	{ 
       for(int i = 1;i<=n;i++) scanf("%d",&a[i].dat),a[i].pos = i;
       sort(a+1,a+n+1,cmp);
       for(int i = 1;i<=n;i++) b[a[i].pos] = i;
       for(int i = 1;i<=n;i++) c[i] = 0;
       long long ans = 0;
       for(int i = 1;i<=n;i++)
       { 
         add(b[i],1);
         ans += i - ask(b[i]);
         // ans += (i-1) - ask(b[i]);
         // add(b[i],1); 
       }
       printf("%lld\n",ans);
	}
	return 0 ;
}