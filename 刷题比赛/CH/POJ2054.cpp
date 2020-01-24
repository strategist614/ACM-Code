/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int n,r; 
struct node 
{
	int c;
	int fa;
	int t;
	double w;
}a[N];
int search()
{
	double maxn = 0;
	int ans = 0;
	for(int i = 1;i<=n;i++)
	{
		if(i != r && a[i].w > maxn)
		{
			maxn = a[i].w;
			ans = i;
		}
	}
	return ans ;
}
int main ()
{
	while(scanf("%d %d",&n,&r)!=EOF)
	{
		if(n == 0 && r == 0) break;
		int ans = 0;
        for(int i= 1;i<=n;i++)
        {
        	cin>>a[i].c;
        	a[i].w = (double)a[i].c;
        	a[i].t = 1;
        	ans += a[i].c;
        }
        for(int i= 1;i<n;i++)
        {
        	int x,y;
        	cin>>x>>y;
        	a[y].fa = x;
        }
        for(int i= 1;i<n;i++)
        {
        	int now = search();
        	a[now].w = 0;
        	int father = a[now].fa;
        	ans += a[now].c * a[father].t;
        	for(int j= 1;j<=n;j++)
        	{
        		if(a[j].fa == now)
        		{
        			a[j].fa = father; 
        		}
        	}
        	a[father].c += a[now].c;
        	a[father].t += a[now].t;
        	a[father].w = (double)a[father].c / (double)a[father].t;
        	}
        cout<<ans<<endl;
	}

	return 0 ;
}
*/
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	
	return 0 ;
}