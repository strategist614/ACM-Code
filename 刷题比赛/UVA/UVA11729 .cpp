#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
const int N = 1005;
struct node
{
   int b;
   int j;	
}a[N];
bool cmp(node x,node y)
{
	return x.j > y.j;
}
int sum[N];
int main ()
{
	int n;
	int flag = 0;
	while(scanf("%d",&n) != EOF && n)
	{
		int ans = 0;
		int _tmp = 0;
		for(int i = 1;i<=n;i++) cin>>a[i].b>>a[i].j;
        sort(a+1,a+n+1,cmp);
        for(int i = 1;i<=n;i++)
        {
            _tmp += a[i].b;
            ans = max(ans,_tmp+a[i].j);//更新任务最晚结束时间
            cout<<ans<<endl;
        }
      //  printf("Case %d: ",++flag);
       // cout<<ans<<endl;
	}
	return 0 ;
}
/*
12
2 10
59 96
23 70
22 81
2 28
90 85
68 44
71 39
22 100
45 66
17 9
61 82
*/
