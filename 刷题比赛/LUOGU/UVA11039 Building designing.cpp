/*
独立思考
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int a[N];
int l[N];
int r[N];
int sum[N];
int dp[N];
std::vector<int> v;
bool cmp(int a,int b)
{
	return a > b;
}
int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i= 1;i<=n;i++) cin>>a[i];
        int tota = 0,totb = 0,tot = 0;
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        memset(sum,0,sizeof(sum));
        memset(dp,0,sizeof(dp));
        for(int i= 1;i<=n;i++)
        {
        	if(a[i] > 0) l[++tota] = a[i];
        	else r[++totb] = a[i];
        }
        sort(l+1,l+tota+1,cmp);
        sort(r+1,r+totb+1);
        int i = 1;
        int j = 1;
        for(int k =1;k<=tota+totb;k++)
        {
        	if(abs(l[i]) > abs(r[j])) sum[++tot] = l[i++];
        	else sum[++tot] = r[j++];
        }
        int ans = 0;
        for(int i =1;i<=tot;)
        {
            int flag = 0;
        	if(sum[i] > 0)
        	{
        		for(int j= i+1;j<=tot;j++)
        			if(sum[j] < 0){ans++;i=j;flag = 1;break;}
        	}
        	else 
        	{
        		for(int j= i+1;j<=tot;j++)
        		{
        			if(sum[j] > 0)
        			{
        				ans++;
        				i = j;
        				flag = 1;
        				break;
        			}
        		}
        	}
        	if(!flag) break;
        }
        if(n) ans += 1;
        cout<<ans<<endl;
	 }
	return 0 ;
}