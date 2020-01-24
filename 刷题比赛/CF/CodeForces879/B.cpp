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
int a[505];
int main ()
{
	ll n,k;
	cin>>n>>k;
	for(int i =1;i <= n;i++) cin>>a[i];
	int maxn = 0;
    int pos = 0;
	for(int i =1;i <= n;i++)
	{
       if(a[i] > maxn) 
       {
       	 maxn = a[i];
       	 pos = i;
       }
	}
	int ans = 0;
	if(pos == 1){
		cout<<a[1]<<endl;
		return 0;
	}
	int ps = 1;
	int last = a[1];
	int cnt = 0; 
	for(int i =2;i <= pos;i++)
	{
       if(a[i] < last) cnt ++;
       else 
       {
       	  if(cnt >= k)
       	  {
       	  	cout<<a[ps]<<endl;
       	  	return 0;
       	  }
       	  last = a[i];
          cnt = 1;
          ps = i;
       }
	}
	cout<<a[pos]<<endl;
	return 0 ;
}