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
const int mod = 998244353;
struct matrix
{
	ll a[10][10];
} A, _;
void print(matrix ans){
	 for(int i = 1;i <= 4;i++){
        	for(int j = 1;j <= 4;j ++)
        		cout<<ans.a[i][j]<<" ";
        	cout<<endl;
        }
}
matrix mul(matrix a, matrix b) {
	matrix ans;
	memset(ans.a, 0, sizeof(ans.a));
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j ++) {
			for (int k = 1; k <= 4; k ++)
				ans.a[i][j] += ((a.a[i][k]+mod) * (b.a[k][j]+mod))% mod;
			    ans.a[i][j] %= mod;
		}
	}
	return ans;
}
matrix ksm(matrix a, int k) {
	matrix ans;
	memset(ans.a,0,sizeof(ans.a));
    for(int i = 1;i <= 4;i++)
        ans.a[i][i] = 1;
    while(k){
    	if(k & 1) ans = mul(ans,a);
    	k >>= 1;
    	a = mul(a,a);
    }
    return ans;
}
int main ()
{
	_.a[1][1] = 3;
	_.a[1][2] = 1;
	_.a[2][1] = -1;
	_.a[2][3] = 1;
	_.a[4][1] = 1;
	_.a[4][4] = 1;
	int k;
	while (~scanf("%d", &k))
	{
		A.a[1][1] = 33;
		A.a[1][2] = 12;
		A.a[1][3] = 4;
		A.a[1][4] = 1;
		matrix ans;
        ans = ksm(_,k - 1);
        ans = mul(A,ans);
        printf("%lld\n",ans.a[1][3] % mod);
	}
	return 0 ;
}

/*
#include <stdio.h>
#include <string.h>  
using namespace std;
typedef long long ll;
int dp[200][2000];
int main()
{
	ll c[1100]={0,1,1};
	for(int i=2;i<1020;i++)
		c[i]=(c[i-1]+c[i-2]);
	memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i <= 40; i++)     //枚举总类
    {
        for (int num = 1; num <= 40; num++)    //枚举个数
        {
            for (int j = c[i]; j <= 1000; j++)      //枚举容量
            {
 
                dp[num][j] += dp[num - 1][j - c[i]];
            }
        }
    }
	for(int i=0;i<=40;i++)
		for(int j=1;j<=1000;j++)
			if(dp[i][j]==0)
			{
				printf("%d\n",j);break;
			}
	return 0;
}
*/