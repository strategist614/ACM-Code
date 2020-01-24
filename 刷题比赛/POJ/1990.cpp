/*
#include<iostream>
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
typedef long long ll;
const int N = 2e4+5;
struct node
{
	int v;
	int x;
}a[N];
bool cmp(node &a,node &b)
{
	return a.x < b.x;
}

int main ()
{
	int n;
	read(n);
	ll ans = 0;
	for(int i= 1;i<=n;i++) 
	{
		read(a[i].v);
		read(a[i].x);
	}
	sort(a+1,a+n+1,cmp);
    for(int i = 1;i<=n;i++)
    {
    	for(int j = i+1; j<=n;j++)
    	{
    		ll tmp = max(a[i].v,a[j].v);
    		ans += (ll)(tmp*(ll)(a[j].x - a[i].x));
    	}
    }
    out(ans);
    puts("");
	return 0 ;
}
TLE 常数太大
*/
#include<iostream>
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
typedef long long ll;
const int N = 2e4+5;
struct node
{
	int v;
	int x;
}a[N];
bool cmp(node &a,node &b)
{
	return a.v < b.v;
}
void add(ll t[],int x,int y)
{
	for(;x <= N;x += x&-x) t[x] += (ll)y;
}
int ask(ll t[],int x)
{
	int ans = 0;
	for(;x;x -= x&-x) ans += t[x];
	return ans; 
}
int n;
ll sum[N],num[N]; 
int main ()
{
    read(n);
    for(int i= 1;i<=n;i++)
    {
    	read(a[i].v);
    	read(a[i].x);
    }
    sort(a+1,a+n+1,cmp);
    ll total = 0;
    ll ans = 0;
    for(int i= 1;i<=n;i++)
    {
        ll le = ask(num,a[i].x);
        ll lsum = ask(sum,a[i].x);
        ll small = le*a[i].x-lsum;
        ll big = total - lsum - (i-1-le)*a[i].x;
        ll tmp = (ll)(small + big) * a[i].v;
        total += a[i].x;
        ans += tmp;
        add(num,a[i].x,1);
        add(sum,a[i].x,a[i].x);
    }
    out(ans);
    puts("");
	return 0 ;
}