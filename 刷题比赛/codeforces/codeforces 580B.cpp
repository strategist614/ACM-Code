#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
struct rec
{
	int m,s;
}a[N];
ll sum[N];
int n,d;
int check(int x)
{
	int l = x;
	int r = n;
    while(l < r)
    {
    	int mid = (l+r+1)>>1;
    	if(a[mid].m - a[x].m < d) l = mid;
    	else r = mid - 1;
    }	
    return l ;
}
bool cmp(rec a,rec b)
{
	return a.m < b.m;
}
int main ()
{
    read(n);
    read(d);
    for(int i = 1;i<=n;i++) cin>>a[i].m>>a[i].s;
    sort(a+1,a+n+1,cmp);
    for(int i = 1;i<=n;i++) sum[i] = sum[i-1] + a[i].s;
    ll ans = 0;
    for(int i = 1;i<=n;i++)
    { 
       int tmp = check(i);
       cout<<tmp<<endl;
       if(tmp == 0) ans = max(ans,(ll)a[i].s);
       else ans = max(ans,(ll)(sum[tmp] - sum[i-1]));
    }
    cout<<ans<<endl;
	return 0 ;
}