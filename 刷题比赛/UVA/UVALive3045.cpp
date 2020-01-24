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
int a[1000050];
int main ()
{
	int n;
	int tot = 0;
	for(int i= 1;i <= 1005;i++)
	{
		//int tmp = i;
        for(int j= 1;j <= i;j++)
        	a[++tot] = i;
	}
	while(scanf("%d",&n)!=EOF && n)
	{
		int ans = 0 ;
        for(int i=1;i<=n;i++)
        	ans+=a[i];
        cout<<n<<" "<<ans<<endl;
	}
	return 0 ;
}