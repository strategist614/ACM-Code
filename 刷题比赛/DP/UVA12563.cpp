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
const int N = 10000;
int n, ti;
int t[N];
struct node
{
	int num;
	int t;
	bool operator<(const node &rhs)const//判断是否更优
	{
		return num < rhs.num || (num == rhs.num && t < rhs.t);
	}
} dp[N];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int tx;
	read(tx);
	int flag = 0;
	while (tx--)
	{
		memset(dp, 0, sizeof(dp));
		read(n);
		read(ti);
		int max_t = 0;
		for (int i = 1; i <= n; i++){
           read(t[i]);
           max_t += t[i];
		}
		max_t = min(max_t,ti - 1);
        for(int i= 1;i <= n;i++){
           for(int j = max_t;j >= t[i];j--)
           {
           	  node tmp;
           	  tmp.num = dp[j - t[i]].num + 1;
           	  tmp.t = dp[j - t[i]].t + t[i];
           	  if(dp[j] < tmp)
           	  	dp[j] = tmp;
           }
        }
        printf("Case %d: %d %d\n",++flag,dp[max_t].num + 1,dp[max_t].t + 678);
	}
	return 0 ;
}
/*
#include<cstdio>
#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
 
const int MAX = 10000;
 
int main()
{
    int T;
    int n,t;
    int dp[MAX];
    int len[55];
    scanf("%d",&T);
    int Case;
    int i,j;
    for(Case=1;Case<=T;Case++)
    {
        scanf("%d%d",&n,&t);
        for(i=0;i<n;i++)
            scanf("%d",&len[i]);
        len[n]=678;
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        int cnt=-1;
        for(i=0;i<=n;i++)
        {
            for(j=t+len[i]-1;j>=len[i];j--)
            {
                if(dp[j-len[i]]!=-1)
                    dp[j]=max(dp[j],dp[j-len[i]]+1);
                cnt=dp[j]>cnt?dp[j]:cnt;
            }
        }
        for(i=6978; ;i--)
            if(dp[i]==cnt)
            {
                printf("Case %d: %d %d\n",Case,cnt,i);
                break;
            }
    }
    return 0;
}
*/
