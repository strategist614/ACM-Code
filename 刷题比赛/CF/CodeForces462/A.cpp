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
char a[105][105];
int main ()
{
	int n;
	cin>>n;
	for(int i= 1;i<=n;i++)
		for(int j =1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	for(int i= 1;i<=n;i++)
	{
		for(int j =1;j<=n;j++)
		{
			int ans = 0;
			if(a[i+1][j] == 'o' && i+1 >= 1 && i+1<=n) ans++;
			if(a[i-1][j] == 'o' && i-1 >= 1 && i-1<=n) ans++;
			if(a[i][j+1] == 'o' && j+1 >= 1 && j+1<=n) ans++;
			if(a[i][j-1] == 'o' && j-1 >= 1 && j-1<=n) ans++;
			if(ans % 2) 
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0 ;
}