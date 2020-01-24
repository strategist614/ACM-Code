#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int prime[] = {0,2,3,5,7,11,13,17,19,23,29};
int n;
ll ans = 0;
ll maxsum = 0;
void dfs(ll now,ll sum,ll k)
{
   if(sum > maxsum)
   {
   	  maxsum = sum;
   	  ans = now;
   }
   if(sum == maxsum && ans > now)
   {
   	 ans = now;
   }
   if(k > 10) return ;
   ll tmp = now;
   for(int i = 1;i <= 31;i++)
   	{
   		if(n / prime[k] < tmp) return ;
   		dfs(tmp*=prime[k],sum*(i+1),k+1);
   	}
} 
int main ()
{
    int t;
    cin>>t;
    int flag = 0;
    while(t--)
    {
    	cin>>n;
    	ans = 0;
        maxsum = 0;
        dfs(1,1,1);
        cout<<"Case #"<<++flag<<":"<<" ";
        cout<<ans<<endl;
    }
	return 0 ;
}