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
const int N = 2e5+5;
struct node
{
	int l;
	int r;
}a[N],b[N];
int main ()
{
	int n,m;
	cin>>n;
	for(int i =1;i <= n;i++) read(a[i].l),read(a[i].r);
	cin>>m;
    for(int i =1; i<= m;i++) read(b[i].l),read(b[i].r);
    int mina = 2e9;
    int maxa = 0;
    int minb =2e9;
    int maxb = 0;
    for(int i =1;i <= n;i++)
    {
    	mina = min(mina,a[i].r);
        maxa = max(maxa,a[i].l);
    }
    for(int i = 1;i <= m;i++){
    	minb = min(minb,b[i].r);
    	maxb = max(maxb,b[i].l);
    }
    int ans = max(maxb-mina,maxa-minb);
    if(ans < 0) cout<<0<<endl;
    else cout<<ans<<endl;
	return 0 ;
}