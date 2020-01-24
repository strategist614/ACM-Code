#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int prime[] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
const ll INF = ((ll)1<<62)+1;
const int N = 50005;
ll ans;
ll d[N];
int op,n;
void dfs(ll dep,ll tmp,ll num,int lim)
{
	if(num > n) return ;
	if(num == n && ans > tmp) ans = tmp;
	if(dep > 16) return ;
	for(int i = 1;i<=lim;i++)
	{
        if(ans / prime[dep] < tmp || num*(i+1) > n) return;
        tmp *= prime[dep];
        if(n % (num*(i+1)) == 0)
        dfs(dep+1,tmp,num*(i+1),i);
	}
}

void Init()
{
    for(int i=1;i<N;i++) d[i] = i;
    for(int i=1;i<N;i++)
    {
        for(int j=i;j<N;j+=i) d[j]--;
        if(!d[d[i]]) d[d[i]] = i;
        d[i] = 0;
    }
}
int main ()
{
    int t;
    cin>>t;
    int flag = 0;
    Init();
    while(t--)
    {
    	cin>>op>>n;
    	if(op == 0)
    	{
    		ans = INF;
            dfs(1,1,1,63);
    	}
    	else 
    	{
            ans = d[n];
    	}
    	printf("Case %d: ",++flag);
        if(ans == 0) puts("Illegal");
        else if(ans >= INF) puts("INF");
        else printf("%lld\n",ans);

    }
	return 0 ;
}