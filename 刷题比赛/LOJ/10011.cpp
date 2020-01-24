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
const int N = 1e5+5;
ll a[N];
int n,m;
int check(int x)
{
    int cnt = 1;
    int now = 1;
    for(int i = 2;i<=n;i++)
    {
    	if(a[i]-a[now] >= x)
    	{
    		now = i;
    		cnt++;
    	}
    }
    return cnt >= m;
}
int main()
{
    read(n);
    read(m);
    for(int i = 1;i<=n;i++) read(a[i]);
    sort(a+1,a+n+1);
    ll r = a[n];
    ll l = 0;
    while(l < r)
    {
        ll mid = (l+r+1)>>1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    out(l);
    puts("");
	return 0 ;
}