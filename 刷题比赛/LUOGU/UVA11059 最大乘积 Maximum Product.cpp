/*
独立思考
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
const ll INF = 0xfffffffffffff;
int a[20];
int main ()
{
    int n;
    int flag = 0 ;
    while(scanf("%d",&n)!=EOF)
    {
    	ll ans = 0;
    	for(int i =1;i<=n;i++) cin>>a[i];
    	for(int i= 1;i<=n;i++)
    	{
    		ll tmp = a[i];
    		ll minn = 0;
    		ans = max(ans,tmp);
    		for(int j= i+1;j<=n;j++)
    		{
    			tmp *= a[j];
                minn = max(minn,tmp);
    		}
    		ans = max(ans,minn);
    	}
    	printf("Case #%d: The maximum product is %lld.\n",++flag,ans);
    	cout<<endl;
    }	
	return 0 ;
}