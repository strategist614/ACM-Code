/*
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N];
struct node
{
	int x;
	int y;
}b[N];
bool cmp(node a,node b)
{
	return a.x < b.x;
}
int vis[N],tot;
std::vector<int> v;
int k,n;
int solve(int m)
{
	int tmp = 0;
	int _ = b[m].x;
	for(int i = m;i <= tot;i++)
	{
		if(b[i].x == _) tmp += 1;
		if(b[i].x > _) tmp += b[m].x;
	}
	if(tmp == k) return 1;
	else return 0 ;
}
int main ()
{
    cin>>n>>k;
    for(int i =1;i<=n;i++) {cin>>a[i];vis[a[i]]++;}
    for(int i =1;i<=2e5;i++) 
    {
        if(vis[i] != 0)
        {
        	b[++tot].x = vis[i];
        	b[tot].y = i; 
        } 
    }
    sort(b+1,b+tot+1,cmp);
   // cout<<1;
    int l = 1;
    int r = tot;
    while(l < r)
    { 
       int mid = (l+r+1)>>1;
       if(solve(mid)) l = mid;
       else r = mid - 1;
    }
   // cout<<l<<endl;
    int _ = b[l].x;
    int __ = k;
    for(int i= l;i<=tot;i++)
    {
       if(b[i].x / _ == 1 && k) v.push_back(b[i].y),k--;  
       if(b[i].x / _ > 1 && k)
       {
          if(b[i].x / _ <= k) 
          {	
             for(int j = 1;j <= b[i].x/_;j++) 
          	   v.push_back(b[i].y);
          	 k -= b[i].x/_;
          }
          else 
          {
          	 for(int j =1;j<=k;j++)
          	 	v.push_back(b[i].y);
          	 k--;
          }
      }
    }
    if(b[tot].x / __ > _)
    {
       for(int i= 1;i<=__;i++)
         cout<<b[tot].y<<" ";
       return 0 ;	
    }
    for(int i= 0;i<v.size();i++)
    	cout<<v[i]<<" ";
    cout<<endl;
	return 0 ;
}
*/
