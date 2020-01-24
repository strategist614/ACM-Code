
#include<iostream>
#include<stack>
#include<cstdio>
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
const int N = 80010;
const int inf = 0x3f3f3f3f;
typedef long long ll;
int a[N];
int main ()
{
	int n;
    read(n);
    for(int i = 1;i <= n;i++) read(a[i]);
    stack<ll> s;
    a[n+1] = inf;
    ll ans = 0;
    for(int i = 1;i <= n+1;i++)
    {
       if(s.empty() || a[s.top()] > a[i]) s.push(i);
       else 
       {
       	  while(s.size() && a[s.top()] <= a[i]) 
          {
          	 int x = s.top();
          	 s.pop();
             ans += (ll)(i-x-1);
          }
          s.push(i);
       }
    }
    out(ans);
    puts("");
	return 0 ;
}