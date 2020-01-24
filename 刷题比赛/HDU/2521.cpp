/*
#include<bits/stdc++.h>
using namespace std;
const int prime[] = {0,2,3,5,7,11,13,17,19};
int solve(int x)
{
	int m = 0;
	for(int i = 1;i <= sqrt(x);i++)
	{
		if(x % i == 0)
		{
			if(x / i == i) m ++;
			else m += 2;
		}
	}
	return m;
}
int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		int ans = 0;
		int maxn = 0;
        for(int i = a ;i<=b;i++)
        {
        	if(solve(i) > maxn)
        	{
        		maxn = solve(i);
        		ans = i;
        	}
            if(solve(i) == maxn && ans > i)
        	{
                ans = i;
        	} 
        }
        cout<<ans<<endl;
	}
	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
int prime[]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int maxsum = 0;
int ans = 0;
int a,b; 
void dfs(int now,int k,int sum)
{
    if(sum > maxsum && now >= a)
    {
    	maxsum = sum;
    	ans = now;
    }
    if(sum == maxsum && ans > now && now >= a)
    	ans = now;
    if(k > 8) return ;
    int tmp = now;
    for(int i =1;;i++)
    {
    	if(b/prime[k] < tmp) return ;
    	dfs(tmp*=prime[k],k+1,sum*(i+1));
    }
}
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
    	maxsum = 0;
    	ans = 0;
    	cin>>a>>b;
    	dfs(1,1,1);
    	if(a == b) ans = a;
    	cout<<ans<<endl;
    }
	return 0 ;
}