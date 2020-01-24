/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b ?gcd(b,a%b):a;}
const int N = 1e5+5;
ll a[N];
ll b[N];
ll f[N];
int n , s;
ll ans = 0;

int solve(ll mid)
{
   memcpy(b,a,sizeof(a));
   for(int i =1;i <= n;i++)
   {
     b[i] += mid * i;
   }
   sort(b+1,b+n+1);
   ll tmp = 0;
   for(int i=1;i <= mid;i++)
   	tmp += b[i];
   return tmp <= s;	
}
int main ()
{
	cin>>n>>s;
    for(int i= 1;i <= n;i ++) {read(a[i]);}
    int l = 0;
    int r = n;
    while(l < r)
    {
    	ll mid = (l + r + 1) >> 1;
    	if(solve(mid)) l = mid;
    	else r = mid - 1;
    }
    cout<<l<<" ";
    for(int i= 1;i <= n;i++)
    	a[i] += l * i;
    sort(a+1,a+n+1);
    for(int i= 1;i <= l;i++) ans += a[i];
    cout<<ans<<endl;
	return 0 ;
}