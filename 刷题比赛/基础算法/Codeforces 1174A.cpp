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
int a[2005];
int t;
int main ()
{
	int n;
	cin>>n;
	for(int i= 1;i <= 2 * n;i++) cin>>a[i];
    sort(a+1,a+2*n+1);
    ll sum1 = 0;
    ll sum2 = 0;
    for(int i =1;i <= n;i++) sum1 += a[i];
    for(int i =n+1;i <= 2 * n;i++) sum2 += a[i];
    if(sum1 == sum2) cout<<-1<<endl;
    else 
    {
    	for(int i =1;i <= 2 * n;i++)
    		cout<<a[i]<<" ";
    }
	return 0 ;
}