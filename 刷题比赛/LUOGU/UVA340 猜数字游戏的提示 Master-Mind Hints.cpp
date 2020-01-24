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
	while (c < '0' || c > '9') {if (c == '-')sgn = -1; c = getchar();}
	while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	x *= sgn;
}
template <typename T>
void out(T x)
{
	if (x < 0) {putchar('-'); x = -x;}
	if (x >= 10)out(x / 10);
	putchar(x % 10 + '0');
}
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
int a[1005];
int b[1005];
int vis1[1005];
int vis2[1005];
int vis3[1005];
int n;
int solve1()
{
	memset(vis1,0,sizeof(vis1));
	int ans = 0;
	for (int i = 1; i <= n; i++) if (a[i] == b[i]) {ans ++; vis1[i] = 1;}
	return ans ;
}
int solve2()
{\
	memset(vis3,0,sizeof(vis3));
	memset(vis2,0,sizeof(vis2));
	int ans = 0;
    for(int i= 1;i<=n;i++)
    {
    	if(vis1[i]) continue;
    	if(vis2[i]) continue;
    	int flag = 0;
    	for(int j =1;j<=n;j++)
    	{
    		if(vis3[j]) continue;
    		if(vis1[j]) continue;
    		if(a[i] == b[j])  {ans ++;vis3[j] = 1;flag = 1;break;}
    	} 
    	if(flag)
    	{
    		vis2[i] = 1;
    	}
    }
    return ans;
}
int main ()
{
	int flag = 0;
	while (scanf("%d", &n) != EOF && n)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 1; i <= n; i++)
		{
			read(a[i]);
		}
		printf("Game %d:\n", ++flag);
		for(;;)
		{
			for (int i = 1; i <= n; i++)
			{
				cin >> b[i];
			}
			if(b[1] == 0) break;
            int x = solve1();
            int y = solve2();
            printf("    (%d,%d)\n",x,y);
		}
	}
	return 0 ;
}
