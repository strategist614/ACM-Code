#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int s,a,b;
struct node
{
	int s;
	int a; 
	int b;
	int t;
};
int vis[N][N];
int bfs()
{ 
	memset(vis,0,sizeof(vis));
	queue<node> q;
	node st;
	st.a = 0;
	st.b = 0;
	st.s = s;
	st.t = 0;
	vis[a][b] = 1;
	q.push(st);
    while(!q.empty())
    {
    	node u= q.front(),v;
    	if(u.a == s/2 && u.s == s/2)
    	{
    	    return u.t;
    	}
    	if(u.s && u.a != a)
    	{
            int c = a - u.a;
            if(u.s >= c) v.a = a,v.s = u.s-c;
            else v.a = u.a+u.s,v.s = 0;
            v.b = u.b,v.t = u.t+1;
            if(!vis[v.a][v.b])
            {
            	q.push(v);
            	vis[v.a][v.b] = 1;
            }
    	}
    	if(u.s && u.b != b)
    	{
    		int c = b - u.b;
    		if(u.s >= c) v.b = b,v.s = u.s-c;
    		else v.b = u.s+u.b,v.s = 0;
    		v.a = u.a,v.t = u.t+1;
    		if(!vis[v.a][v.b])
    		{
    			q.push(v);
    			vis[v.a][v.b] = 1;
    		}
    	}
    	if(u.a && u.s != s)
    	{
    		int c = s - u.s;
    		if(u.a >= c) v.s = s,v.a = u.a - c;
    		else v.s = u.a+u.s,v.a = 0;
    		v.b = u.b,v.t = u.t+1;
    		if(!vis[v.a][v.b])
    		{
    			q.push(v);
    			vis[v.a][v.b] = 1;
    		}
    	}
    	if(u.a && u.b != b)
    	{
    		int c = b - u.b;
    		if(u.a >= c) v.b = b,v.a = u.a-c;
    		else v.b = u.a+u.b,v.a = 0;
    		v.s = u.s,v.t = u.t+1;
    		if(!vis[v.a][v.b])
    		{
    			q.push(v);
    			vis[v.a][v.b] = 1;
    		}
    	}
    	if(u.b && u.s != s)
    	{
    		int c = s - u.s;
    		if(u.b >= c)v.s = s,v.b = u.b - c;
    		else v.s = u.b+u.s,v.b = 0;
    		v.a = u.a,v.t = u.t+1;
    		if(!vis[v.a][v.b])
    		{
    			q.push(v);
    			vis[v.a][v.b] = 1;
    		}
    	}
    	if(u.b && u.a != a)
    	{
    		int c = a - u.a;
    		if(u.b >= c)v.a = a,v.b = u.b - c;
    		else v.a = u.b+u.a,v.b = 0;
    		v.s = u.s,v.t = u.t+1;
    		if(!vis[v.a][v.b])
    		{
    			q.push(v);
    			vis[v.a][v.b] = 1;
    		}
    	}
    	q.pop();
    }
    return 0;
}
int main ()
{
    while(scanf("%d %d %d",&s,&a,&b)!=EOF)
    {
       if(s == 0 && a == 0 && b == 0) break;
       if(s % 2) puts("NO");
       else 
       {
         if(a < b) swap(a,b);
         int ans = bfs();
         if(!ans) cout<<"NO"<<endl;
         else cout<<ans<<endl;
       }       
    }
	return 0 ;
}