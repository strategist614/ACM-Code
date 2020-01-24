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
const int N = 1001010;
double sum[N];
int main ()
{
	sum[0] = 0;
	sum[1] = 1.0;
	double ans = 1.0;
	for(int i= 2;i<=100000009;i++)
	{
		ans += 1.0/i;
	    if(i % 100 == 0)
	    {
	    	sum[i/100] = ans;
	    }
	}
	int t;
	cin>>t;
	int flag = 0;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int pos = n/100;
    	double ans = 0.0;
    	for(int i= pos*100+1;i<=n;i++)
          ans += 1.0/i;
        printf("Case %d: %.10f\n",++flag,sum[pos]+ans);
    }
	return 0 ;
}