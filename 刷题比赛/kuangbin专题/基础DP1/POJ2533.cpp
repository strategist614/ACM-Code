/*
独立思考
*/
#include<iostream>
#include<cstring>
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
typedef long long ll;
typedef unsigned long long ull;
int a[1005];
int dp[1005];
int main ()
{ 
    int n;
    read(n);
    for(int i= 1;i<=n;i++) read(a[i]);
    int ans = 0;
    for(int i= 1;i<=n;i++){
     dp[i] = 1;
     for(int j= 1;j<=i;j++)	
     {
        if(a[j] < a[i])
        dp[i] = max(dp[i],dp[j]+1);
     }
     ans = max(ans,dp[i]);
   }
   cout<<ans<<endl;
	return 0 ;
}
