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
const int N = 10005;
int f[N];
int a[N];
int ans = 0;
int n;
bool jud()
{
	for(int i =1;i <= n;i++)
	{
		if(f[i] < a[i] + a[i - 1]) return false;
		else if(f[i] == 3 && a[i] + a[i - 1] == 1) return false;
		else if(f[i] == a[i] + a[i - 1]) a[i + 1] = 0;
		else a[i + 1] = 1;   
	} 
	return f[n] == a[n] + a[n - 1];
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	//int n;
	read(n);
	for(int i =1;i <= n;i++) read(f[i]);
	a[1] = 1;
    ans += jud();
    a[1] = 0;
    ans += jud();
    cout << ans << endl;
	return 0 ;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int n, a[maxn], dp[maxn];
bool f(){
    for(int i = 2; i <= n; i++){
        dp[i + 1] = a[i] - dp[i] - dp[i-1];
    }
    if(dp[n+1] == 0) return true; //n+1格无雷，合法
    else return false;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = 0;
    for(int i = 0; i <= a[1]; i++){ //枚举一下第一格有没有雷
        memset(dp, 0, sizeof(dp));
        dp[1] = i;
        dp[2] = a[1] - i;
        if(f()) ans++;
    }
    cout << ans << endl;
    return 0;
}

*/
/*
#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <cmath>

using namespace std;

const int maxn=10010;

int n,a[maxn];

long long dp[maxn][2][2][2],ans;

int main()

{

    scanf("%d",&n);

    for (int i=1;i<=n;i++) scanf("%d",&a[i]);

    for (int i=1;i<=n;i++)

    {

        if (i==1)

        {

            if (a[i]==0) dp[i][0][0][0]=1;

            if (a[i]==1)

            {dp[i][0][1][0]=1; dp[i][0][0][1]=1;}

            if (a[i]==2) dp[i][0][1][1]=1;

        }

        else if (i==n)

        {

            if (a[i]==0)

            {

                dp[i][0][0][0]+=dp[i-1][0][0][0];

                dp[i][0][0][0]+=dp[i-1][1][0][0];

            }

            if (a[i]==1)

            {

                dp[i][1][0][0]+=dp[i-1][0][1][0];

                dp[i][1][0][0]+=dp[i-1][1][1][0];

                dp[i][0][1][0]+=dp[i-1][0][0][1];

                dp[i][0][1][0]+=dp[i-1][1][0][1];

            }

            if (a[i]==2)

            {

                dp[i][1][1][0]+=dp[i-1][0][1][1];

                dp[i][1][1][0]+=dp[i-1][1][1][1];

            }

        }

        else

        {

            if (a[i]==0)

            {

                dp[i][0][0][0]+=dp[i-1][0][0][0];

                dp[i][0][0][0]+=dp[i-1][1][0][0];

            }

            if (a[i]==1)

            {

                dp[i][1][0][0]+=dp[i-1][0][1][0];

                dp[i][1][0][0]+=dp[i-1][1][1][0];

                dp[i][0][1][0]+=dp[i-1][0][0][1];

                dp[i][0][1][0]+=dp[i-1][1][0][1];

                dp[i][0][0][1]+=dp[i-1][0][0][0];

                dp[i][0][0][1]+=dp[i-1][1][0][0];

            }

            if (a[i]==2)

            {

                dp[i][1][1][0]+=dp[i-1][0][1][1];

                dp[i][1][1][0]+=dp[i-1][1][1][1];

                dp[i][1][0][1]+=dp[i-1][0][1][0];

                dp[i][1][0][1]+=dp[i-1][1][1][0];

                dp[i][0][1][1]+=dp[i-1][0][0][1];

                dp[i][0][1][1]+=dp[i-1][1][0][1];

            }

            if (a[i]==3)

            {

                dp[i][1][1][1]+=dp[i-1][0][1][1];

                dp[i][1][1][1]+=dp[i-1][1][1][1];

            }

        }

    }

    for (int i=0;i<=1;i++)

     for (int j=0;j<=1;j++) ans+=dp[n][i][j][0];

    printf("%lld\n",ans);

return 0;

}


--------------------- 
作者：syh0313 
来源：CSDN 
原文：https://blog.csdn.net/syh0313/article/details/87482867 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/