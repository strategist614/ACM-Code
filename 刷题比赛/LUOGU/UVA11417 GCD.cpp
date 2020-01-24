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
int gcd(int a,int b) { return b ?gcd(b,a%b):a;}
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
       int ans = 0;
       for(int i=1;i<n;i++)
       	for(int j =i+1;j<=n;j++)
       	{
       		ans += gcd(i,j);
       	}
       	cout<<ans<<endl;
	}
	return 0 ;
}
