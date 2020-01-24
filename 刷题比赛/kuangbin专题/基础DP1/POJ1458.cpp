/*
独立思考
*/
#include<iostream>
#include<cstdio>
#include<string>
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
int dp[1005][1005];
char a[1005];
char b[1005];
int main ()
{
	while(scanf("%s %s",a+1,b+1)!=EOF)
	{
		int lena = strlen(a+1);
		int lenb = strlen(b+1);
		for(int i =1;i<=lena;i++)
			for(int j= 1;j<=lenb;j++)
			{
				if(a[i] == b[j])
				{
					dp[i][j] = dp[i-1][j-1]+1;
				}
				else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		printf("%d\n",dp[lena][lenb]);
	}
	return 0 ;
}
