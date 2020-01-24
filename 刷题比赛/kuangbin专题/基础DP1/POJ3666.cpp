/*
独立思考
*/
#include<iostream>
#include<algorithm>
#include<cstring>
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
const int N = 2005;
int a[N],b[N],c[N];
int dp1[N][N];
int dp2[N][N];
int main ()
{
	int n;
	read(n);
	for(int i =1;i<=n;i++) 
	{
		read(a[i]);
		b[i] = a[i];
	}
	sort(b+1,b+n+1);
	for(int i =1;i<=n;i++)
	{
        c[i] = b[n+1-i];
        dp1[1][i] = abs(a[1]-b[i]);
        dp2[1][i] = abs(a[1]-c[i]);
	}
    for(int i =2;i<=n;i++)
    {
    	int minn1 = dp1[i-1][1];
    	int minn2 = dp2[i-1][1];
    	for(int j= 1;j<=n;j++)
    	{

    		minn1 = min(minn1,dp1[i-1][j]);
    		minn2 = min(minn2,dp2[i-1][j]);
    		dp1[i][j] = minn1 + abs(a[i]-b[j]);
    		dp2[i][j] = minn2 + abs(a[i]-c[j]);
    	}
    }
    int ans = 0x7fffffff;
    for(int i =1;i<=n;i++)
    	{
    		ans = min(ans,dp1[n][i]);
            ans = min(ans,dp2[n][i]);
    	}
    cout<<ans<<endl;
	return 0 ;
}
