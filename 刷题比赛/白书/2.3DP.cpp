/*
#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int w[N],v[N];
int W;
int ans = 0,n;
int dfs(int dep,int j)
{
	if(dep == n)
	{
		ans = 0;
	}
	else if(j < w[dep])
	{
		dfs(dep+1,j);
	}
	else 
	{
		ans = max(dfs(dep+1,j),dfs(dep+1,j-w[dep])+v[dep]);
	}
	return ans;
}
int main ()
{
    cin>>n;
    for(int i= 1;i<=n;i++) cin>>w[i]>>v[i];
    cin>>W;
    cout<<dfs(0,W)<<endl;
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int dp[N][N];
int w[N],v[N];
int W;
int ans = 0,n;
int dfs(int i,int j)
{
	if(dp[i][j] >= 0)
	{
		return dp[i][j];
	}
	if(i == n)
	{
		ans = 0;
	}
	else if(j < w[i])
	{
		ans = dfs(i+1,j);
	}
	else 
	{
		ans = max(dfs(i+1,j),dfs(i+1,j-w[i])+v[i]);
	}
	return dp[i][j] = ans;
}
int main ()
{
	memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i= 1;i<=n;i++) cin>>w[i]>>v[i];
    cin>>W;
    cout<<dfs(0,W)<<endl;
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
string x,y;
int lenx,leny,A[201][201];
int search(int i,int j)
{
	if(A[i][j]+1) return A[i][j];
	if(!i&&!j)
	{
		if(x[i]==y[j])
			return A[i][j]=1;
		else
			return A[i][j]=0;
	}
	if(!i)
	{
		for(int k=j;k>=0;k--)
			if(x[i]==y[k])
				return A[i][j]=1;
		return A[i][j]=0;
	}
	if(!j)
	{
		for(int k=i;k>=0;k--)
			if(x[k]==y[j])
				return A[i][j]=1;
		return A[i][j]=0;
	}
	if(x[i]==y[j]) return A[i][j]=1+search(i-1,j-1);
	else return A[i][j]=max(search(i,j-1),search(i-1,j));
}
int main()
{
	while(cin>>x>>y)
	{
		memset(A,-1,sizeof(A));
		cout<<search(x.length()-1,y.length()-1)<<endl;
	}
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int maxn = 0;
string s1,s2;
void dfs(int s,int pa,int pb)
{
	if(pa >= s1.size() || pb >= s2.size()) return ;
	for(int i= pa;i<s1.size();i++)
	{
		int j;
		for(j = pb;j < s2.size();j++)
		{
			if(s1[i] == s2[j]) break;
		}
		if(j == s2.size()) continue;
		dfs(s+1,pa+1,pb+1);
		maxn = max(maxn,s);
	}
}
int main ()
{
    cin>>s1>>s2;
    dfs(1,0,0);
    cout<<maxn<<endl;
	return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int dp[N][N];
int maxn = 0;
string s1,s2;
int dfs(int i,int j)
{
	if(i == s1.size() || j == s2.size()) return 0;
	if(dp[i][j] != -1) return dp[i][j];
    if(!i && !j) 
	{
		if(s1[i] == s2[j])return dp[i][j] = 1;
		else return dp[i][j] = 0; 	
	}
    if(!i)
    {
    	for(int k = j;k >= 0;k--)
    	{
    		if(s1[i] == s2[k]) return dp[i][j] = 1;
    	}
    	return dp[i][j] = 0;
    }
    if(!j)
    {
    	for(int k = i;k >= 0;k--)
    	{
    		if(s1[k] == s2[j]) return dp[i][j] = 1;
    	}
    	return dp[i][j] = 0;
    }
	int res = 0;
	if(s1[i] == s2[j]) res = dfs(i-1,j-1)+1;
	else res = max(dfs(i-1,j),dfs(i,j-1));
	dp[i][j] = res;
	return res;
}
int main ()
{
	memset(dp,-1,sizeof(dp));
    cin>>s1>>s2;
    cout<<dfs(s1.size()-1,s2.size()-1)<<endl;
	return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int a[N];
int dp[N];
int n;
int main ()
{
	cin>>n;
	for(int i= 1;i<=n;i++) cin>>a[i];
    int ans = 0;
    for(int i= 1;i<=n;i++)
    {
    	dp[i] = 1;
        for(int j= 1;j <= i;j++)
        {
        	if(a[j] < a[i])
        	dp[i] = max(dp[i],dp[j]+1);
        }
        ans = max(dp[i],ans);
    }
    cout<<ans<<endl;
	return 0 ;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int n;
int dp[15];
int a[15];
int main ()
{
    cin>>n;
    memset(dp,0x7f,sizeof(dp));
    for(int i =1;i<=n;i++) cin>>a[i];
    for(int i =1;i<=n;i++)
    {
    	*lower_bound(dp+1,dp+n+1,a[i]) = a[i];
    }
    cout<<lower_bound(dp+1,dp+n+1,0x7f)-(dp+1);
	return 0 ;
}
*/
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int a[10005];
int main ()
{
	int n;
	cin>>n;
	for(int i= 1;i<=n;i++) cin>>a[i];
    stack<int> s;
    int ans = 0;
    for(int i= 1;i<=n;i++)
    {
    	if(a[i] > s.top() || s.empty())
    	{
           s.push(a[i]);
    	   ans = max(ans,(int)s.size());
    	}
    	else 
    	{
           while(s.top() > a[i] && s.size())
           {
           	  s.pop();
           } 
           s.push(a[i]);
           ans = max(ans,(int)s.size());
    	}
    }
    ans = max(ans,(int)s.size());
    cout<<ans<<endl;
	return 0 ;
}